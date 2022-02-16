#include "SystemNotify.h"
#include "Systeminfo_Def.h"

static NotifyBroker systemdatacenter("SystemDate");

NotifyBroker* SystemNotify::Broker()
{
    return &systemdatacenter;
}

void SystemNotify_Init(void){
   Notification* SYS_StatusBar = new Notification("StatusBar", &systemdatacenter, 0);
   extern void SYS_StatusBar_Init(Notification* account);
   SYS_StatusBar_Init(SYS_StatusBar);
}