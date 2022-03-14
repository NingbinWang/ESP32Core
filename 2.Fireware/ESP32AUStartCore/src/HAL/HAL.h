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
    // Bluetooth
    bool BT_Init();
    void BT_Update();
    bool BluetoothConnected();
    //Wlan
    bool Wlan_Init();
    void Wlan_Update();
    // Power
    void Power_Init();
    void Power_HandleTimeUpdate();
    void Power_SetAutoLowPowerTimeout(uint16_t sec);
    uint16_t Power_GetAutoLowPowerTimeout();
    void Power_SetAutoLowPowerEnable(bool en);
    void Power_Shutdown();
    void Power_Update();
    void Power_EventMonitor();
    void Power_GetInfo(Power_Info_t* info);
    typedef void(* Power_CallbackFunction_t)(void);
    void Power_SetEventCallback(Power_CallbackFunction_t callback);
    //SD
    bool SD_Init();
    void SD_Update();
    bool SD_GetReady();
    float SD_GetCardSizeMB();
    typedef void(* SD_CallbackFunction_t)(bool insert);
    void SD_SetEventCallback(SD_CallbackFunction_t callback);
}


#endif