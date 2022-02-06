#ifndef _FRAMEWORK_H_
#define _FRAMEWORK_H_

#ifdef ARDUINO
#include "HAL/LCDPort/Display.h"
#define INIT_DONE() do{xTaskNotifyGive(handleTaskLvgl);}while(0)
#else
#define INIT_DONE() do{}while(0)
#endif

void Framework_Init(void);

#endif