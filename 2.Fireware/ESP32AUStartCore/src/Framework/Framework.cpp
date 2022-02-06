#include "Framework.h"
#include "Framework/PageManager/PageManager.h"
#include "Framework/Resources/ResourcePool.h"
void Framework_Init(void)
{
    //static PageFactory factory;
   // static PageManager manager(&factory);
   // Resource.Init();
    //启动刷屏线程
    INIT_DONE();
}