#ifndef _PAGE_FACTORY_H_
#define _PAGE_FACTORY_H_

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
