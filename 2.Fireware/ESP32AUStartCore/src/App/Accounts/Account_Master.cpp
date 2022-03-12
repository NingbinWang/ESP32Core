#include "Account_Master.h"
#include "HAL/HAL.h"

static NotifyBroker dataCenter("MASTER");

NotifyBroker* AccountSystem::Broker()
{
    return &dataCenter;
}

void Accounts_Init()
{

}
