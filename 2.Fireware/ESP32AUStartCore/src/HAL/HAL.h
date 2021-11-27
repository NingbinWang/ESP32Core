#ifndef _HAL_H_
#define _HAL_H_
#include <stdint.h>
#include <Arduino.h>
#include "App/Configs/Config.h"
#include "lvgl.h"

namespace HAL
{
    void Init();
    // Backlight 
    void Backlight_Init();
    uint32_t Backlight_GetValue();
    void Backlight_SetValue(int32_t val);
    void Backlight_SetGradual(uint32_t target, uint16_t time = 500);
    void Backlight_ForceLit(bool en);
}


#endif