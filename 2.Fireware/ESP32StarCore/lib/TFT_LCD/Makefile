KERNELRELEASE?=
PWD := $(shell pwd)
TOPDIR := $(PWD)/../../../../
KDIR := $(LINUX_DIR)


MODULE_NAME = hat_panels

ifneq ($(KERNELRELEASE),)
include $(TOPDIR)/.config
intf_core := intf/lcd_common.o
intf_core += intf/lcd_linuxframebuf.o
bsp_core := bsp/platform_linux.o
hal_core := hal/st7789v2/st7789.o
$(MODULE_NAME)-y += $(intf_core)
$(MODULE_NAME)-y += $(bsp_core)
$(MODULE_NAME)-y += $(hal_core) 


obj-m := $(MODULE_NAME).o

KDIR	?= /lib/modules/$(shell uname -r)/build

default:
	@$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	@rm -rf *.o *.ko *.o.cmd *.mod.c *.symvers .*.cmd .tmp_versions modules.order





endif

.PHONY : all