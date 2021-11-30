#ifndef _RESOURCE_POOL_
#define _RESOURCE_POOL_

#include "App/Utils/PageManager/ResourceManager.h"
#include "lvgl/lvgl.h"

class ResourcePool
{

public:
    ResourceManager Font;
    ResourceManager Image;

public:
    void Init();
    lv_font_t* GetFont(const char* name)
    {
        return (lv_font_t*)Font.GetResource(name);
    }
    const void* GetImage(const char* name)
    {
        return Image.GetResource(name);
    }
};

extern ResourcePool Resource;

#endif
