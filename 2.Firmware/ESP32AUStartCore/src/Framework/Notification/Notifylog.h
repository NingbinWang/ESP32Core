#ifndef _NOTIFIYLOG_H_
#define _NOTIFIYLOG_H_

#if !defined(ARDUINO) && DATA_CENTER_USE_LOG
#include <stdio.h>
#  define DC_LOG_INFO(format, ...)      LV_LOG_INFO(format, ##__VA_ARGS__)
#  define DC_LOG_WARN(format, ...)      LV_LOG_WARN(format, ##__VA_ARGS__)
#  define DC_LOG_ERROR(format, ...)     LV_LOG_ERROR(format, ##__VA_ARGS__)
#else
#ifdef ARDUINO
#include <Arduino.h>
#  define DC_LOG_INFO(...)      do{Serial.printf("[Info][%s]",__func__);Serial.printf(__VA_ARGS__);Serial.println();}while(0)
#  define DC_LOG_WARN(...)      do{Serial.printf("[Warn][%s]",__func__);Serial.printf(__VA_ARGS__);Serial.println();}while(0)
#  define DC_LOG_ERROR(...)     do{Serial.printf("[Error][%s]",__func__);Serial.printf(__VA_ARGS__);Serial.println();}while(0)
#else
#  define DC_LOG_INFO(...)     
#  define DC_LOG_WARN(...)
#  define DC_LOG_ERROR(...)
#endif
#endif

#endif