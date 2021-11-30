#ifndef __PM_LOG_H
#define __PM_LOG_H

#define PAGE_MANAGER_USE_LOG 1

#if !defined(ARDUINO) && PAGE_MANAGER_USE_LOG
#include <stdio.h>
#  define PM_LOG_INFO(format, ...)  //printf("\r\nPM INFO: "),printf(format, ##__VA_ARGS__)
#  define PM_LOG_WARN(format, ...)  printf("\r\nPM WARN: "),printf(format, ##__VA_ARGS__)
#  define PM_LOG_ERROR(format, ...) printf("\r\nPM ERROR: "),printf(format, ##__VA_ARGS__)
#else
#  define PM_LOG_INFO(...)
#  define PM_LOG_WARN(...)
#  define PM_LOG_ERROR(...)
#endif

#endif
