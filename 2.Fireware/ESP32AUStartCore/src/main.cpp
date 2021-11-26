#include <Arduino.h>
#include "HAL/HAL.h"
#include "Port/Display.h"
#include "App/App.h"

void setup() {
   HAL::Init();
   Port_Init();
   App_Init();
}

void loop() {
  // put your main code here, to run repeatedly:
}