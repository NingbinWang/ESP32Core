
#include "StatusBar.h"
#include "HAL/HAL.h"
#include "Framework/Resources/ResourcePool.h"
#include "Configs/Config.h"
#include "Framework/Utils/lv_ext/lv_obj_ext_func.h"
#include "Framework/Notification/Notification.h"
#include "App/Notify/System/Systeminfo_Def.h"
#include "App/Notify/NotifyCenter.h"

#define BATT_USAGE_HEIGHT (lv_obj_get_style_height(ui.battery.img, 0) - 6)
#define BATT_USAGE_WIDTH  (lv_obj_get_style_width(ui.battery.img, 0) - 4)

#define STATUS_BAR_HEIGHT 22

static Notification* actStatusBar;

static void StatusBar_AnimCreate(lv_obj_t* contBatt);

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

static void StatusBar_ConBattSetOpa(lv_obj_t* obj, int32_t opa)
{
    lv_obj_set_style_opa(obj, opa, 0);
}

static void StatusBar_onAnimOpaFinish(lv_anim_t* a)
{
    lv_obj_t* obj = (lv_obj_t*)a->var;
    StatusBar_ConBattSetOpa(obj, LV_OPA_COVER);
    StatusBar_AnimCreate(obj);
}

static void StatusBar_onAnimHeightFinish(lv_anim_t* a)
{
    lv_anim_t a_opa;
    lv_anim_init(&a_opa);
    lv_anim_set_var(&a_opa, a->var);
    lv_anim_set_exec_cb(&a_opa, (lv_anim_exec_xcb_t)StatusBar_ConBattSetOpa);
    lv_anim_set_ready_cb(&a_opa, StatusBar_onAnimOpaFinish);
    lv_anim_set_values(&a_opa, LV_OPA_COVER, LV_OPA_TRANSP);
    lv_anim_set_early_apply(&a_opa, true);
    lv_anim_set_delay(&a_opa, 500);
    lv_anim_set_time(&a_opa, 500);
    lv_anim_start(&a_opa);
}

static void StatusBar_AnimCreate(lv_obj_t* contBatt)
{
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, contBatt);
    lv_anim_set_exec_cb(&a, [](void* var, int32_t v) {
        lv_obj_set_height((lv_obj_t*)var, v);
    });
    lv_anim_set_values(&a, 0, BATT_USAGE_HEIGHT);
    lv_anim_set_time(&a, 1000);
    lv_anim_set_ready_cb(&a, StatusBar_onAnimHeightFinish);
    lv_anim_start(&a);
}

static void StatusBar_Update(lv_timer_t* timer)
{
    SystemInfoDef::Storage_Basic_Info_t sdInfo;
    actStatusBar->Pull("Storage", &sdInfo, sizeof(sdInfo));
    sdInfo.isDetect ? lv_obj_clear_flag(ui.imgSD, LV_OBJ_FLAG_HIDDEN) : lv_obj_add_flag(ui.imgSD, LV_OBJ_FLAG_HIDDEN);

   // HAL::BluetoothConnected() ? lv_obj_clear_flag(ui.imgBT, LV_OBJ_FLAG_HIDDEN) : lv_obj_add_flag(ui.imgBT, LV_OBJ_FLAG_HIDDEN);

    // battery 
    HAL::Power_Info_t power;
    actStatusBar->Pull("Power", &power, sizeof(power));
    lv_label_set_text_fmt(ui.battery.label, "%d", power.usage);

    bool Is_BattCharging = power.isCharging;
    lv_obj_t* contBatt = ui.battery.objUsage;
    static bool Is_BattChargingAnimActive = false;
    if(Is_BattCharging)
    {
        if(!Is_BattChargingAnimActive)
        {
            StatusBar_AnimCreate(contBatt);
            Is_BattChargingAnimActive = true;
        }
    }
    else
    {
        if(Is_BattChargingAnimActive)
        {
            lv_anim_del(contBatt, nullptr);
            StatusBar_ConBattSetOpa(contBatt, LV_OPA_COVER);
            Is_BattChargingAnimActive = false;
        }
        lv_coord_t height = lv_map(power.usage, 0, 100, 0, BATT_USAGE_HEIGHT);
        lv_obj_set_height(contBatt, height);
    }
    
}

static lv_obj_t* StatusBar_Create(lv_obj_t* par)
{
    lv_obj_t* cont = lv_obj_create(par);
    lv_obj_remove_style_all(cont);

    lv_obj_set_size(cont, LV_HOR_RES, CONFIG_STATUS_BAR_HEIGHT);//拉伸至最大
    lv_obj_set_y(cont, CONFIG_STATUS_BAR_HEIGHT);//设置状态栏的位置

    /* style1 */
    lv_obj_set_style_bg_opa(cont, LV_OPA_TRANSP, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(cont, lv_color_hex(0x333333), LV_STATE_DEFAULT);

    /* style2 */
    lv_obj_set_style_bg_opa(cont, LV_OPA_60, LV_STATE_USER_1);
    lv_obj_set_style_bg_color(cont, lv_color_black(), LV_STATE_USER_1);
    lv_obj_set_style_shadow_color(cont, lv_color_black(), LV_STATE_USER_1);
    lv_obj_set_style_shadow_width(cont, 10, LV_STATE_USER_1);

    static lv_style_transition_dsc_t tran;
    static const lv_style_prop_t prop[] =
    {
        LV_STYLE_BG_COLOR,
        LV_STYLE_OPA,
        LV_STYLE_PROP_INV
    };
    lv_style_transition_dsc_init(
        &tran,
        prop,
        lv_anim_path_ease_out,
        200,
        0,
        nullptr
    );
    lv_obj_set_style_transition(cont, &tran, LV_STATE_USER_1);

    ui.cont = cont;

    static lv_style_t style;
    lv_style_init(&style);
    lv_style_set_text_color(&style, lv_color_white());
    lv_style_set_text_font(&style, Resource.GetFont("bahnschrift_13"));
    lv_obj_t* img;
    lv_obj_t* label;
//  satellite
    if(CONFIG_STATUSBAR_SHOW_STATELLITE)
    {
      img = lv_img_create(cont);
      lv_img_set_src(img, Resource.GetImage("satellite"));
      lv_obj_align(img, LV_ALIGN_LEFT_MID, 14, 0);
      ui.satellite.img = img;

       lv_obj_t* label = lv_label_create(cont);
       lv_obj_add_style(label, &style, 0);
       lv_obj_align_to(label, ui.satellite.img, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
       lv_label_set_text(label, "0");
       ui.satellite.label = label;
    }

// sd card 
    if(CONFIG_STATUSBAR_SHOW_SDCARD)
    {
      img = lv_img_create(cont);
      lv_img_set_src(img, Resource.GetImage("sd_card"));
      lv_obj_align(img, LV_ALIGN_LEFT_MID, 14, -1);
      lv_obj_add_flag(img, LV_OBJ_FLAG_HIDDEN);//默认隐藏
      ui.imgSD = img;
    }

// bluetooth 
    if(CONFIG_STATUSBAR_SHOW_BLUETOOTH)
    {
      img = lv_img_create(cont);
      lv_img_set_src(img, Resource.GetImage("bluetooth"));
      lv_obj_align(img, LV_ALIGN_LEFT_MID, 32, 0);
      lv_obj_add_flag(img, LV_OBJ_FLAG_HIDDEN);
      ui.imgBT = img;
    }

// clock
   if(CONFIG_STATUSBAR_SHOW_TIME)
   {
     label = lv_label_create(cont);
     lv_obj_add_style(label, &style, 0);
     lv_label_set_text(label, "00:00");
     lv_obj_center(label);
     ui.labelClock = label;
   }

// recorder 
    label = lv_label_create(cont);
    lv_obj_add_style(label, &style, 0);
    lv_obj_align(label, LV_ALIGN_RIGHT_MID, -50, 0);
    lv_label_set_text(label, "");
    lv_obj_add_flag(label, LV_OBJ_FLAG_HIDDEN);
    ui.labelRec = label;

// battery
   if(CONFIG_STATUSBAR_SHOWBATTERY)
   {
    img = lv_img_create(cont);
    lv_img_set_src(img, Resource.GetImage("battery"));
    lv_obj_align(img, LV_ALIGN_RIGHT_MID, -30, 0);
    lv_img_t* img_ext = (lv_img_t*)img;
    lv_obj_set_size(img, img_ext->w, img_ext->h);
    ui.battery.img = img;

    lv_obj_t* obj = lv_obj_create(img);
    lv_obj_remove_style_all(obj);
    lv_obj_set_style_bg_color(obj, lv_color_white(), 0);
    lv_obj_set_style_bg_opa(obj, LV_OPA_COVER, 0);
    lv_obj_set_style_opa(obj, LV_OPA_COVER, 0);
    lv_obj_set_size(obj, BATT_USAGE_WIDTH, BATT_USAGE_HEIGHT);
    lv_obj_align(obj, LV_ALIGN_BOTTOM_MID, 0, -2);
    ui.battery.objUsage = obj;

    label = lv_label_create(cont);
    lv_obj_add_style(label, &style, 0);
    lv_obj_align_to(label, ui.battery.img, LV_ALIGN_OUT_RIGHT_MID, 5, 0);
    lv_label_set_text(label, "100%");
    ui.battery.label = label;
   }

    StatusBar::SetStyle(StatusBar::STYLE_TRANSP);

    lv_timer_t* timer = lv_timer_create(StatusBar_Update, 1000, nullptr);
    lv_timer_ready(timer);

    return ui.cont;
}

void StatusBar::SetStyle(Style_t style)
{
    lv_obj_t* cont = ui.cont;
    if (style == STYLE_TRANSP)
    {
        lv_obj_add_state(cont, LV_STATE_DEFAULT);
        lv_obj_clear_state(cont, LV_STATE_USER_1);
    }
    else if (style == STYLE_BLACK)
    {
        lv_obj_add_state(cont, LV_STATE_USER_1);
    }
    else
    {
        return;
    }
}

void StatusBar::Init(lv_obj_t* par)
{
    StatusBar_Create(par);
}

void StatusBar::Appear(bool en)
{
    int32_t start = -CONFIG_STATUS_BAR_HEIGHT;
    int32_t end = 0;

    if (!en)
    {
        int32_t temp = start;
        start = end;
        end = temp;
    }

    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, ui.cont);
    lv_anim_set_values(&a, start, end);
    lv_anim_set_time(&a, 500);
    lv_anim_set_delay(&a, 1000);
    lv_anim_set_exec_cb(&a, LV_ANIM_EXEC(y));
    lv_anim_set_path_cb(&a, lv_anim_path_ease_out);
    lv_anim_set_early_apply(&a, true);
    lv_anim_start(&a);
}

void SYS_StatusBar_Init(Notification* account)
{
    account->Subscribe("Power");
    account->Subscribe("Storage");
    account->SetEventCallback(onEvent);

    actStatusBar = account;
}