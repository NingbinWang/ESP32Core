#include "ResourcePool.h"
#include "Utils/PageManager/ResourceManager.h"

static ResourceManager Font;
static ResourceManager Image;

extern "C" {
#define IMPORT_FONT(name) \
do{\
    LV_FONT_DECLARE(font_##name)\
    Font.AddResource(#name, (void*)&font_##name);\
}while(0)

#define IMPORT_IMG(name) \
do{\
    LV_IMG_DECLARE(img_src_##name)\
    Image.AddResource(#name, (void*)&img_src_##name);\
}while (0)

    static void Resource_Init()
    {
        /* Import Fonts */
        IMPORT_FONT(bahnschrift_13);
        IMPORT_FONT(bahnschrift_17);
        IMPORT_FONT(bahnschrift_32);
        IMPORT_FONT(bahnschrift_65);
        IMPORT_FONT(agencyb_36);

        /* Import Images */
        IMPORT_IMG(bicycle);
        IMPORT_IMG(compass);
        IMPORT_IMG(gyroscope);
        IMPORT_IMG(menu);
        IMPORT_IMG(origin_point);
        IMPORT_IMG(pause);
        IMPORT_IMG(satellite);
        IMPORT_IMG(start);
        IMPORT_IMG(stop);
        IMPORT_IMG(storage);
        IMPORT_IMG(system_info);
        IMPORT_IMG(time_info);
        IMPORT_IMG(trip);
    }

} /* extern "C" */

void ResourcePool::Init()
{
    Resource_Init();
    Font.SetDefault((void*)&lv_font_montserrat_14);
}

lv_font_t* ResourcePool::GetFont(const char* name)
{
    return (lv_font_t*)Font.GetResource(name);
}
const void* ResourcePool::GetImage(const char* name)
{
    return Image.GetResource(name);
}
