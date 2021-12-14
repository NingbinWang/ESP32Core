#include "Framework/PagesManager/PagesManager.h"

class AppFactory : public PageFactory
{
public:
    virtual PageBase* CreatePage(const char* name);
private:

};



