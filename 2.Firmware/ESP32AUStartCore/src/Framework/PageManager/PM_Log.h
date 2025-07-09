#ifndef _PM_LOG_H_
#define _PM_LOG_H_

#define PAGE_MANAGER_USE_LOG 1

#if !defined(ARDUINO) && PAGE_MANAGER_USE_LOG
#include <stdio.h>
#  define _PM_LOG(format, ...)      printf("[PM]"format"\r\n", ##__VA_ARGS__)
#  define PM_LOG_INFO(format, ...)  _PM_LOG("[Info] "format, ##__VA_ARGS__)
#  define PM_LOG_WARN(format, ...)  _PM_LOG("[Warn] "format, ##__VA_ARGS__)
#  define PM_LOG_ERROR(format, ...) _PM_LOG("[Error] "format, ##__VA_ARGS__)
#else
#ifdef ARDUINO
#include <Arduino.h>
#  define PM_LOG_INFO(...)      do{Serial.printf("[Info] ");Serial.printf(__VA_ARGS__);Serial.println();}while(0)
#  define PM_LOG_WARN(...)      do{Serial.printf("[Warn] ");Serial.printf(__VA_ARGS__);Serial.println();}while(0)
#  define PM_LOG_ERROR(...)     do{Serial.printf("[Error] ");Serial.printf(__VA_ARGS__);Serial.println();}while(0)
#else
#  define PM_LOG_INFO(...)     
#  define PM_LOG_WARN(...)
#  define PM_LOG_ERROR(...)
#endif
#endif


#endif // !_PAGESMANAGER_LOG_H_

