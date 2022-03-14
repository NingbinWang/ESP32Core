#include "Account_Master.h"
#include "HAL/HAL.h"

static NotifyBroker dataCenter("MASTER");

NotifyBroker* AccountSystem::Broker()
{
    return &dataCenter;
}

void Accounts_Init()
{
    //IMU Accounts
   Notification* actIMU = new Notification("IMU", &dataCenter, sizeof(HAL::IMU_Info_t));
   extern void _ACT_IMU_Init(Notification* account);
   _ACT_IMU_Init(actIMU);
}
