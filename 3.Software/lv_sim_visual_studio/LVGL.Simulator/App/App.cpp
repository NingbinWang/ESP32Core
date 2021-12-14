#include "App/App.h"
#include "HAL/HAL.h"

#include "Framework/PagesManager/PagesManager.h"
#include "Framework/Pages/AppFactory.h"
//#include "Framework/Utils/lv_monkey/lv_monkey.h"


void App_Init()
{
    static AppFactory factory;
    static PagesManager manager(&factory);
    /*----------------------- Pages Init -----------------------*/
    INIT_DONE();
}

void App_UnInit()
{
}

