#ifndef _APP_H_
#define _APP_H_

#ifdef ARDUINO
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#include "Configs/Config.h"
#define ACCOUNT_SEND_NOTIFY_CMD(ACT, CMD)\
do{\
    AccountSystem::ACT##_Info_t info;\
    memset(&info, 0, sizeof(info));\
    info.cmd = AccountSystem::CMD;\
    AccountSystem::Broker()->AccountMaster.Notify(#ACT, &info, sizeof(info));\
}while(0)


void App_Init();

#endif
