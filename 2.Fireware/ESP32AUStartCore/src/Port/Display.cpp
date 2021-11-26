#include "Display.h"
#include "HAL/HAL.h"

/**
  * @brief  显示初始化
  * @param  无
  * @retval 无
  */
void Port_Init()
{
    static SCREEN_CLASS screen;
    /* 屏幕初始化 */
    screen.begin();
    screen.setRotation(0);
    screen.fillScreen(TFT_BLUE);
    Serial.println("Port_Init\n");
     /* 背光渐亮 */
    //HAL::Backlight_SetGradual(500, 1000);
    
}