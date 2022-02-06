#include "Display.h"
#include "HAL/HAL.h"

TaskHandle_t handleTaskLvgl;
void TaskLvglUpdate(void* parameter)
{
    ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

    for (;;)
    {
        lv_task_handler();
        //lv_timer_handler();
        //Serial.println("lvgl alive");
        delay(5);
    }
}
/**
  * @brief  显示初始化
  * @param  无
  * @retval 无
  */
void Port_Init()
{
    static SCREEN_CLASS screen;
    // 屏幕初始化
    screen.begin();
    screen.setRotation(0);// Landscape orientation, flipped
    screen.fillScreen(TFT_BLACK);
    // lvgl初始化
    lv_init();
    lv_port_disp_init(&screen);
    String LVGL_Arduino = "I am LVGL_Arduino ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();
    Serial.println( LVGL_Arduino );
       // Update display in parallel thread.
    xTaskCreate(
        TaskLvglUpdate,
        "LvglThread",
        20000,
        nullptr,
        configMAX_PRIORITIES - 1,
        &handleTaskLvgl);
    // 背光渐亮 
    HAL::Backlight_ForceLit(1);//由于开发板上没有设计相关的电阻来分压，暂时使用常亮的方案 后续开启PWM需要在HAL中开启初始化
    //HAL::Backlight_SetGradual(500, 1000);
}