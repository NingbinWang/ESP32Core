#include "platform_linux.h"
#ifdef _LINUX_BUILD_
#include "platform .h"
#include "../include/lcd_linuxframebuf.h"
#include "../include/lcd_common.h"
#include "../include/stddef_type.h"

static struct cdev *lcd_cdev;
static struct class *lcd_class;
struct spi_device *protocol_spi = NULL;
struct protocol_info info;


#define SEND_SPI_COMMOND 0
#define SEND_SPI_PARAMETER 1

static int lcddrv_open(struct inode *inode, struct file *filp)
{

  return 0;
}

static int lcddrv_release(struct inode *inode, struct file *filp)
{

	return 0;
}

static long lcddrv_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
   u32	tmp;
   int	ret = 0;
   switch (cmd)
   {
      case IOCTL_HAT_FB_START:
      {
           hat_fb_start_reflash();
           break;
      }
      case IOCTL_HAT_FB_STOP:
      {
           hat_fb_stop_reflash();
           break;
      }
      case IOCTL_HAT_FB_FRAME_SET:
      {
           ret = __get_user(tmp, (u8 __user *)arg);
           if(ret == 0){
               hat_fb_farme_hz_set((int)tmp);
           }
           break;
      }
      
      default:
       break;
   }
	return 0;
}

static ssize_t lcddrv_write(struct file *filp, const char __user *buf, size_t size, loff_t *pos)
{
    printk( "lcddrv_write no support! please no write lcd\n!!!");
   return 0;
}

static const struct file_operations lcddrv_fops = {
	.owner = THIS_MODULE,
	.open = lcddrv_open,
   .write = lcddrv_write,
	.unlocked_ioctl = lcddrv_ioctl,
	.release = lcddrv_release,
};

static int protocal_spi_read(unsigned char *buf, unsigned int len)
{
	int ret = 0;

	if((NULL == protocol_spi) || (NULL == buf))
	{
		printk("%s:%d input param error!", __FUNCTION__,__LINE__);
		return -EINVAL;
	}

	ret = spi_read(protocol_spi, buf, len);
	if(ret)
	{
       printk( "protocal_spi_send fail ret = %d!", ret);
	}
	return ret;
}



static int protocal_spi_send(bool a0, unsigned char *buf, unsigned int len)
{
	int ret = 0;

	if((NULL == protocol_spi) || (NULL == buf))
	{
		printk("%s:%d input param error!", __FUNCTION__,__LINE__);
		return -EINVAL;
	}

	if(SEND_SPI_COMMOND == a0)
	{
		gpio_set_value(info.gpio_a0, 0); // 拉低A0引脚
	}
	else
	{
		gpio_set_value(info.gpio_a0, 1);// 拉高A0引脚
	}

	ret = spi_write(protocol_spi, buf, len);
	if(ret)
	{
       printk( "protocal_spi_send fail ret = %d!", ret);
	}
	return ret;
}
static int protocal_spi_OneParameter_read(unsigned char *data)
{
   return  protocal_spi_read(data,1);
}


static int protocal_spi_Command_send(unsigned char cmd)
{
   return  protocal_spi_send(SEND_SPI_COMMOND,&cmd,1);
}

static int protocal_spi_Parameter_send(unsigned char *buf, unsigned int len)
{
   return  protocal_spi_send(SEND_SPI_PARAMETER,buf,len);
}

static int protocal_spi_OneParameter_send(unsigned char data)
{
   return  protocal_spi_send(SEND_SPI_PARAMETER,&data,1);
}


static int  protocol_data_parse_dt(struct protocol_data *protocol)
{
   struct device_node *fdt_node;
   int rc = 0;
   fdt_node = of_find_node_by_path("/hat_lcd");
   if(!fdt_node){
      printk("can't find node\n");
      return -1;
   }
   if(!of_device_is_compatible(fdt_node,"hat_lcd")){
		printk("can't find node match\n");
		return -1;
	}


   rc = of_property_read_u32(fdt_node,"spi_bus",&(protocol->spi_bus));
   if(rc < 0)
   {
      printk("find spi_bus fail\n");
      return -1;
   }
      rc = of_property_read_u32(fdt_node,"spi_mode",&(protocol->spi_mode));
   if(rc < 0)
   {
      printk("find spi_mode fail\n");
      return -1;
   }
      rc = of_property_read_u32(fdt_node,"spi_bitsperword",&(protocol->spi_bitsperword));
   if(rc < 0)
   {
      printk("find spi_bitsperword fail\n");
      return -1;
   }
   return 0;
}


static int  protocol_info_parse_dt(struct device *dev)
{
   struct device_node *np = dev->of_node;
   int rc = 0;
   info.spi_maxspeedhz = -1;
   info.width = -1;
   info.height = -1;
   info.bpp = -1;
   info.pixfmt = -1;
   info.gpio_rst = -1;
   info.gpio_a0 = -1;
   info.gpio_te = -1;
   rc = of_property_read_u32(np,"spi-max-frequency",&info.spi_maxspeedhz);
   if(rc < 0)
   {
      printk("find spi_maxspeedhz fail\n");
      return -1;
   }
   rc = of_property_read_u32(np, "width",&info.width);
   if(rc < 0){
     printk( "%s lcd get width fail\n", __func__);
	  return rc;
   }
   rc = of_property_read_u32(np, "height",&info.height);
   if(rc < 0){
     printk( "%s lcd get height fail\n", __func__);
	  return rc;
   }
   rc = of_property_read_u32(np, "bpp",&info.bpp);
   if(rc < 0){
     printk( "%s lcd get bpp fail\n", __func__);
	  return rc;
   }
   rc = of_property_read_u32(np, "pixfmt",&info.pixfmt);
   if(rc < 0){
     printk( "%s lcd get pixfmt fail\n", __func__);
	  return rc;
   }
   rc = of_property_read_u32(np, "gpio_rst",&info.gpio_rst);
   if(rc < 0){
     printk( "%s lcd get gpio_rst fail\n", __func__);
	  return rc;
   }
   rc = of_property_read_u32(np, "gpio_a0",&info.gpio_a0);
   if(rc < 0){
     printk( "%s lcd get gpio_a0 fail\n", __func__);
	  return rc;
   }
   rc = of_property_read_u32(np, "gpio_te",&info.gpio_te);
   if(rc < 0){
     printk( "%s lcd get gpio_te fail or no gpio_te\n", __func__);
   }
   
   rc = of_property_read_u32(np, "gpio_bl",&info.gpio_bl);
   if(rc < 0){
     printk( "%s lcd get gpio_te fail or no gpio_bl\n", __func__);
   }
   
   protocol_lcd.pixfmt=info.pixfmt;
   protocol_lcd.width=info.width;
   protocol_lcd.height=info.height;
   protocol_lcd.bpp = info.bpp;
   protocol_lcd.gpio_a0 = info.gpio_a0;
   protocol_lcd.gpio_rst = info.gpio_rst;
   protocol_lcd.gpio_te = info.gpio_te;
   protocol_lcd.type = LCD_TRANSFER_SPI;
   return 0;
}

static irqreturn_t  protocal_te_handler(int irq, void *dev_id)
{
    return IRQ_WAKE_THREAD;
}


static int protocol_hw_init(void)
{
   int ret = 0;
   ret = gpio_request(info.gpio_rst, "protocol_gpio_rst");
	if(ret < 0){
	    pr_err("%s: gpio resquest gpio_rst fail!(ret = %d)\n", __func__, ret);
	    return ret;
	}
   ret = gpio_direction_output(info.gpio_rst, 1);
	if(ret < 0){
	    pr_err("%s: gpio set gpio_rst fail!(ret = %d)\n", __func__, ret);
		 goto gpio_rst_fail;
	}	
   ret = gpio_request(info.gpio_a0, "protocol_gpio_a0");
	if(ret < 0){
	    pr_err("%s: gpio resquest  gpio_a0 fail!(ret = %d)\n", __func__, ret);
	    goto gpio_rst_fail;
	}
    pr_err("%s:gpio_a0:%d\n",__func__,info.gpio_a0);
   ret = gpio_direction_output(info.gpio_a0, 1);
	if(ret < 0){
	    pr_err( "%s: gpio set gpio_a0 fail!(ret = %d)\n", __func__, ret);
       goto gpio_a0_fail;
	}
	
	ret = gpio_request(info.gpio_bl, "protocol_gpio_bl");
	if(ret < 0){
	    pr_err("%s: gpio resquest  gpio_bl fail!(ret = %d)\n", __func__, ret);
	    goto gpio_a0_fail;
	}
    pr_err("%s:gpio_bl:%d\n",__func__,info.gpio_bl);
   ret = gpio_direction_output(info.gpio_bl, 0);
	if(ret < 0){
	    pr_err( "%s: gpio set gpio_a0 fail!(ret = %d)\n", __func__, ret);
       goto gpio_bl_fail;
	}
   pr_err("%s:gpio_te:%d\n",__func__,info.gpio_te);

  ret = request_threaded_irq(gpio_to_irq(info.gpio_te),protocal_te_handler,protocal_te_threadhandler,IRQF_TRIGGER_RISING,"hat_panels_irq",(void*)0);
  if(ret < 0){
	    pr_err( "%s: gpio set gpio_a0 fail!(ret = %d)\n", __func__, ret);
       goto gpio_a0_fail;
	}

   return 0;
gpio_bl_fail:
   gpio_free(info.gpio_bl);
gpio_a0_fail:
   gpio_free(info.gpio_a0);
gpio_rst_fail:
   gpio_free(info.gpio_rst);
   return ret;
}

static int protocol_spi_init(struct protocol_data *protocol)
{
  	struct spi_master *master = NULL;
	char spi_name[128] = {0};
   int ret = 0;
	struct device *device;
	struct bus_type *hat_spi_bus_type;
   // find spi master device 
   hat_spi_bus_type = &spi_bus_type;
   master = spi_busnum_to_master(protocol->spi_bus);
   if(!master){
      printk("spi_busnum_to_master() error!");
      return -EINVAL;
   }
   snprintf(spi_name, sizeof(spi_name), "%s.%u", dev_name(&master->dev),0);
   device = bus_find_device_by_name(hat_spi_bus_type, NULL, spi_name);
	if (device == NULL) {
	   dev_err(NULL, "chipselect %d has not been used\n", protocol->spi_bus);
		ret = -EINVAL;
		goto no_find_spi_master;
	}
   protocol_spi = to_spi_device(device);
   if(protocol_spi == NULL){
      dev_err(device, "to_spi_device() error!\n");
		ret = -EINVAL;
		goto get_spi_device_fail;
   }
   ret =  protocol_info_parse_dt(&protocol_spi->dev);
   if(ret < 0){
      dev_err(device, "protocol_info_parse_dt() error!\n");
		ret = -EINVAL;
		goto get_spi_device_fail;
   }
   ret = protocol_hw_init();
   if(ret < 0){
      dev_err(device, "protocol_info_parse_dt() error!\n");
		ret = -EINVAL;
		goto get_spi_device_fail;
   }
   // spi初始化
	protocol_spi->max_speed_hz = info.spi_maxspeedhz; //
	protocol_spi->bits_per_word = protocol->spi_bitsperword;
	protocol_spi->mode |= SPI_MODE_3 & (~SPI_LSB_FIRST); // 模式3、MSB
	ret = spi_setup(protocol_spi);
	if(ret < 0)
	{
		dev_err(device,"%s spi interface init fail!\n", __func__);
		return ret;
	}
   //bindind work function
     protocol_lcd.sendCommand = protocal_spi_Command_send;
     protocol_lcd.sendParameter = protocal_spi_Parameter_send;
     protocol_lcd.sendOneParameter = protocal_spi_OneParameter_send;
     protocol_lcd.lcd_delay = msleep;
     protocol_lcd.readOneParameter = protocal_spi_OneParameter_read;
   return 0;
get_spi_device_fail:
   put_device(device);
no_find_spi_master:
   return ret;
}

static int protocol_spi_probe(void)
{
   struct protocol_data *protocol;
	int ret = 0;
   int count = 1;
   // Allocate driver data
	protocol = kzalloc(sizeof(*protocol), GFP_KERNEL);
	if (!protocol)
		return -ENOMEM;
   // allocalte chrdev
   ret = alloc_chrdev_region(&protocol->dev,0,count,"hat_panels");
	if(ret){
		printk("fail to allocate char device region\n");
		goto alloc_chrdev_fail;
	}
	lcd_cdev = cdev_alloc();
	if(!lcd_cdev){
		printk("fpga cdev_alloc fail!\n");
        goto cdev_alloc_fail;
	}
   cdev_init(lcd_cdev,&lcddrv_fops);
   lcd_cdev->owner = THIS_MODULE;
	ret = cdev_add(lcd_cdev,protocol->dev,count);
	if(ret){
		printk("cdev add fail\n");
		goto cdev_fail;
	}
   lcd_class = class_create(THIS_MODULE,"hat_panels");
   if(IS_ERR(lcd_class)){
		printk("class create fail\n");
		goto cdev_fail;
	}
   ret = protocol_data_parse_dt(protocol);
   if(ret < 0){
      printk("protocol_data_parse_dt fail\n");
		goto cdev_fail;
   }
   ret = protocol_spi_init(protocol);
   if(ret < 0){
      printk("protocol_spi_init fail\n");
		goto cdev_fail;
   }
   protocol->device = device_create(lcd_class,&protocol_spi->dev,protocol->dev,protocol,"hat_panels");
   if(IS_ERR(protocol->device)) {
      put_device(protocol->device);
      goto cdev_fail;
   }
   
   //porting devices
   gpio_set_value(info.gpio_rst, 0);
   msleep(200);
   gpio_set_value(info.gpio_rst, 1);
   lcd_common_binding(LCD_TYPE_ST7789V2);
   lcd_common_funciton.lcd_init();
   lcd_common_funciton.lcd_show_logo();
   gpio_set_value(info.gpio_bl, 1);
   hat_panel_fb_drv_init();
   return 0;
cdev_fail:
	cdev_del(lcd_cdev);
cdev_alloc_fail:
     unregister_chrdev_region(protocol->dev,count);
alloc_chrdev_fail:
    kfree(protocol);
	 return ret;
}

#if 1
static int __init cdev_protocol_entry(void)
{
   int ret = 0;
   ret = protocol_spi_probe();
   return ret;
}

static void __exit protocal_exit(void)
{
  class_destroy(lcd_class);
  cdev_del(lcd_cdev);
//unregister_chrdev_region(protocol->dev,count);
}
module_init(cdev_protocol_entry);
module_exit(protocal_exit);

MODULE_AUTHOR("Alex King <188101696@qq.com>");
MODULE_DESCRIPTION(" hat-lcd driver");
MODULE_LICENSE("Dual BSD/GPL");
MODULE_ALIAS("platform:hat-lcd");
MODULE_VERSION("V1.00.003");
#endif
#endif
