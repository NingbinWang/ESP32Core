#include "../include/lcd_common.h"
#include "../hal/st7789v2/st7789.h"
#include "../hal/ssd1306/ssd1306.h"
struct lcd_t protocol_lcd;
struct lcd_function lcd_common_funciton;

int lcd_common_binding(lcd_type_t type)
{
 switch (type)
 {
#ifdef SETUP_ST7789V2
 case LCD_TYPE_ST7789V2:
     lcd_common_funciton.lcd_init=st7789_drvinit;
     lcd_common_funciton.lcd_show_cmd=st7789_drv_show_cmd;
     lcd_common_funciton.lcd_show_data=st7789_drv_show_data;
     lcd_common_funciton.lcd_show_logo=st7789_drvpitcure_logo;
     break;
#endif
#ifdef SETUP_SSD1306
 case LCD_TYPE_SSD1306:
	 protocol_lcd.width = 128;
	 protocol_lcd.height = 64;
	 lcd_common_funciton.lcd_init=ssd1306_drvinit;
     break;
#endif
#ifdef SETUP_ILI9341
 case LCD_TYPE_ILI9341:
     break;
#endif
 default:
     break;
 }
 return 0;
}