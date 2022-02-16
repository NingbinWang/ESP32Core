#ifndef _ACCOUNT_MASTER_H_
#define _ACCOUNT_MASTER_H_

#include "Framework/Notification/NotifyBroker.h"
#include "HAL/HAL_Def.h"
#include "ACT_Def.h"

#define ACCOUNT_INIT_DEF(name) void _ACT_##name##_Init(Notification* account)

void Accounts_Init();

namespace AccountSystem
{

  NotifyBroker* Broker();

  void IMU_Commit(HAL::IMU_Info_t* info);
}

#endif
