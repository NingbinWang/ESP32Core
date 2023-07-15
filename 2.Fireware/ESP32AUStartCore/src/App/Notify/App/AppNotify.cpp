#include "AppNotify.h"
#include "HAL/HAL.h"

void AppNotify_Init()
{
     NotifyBroker* center = NotifyCenter::Broker();
     Notification* APP_IMU = new Notification("imu",center, sizeof(HAL::IMU_Info_t));
     Notification* APP_Config = new Notification("sysconfig",center, 0);
    extern void APP_IMU_Init(Notification* account);
    APP_IMU_Init(APP_IMU);
    extern void APP_Config_Init(Notification* account);
    APP_Config_Init(APP_Config);
}