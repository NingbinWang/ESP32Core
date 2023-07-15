#include "Framework/PageManager/PageManager.h"
#include "Pages/StatusBar/StatusBar.h"
#include "App.h"
#include "Pages/Factory.h"
#include "Notify/App/AppNotify.h"
#include "Notify/System/SystemNotify.h"
#include "Framework/Resources/ResourcePool.h"


void App_Init()
{
    static Factory factory;
    static PageManager manager(&factory);
    SystemNotify_Init();
    AppNotify_Init();
    Resource.Init();
      /*----------------------- Pages Init -----------------------*/
    StatusBar::Init(lv_layer_top());
    manager.Install("SystemInfos", "Pages/SystemInfos");
    manager.Install("Startup", "Pages/Startup");
    manager.SetGlobalLoadAnimType(PageManager::LOAD_ANIM_OVER_TOP, 500);
    manager.Push("Pages/Startup");

    INIT_DONE(); 
}


void App_UnInit()
{
   
}

