#include "Account_Master.h"
#include "HAL/HAL.h"

static NotifyBroker dataCenter("MASTER");

NotifyBroker* AccountSystem::Broker()
{
    return &dataCenter;
}

void Accounts_Init()
{
#define ACT_DEF(NodeName, bufferSize)\
    Notification* act##NodeName = new Notification(#NodeName, &dataCenter, bufferSize);

#include "ACT_LIST.inc"

#undef ACT_DEF

#define ACT_DEF(NodeName, bufferSize)\
do{\
    extern void _ACT_##NodeName##_Init(Notification* account);\
    _ACT_##NodeName##_Init(act##NodeName);\
}while(0)

#include "ACT_LIST.inc"

#undef ACT_DEF
}
