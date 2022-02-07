#ifndef _HAL_H_
#define _HAL_H_
#include <stdint.h>
#include "Configs/Config.h"
#ifdef ARDUINO
#include <Arduino.h>
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif
#include "HAL_Def.h"

namespace HAL
{
    void Init();
    void Update();
    // Backlight 
    void Backlight_Init();
    uint32_t Backlight_GetValue();
    void Backlight_SetValue(int32_t val);
    void Backlight_SetGradual(uint32_t target, uint16_t time = 500);
    void Backlight_ForceLit(bool en);
    // I2C
    void I2C_Init(bool startScan);
    // IMU
    void IMU_Init();
    void IMU_Update();
}


#endif