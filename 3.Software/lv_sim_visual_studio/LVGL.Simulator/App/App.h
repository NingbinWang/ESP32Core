#ifndef _APP_H_
#define _APP_H_




#ifdef ARDUINO
#include "Port/Display.h"
#define INIT_DONE() \
do{                 \
    xTaskNotifyGive(handleTaskLvgl); \
}while(0) \

#else
#define INIT_DONE() \
do{                 \
}while(0) \

void App_Init();

#endif

#endif
