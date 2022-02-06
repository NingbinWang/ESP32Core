#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include "TFT_eSPI.h"
#ifdef ARDUINO
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


typedef TFT_eSPI SCREEN_CLASS;
void Port_Init();
void lv_port_disp_init(SCREEN_CLASS* scr);

extern TaskHandle_t handleTaskLvgl;

#endif