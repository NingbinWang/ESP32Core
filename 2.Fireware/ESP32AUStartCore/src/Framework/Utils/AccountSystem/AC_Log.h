#ifndef _AC_LOG_H_
#define _AC_LOG_H_

#ifdef ARDUINO
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#define ACCOUNT_CENTER_USE_LOG 1

#if !defined(ARDUINO) && ACCOUNT_CENTER_USE_LOG
#include <stdio.h>
#  define DC_LOG_INFO(format, ...)      LV_LOG_INFO(format, ##__VA_ARGS__)
#  define DC_LOG_WARN(format, ...)      LV_LOG_WARN(format, ##__VA_ARGS__)
#  define DC_LOG_ERROR(format, ...)     LV_LOG_ERROR(format, ##__VA_ARGS__)
#else
#  define DC_LOG_INFO(format, ...)      LV_LOG_INFO(format, ##__VA_ARGS__)
#  define DC_LOG_WARN(format, ...)      LV_LOG_WARN(format, ##__VA_ARGS__)
#  define DC_LOG_ERROR(format, ...)     LV_LOG_ERROR(format, ##__VA_ARGS__)
#endif

#endif // !_AC_LOG_H_

