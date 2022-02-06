#include <Arduino.h>
#include "HAL/HAL.h"
#include "HAL/LCDPort/Display.h"
#include "Framework/Framework.h"
#include "App/App.h"

void setup() {
   HAL::Init();
   Port_Init();
   Framework_Init();
   //App_Init();
}

void loop() {
   HAL::Update();
   delay(20);
}