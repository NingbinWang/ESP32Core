#include "App/App.h"
#include "HAL/HAL.h"

#include "Framework/PageManager/PageManager.h"
#include "Framework/Pages/AppFactory.h"
#include "Accounts/Account_Master.h"


void App_Init()
{
    static AppFactory appfactory;
    static PageManager manager(&appfactory);
    Accounts_Init();
    manager.Install("Cortana", "Pages/Cortana");
}


void App_UnInit()
{
   
}

