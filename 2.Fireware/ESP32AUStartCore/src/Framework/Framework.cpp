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
    manager.Install("Template", "Pages/Template");
    //启动刷屏线程
    INIT_DONE(); 
}