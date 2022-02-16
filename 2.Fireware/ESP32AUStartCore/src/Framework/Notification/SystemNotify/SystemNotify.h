#ifndef _SYSTEMNOTIFY_H_
#define _SYSTEMNOTIFY_H_

#include "Framework/Notification/NotifyBroker.h"


void SystemNotify_Init(void);

namespace SystemNotify{
     NotifyBroker* Broker();

}

#endif