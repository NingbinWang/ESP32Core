#include "AppFactory.h"
#include "Template/Template.h"
#include "SystemInfos/SystemInfos.h"
#include "StartUp/StartUp.h"

#define APP_CLASS_MATCH(className)\
do{\
    if (strcmp(name, #className) == 0)\
    {\
        return new Page::className;\
    }\
}while(0)

PageBase* AppFactory::CreatePage(const char* name)
{
    APP_CLASS_MATCH(Template);
    APP_CLASS_MATCH(SystemInfos);
    APP_CLASS_MATCH(Startup);

    return nullptr;
}
