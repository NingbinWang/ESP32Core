#include "PageFactory.h"
#include "Framework/PageManager/PageManager.h"
#include "Framework/Pages/StartUp/StartUp.h"
#include "Framework/Pages/SystemInfos/SystemInfos.h"
#define PAGE_CLASS_MATCH(className) \
do{ \
    if (strcmp(name, #className) == 0) \
    { \
        return new Page::className; \
    } \
}while(0)

PageBase* PageFactory::CreatePage(const char* name)
{
    PAGE_CLASS_MATCH(Startup);
    PAGE_CLASS_MATCH(SystemInfos);
    return nullptr;
}
