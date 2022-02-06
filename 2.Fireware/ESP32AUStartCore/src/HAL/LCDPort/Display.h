#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include "TFT_eSPI.h"
#include "lvgl.h"


typedef TFT_eSPI SCREEN_CLASS;
void Port_Init();
void lv_port_disp_init(SCREEN_CLASS* scr);

extern TaskHandle_t handleTaskLvgl;

#endif