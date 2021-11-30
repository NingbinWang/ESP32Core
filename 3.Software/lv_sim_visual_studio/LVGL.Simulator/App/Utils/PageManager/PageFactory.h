#ifndef __PAGE_FACTORY_H
#define __PAGE_FACTORY_H

#include "PageBase.h"

class PageFactory
{
public:

    virtual PageBase* CreatePage(const char* name)
    {
        return nullptr;
    };
};


#endif // !__PAGE_FACTORY_H
