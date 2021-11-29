#ifndef _RESOURCE_POOL_
#define _RESOURCE_POOL_

#include "App/Utils/PageManager/ResourceManager.h"
#include "lvgl.h"

class ResourcePool
{

public:
    ResourceManager Font_;
    ResourceManager Image_;

public:
    void Init();
    lv_font_t* GetFont(const char* name)
    {
        return (lv_font_t*)Font_.GetResource(name);
    }
    const void* GetImage(const char* name)
    {
        return Image_.GetResource(name);
    }
};

extern ResourcePool Resource;

#endif
