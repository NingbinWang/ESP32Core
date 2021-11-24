#ifndef _PLATFORM_LINUX_H_
#define _PLATFORM_LINUX_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "../include/config.h"
#ifdef _LINUX_BUILD_
#include <linux/init.h>
#include <linux/module.h>
#include <linux/gpio.h>
#include <linux/err.h>
#include <linux/errno.h>
#include <linux/string.h>
//mem
#include <linux/mm.h>
#include <linux/slab.h>
//spi
#include <linux/spi/spi.h>
#include <linux/spi/spidev.h>
//fdt
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/of_fdt.h>
#include <linux/of_device.h>
#include <linux/of_platform.h>
//cdev
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
//delay
#include <linux/delay.h>
//platfrom
#include <linux/platform_device.h>
//fb
#include <linux/fb.h>
//semap
#include <linux/semaphore.h>
//fifo
#include <linux/kfifo.h>
//mutex
#include <linux/mutex.h>
#include <linux/rwlock_types.h>
//pwm
#include <linux/pwm.h>
//dma
#include <linux/dma-mapping.h>
//irq
#include <linux/interrupt.h>
#include <linux/irq.h>
//thread
#include <linux/sched.h>
#include <linux/kthread.h>

//timer
#include <linux/time.h> 
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/div64.h>

//fifo
#include <linux/kfifo.h>

#ifdef CONFIG_PM
#include <linux/pm.h>
#endif

//customize
#include "../include/lcd_common.h"
#include "../include/stddef_type.h"
#include "../hal/st7789v2/st7789.h"


extern spinlock_t  gpio_te_lock;

struct protocol_info
{
    char* type;
    unsigned int  spi_maxspeedhz;
    unsigned int  width;// Current display width
    unsigned int  height;// Current display height
    unsigned int  bpp;// Current display rgbbit
    unsigned int  pixfmt;//Current display pixfmt
    unsigned int  gpio_rst;
    unsigned int  gpio_a0;
    unsigned int  gpio_te;
	unsigned int  gpio_bl;
};


struct protocol_data {
	dev_t  dev;
    struct device *device;
    char transfer[128];
    char ic[128];
    int spi_bus;
    int spi_mode;
    int spi_bitsperword;
};

extern struct spi_device *protocol_spi;


#ifdef DEBUG
#define HAT_DBG_FATAL     0
#define HAT_DBG_ERR       1
#define HAT_DBG_WRN       2
#define HAT_DBG_UNIT      3
#define HAT_DBG_FUNC      4
#define HAT_DBG_IND       5
#define HAT_DBG_MSG       6
#define HAT_DBG_VALUE     7
#define HAT_DBG_USER      8

unsigned int debug_level = 8;
#define hat_dbg(level, fmt, args...)                \
do {                                               \
	if (unlikely(HAT_DBG_##level <= debug_level))    \
		pr_warn("%s:" fmt, __func__, ##args);   \
} while (0)
#else
#define hat_dbg(fmt, ...)
#endif




#ifdef __cplusplus
}
#endif

#endif

#endif