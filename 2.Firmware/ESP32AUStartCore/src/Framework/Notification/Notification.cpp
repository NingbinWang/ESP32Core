#include "Notification.h"
#include "Notifylog.h"
#include <string.h>
#include "NotifyBroker.h"

/**
  * @brief  Notification constructor
  * @param  id:       Unique name
  * @param  center:   Pointer to the data center
  * @param  bufSize:  The length of the data to be cached
  * @param  userData: Point to the address of user-defined data
  * @retval None
  */
Notification::Notification(
    const char* id,
    NotifyBroker* center,
    uint32_t bufSize,
    void* userData
)
{
    memset(&priv, 0, sizeof(priv));

    ID = id;
    Center = center;
    UserData = userData;

    if (bufSize != 0)
    {
        uint8_t* buf0 = new uint8_t[bufSize];

        if (!buf0)
        {
            DC_LOG_ERROR("[%s] buf0 malloc failed!", ID);
            return;
        }

        uint8_t* buf1 = new uint8_t[bufSize];

        if (!buf1)
        {
            delete [] buf0;
            DC_LOG_ERROR("[%s] buf1 malloc failed!", ID);
            return;
        }

        memset(buf0, 0, bufSize);
        memset(buf1, 0, bufSize);
        PingPongBuffer_Init(&priv.BufferManager, buf0, buf1);
        DC_LOG_INFO("[%s] cached %d x2 bytes", ID, bufSize);
        priv.BufferSize = bufSize;
    }

    Center->AddAccount(this);

    DC_LOG_INFO("[%s] created", ID);
}

/**
  * @brief  Account destructor
  * @param  None
  * @retval None
  */
Notification::~Notification()
{
    DC_LOG_INFO("[%s] deleting...", ID);

    /* Release cache */
    if(priv.BufferSize)
    {
        delete priv.BufferManager.buffer[0];
        delete priv.BufferManager.buffer[1];
    }

    /* Delete timer */
    if (priv.timer)
    {
        lv_timer_del(priv.timer);
        DC_LOG_INFO("[%s] task deleted", ID);
    }

    /* Let subscribers unfollow */
    for(auto iter : subscribers)
    {
        iter->Unsubscribe(ID);
        DC_LOG_INFO("sub[%s] unsubscribed pub[%s]", iter->ID, ID);
    }

    /* Ask the publisher to delete this subscriber */
    for (auto iter : publishers)
    {
        Center->Remove(&iter->subscribers, this);
        DC_LOG_INFO("pub[%s] removed sub[%s]", iter->ID, ID);
    }

    /* Let the data center delete the account */
    Center->RemoveAccount(this);
    DC_LOG_INFO("[%s] deleted", ID);
}

/**
  * @brief  Subscribe to Publisher
  * @param  pubID: Publisher ID
  * @retval Pointer to publisher
  */
Notification* Notification::Subscribe(const char* pubID)
{
    /* Not allowed to subscribe to yourself */
    if (strcmp(pubID, ID) == 0)
    {
        DC_LOG_ERROR("[%s] try to subscribe to it itself", ID);
        return nullptr;
    }

    /* Whether to subscribe repeatedly */
    Notification* pub = Center->Find(&publishers, pubID);
    if(pub != nullptr)
    {
        DC_LOG_ERROR("Multi subscribe pub[%s]", pubID);
        return nullptr;
    }

    /* BWhether the account is created */
    pub = Center->SearchAccount(pubID);
    if (pub == nullptr)
    {
        DC_LOG_ERROR("pub[%s] was not found", pubID);
        return nullptr;
    }

    /* Add the publisher to the subscription list */
    publishers.push_back(pub);

    /* Let the publisher add this subscriber */
    pub->subscribers.push_back(this);

    DC_LOG_INFO("sub[%s] subscribed pub[%s]", ID, pubID);

    return pub;
}

/**
  * @brief  Unsubscribe from publisher
  * @param  pubID: Publisher ID
  * @retval Return true if unsubscribe is successful
  */
bool Notification::Unsubscribe(const char* pubID)
{
    /* Whether to subscribe to the publisher */
    Notification* pub = Center->Find(&publishers, pubID);
    if (pub == nullptr)
    {
        DC_LOG_WARN("sub[%s] was not subscribe pub[%s]", ID, pubID);
        return false;
    }

    /* Remove the publisher from the subscription list */
    Center->Remove(&publishers, pub);

    /* Let the publisher add this subscriber */
    Center->Remove(&pub->subscribers, this);

    return true;
}

/**
  * @brief  Submit data to cache
  * @param  data_p: Pointer to data
  * @param  size:   The size of the data
  * @retval Return true if the submission is successful
  */
bool Notification::Commit(const void* data_p, uint32_t size)
{
    if (!size || size != priv.BufferSize)
    {
        DC_LOG_ERROR("pub[%s] has not cache", ID);
        return false;
    }

    void* wBuf;
    PingPongBuffer_GetWriteBuf(&priv.BufferManager, &wBuf);

    memcpy(wBuf, data_p, size);

    PingPongBuffer_SetWriteDone(&priv.BufferManager);

    DC_LOG_INFO("pub[%s] commit data(0x%p)[%d] >> data(0x%p)[%d] done",
                ID, data_p, size, wBuf, size);

    return true;
}

/**
  * @brief  Publish data to subscribers
  * @param  None
  * @retval error code
  */
int Notification::Publish()
{
    int retval = ERROR_UNKNOW;

    if (priv.BufferSize == 0)
    {
        DC_LOG_ERROR("pub[%s] has not cache", ID);
        return ERROR_NO_CACHE;
    }

    void* rBuf;
    if (!PingPongBuffer_GetReadBuf(&priv.BufferManager, &rBuf))
    {
        DC_LOG_WARN("pub[%s] data was not commit", ID);
        return ERROR_NO_COMMITED;
    }

    EventParam_t param;
    param.event = EVENT_PUB_PUBLISH;
    param.tran = this;
    param.recv = nullptr;
    param.data_p = rBuf;
    param.size = priv.BufferSize;

    /* Push messages to subscribers */
    for(auto iter : subscribers)
    {
        Notification* sub = iter;
        EventCallback_t callback = sub->priv.eventCallback;

        DC_LOG_INFO("pub[%s] push >> data(0x%p)[%d] >> sub[%s]...",
                    ID, param.data_p, param.size, sub->ID);

        if (callback != nullptr)
        {
            param.recv = sub;
            int ret = callback(sub, &param);

            DC_LOG_INFO("push done: %d", ret);
            retval = ret;
        }
        else
        {
            DC_LOG_INFO("sub[%s] not register callback", sub->ID);
        }
    }

    PingPongBuffer_SetReadDone(&priv.BufferManager);

    return retval;
}

/**
  * @brief  Pull data from the publisher
  * @param  pubID:  Publisher ID
  * @param  data_p: Pointer to data
  * @param  size:   The size of the data
  * @retval error code
  */
int Notification::Pull(const char* pubID, void* data_p, uint32_t size)
{
    Notification* pub = Center->Find(&publishers, pubID);
    if (pub == nullptr)
    {
        DC_LOG_ERROR("sub[%s] was not subscribe pub[%s]", ID, pubID);
        return ERROR_NOT_FOUND;
    }
    return Pull(pub, data_p, size);
}

int Notification::Pull(Notification* pub, void* data_p, uint32_t size)
{
    int retval = ERROR_UNKNOW;

    if (pub == nullptr)
    {
        return ERROR_NOT_FOUND;
    }

    DC_LOG_INFO("sub[%s] pull << data(0x%p)[%d] << pub[%s] ...",
                ID, data_p, size, pub->ID);

    EventCallback_t callback = pub->priv.eventCallback;
    if (callback != nullptr)
    {
        EventParam_t param;
        param.event = EVENT_SUB_PULL;
        param.tran = this;
        param.recv = pub;
        param.data_p = data_p;
        param.size = size;

        int ret = callback(pub, &param);

        DC_LOG_INFO("pull done: %d", ret);
        retval = ret;
    }
    else
    {
        DC_LOG_INFO("pub[%s] not registed pull callback, read commit cache...", pub->ID);

        if (pub->priv.BufferSize == size)
        {
            void* rBuf;
            if (PingPongBuffer_GetReadBuf(&pub->priv.BufferManager, &rBuf))
            {
                memcpy(data_p, rBuf, size);
                PingPongBuffer_SetReadDone(&pub->priv.BufferManager);
                DC_LOG_INFO("read done");
                retval = 0;
            }
            else
            {
                DC_LOG_WARN("pub[%s] data was not commit!", pub->ID);
            }
        }
        else
        {
            DC_LOG_ERROR(
                "Data size pub[%s]:%d != sub[%s]:%d",
                pub->ID,
                pub->priv.BufferSize,
                this->ID,
                size
            );
        }
    }

    return retval;
}

/**
  * @brief  Send a notification to the publisher
  * @param  pubID: Publisher ID
  * @param  data_p: Pointer to data
  * @param  size:   The size of the data
  * @retval error code
  */
int Notification::Notify(const char* pubID, const void* data_p, uint32_t size)
{
    Notification* pub = Center->Find(&publishers, pubID);
    if (pub == nullptr)
    {
        DC_LOG_ERROR("sub[%s] was not subscribe pub[%s]", ID, pubID);
        return ERROR_NOT_FOUND;
    }
    return Notify(pub, data_p, size);
}

/**
  * @brief  Send a notification to the publisher
  * @param  pub:    Pointer to publisher
  * @param  data_p: Pointer to data
  * @param  size:   The size of the data
  * @retval error code
  */
int Notification::Notify(Notification* pub, const void* data_p, uint32_t size)
{
    int retval = ERROR_UNKNOW;

    if (pub == nullptr)
    {
        return ERROR_NOT_FOUND;
    }

    DC_LOG_INFO("sub[%s] notify >> data(0x%p)[%d] >> pub[%s] ...",
                ID, data_p, size, pub->ID);

    EventCallback_t callback = pub->priv.eventCallback;
    if (callback != nullptr)
    {
        EventParam_t param;
        param.event = EVENT_NOTIFY;
        param.tran = this;
        param.recv = pub;
        param.data_p = (void*)data_p;
        param.size = size;

        int ret = callback(pub, &param);

        DC_LOG_INFO("send done: %d", ret);
        retval = ret;
    }
    else
    {
        DC_LOG_WARN("pub[%s] not register callback", pub->ID);
        retval = ERROR_NO_CALLBACK;
    }

    return retval;
}

/**
  * @brief  Set event callback
  * @param  callback: Callback function pointer
  * @retval None
  */
void Notification::SetEventCallback(EventCallback_t callback)
{
    priv.eventCallback = callback;
}

/**
  * @brief  Timer callback entry function
  * @param  timer: Pointer to timer
  * @retval None
  */
void Notification::TimerCallbackHandler(lv_timer_t* timer)
{
    Notification* instance = (Notification*)(timer->user_data);
    EventCallback_t callback = instance->priv.eventCallback;
    if(callback)
    {
        EventParam_t param;
        param.event = EVENT_TIMER;
        param.tran = instance;
        param.recv = instance;
        param.data_p = nullptr;
        param.size = 0;

        callback(instance, &param);
    }
}

/**
  * @brief  Set timing period
  * @param  period: Timing period
  * @retval None
  */
void Notification::SetTimerPeriod(uint32_t period)
{
    if(priv.timer)
    {
        lv_timer_del(priv.timer);
        priv.timer = nullptr;
    }

    if(period == 0)
    {
        return;
    }

    priv.timer = lv_timer_create(
                     TimerCallbackHandler,
                     period,
                     this
                 );
}

/**
  * @brief  Set timer enable
  * @param  en: Whether to enable
  * @retval None
  */
void Notification::SetTimerEnable(bool en)
{
    lv_timer_t* timer = priv.timer;

    if (timer == nullptr)
    {
        return;
    }

    en ? lv_timer_resume(timer) : lv_timer_pause(timer);
}

/**
  * @brief  Get the number of publishers
  * @retval number of publishers
  */
uint32_t Notification::GetPublisherSize()
{
    return publishers.size();
}

/**
  * @brief  Get the number of subscribes
  * @retval number of subscribes
  */
uint32_t Notification::GetSubscribeSize()
{
    return subscribers.size();
}

