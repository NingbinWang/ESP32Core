﻿/*
 * PROJECT:   LVGL PC Simulator using Visual Studio
 * FILE:      LVGL.Simulator.cpp
 * PURPOSE:   Implementation for LVGL ported to Windows Desktop
 *
 * LICENSE:   The MIT License
 *
 * DEVELOPER: Mouri_Naruto (Mouri_Naruto AT Outlook.com)
 */
#include <Windows.h>

#include "resource.h"
#include "App.h"
#include "HAL/HAL.h"

#if _MSC_VER >= 1200
 // Disable compilation warnings.
#pragma warning(push)
// nonstandard extension used : bit field types other than int
#pragma warning(disable:4214)
// 'conversion' conversion from 'type1' to 'type2', possible loss of data
#pragma warning(disable:4244)
#endif

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lv_demos/lv_demo.h"
#include "lv_drivers/win32drv/win32drv.h"

#if _MSC_VER >= 1200
// Restore compilation warnings.
#pragma warning(pop)
#endif

#include <stdio.h>

int main()
{
    lv_init();

    if (!lv_win32_init(
        GetModuleHandleW(NULL),
        SW_SHOW,
        240,
        320,
        LoadIconW(GetModuleHandleW(NULL), MAKEINTRESOURCE(IDI_LVGL))))
    {
        return -1;
    }

    HAL::HAL_Init();
    App_Init();

    while (!lv_win32_quit_signal)
    {
        lv_task_handler();
        Sleep(1);
    }

    return 0;
}
