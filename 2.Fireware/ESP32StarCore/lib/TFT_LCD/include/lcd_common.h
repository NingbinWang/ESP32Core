#ifndef _LCD_COMMON_H_
#define _LCD_COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Enumeration, describing display type
 */
typedef enum
{
    /** Default type of LCD display: ssd1306 oled */
    LCD_TYPE_SSD1306,
    /** Experimental type of LCD display: pcd8544 led */
    LCD_TYPE_ST7789V2,
	LCD_TYPE_ILI9341,
    /** User LCD type */
    LCD_TYPE_CUSTOM,
} lcd_type_t;

typedef enum
{
    LCD_TRANSFER_SPI,
    LCD_TRANSFER_I2C,
	LCD_TRANSFER_FSMC,
} lcd_transfer_t;

typedef enum
{
    PIXELFORMAT_RGB444,
    PIXELFORMAT_RGB565,
    PIXELFORMAT_RGB666,
    PIXELFORMAT_RGB888,
} lcd_pixfmt_t;

struct lcd_t
{
    lcd_type_t type; // Current selected lcd display type
    unsigned int  width;// Current display width
    unsigned int height;// Current display height
    unsigned int bpp;// Current display rgbbit
    lcd_pixfmt_t pixfmt;//Current display pixfmt
    unsigned int  gpio_rst;//Current reset pin
    unsigned int  gpio_a0;//Current cmd/data pin
    unsigned int  gpio_te;//te
    void (* lcd_delay) (unsigned int ms);
    int (* sendCommand) (unsigned char cmd);//sendcommands communication 
    int (* sendOneParameter) (unsigned char data);// sendparameter communication
    int (* sendParameter) (unsigned char *data,unsigned int len);// sendparameter communication
    int (* readOneParameter) (unsigned char *data);// sendparameter communication
    int (* sendFSMCParameter) (unsigned char cmd);//only for stm32
    int (* readFSMCParameter) (unsigned char cmd);//only for stm32
};

/**
 * Holds pointers to functions of currently initialized interface.
 */
extern struct lcd_t protocol_lcd;

struct lcd_function
{
    int te_sync;
    void (* lcd_init)(void);
    void (* lcd_show_cmd)(void);
    void (* lcd_show_data)(unsigned char *data, int size);
    void (* lcd_show_logo)(void);
};

extern struct lcd_function lcd_common_funciton;



//funcion
int lcd_common_binding(lcd_type_t type);



#ifdef __cplusplus
}
#endif


#endif