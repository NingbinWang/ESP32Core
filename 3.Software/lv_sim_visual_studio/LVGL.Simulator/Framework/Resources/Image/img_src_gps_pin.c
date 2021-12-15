﻿#ifdef ARDUINO
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#ifndef LV_ATTRIBUTE_IMG_IMG_SRC_GPS_PIN
#define LV_ATTRIBUTE_IMG_IMG_SRC_GPS_PIN
#endif

const LV_ATTRIBUTE_MEM_ALIGN LV_ATTRIBUTE_LARGE_CONST LV_ATTRIBUTE_IMG_IMG_SRC_GPS_PIN uint8_t img_src_gps_pin_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
  /*Pixel format: Blue: 2 bit, Green: 3 bit, Red: 3 bit, Alpha 8 bit */
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 
  0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 
  0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 
  0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 
  0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 
  0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 
  0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 
  0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x02, 0xff, 0x02, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
  0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x01, 0xff, 0x01, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
  /*Pixel format: Blue: 5 bit, Green: 6 bit, Red: 5 bit, Alpha 8 bit*/
  0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x03, 0x00, 0xff, 0x03, 0x00, 0xff, 0x03, 0x00, 0xff, 0x03, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x04, 0x00, 0xff, 0x04, 0x00, 0xff, 0x04, 0x00, 0xff, 0x04, 0x00, 0xff, 0x04, 0x00, 0xff, 0x04, 0x00, 0xff, 0x04, 0x00, 0xff, 0x04, 0x00, 0xff, 0x00, 0x00, 0xff, 0x01, 0x00, 0xff, 
  0x00, 0x00, 0xff, 0x05, 0x00, 0xff, 0x05, 0x00, 0xff, 0x05, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x05, 0x00, 0xff, 0x05, 0x00, 0xff, 0x05, 0x00, 0xff, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0xff, 0x05, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x05, 0x00, 0xff, 0x06, 0x00, 0xff, 
  0x06, 0x00, 0xff, 0x06, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x06, 0x00, 0xff, 0x06, 0x00, 0xff, 
  0x06, 0x00, 0xff, 0x06, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x06, 0x00, 0xff, 0x07, 0x00, 0xff, 
  0x07, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x05, 0x00, 0xff, 
  0x07, 0x00, 0xff, 0x07, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x06, 0x00, 0xff, 0x07, 0x00, 0xff, 
  0x07, 0x00, 0xff, 0x07, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x07, 0x00, 0xff, 0x08, 0x00, 0xff, 
  0x08, 0x00, 0xff, 0x08, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x08, 0x00, 0xff, 0x08, 0x00, 0xff, 
  0x00, 0x00, 0xff, 0x08, 0x00, 0xff, 0x08, 0x00, 0xff, 0x07, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x0c, 0x00, 0xff, 0x08, 0x00, 0xff, 0x09, 0x00, 0xff, 0x09, 0x00, 0xff, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x09, 0x00, 0xff, 0x09, 0x00, 0xff, 0x09, 0x00, 0xff, 0x09, 0x00, 0xff, 0x09, 0x00, 0xff, 0x09, 0x00, 0xff, 0x0a, 0x00, 0xff, 0x0a, 0x00, 0xff, 0x01, 0x00, 0xff, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x01, 0x00, 0xff, 0x0a, 0x00, 0xff, 0x0a, 0x00, 0xff, 0x0a, 0x00, 0xff, 0x0a, 0x00, 0xff, 0x01, 0x00, 0xff, 0x00, 0x00, 0xff, 0x01, 0x00, 0xff, 0x00, 0x00, 0xff, 
  0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x00, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x0a, 0x00, 0xff, 0x0a, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x02, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 
  0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 
  0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 
  0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 
  0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 
  0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 
  0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 
  0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 
  0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x02, 0x00, 0xff, 0x02, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x03, 0x00, 0xff, 0x02, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 
  0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x02, 0x00, 0xff, 0x03, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x0b, 0x00, 0xff, 0x03, 0x00, 0xff, 0x03, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 0x01, 0x00, 0xff, 
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
  /*Pixel format:  Blue: 5 bit Green: 6 bit, Red: 5 bit, Alpha 8 bit  BUT the 2  color bytes are swapped*/
  0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x03, 0xff, 0x00, 0x03, 0xff, 0x00, 0x03, 0xff, 0x00, 0x03, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x04, 0xff, 0x00, 0x04, 0xff, 0x00, 0x04, 0xff, 0x00, 0x04, 0xff, 0x00, 0x04, 0xff, 0x00, 0x04, 0xff, 0x00, 0x04, 0xff, 0x00, 0x04, 0xff, 0x00, 0x00, 0xff, 0x00, 0x01, 0xff, 
  0x00, 0x00, 0xff, 0x00, 0x05, 0xff, 0x00, 0x05, 0xff, 0x00, 0x05, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x05, 0xff, 0x00, 0x05, 0xff, 0x00, 0x05, 0xff, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0xff, 0x00, 0x05, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x05, 0xff, 0x00, 0x06, 0xff, 
  0x00, 0x06, 0xff, 0x00, 0x06, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x06, 0xff, 0x00, 0x06, 0xff, 
  0x00, 0x06, 0xff, 0x00, 0x06, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x06, 0xff, 0x00, 0x07, 0xff, 
  0x00, 0x07, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x05, 0xff, 
  0x00, 0x07, 0xff, 0x00, 0x07, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x06, 0xff, 0x00, 0x07, 0xff, 
  0x00, 0x07, 0xff, 0x00, 0x07, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x07, 0xff, 0x00, 0x08, 0xff, 
  0x00, 0x08, 0xff, 0x00, 0x08, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x08, 0xff, 0x00, 0x08, 0xff, 
  0x00, 0x00, 0xff, 0x00, 0x08, 0xff, 0x00, 0x08, 0xff, 0x00, 0x07, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x0c, 0xff, 0x00, 0x08, 0xff, 0x00, 0x09, 0xff, 0x00, 0x09, 0xff, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x09, 0xff, 0x00, 0x09, 0xff, 0x00, 0x09, 0xff, 0x00, 0x09, 0xff, 0x00, 0x09, 0xff, 0x00, 0x09, 0xff, 0x00, 0x0a, 0xff, 0x00, 0x0a, 0xff, 0x00, 0x01, 0xff, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x01, 0xff, 0x00, 0x0a, 0xff, 0x00, 0x0a, 0xff, 0x00, 0x0a, 0xff, 0x00, 0x0a, 0xff, 0x00, 0x01, 0xff, 0x00, 0x00, 0xff, 0x00, 0x01, 0xff, 0x00, 0x00, 0xff, 
  0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x00, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x0a, 0xff, 0x00, 0x0a, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x02, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 
  0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 
  0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 
  0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 
  0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 
  0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 
  0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 
  0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 
  0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x02, 0xff, 0x00, 0x02, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x03, 0xff, 0x00, 0x02, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 
  0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x02, 0xff, 0x00, 0x03, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x0b, 0xff, 0x00, 0x03, 0xff, 0x00, 0x03, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 0x00, 0x01, 0xff, 
#endif
#if LV_COLOR_DEPTH == 32
  /*Pixel format:  Blue: 8 bit, Green: 8 bit, Red: 8 bit, Alpha: 8 bit*/
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x19, 0x00, 0x00, 0xff, 0x1a, 0x00, 0x00, 0xff, 0x1b, 0x00, 0x00, 0xff, 0x1c, 0x00, 0x00, 0xff, 0x01, 0x00, 0x00, 0xff, 0x02, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0xff, 0x04, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x1d, 0x00, 0x00, 0xff, 0x1e, 0x00, 0x00, 0xff, 0x1f, 0x00, 0x00, 0xff, 0x20, 0x00, 0x00, 0xff, 0x21, 0x00, 0x00, 0xff, 0x22, 0x00, 0x00, 0xff, 0x23, 0x00, 0x00, 0xff, 0x24, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0xff, 0x05, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x25, 0x00, 0x00, 0xff, 0x26, 0x00, 0x00, 0xff, 0x27, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5e, 0x00, 0x00, 0xff, 0x5f, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x28, 0x00, 0x00, 0xff, 0x29, 0x00, 0x00, 0xff, 0x2a, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x2b, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5e, 0x00, 0x00, 0xff, 0x5f, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x2c, 0x00, 0x00, 0xff, 0x2d, 0x00, 0x00, 0xff, 
  0x2e, 0x00, 0x00, 0xff, 0x2f, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5e, 0x00, 0x00, 0xff, 0x5f, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x30, 0x00, 0x00, 0xff, 0x31, 0x00, 0x00, 0xff, 
  0x32, 0x00, 0x00, 0xff, 0x33, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5e, 0x00, 0x00, 0xff, 0x5f, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x34, 0x00, 0x00, 0xff, 0x35, 0x00, 0x00, 0xff, 
  0x36, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5e, 0x00, 0x00, 0xff, 0x5f, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x2c, 0x00, 0x00, 0xff, 
  0x37, 0x00, 0x00, 0xff, 0x38, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5e, 0x00, 0x00, 0xff, 0x5f, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x34, 0x00, 0x00, 0xff, 0x39, 0x00, 0x00, 0xff, 
  0x3a, 0x00, 0x00, 0xff, 0x3b, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5e, 0x00, 0x00, 0xff, 0x5f, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x3c, 0x00, 0x00, 0xff, 0x3d, 0x00, 0x00, 0xff, 
  0x3e, 0x00, 0x00, 0xff, 0x3f, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x5e, 0x00, 0x00, 0xff, 0x5f, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x40, 0x00, 0x00, 0xff, 0x41, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x42, 0x00, 0x00, 0xff, 0x43, 0x00, 0x00, 0xff, 0x38, 0x00, 0x00, 0xff, 0x5d, 0x00, 0x00, 0xff, 0x61, 0x00, 0x00, 0xff, 0x62, 0x00, 0x00, 0xff, 0x60, 0x00, 0x00, 0xff, 0x44, 0x00, 0x00, 0xff, 0x45, 0x00, 0x00, 0xff, 0x46, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x47, 0x00, 0x00, 0xff, 0x48, 0x00, 0x00, 0xff, 0x49, 0x00, 0x00, 0xff, 0x4a, 0x00, 0x00, 0xff, 0x4b, 0x00, 0x00, 0xff, 0x4c, 0x00, 0x00, 0xff, 0x4d, 0x00, 0x00, 0xff, 0x4e, 0x00, 0x00, 0xff, 0x05, 0x00, 0x00, 0xff, 0x01, 0x00, 0x00, 0xff, 
  0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x06, 0x00, 0x00, 0xff, 0x4f, 0x00, 0x00, 0xff, 0x50, 0x00, 0x00, 0xff, 0x51, 0x00, 0x00, 0xff, 0x52, 0x00, 0x00, 0xff, 0x07, 0x00, 0x00, 0xff, 0x02, 0x00, 0x00, 0xff, 0x05, 0x00, 0x00, 0xff, 0x04, 0x00, 0x00, 0xff, 
  0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x00, 0x00, 0x00, 0xff, 0x09, 0x00, 0x00, 0xff, 0x0a, 0x00, 0x00, 0xff, 0x53, 0x00, 0x00, 0xff, 0x54, 0x00, 0x00, 0xff, 0x0b, 0x00, 0x00, 0xff, 0x0c, 0x00, 0x00, 0xff, 0x0d, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 
  0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x0e, 0x00, 0x00, 0xff, 0x0f, 0x00, 0x00, 0xff, 0x55, 0x00, 0x00, 0xff, 0x56, 0x00, 0x00, 0xff, 0x10, 0x00, 0x00, 0xff, 0x11, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 
  0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x0e, 0x00, 0x00, 0xff, 0x0f, 0x00, 0x00, 0xff, 0x55, 0x00, 0x00, 0xff, 0x56, 0x00, 0x00, 0xff, 0x10, 0x00, 0x00, 0xff, 0x11, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 
  0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x0e, 0x00, 0x00, 0xff, 0x0f, 0x00, 0x00, 0xff, 0x55, 0x00, 0x00, 0xff, 0x56, 0x00, 0x00, 0xff, 0x10, 0x00, 0x00, 0xff, 0x11, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 
  0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x0e, 0x00, 0x00, 0xff, 0x0f, 0x00, 0x00, 0xff, 0x55, 0x00, 0x00, 0xff, 0x56, 0x00, 0x00, 0xff, 0x10, 0x00, 0x00, 0xff, 0x11, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 
  0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x0e, 0x00, 0x00, 0xff, 0x0f, 0x00, 0x00, 0xff, 0x55, 0x00, 0x00, 0xff, 0x56, 0x00, 0x00, 0xff, 0x10, 0x00, 0x00, 0xff, 0x11, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 
  0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x0e, 0x00, 0x00, 0xff, 0x0f, 0x00, 0x00, 0xff, 0x55, 0x00, 0x00, 0xff, 0x56, 0x00, 0x00, 0xff, 0x10, 0x00, 0x00, 0xff, 0x11, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 
  0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x0e, 0x00, 0x00, 0xff, 0x12, 0x00, 0x00, 0xff, 0x57, 0x00, 0x00, 0xff, 0x58, 0x00, 0x00, 0xff, 0x13, 0x00, 0x00, 0xff, 0x11, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 
  0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x0e, 0x00, 0x00, 0xff, 0x14, 0x00, 0x00, 0xff, 0x59, 0x00, 0x00, 0xff, 0x5a, 0x00, 0x00, 0xff, 0x15, 0x00, 0x00, 0xff, 0x11, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 
  0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x0e, 0x00, 0x00, 0xff, 0x16, 0x00, 0x00, 0xff, 0x5b, 0x00, 0x00, 0xff, 0x5c, 0x00, 0x00, 0xff, 0x17, 0x00, 0x00, 0xff, 0x18, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 0x08, 0x00, 0x00, 0xff, 
#endif
};

const lv_img_dsc_t img_src_gps_pin = {
  .header.always_zero = 0,
  .header.w = 12,
  .header.h = 23,
  .data_size = 276 * LV_IMG_PX_SIZE_ALPHA_BYTE,
  .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
  .data = img_src_gps_pin_map,
};

