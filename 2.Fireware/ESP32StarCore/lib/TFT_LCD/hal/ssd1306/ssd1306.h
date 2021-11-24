#ifndef _SSD1306_H_
#define _SSD1306_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "../../include/lcd_common.h"
#include "../../include/config.h"

#ifdef SETUP_SSD1306
void ssd1306_drvinit(void);
#endif

#ifdef __cplusplus
}
#endif


#endif
