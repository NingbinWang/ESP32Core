#include "AppNotify.h"
#include "HAL/HAL.h"

static  Notification* actIMU;

void IMU_Commit(HAL::IMU_Info_t* info)
{
    actIMU->Commit(info,sizeof(HAL::IMU_Info_t));
}

void APP_IMU_Init(Notification* account)
{
    actIMU = account;
}