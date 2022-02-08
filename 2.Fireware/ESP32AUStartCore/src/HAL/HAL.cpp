#include "HAL.h"
#include "Configs/Version.h"
#include "Adafruit_MPU6050.h"

//screen
#define DISP_HOR_RES         CONFIG_SCREEN_HOR_RES
#define DISP_VER_RES         CONFIG_SCREEN_VER_RES
#define DISP_BUF_SIZE        CONFIG_SCREEN_BUFFER_SIZE

extern lv_color_t* lv_disp_buf_p;

void HAL::Init()
{
    //serial init
    Serial.begin(115200);
    Serial.println(VERSION_FIRMWARE_NAME);
    Serial.println("Version: " VERSION_SOFTWARE);
    Serial.println("Author: " VERSION_AUTHOR_NAME);
    //lvgl display buf 需要在很早之前被调用，以避免后续内存不够的问题
     // Move the malloc process to Init() to make sure that the largest heap can be used for this buffer.
    lv_disp_buf_p = static_cast<lv_color_t*>(malloc(DISP_BUF_SIZE * sizeof(lv_color_t)));
    if (lv_disp_buf_p == nullptr)
        LV_LOG_WARN("lv_port_disp_init malloc failed!\n");
    //I2C扫描
    HAL::I2C_Init(true);
    //IMU初始化
    HAL::IMU_Init();
    //蓝牙初始化
     HAL::BT_Init();
    //背光ADC初始化
   // HAL::Backlight_Init();
}
void HAL::Update()
{
   // lv_timer_handler();
  //  Serial.println("lvgl alive");
    HAL::IMU_Update();
    HAL::BT_Update();
    delay(1000);
}
