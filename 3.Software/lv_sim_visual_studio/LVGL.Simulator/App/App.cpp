#include "App/App.h"
#include "HAL/HAL.h"

#include "Framework/PageManager/PageManager.h"
#include "Framework/Pages/AppFactory.h"
#include "Accounts/Account_Master.h"
#include "Framework/Resources/ResourcePool.h"
#include "Framework/Pages/StatusBar/StatusBar.h"


void App_Init()
{
    static AppFactory factory;
    static PageManager manager(&factory);
    Accounts_Init();
    Resource.Init();
    /*----------------------- Pages Init -----------------------*/
    StatusBar::Init(lv_layer_top());
    manager.Install("Template", "Framework/Pages/Template");
    manager.Install("SystemInfos", "Framework/Pages/SystemInfos");
    manager.Install("Startup", "Framework/Pages/Startup");
    manager.SetGlobalLoadAnimType(PageManager::LOAD_ANIM_OVER_TOP, 500);
    manager.Push("Pages/Startup");
    ACCOUNT_SEND_NOTIFY_CMD(SysConfig, SYSCONFIG_CMD_LOAD);

    INIT_DONE();
}

void App_UnInit()
{
    ACCOUNT_SEND_NOTIFY_CMD(SysConfig, SYSCONFIG_CMD_SAVE);
}

