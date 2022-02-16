#ifndef _SYSTEMINFO_DEF_H_
#define _SYSTEMINFO_DEF_H_
#include <stdint.h>

namespace SystemInfoDef
{

/* StatusBar */
typedef struct
{
    bool showLabelRec;
    const char* labelRecStr;
} StatusBar_Info_t;

// SysConfig
typedef enum
{
    SYSCONFIG_CMD_LOAD,
    SYSCONFIG_CMD_SAVE,
} SysConfig_Cmd_t;

typedef struct
{
    SysConfig_Cmd_t cmd;
    bool soundEnable;
    double longitudeDefault;
    double latitudeDefault;
    char language[8];
    char mapDirPath[32];
    bool WGS84;
    char arrowTheme[8];
} SysConfig_Info_t;





}


#endif