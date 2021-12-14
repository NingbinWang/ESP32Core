﻿#ifndef _CONFIG_H_
#define _CONFIG_H_

//Screen
// Generic ESP32 setup
#define CONFIG_SCREEN_CS_PIN        5
#define CONFIG_SCREEN_DC_PIN        2
#define CONFIG_SCREEN_RST_PIN       4
#define CONFIG_SCREEN_SCK_PIN       18
#define CONFIG_SCREEN_MOSI_PIN      23
#define CONFIG_SCREEN_BLK_PIN       12
#define CONFIG_SCREEN_MISO_PIN      19

#define CONFIG_SCREEN_HOR_RES       240
#define CONFIG_SCREEN_VER_RES       320
#define CONFIG_SCREEN_BUFFER_SIZE   (CONFIG_SCREEN_HOR_RES * CONFIG_SCREEN_VER_RES /2)

#define CONFIG_MONKEY_TEST_ENABLE 0
#if CONFIG_MONKEY_TEST_ENABLE
#  define CONFIG_MONKEY_INDEV_TYPE            LV_INDEV_TYPE_ENCODER
#  define CONFIG_MONKEY_TIME_MIN              10
#  define CONFIG_MONKEY_TIME_MAX              100
#  define CONFIG_MONKEY_INPUT_RANGE_MIN       -5
#  define CONFIG_MONKEY_INPUT_RANGE_MAX       5
#endif



#endif // !_CONFIG_H_
