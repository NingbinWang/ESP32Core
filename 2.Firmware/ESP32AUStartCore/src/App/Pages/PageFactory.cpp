#include "Factory.h"
#include "StartUp/StartUp.h"
#include "SystemInfos/SystemInfos.h"
#define PAGE_CLASS_MATCH(className) \
do{ \
    if (strcmp(name, #className) == 0) \
    { \
        return new Page::className; \
    } \
}while(0)

PageBase* Factory::CreatePage(const char* name)
{
    PAGE_CLASS_MATCH(Startup);
    PAGE_CLASS_MATCH(SystemInfos);
    return nullptr;
}
