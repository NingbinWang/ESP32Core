#ifndef __TEMPLATE_MODEL_H
#define __TEMPLATE_MODEL_H

#ifdef ARDUINO
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

namespace Page
{

class TemplateModel
{
public:
    uint32_t TickSave;
    uint32_t GetData();
private:

};

}

#endif
