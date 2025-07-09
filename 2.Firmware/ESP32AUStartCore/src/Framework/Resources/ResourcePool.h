#ifndef __RESOURCE_POOL
#define __RESOURCE_POOL

#include "Framework/ResourceManager/ResourceManager.h"

#ifdef ARDUINO
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif


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
