#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#ifdef PLATFROMIO
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif // AURDINO 


void Port_Init();

#endif // !_DISPLAY_H_

