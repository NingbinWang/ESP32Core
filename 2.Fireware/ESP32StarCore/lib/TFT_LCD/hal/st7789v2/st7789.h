#ifndef _ST7789_H_
#define _ST7789_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "../../include/lcd_common.h"
#include "../../include/config.h"

#ifdef SETUP_ST7789V2
void st7789_drvinit(void);
void st7789_drv_send_data(unsigned char *data, int size);
void st7789_drv_show_cmd(void);
void st7789_drv_show_data(unsigned char *data, int size);
void st7789_drv_memory_data_access(unsigned int xStart,unsigned int yStart,unsigned int xEnd,unsigned int yEnd);
void st7789_drvpitcure_logo(void);
#endif

#ifdef __cplusplus
}
#endif

#endif