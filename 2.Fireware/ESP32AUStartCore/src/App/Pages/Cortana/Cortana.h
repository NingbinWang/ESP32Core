#ifndef _CORTANA_H_
#define _CORTANA_H_

#include "CortanaView.h"
#include "CortanaModel.h"

namespace Page
{

class Cortana : public PageBase
{
public:

public:
    Cortana();
    virtual ~Cortana();

    virtual void onCustomAttrConfig();
    virtual void onViewLoad();
    virtual void onViewDidLoad();
    virtual void onViewWillAppear();
    virtual void onViewDidAppear();
    virtual void onViewWillDisappear();
    virtual void onViewDidDisappear();
    virtual void onViewDidUnload();

private:
    void Update();
    void AttachEvent(lv_obj_t* obj);
    static void onTimerUpdate(lv_timer_t* timer);
    static void onEvent(lv_event_t* event);

private:
    CortanaView View;
    CortanaModel Model;
    lv_timer_t* timer;
};

}

#endif
