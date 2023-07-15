#ifndef _APP_H_
#define _APP_H_

#ifdef ARDUINO
#include "lvgl.h"
#include "HAL/LCDPort/Display.h"
#define INIT_DONE() do{xTaskNotifyGive(handleTaskLvgl);}while(0)
#else
#include "lvgl/lvgl.h"
#define INIT_DONE() do{}while(0)
#endif

#define SYSTEM_SEND_NOTIFY_CMD(ACT, CMD)\
do{\
    SystemInfoDef::ACT##_Info_t info;\
    memset(&info, 0, sizeof(info));\
    info.cmd = SystemInfoDef::CMD;\
    NotifyCenter::Broker()->AccountMaster.Notify(#ACT, &info, sizeof(info));\
}while(0)


void App_Init();

#endif
