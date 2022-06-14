#ifndef _CONFIG_H_
#define _CONFIG_H_

//Screen
// Only define one driver, the other ones must be commented out
//#define ILI9341_DRIVER       // Generic driver for common displays
//#define ILI9341_2_DRIVER     // Alternative ILI9341 driver, see https://github.com/Bodmer/TFT_eSPI/issues/1172
//#define ST7735_DRIVER      // Define additional parameters below for this display
//#define ILI9163_DRIVER     // Define additional parameters below for this display
//#define S6D02A1_DRIVER
//#define RPI_ILI9486_DRIVER // 20MHz maximum SPI
//#define HX8357D_DRIVER
//#define ILI9481_DRIVER
//#define ILI9486_DRIVER
//#define ILI9488_DRIVER     // WARNING: Do not connect ILI9488 display SDO to MISO if other devices share the SPI bus (TFT SDO does NOT tristate when CS is high)
#define ST7789_DRIVER      // Full configuration option, define additional parameters below for this display
//#define ST7789_2_DRIVER    // Minimal configuration option, define additional parameters below for this display
//#define R61581_DRIVER
//#define RM68140_DRIVER
//#define ST7796_DRIVER
//#define SSD1351_DRIVER
//#define SSD1963_480_DRIVER
//#define SSD1963_800_DRIVER
//#define SSD1963_800ALT_DRIVER
//#define ILI9225_DRIVER
//#define GC9A01_DRIVER

//Screen ESP32 setup
#define CONFIG_SCREEN_CS_PIN        -1
#define CONFIG_SCREEN_DC_PIN        2
#define CONFIG_SCREEN_RST_PIN       4
#define CONFIG_SCREEN_SCK_PIN       18
#define CONFIG_SCREEN_MOSI_PIN      23
#define CONFIG_SCREEN_BLK_PIN       12
#define CONFIG_SCREEN_MISO_PIN      -1

#define CONFIG_SCREEN_HOR_RES       240
#define CONFIG_SCREEN_VER_RES       240
#define CONFIG_SCREEN_BUFFER_SIZE   (CONFIG_SCREEN_HOR_RES * CONFIG_SCREEN_VER_RES /2)

//StartUp name config
#define STARTUP_LABLE "TIANYA"
#define CONFIG_STARTUP_MUSIC_PLAY       false

//StatusBar
//Screen Statusbar height
#define CONFIG_STATUS_BAR_HEIGHT               15
//Screen Statusbar flag
#define CONFIG_STATUSBAR_SHOW_STATELLITE  false
#define CONFIG_STATUSBAR_SHOW_SDCARD      false
#define CONFIG_STATUSBAR_SHOW_BLUETOOTH      true
#define CONFIG_STATUSBAR_SHOW_TIME       false
#define CONFIG_STATUSBAR_SHOWBATTERY    true


//bluetooth
#define CONFIG_BLUETOOTH_NAME  "TIANYA"

// IMU
//#define CONFIG_IMU_MPU9250
//#define CONFIG_IMU_BP280
#define CONFIG_IMU_MPU6050

#define CONFIG_IMU_INT1_PIN         32
#define CONFIG_IMU_INT2_PIN         33

// I2C
#define CONFIG_MCU_SDA_PIN          32
#define CONFIG_MCU_SCL_PIN          33

// SD CARD 
#define CONFIG_SD_SPI               SPI_SD
#define CONFIG_SD_CD_PIN            -1
#define CONFIG_SD_MOSI_PIN          13
#define CONFIG_SD_MISO_PIN          26
#define CONFIG_SD_SCK_PIN           14
#define CONFIG_SD_CS_PIN            15
#define CONFIG_SD_DET_PIN           22

// Battery 
#define CONFIG_BAT_DET_PIN          37
#define CONFIG_BAT_CHG_DET_PIN      38

// Buzzer
#define CONFIG_BUZZ_PIN             25
#define CONFIG_BUZZ_CHANNEL         2
#define CONFIG_SOUND_ENABLE_DEFAULT false

// Encoder 
#define CONFIG_ENCODER_B_PIN        19
#define CONFIG_ENCODER_A_PIN        21
#define CONFIG_ENCODER_PUSH_PIN     5

// Power
#define CONFIG_POWER_EN_PIN         21


#endif // !_CONFIG_H_
