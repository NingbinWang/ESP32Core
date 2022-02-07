#ifndef _RM_LOG_H_
#define _RM_LOG_H_

#define RESOURCE_MANAGER_USE_LOG 1

#if !defined(ARDUINO) && RESOURCE_MANAGER_USE_LOG
#include <stdio.h>
#  define _RM_LOG(format, ...)      printf("[PM]"format"\r\n", ##__VA_ARGS__)
#  define RM_LOG_INFO(format, ...)  _RM_LOG("[Info] "format, ##__VA_ARGS__)
#  define RM_LOG_WARN(format, ...)  _RM_LOG("[Warn] "format, ##__VA_ARGS__)
#  define RM_LOG_ERROR(format, ...) _RM_LOG("[Error] "format, ##__VA_ARGS__)
#else
#  define RM_LOG_INFO(...)    
#  define RM_LOG_WARN(...)
#  define RM_LOG_ERROR(...)
#endif


#endif // !_RM_LOG_H_
