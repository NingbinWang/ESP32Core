#include <Arduino.h>
#include "HAL/HAL.h"
#include "HAL/LCDPort/Display.h"
#include "Framework/Resources/ResourcePool.h"
#include "Framework/Framework.h"
#include "App/App.h"

void setup() {
   HAL::Init();
   Port_Init();
   Resource.Init();//资源需要先初始化
   App_Init();
   Framework_Init();
   Framework_work();
}

void loop() {
   HAL::Update();
   delay(20);
}