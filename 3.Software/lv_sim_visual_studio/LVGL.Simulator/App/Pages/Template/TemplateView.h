#ifndef _TEMPLATE_VIEW_H_
#define _TEMPLATE_VIEW_H_

#include "../Page.h"

namespace Page
{

    class TemplateView
    {
    public:
        void Create(lv_obj_t* root);

    public:
        struct
        {
            lv_obj_t* labelTitle;
            lv_obj_t* labelTick;
        } ui;

    private:

    };

}

#endif 
