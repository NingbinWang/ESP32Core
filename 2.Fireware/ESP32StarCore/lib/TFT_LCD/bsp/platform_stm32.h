#ifndef _PLATFORM_STM32_H_
#define _PLATFORM_STM32_H_

#include "../include/config.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _STM32_HAL_BUILD_
#include "spi.h"
#include "fsmc.h"
#include "gpio.h"
#include "stm32f1xx_hal.h"
#include <stdbool.h>
#include "cmsis_os.h"
#include "main.h"
//customize
#include "../include/lcd_common.h"


#define SEND_SPI_COMMOND 0
#define SEND_SPI_PARAMETER 1

struct protocol_data {
    char transfer[128];
    char ic[128];
    int spi_bus;
    int spi_mode;
    int spi_bitsperword;
};


struct protocol_info
{
    char* type;
    unsigned int  spi_maxspeedhz;
    unsigned int  width;// Current display width
    unsigned int  height;// Current display height
    unsigned int  bpp;// Current display rgbbit
    unsigned int  pixfmt;//Current display pixfmt
    unsigned int  id;
    unsigned int  gpio_rst;
    unsigned int  gpio_a0;
    unsigned int  gpio_te;
};

int protocol_spi_probe(void);


#endif

#ifdef __cplusplus
}
#endif


#endif
