#include "App/App.h"
#include "HAL/HAL.h"

#include "Framework/PageManager/PageManager.h"
#include "Framework/Pages/AppFactory.h"
#include "Accounts/Account_Master.h"



void App_Notify_Init(void)
{

}

void App_Init()
{
    static AppFactory appfactory;
    static PageManager manager(&appfactory);
    manager.Install("Cortana", "Pages/Cortana");
}


void App_UnInit()
{
    //ACCOUNT_SEND_NOTIFY_CMD(SysConfig, SYSCONFIG_CMD_SAVE);
}

