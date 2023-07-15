#include "SystemNotify.h"
#include "Systeminfo_Def.h"

static int onEvent(Notification* account, Notification::EventParam_t* param)
{
    return 0;
}

void SYS_Power_Init(Notification* account){
   account->SetEventCallback(onEvent);
}