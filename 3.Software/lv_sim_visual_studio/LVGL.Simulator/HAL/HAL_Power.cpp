#include "HAL/HAL.h"



static HAL::Power_CallbackFunction_t Power_EventCallback = NULL;

#define BATT_MAX_VOLTAGE    3900
#define BATT_MIN_VOLTAGE    3300


static void Power_ADC_Init()
{

}

/**
  * @brief  电源初始化
  * @param  无
  * @retval 无
  */
void HAL::Power_Init()
{
  
}

static void Power_ADC_TrigUpdate()
{
    
}

/**
  * @brief  更新操作时间
  * @param  无
  * @retval 无
  */
void HAL::Power_HandleTimeUpdate()
{
    
}

/**
  * @brief  设置自动关机时间
  * @param  sec:时间(秒)
  * @retval 无
  */
void HAL::Power_SetAutoLowPowerTimeout(uint16_t sec)
{
   
}

/**
  * @brief  获取自动关机时间
  * @param  无
  * @retval sec:时间(秒)
  */
uint16_t HAL::Power_GetAutoLowPowerTimeout()
{
    return 10000;
}

/**
  * @brief  设置自动关机功能使能
  * @param  en:使能
  * @retval 无
  */
void HAL::Power_SetAutoLowPowerEnable(bool en)
{
  
}

/**
  * @brief  执行关机
  * @param  无
  * @retval 无
  */
void HAL::Power_Shutdown()
{
  
}

/**
  * @brief  自动关机监控
  * @param  无
  * @retval 无
  */
void HAL::Power_Update()
{
 
}

void HAL::Power_GetInfo(Power_Info_t* info)
{
}
