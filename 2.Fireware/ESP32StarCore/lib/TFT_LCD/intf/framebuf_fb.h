#ifndef _FRAMEBUF_FB_H_
#define _FRAMEBUF_FB_H_
#ifdef __cplusplus
extern "C" {
#endif
#include "../include/config.h"
#ifdef _LINUX_BUILD_
#include <linux/fb.h>

#define HAT_FB_BLANK                            (0x1)
#define HAT_FB_CREATE_BUFFER_BY_FB              0
#define GET_BUFF_MALLOC                         0
#define CUSTOMIZE_MALLOC                        1
#define DEFERRED_IO_WORK                        0  //fbtft deferred io
#define KERNEL_THREAD_WORK                      1  //kernel reflash lcd

#define MAX_FRAME_BUF 5

//#define HAT_FB_MAKE_FB_ID(IDE, LAYER_ID)        (((IDE & 0xF) << 2) | (LAYER_ID & 0x3))

struct timeval t_transfer_start;
struct timeval t_transfer_end;
long long t_transfer_time = 0;



struct hatpanelsfb_info {
    struct device *dev;
    struct fb_info *fb;
};

struct fb_page {
	unsigned int x;
	unsigned int y;
	unsigned char *buffer;//unsigned short
	unsigned int len;
};

/* framebuffer private data */
struct hat_fb_par {
	struct spi_device *spi;
	struct fb_info *info;
	unsigned int frame_size;
	unsigned int frame_hz;
	unsigned int pages_count;
	struct fb_page *pages;
	unsigned char *last_buffer_start;//unsigned short
	struct task_struct *reflash_task;
	struct kfifo fifo;
	struct pwm_device *pwm;
	unsigned int pwm_period;
};

typedef struct framebuf_fb_data_list
{
	unsigned int index;
	char * buf;
	struct list_head head;
}frame_list;


#ifdef __cplusplus
}
#endif
#endif

#endif