#include "AppNotify.h"
#include "Configs/Config.h"
#include  "HAL/HAL.h"
#include "App/Notify/System/Systeminfo_Def.h"

using namespace AppInfoDef;

static SysConfig_Info_t sysConfig =
    {
        .cmd = SYSCONFIG_CMD_LOAD,
        .soundEnable = CONFIG_SOUND_ENABLE_DEFAULT,
        .longitudeDefault = CONFIG_GPS_LNG_DEFAULT,
        .latitudeDefault = CONFIG_GPS_LAT_DEFAULT,
        .language = CONFIG_SYSTEM_LANGUAGE_DEFAULT,
        .mapDirPath = CONFIG_MAP_DIR_PATH,
        .WGS84 = CONFIG_MAP_USE_WGS84_DEFAULT,
        .arrowTheme = CONFIG_ARROW_THEME_DEFAULT,
    };

static int onEvent(Notification* account, Notification::EventParam_t* param)
{
    if (param->size != sizeof(SysConfig_Info_t))
    {
        return Notification::ERROR_SIZE_MISMATCH;
    }

    SysConfig_Info_t* info = (SysConfig_Info_t*) param->data_p;

    switch (param->event)
    {
        case Notification::EVENT_NOTIFY:
        {
            if (info->cmd == SYSCONFIG_CMD_LOAD)
            {
                //HAL::Buzz_SetEnable(sysConfig.soundEnable);
            }
        }
            break;
        case Notification::EVENT_SUB_PULL:
        {
            memcpy(info, &sysConfig, sizeof(sysConfig));
        }
            break;
        default:
            return Notification::ERROR_UNSUPPORTED_REQUEST;
    }

    return 0;
}


void APP_Config_Init(Notification* account)
{
    account->Subscribe("Storage");
    account->SetEventCallback(onEvent);

    STORAGE_VALUE_REG(account, sysConfig.soundEnable, SystemInfoDef::STORAGE_TYPE_INT);
    STORAGE_VALUE_REG(account, sysConfig.longitudeDefault, SystemInfoDef::STORAGE_TYPE_DOUBLE);
    STORAGE_VALUE_REG(account, sysConfig.latitudeDefault, SystemInfoDef::STORAGE_TYPE_DOUBLE);
    STORAGE_VALUE_REG(account, sysConfig.language, SystemInfoDef::STORAGE_TYPE_STRING);
    STORAGE_VALUE_REG(account, sysConfig.mapDirPath, SystemInfoDef::STORAGE_TYPE_STRING);
    STORAGE_VALUE_REG(account, sysConfig.WGS84, SystemInfoDef::STORAGE_TYPE_INT);
    STORAGE_VALUE_REG(account, sysConfig.arrowTheme, SystemInfoDef::STORAGE_TYPE_STRING);
}