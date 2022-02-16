#include "SystemNotify.h"
#include "Systeminfo_Def.h"
#include "Framework/Pages/StatusBar/StatusBar.h"

static Notification* Sys_StatusBar;

static int onEvent(Notification* account, Notification::EventParam_t* param)
{
    if (param->event != Notification::EVENT_NOTIFY)
    {
        return Notification::ERROR_UNSUPPORTED_REQUEST;
    }

    if (param->size != sizeof(SystemInfoDef::StatusBar_Info_t))
    {
        return Notification::ERROR_SIZE_MISMATCH;
    }

    SystemInfoDef::StatusBar_Info_t* info = (SystemInfoDef::StatusBar_Info_t*)param->data_p;

    if (info->showLabelRec)
    {
        lv_obj_clear_flag(ui.labelRec, LV_OBJ_FLAG_HIDDEN);
        const char* str = info->labelRecStr;

        if (str)
        {
            lv_label_set_text(ui.labelRec, str);
        }
    }
    else
    {
        lv_obj_add_flag(ui.labelRec, LV_OBJ_FLAG_HIDDEN);
    }

    return 0;
}

void SYS_StatusBar_Init(Notification* account){
   account->SetEventCallback(onEvent);
   Sys_StatusBar= account;
}