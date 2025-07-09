
#ifndef _APPINFO_DEF_H_
#define _APPINFO_DEF_H_
#include <stdint.h>


namespace AppInfoDef
{

/* SysConfig */
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