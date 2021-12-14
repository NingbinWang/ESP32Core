#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <stdint.h>
#include <vector>
#include "PingPongBuffer/PingPongBuffer.h"
#include "lvgl/lvgl.h"

class AccountBroker;

class Account
{
public:

    /* Event type enumeration */
    typedef enum
    {
        EVENT_NONE,
        EVENT_PUB_PUBLISH, // Publisher posted information
        EVENT_SUB_PULL,    // Subscriber data pull request
        EVENT_NOTIFY,      // Subscribers send notifications to publishers
        EVENT_TIMER,       // Timed event
        _EVENT_LAST
    } EventCode_t;

    /* Error type enumeration */
    typedef enum
    {
        ERROR_NONE = 0,
        ERROR_UNKNOW = -1,
        ERROR_SIZE_MISMATCH = -2,
        ERROR_UNSUPPORTED_REQUEST = -3,
        ERROR_NO_CALLBACK = -4,
        ERROR_NO_CACHE = -5,
        ERROR_NO_COMMITED = -6,
        ERROR_NOT_FOUND = -7,
        ERROR_PARAM_ERROR = -8
    } ErrorCode_t;

    /* Event parameter structure */
    typedef struct
    {
        EventCode_t event; // Event type
        Account* tran;     // Pointer to sender
        Account* recv;     // Pointer to receiver
        void* data_p;      // Pointer to data
        uint32_t size;     // The length of the data
    } EventParam_t;

    /* Event callback function pointer */
    typedef int (*EventCallback_t)(Account* account, EventParam_t* param);

public:
    Account(
        const char* id,
        AccountBroker* center,
        uint32_t bufSize = 0,
        void* userData = nullptr
    );
    ~Account();

    Account* Subscribe(const char* pubID);
    bool Unsubscribe(const char* pubID);
    bool Commit(const void* data_p, uint32_t size);
    int Publish();
    int Pull(const char* pubID, void* data_p, uint32_t size);
    int Pull(Account* pub, void* data_p, uint32_t size);
    int Notify(const char* pubID, const void* data_p, uint32_t size);
    int Notify(Account* pub, const void* data_p, uint32_t size);
    void SetEventCallback(EventCallback_t callback);
    void SetTimerPeriod(uint32_t period);
    void SetTimerEnable(bool en);
    uint32_t GetPublisherSize();
    uint32_t GetSubscribeSize();

public:
    const char* ID;      /* Unique account ID */
    AccountBroker* Center;  /* Pointer to the data center */
    void* UserData;

    std::vector<Account*> publishers;  /* Followed publishers */
    std::vector<Account*> subscribers; /* Followed subscribers */

    struct
    {
        EventCallback_t eventCallback;
        lv_timer_t* timer;
        PingPongBuffer_t BufferManager;
        uint32_t BufferSize;
    } priv;

private:
    static void TimerCallbackHandler(lv_timer_t* task);
};


#endif
