#include <Arduino.h>
#include "Arduino_GFX_Library.h"
#include "pin_config.h"
#include "SensorPCF85063.hpp"
#include <Wire.h>

#include "HWCDC.h"
HWCDC USBSerial;

SensorPCF85063 rtc;
uint32_t lastMillis;
char previousTimeString[20] = "";
Arduino_DataBus *bus = new Arduino_ESP32SPI(LCD_DC, LCD_CS, LCD_SCK, LCD_MOSI);

Arduino_GFX *gfx = new Arduino_ST7789(bus, LCD_RST /* RST */,
                                      0 /* rotation */, true /* IPS */, LCD_WIDTH, LCD_HEIGHT, 0, 20, 0, 0);

int16_t getCenteredX(const char *text, uint8_t textSize) {
  int16_t textWidth = strlen(text) * 3 * textSize;  // 6 pixels per character in default size
  return (LCD_WIDTH - textWidth) / 2;
}

void setup() {
  USBSerial.begin(115200);
  if (!rtc.begin(Wire, PCF85063_SLAVE_ADDRESS, IIC_SDA, IIC_SCL)) {
    USBSerial.println("Failed to find PCF8563 - check your wiring!");
    while (1) {
      delay(1000);
    }
  }

  uint16_t year = 2024;
  uint8_t month = 9;
  uint8_t day = 24;
  uint8_t hour = 11;
  uint8_t minute = 24;
  uint8_t second = 30;

  rtc.setDateTime(year, month, day, hour, minute, second);
  gfx->begin();
  gfx->fillScreen(WHITE);
  pinMode(LCD_BL, OUTPUT);
  digitalWrite(LCD_BL, HIGH);
}

void loop() {

  if (millis() - lastMillis > 1000) {
    lastMillis = millis();

    RTC_DateTime datetime = rtc.getDateTime();

    // Format the current time as a string
    char timeString[20];
    sprintf(timeString, "%04d-%02d-%02d %02d:%02d:%02d",
            datetime.year, datetime.month, datetime.day,
            datetime.hour, datetime.minute, datetime.second);

    // Only update the time if it has changed
    if (strcmp(timeString, previousTimeString) != 0) {
      // Clear the previous time area by filling a small rectangle
      gfx->fillRect(0, 150, LCD_WIDTH, 50, WHITE);  // Clear the area for the time
      gfx->setTextColor(BLACK);
      gfx->setTextSize(3,3,0);

      int16_t timeX = getCenteredX(timeString, 3);
      gfx->setCursor(timeX, 150);  // Adjust Y-coordinate as needed
      gfx->println(timeString);  // Display the new time

      // Save the current time as the previous time
      strcpy(previousTimeString, timeString);
    }
  }
}
