#include "Framework.h"
#include "Framework/PageManager/PageManager.h"
#include "Framework/Resources/ResourcePool.h"
#include "Framework/Pages/StatusBar/StatusBar.h"
void Framework_Init(void)
{
    static PageFactory factory;
    static PageManager manager(&factory);
    Resource.Init();
    StatusBar::Init(lv_layer_top());
    manager.Install("Startup", "Pages/Startup");
    manager.SetGlobalLoadAnimType(PageManager::LOAD_ANIM_OVER_TOP, 500);
    manager.Push("Pages/Startup");
    //启动刷屏线程
    INIT_DONE(); 
}

void Framework_work(void)
{
     //启动刷屏线程
    INIT_DONE(); 
}