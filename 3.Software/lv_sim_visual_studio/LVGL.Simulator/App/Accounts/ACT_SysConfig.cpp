#include "Account_Master.h"
#include "HAL/HAL.h"
#include "App/Configs/Config.h"

using namespace AccountSystem;

static SysConfig_Info_t sysConfig =
    {
       SYSCONFIG_CMD_LOAD,//cmd
	   CONFIG_SOUND_ENABLE_DEFAULT,
       CONFIG_SYSTEM_LANGUAGE_DEFAULT,//language
       CONFIG_ARROW_THEME_DEFAULT,//arrowTheme
    };

static int onEvent(Account* account, Account::EventParam_t* param)
{
    if (param->size != sizeof(SysConfig_Info_t))
    {
        return Account::ERROR_SIZE_MISMATCH;
    }

    SysConfig_Info_t* info = (SysConfig_Info_t*) param->data_p;

    switch (param->event)
    {
        case Account::EVENT_NOTIFY:
        {
            if (info->cmd == SYSCONFIG_CMD_LOAD)
            {
                HAL::Buzz_SetEnable(sysConfig.soundEnable);
            }
        }
            break;
        case Account::EVENT_SUB_PULL:
        {
            memcpy(info, &sysConfig, sizeof(sysConfig));
        }
            break;
        default:
            return Account::ERROR_UNSUPPORTED_REQUEST;
    }

    return 0;
}

ACCOUNT_INIT_DEF(SysConfig)
{
  //  account->Subscribe("Storage");
  //  account->SetEventCallback(onEvent);
   // STORAGE_VALUE_REG(account, sysConfig.soundEnable, STORAGE_TYPE_INT);
   // STORAGE_VALUE_REG(account, sysConfig.language, STORAGE_TYPE_STRING);
   // STORAGE_VALUE_REG(account, sysConfig.arrowTheme, STORAGE_TYPE_STRING);
}
