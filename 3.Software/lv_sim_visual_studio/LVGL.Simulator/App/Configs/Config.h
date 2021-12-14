#ifndef _CONFIG_H_
#define _CONFIG_H_

#define CONFIG_GPS_LNG_DEFAULT                116.391332
#define CONFIG_GPS_LAT_DEFAULT                39.907415
#define CONFIG_SYSTEM_LANGUAGE_DEFAULT        {'e','n','-','G','B'}
#define CONFIG_MAP_DIR_PATH                   {'/','M','A','P'}//"/MAP"
#define CONFIG_MAP_USE_WGS84_DEFAULT          false
#define CONFIG_ARROW_THEME_DEFAULT            "default"
//Screen
// Generic ESP32 setup
#define CONFIG_SCREEN_CS_PIN        5
#define CONFIG_SCREEN_DC_PIN        2
#define CONFIG_SCREEN_RST_PIN       4
#define CONFIG_SCREEN_SCK_PIN       18
#define CONFIG_SCREEN_MOSI_PIN      23
#define CONFIG_SCREEN_BLK_PIN       12
#define CONFIG_SCREEN_MISO_PIN      19

#define CONFIG_SCREEN_HOR_RES       240
#define CONFIG_SCREEN_VER_RES       320
#define CONFIG_SCREEN_BUFFER_SIZE   (CONFIG_SCREEN_HOR_RES * CONFIG_SCREEN_VER_RES /2)

#define CONFIG_MONKEY_TEST_ENABLE 0
#if CONFIG_MONKEY_TEST_ENABLE
#  define CONFIG_MONKEY_INDEV_TYPE            LV_INDEV_TYPE_ENCODER
#  define CONFIG_MONKEY_TIME_MIN              10
#  define CONFIG_MONKEY_TIME_MAX              100
#  define CONFIG_MONKEY_INPUT_RANGE_MIN       -5
#  define CONFIG_MONKEY_INPUT_RANGE_MAX       5
#endif

/* Buzzer */
#define CONFIG_BUZZ_PIN             25
#define CONFIG_BUZZ_CHANNEL         2
#define CONFIG_SOUND_ENABLE_DEFAULT false


#endif // !_CONFIG_H_
