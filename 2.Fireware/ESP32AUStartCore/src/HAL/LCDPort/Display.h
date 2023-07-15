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
void lv_fs_if_init();
void lv_port_indev_init();

extern TaskHandle_t handleTaskLvgl;

#endif