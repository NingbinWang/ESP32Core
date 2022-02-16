#include "Account_Master.h"
#include "HAL/HAL.h"
#include "Configs/Config.h"

using namespace AccountSystem;

static SysConfig_Info_t sysConfig =
    {
        .cmd = SYSCONFIG_CMD_LOAD,
        .soundEnable = CONFIG_SOUND_ENABLE_DEFAULT,
       // .longitudeDefault = 0,
       // .latitudeDefault = 0,
        //.language = 0,
       // .mapDirPath = 0,
       // .WGS84 = 0,
        //.arrowTheme = 0,
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
               // HAL::Buzz_SetEnable(sysConfig.soundEnable);
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

ACCOUNT_INIT_DEF(SysConfig)
{
    /*
    account->Subscribe("Storage");
    account->SetEventCallback(onEvent);

    STORAGE_VALUE_REG(account, sysConfig.soundEnable, STORAGE_TYPE_INT);
    STORAGE_VALUE_REG(account, sysConfig.longitudeDefault, STORAGE_TYPE_DOUBLE);
    STORAGE_VALUE_REG(account, sysConfig.latitudeDefault, STORAGE_TYPE_DOUBLE);
    STORAGE_VALUE_REG(account, sysConfig.language, STORAGE_TYPE_STRING);
    STORAGE_VALUE_REG(account, sysConfig.mapDirPath, STORAGE_TYPE_STRING);
    STORAGE_VALUE_REG(account, sysConfig.WGS84, STORAGE_TYPE_INT);
    STORAGE_VALUE_REG(account, sysConfig.arrowTheme, STORAGE_TYPE_STRING);
    */
}
