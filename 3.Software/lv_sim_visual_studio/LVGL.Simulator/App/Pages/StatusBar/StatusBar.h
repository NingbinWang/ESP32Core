#ifndef _STATUS_BAR_H_
#define _STATUS_BAR_H_

#include "../Page.h"

namespace StatusBar
{

    typedef enum
    {
        STYLE_TRANSP,
        STYLE_BLACK,
        STYLE_MAX
    } Style_t;

    void Init(lv_obj_t* par);
    void SetStyle(Style_t style);
    void Appear(bool en);

}


#endif
