#ifndef _LCD_LINUX_FRAMEBUF_H_
#define _LCD_LINUX_FRAMEBUF_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../bsp/platform_linux.h"
#ifdef _LINUX_BUILD_
int hat_panel_fb_drv_init(void);

void hat_fb_start_reflash(void);
void hat_fb_stop_reflash(void);
void hat_fb_farme_hz_set(int farme_hz);

#define FB_IOC_MAGIC       'F'

/* graphics information setting, the graphics are the source patterns(fonts or images)  that blit to target */
#define IOCTL_HAT_FB_START                  _IOWR(FB_IOC_MAGIC, 6, unsigned int)
#define IOCTL_HAT_FB_STOP                   _IOWR(FB_IOC_MAGIC, 7, unsigned int)
#define IOCTL_HAT_FB_FRAME_SET              _IOWR(FB_IOC_MAGIC, 8, unsigned int)

irqreturn_t protocal_te_threadhandler(int irq, void *dev_id);
#endif

#ifdef __cplusplus
}
#endif

#endif
