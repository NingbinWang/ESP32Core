#ifndef _SYSTEMNOTIFY_H_
#define _SYSTEMNOTIFY_H_

#include "Framework/Notification/NotifyBroker.h"
#include "Systeminfo_Def.h"

void SystemNotify_Init(void);
Notification* get_SYS_StatusBar(void);
namespace SystemNotify{
     NotifyBroker* Broker();
}

#endif