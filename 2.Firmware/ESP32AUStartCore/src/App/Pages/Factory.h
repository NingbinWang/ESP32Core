#ifndef _FACTORY_H_
#define _FACTORY_H_

#include "Framework/PageManager/PageManager.h"

class Factory : public PageFactory
{
public:
    virtual PageBase* CreatePage(const char* name);
private:

};


#endif