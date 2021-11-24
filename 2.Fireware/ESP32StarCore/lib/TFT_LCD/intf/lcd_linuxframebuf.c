#include "../include/config.h"
#ifdef _LINUX_BUILD_
#include "../include/lcd_linuxframebuf.h"
#include "framebuf_fb.h"

#if DEFERRED_IO_WORK
#define REFRESHRATE 8
static unsigned int  refreshrate = REFRESHRATE;
//module_param(refreshrate, uint , 0);
#endif

static struct platform_device *hat_fb_device;
struct hatpanelsfb_info *frameinfo;
static const char driver_name[] = "hatpanles_lcd";
static unsigned int init;
static DEFINE_MUTEX(device_fb_lock);

frame_list *listhead;
unsigned int list_count = 0;
char* frame_pbuf[MAX_FRAME_BUF];

#if DEFERRED_IO_WORK
static void hat_panles_update_display(struct hat_fb_par *item,unsigned int index)
{
    unsigned int x;
    unsigned int y;
	unsigned char *buffer;
	unsigned int len;
	//  unsigned int count;
	//unsigned int diff;
    //mutex_lock(&item->direct_mutex);	 
	x = item->pages[index].x;
	y = item->pages[index].y;		 
	buffer = item->pages[index].buffer;
	len = item->pages[index].len;
				 
	// check if we should change the chip framebuffer pointer
	if (item->last_buffer_start!=buffer)
	{
		st7789_drv_memory_data_access(x,y,protocol_lcd.width-1,protocol_lcd.height-1);
	}
	st7789_drv_send_data(buffer,len);
	item->last_buffer_start=&buffer[len];
	// mutex_unlock(&item->direct_mutex);
}

static void hat_panels_deferred_io(struct fb_info *fbinfo,struct list_head *pagelist)
{
	struct hat_fb_par *par = fbinfo->par;
	struct page *page;
	list_for_each_entry(page, pagelist, lru) {
		printk("[%s]:the pages x is %d, y is %d \n",__func__, par->pages[page->index].x, par->pages[page->index].y);
		hat_panles_update_display(fbinfo->par,page->index);
	}
}
#endif
#if KERNEL_THREAD_WORK
static void hat_fb_update_display(struct fb_info  *fbinfo)
{
	struct hat_fb_par *fb_par = (struct hat_fb_par *) fbinfo->par;
    u16* p = (u16 *)(fbinfo->screen_base);
    frame_list *listnode;
	struct list_head *head =  &listhead->head;	
	mutex_lock(&device_fb_lock);
	if(list_count < MAX_FRAME_BUF){
		  listnode = (frame_list *)kmalloc(sizeof(frame_list), GFP_KERNEL);
	      //listnode->buf = (char *)kmalloc(fb_par->frame_size, GFP_KERNEL);
		  listnode->buf = frame_pbuf[list_count];
	      listnode->index = list_count;
	      memmove(listnode->buf,p,fb_par->frame_size);
          list_add_tail(&listnode->head, head);
		  list_count++;
	}else{
		 printk("list count = %d,over buffer\n",list_count);
	}
	mutex_unlock(&device_fb_lock);
}

static int hat_fb_reflash_thread_func(void *data)
{
	struct fb_info *fbinfo = (struct fb_info *)data;
	struct hat_fb_par *fb_par = (struct hat_fb_par *) fbinfo->par;
	while(1){
		if(kthread_should_stop()) {
			break;
		}
        hat_fb_update_display(fbinfo);
		msleep_interruptible(fb_par->frame_hz);
	}
	return 0;
}

irqreturn_t protocal_te_threadhandler(int irq, void *dev_id)
{
      frame_list *pos;
	  struct list_head *head =  &listhead->head;
	  mutex_lock(&device_fb_lock);
	  if(list_count > 0){
	     pos = list_first_entry(head,frame_list,head);
		 if(pos->buf != NULL){
	        lcd_common_funciton.lcd_show_cmd();
            lcd_common_funciton.lcd_show_data(pos->buf,protocol_lcd.width* protocol_lcd.height*2);
	       // kfree(pos->buf);
		 }else{
			 printk("pos->buf is null but have sameone to use\n");
		 }
	     list_del(&pos->head);
		 kfree(pos);
	     list_count--;
	  }
	  //else{
	  //	  printk("no data!\n");
	  //}
	  mutex_unlock(&device_fb_lock);
	  return IRQ_HANDLED;
}

#endif


int hat_fb_video_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
	return 0;
}

int hat_fb_video_set_par(struct fb_info *info)
{
	return 0;
}

static int hat_fb_blank(int blank_mode, struct fb_info *info)
{

	return 0;
}

static ssize_t hat_fb_write(struct fb_info *info, const char __user *buf,size_t count, loff_t *ppos)
{
	unsigned long total_size;
	unsigned long p = *ppos;
	u8 __iomem *dst;

	total_size = info->fix.smem_len;

	if (p > total_size)
		return -EINVAL;

	if (count + p > total_size)
		count = total_size - p;

	if (!count)
		return -EINVAL;

	dst = (void __force *) (info->screen_base + p);

	if (copy_from_user(dst, buf, count))
		return -EFAULT;
    lcd_common_funciton.lcd_show_cmd();
	lcd_common_funciton.lcd_show_data(buf,count);

	*ppos += count;

	return count;
}

/*
static void hat_fd_fillrect(struct fb_info *info, const struct fb_fillrect *rect)
{
	sys_fillrect(info, rect);	
}

static void hat_fd_copyarea(struct fb_info *info, const struct fb_copyarea *area)
{
	sys_copyarea(info, area);
}

static void hat_fd_imageblit(struct fb_info *info, const struct fb_image *image)
{
	sys_imageblit(info, image);
}
*/
/*
 *  Frame buffer operations
 */
struct fb_ops hat_fb_video_ops = {
	.owner		= THIS_MODULE,
	.fb_write	= hat_fb_write,
	.fb_blank	= hat_fb_blank,
	.fb_check_var	= hat_fb_video_check_var,
	.fb_set_par	= hat_fb_video_set_par,
	//.fb_fillrect	= hat_fd_fillrect,
	//.fb_copyarea	= hat_fd_copyarea,
	//.fb_imageblit	= hat_fd_imageblit,
	
};



static int hat_fb_video_fill_para(struct fb_info *fbinfo)
{
	struct hat_fb_par *fb_par = (struct hat_fb_par *) fbinfo->par;
#if DEFERRED_IO_WORK
    struct fb_deferred_io *hat_panels_defio;
#endif
    int ret = 0;

	fbinfo->fix.type	    = FB_TYPE_PACKED_PIXELS;
	fbinfo->fix.visual =         FB_VISUAL_TRUECOLOR;
	fbinfo->fix.type_aux	    = 0;
	fbinfo->fix.xpanstep	    = 0;
	fbinfo->fix.ypanstep	    = 0;
	fbinfo->fix.ywrapstep	    = 0;
	fbinfo->fix.accel	    = FB_ACCEL_NONE;
	strncpy(fbinfo->fix.id,"hat_fd_lcd", 10);
    fbinfo->fix.line_length =  (protocol_lcd.bpp) / 8;
	if (fb_par == NULL) {
		printk("fb_par is NULL\n");
		return -EINVAL;
	}
	fbinfo->var.xres		= protocol_lcd.width;
	fbinfo->var.yres		= protocol_lcd.height;
	fbinfo->var.xres_virtual	= protocol_lcd.width;
	fbinfo->var.yres_virtual	=  protocol_lcd.height;
	fbinfo->var.bits_per_pixel	=  protocol_lcd.bpp;
	fbinfo->var.nonstd =         1;
	/* RGB565 */
	fbinfo->var.red.offset =     11;
	fbinfo->var.red.length =     5;
	fbinfo->var.green.offset =   5;
	fbinfo->var.green.length =   6;
	fbinfo->var.blue.offset =    0;
	fbinfo->var.blue.length =    5;
	fbinfo->var.transp.offset =  0;
	fbinfo->var.transp.length =  0;

	fbinfo->flags =  FBINFO_FLAG_DEFAULT | FBINFO_VIRTFB;
#if DEFERRED_IO_WORK
	hat_panels_defio = kzalloc(sizeof(struct fb_deferred_io), GFP_KERNEL);
	if (!hat_panels_defio) {
		printk( "Couldn't allocate deferred io.\n");
		ret = -ENOMEM;
		return ret;
	}
    hat_panels_defio->delay = HZ / refreshrate;
	hat_panels_defio->deferred_io = hat_panels_deferred_io;
    fbinfo->fbdefio = hat_panels_defio;
	fb_deferred_io_init(fbinfo);
#endif
	fbinfo->fbops = &hat_fb_video_ops;
	fbinfo->flags = FBINFO_FLAG_DEFAULT;

	fbinfo->var.nonstd      = 0;
	fbinfo->var.activate    = FB_ACTIVATE_NOW;
	fbinfo->var.accel_flags = 0;
	fbinfo->var.vmode       = FB_VMODE_NONINTERLACED;
    printk("hat_fb_video_fill_para ok\n");

	return ret;
}

int hat_fb_video_probe(struct fb_info *fbinfo)
{
	int ret = 0;
	/* fill parameter */

	ret = hat_fb_video_fill_para(fbinfo);
	return ret;
}


#if HAT_FB_CREATE_BUFFER_BY_FB /*frame buffer is allocated from HDAL, so we don't need to allocate it in fb driver*/
int hat_fb_map_video_memory(struct fb_info *info)
{
	dma_addr_t map_dma = 0;
	unsigned map_size;
    map_size = PAGE_ALIGN(info->fix.smem_len);
	dma_set_coherent_mask(info->dev, DMA_BIT_MASK(32));

	printk("map_video_memory(fbi=%p) map_size:0x%x\n", info, map_size);
	info->screen_base = dma_alloc_writecombine(info->dev, map_size,&map_dma, GFP_KERNEL);
	if (info->screen_base == NULL) {
		printk("Out of memory\n");
		return -ENOMEM;
	}
	if (info->screen_base) {
		/* prevent initial garbage on screen */
		printk("map_video_memory: clear %p:%08x\n",info->screen_base, map_size);
		memset(info->screen_base, 0x00, map_size);
		info->fix.smem_start = map_dma;
		printk("map_video_memory: phy=%08lx vir=%p size=%08x\n",info->fix.smem_start, info->screen_base, map_size);
	}

	return info->screen_base ? 0 : -ENOMEM;
}

void hat_fb_unmap_video_memory(struct fb_info *info)
{
	dma_free_writecombine(info->dev, PAGE_ALIGN(info->fix.smem_len),info->screen_base, info->fix.smem_start);
}

#endif

#if GET_BUFF_MALLOC
int hat_get_video_buf_addr(unsigned long *phys_addr, char __iomem **virt_addr, unsigned int *buffer_len)
{
	lcd_pixfmt_t format;
    unsigned char* vmem;
	 struct hat_fb_par *par;
	 par = frameinfo->fb->par;
	format = protocol_lcd.pixfmt;
    par->frame_size = protocol_lcd.width* protocol_lcd.height*2;//1z帧大小
	
	par->pages_count = frame_size / PAGE_SIZE;
	if ((par->pages_count * PAGE_SIZE) < frame_size) {
		par->pages_count++;
	}
	if (format == PIXELFORMAT_RGB444) {
		*buffer_len = (protocol_lcd.width)*(protocol_lcd.height)*12/8;
	} else if (format == PIXELFORMAT_RGB565) {
		*buffer_len = (protocol_lcd.width)*(protocol_lcd.height)*16/8;
    } else if (format == PIXELFORMAT_RGB666) {
		*buffer_len = (protocol_lcd.width)*(protocol_lcd.height)*18/8;
	} else {
		printk("buffer format not set!\r\n");
		*buffer_len = -1;
	}
	vmem = (void *)__get_free_pages(GFP_KERNEL | __GFP_ZERO,get_order(*buffer_len));
	if (!vmem) {
		printk("Couldn't allocate graphical memory.\n");
		return -ENOMEM;
	}
	memset(vmem, 0x00, *buffer_len);
	*phys_addr =__pa(vmem);
    *virt_addr =(unsigned char __force __iomem *)vmem;
	printk("virt_addr: %x, phys_addr: %lx, buffer_size: %d\r\n", (unsigned int)*virt_addr, (unsigned long)*phys_addr, (int)*buffer_len);
	return 0;
}
#endif

#if CUSTOMIZE_MALLOC
static int hat_fb_malloc_mmap(struct fb_info *fbinfo)
{
	u8 *v_addr;
    u32 p_addr;
	 struct hat_fb_par *par = (struct hat_fb_par *) fbinfo->par;
	//par->frame_size = protocol_lcd.width* protocol_lcd.height*2+sizeof(unsigned long)*2;//1帧大小加帧头与帧尾
	par->frame_size = protocol_lcd.width* protocol_lcd.height*2;//1帧大小
	v_addr = dma_alloc_coherent(NULL,par->frame_size, &p_addr, GFP_KERNEL);
	if(!v_addr)
	{
		printk("Couldn't allocate graphical memory.\n");
		return -ENOMEM;
	}
	fbinfo->fix.smem_start = p_addr;
	fbinfo->screen_base = v_addr;
	fbinfo->fix.smem_len = par->frame_size;
	return 0;
}

#endif


static int hat_fb_list_malloc(struct fb_info *fbinfo)
{
      listhead = (frame_list *)kmalloc(sizeof(frame_list), GFP_KERNEL);
	  int i = 0;
      INIT_LIST_HEAD(&listhead->head);
	  //建立N个结点，依次加入到链表当中/初始化内存 
	 struct hat_fb_par *par = (struct hat_fb_par *) fbinfo->par;
     for(i = 0;i < MAX_FRAME_BUF;i++)
	 {
         
		 //listnode = (frame_list *)kmalloc(sizeof(frame_list), GFP_KERNEL);
		 //listnode->buf = (char *)kmalloc(fb_par->frame_size, GFP_KERNEL);
		 //listnode->index = i;
		 //list_add_tail(&listnode->list, &listhead.list);
		 frame_pbuf[i] = (char *)kzalloc(par->frame_size,GFP_KERNEL);
	 }
	 
	 return 0;

}

#if DEFERRED_IO_WORK
static int hat_fb_pages_alloc(struct fb_info *info)
{
   struct hat_fb_par *par;
    u32 pixels_per_page = 0;
	u32 yoffset_per_page = 0;
	u32 xoffset_per_page = 0;
	u32 index;
	unsigned short x = 0;
	unsigned short y = 0;
	unsigned char *buffer;
	unsigned int len;
	par = info->par;
    par->pages = kmalloc(par->pages_count * sizeof(struct fb_page),GFP_KERNEL);
	if(!par->pages){
		printk( "[%s]: unable to kmalloc for fb_page\n", __func__);
		return -ENOMEM;
	}
	pixels_per_page = PAGE_SIZE / (info->var.bits_per_pixel / 8);
	yoffset_per_page = pixels_per_page / info->var.xres;
	xoffset_per_page = pixels_per_page -(yoffset_per_page * info->var.xres);
	printk("[%s]: pixels_per_page=%hu yoffset_per_page=%hu xoffset_per_page=%hu\n",__func__, pixels_per_page, yoffset_per_page, xoffset_per_page);//5 144
	buffer = (unsigned char *)info->fix.smem_start;
    for (index = 0; index < par->pages_count; index++) {
		len = (info->var.xres * info->var.yres)-(index * pixels_per_page);
		if (len > pixels_per_page) {
			len = pixels_per_page;
		}
		printk("%s: page[%d]: x=%3hu y=%3hu buffer=0x%x len=%3hu\n",__func__, index, x, y, buffer, len);
		par->pages[index].x = x;
		par->pages[index].y = y;
		par->pages[index].buffer = buffer;
		par->pages[index].len = len;

		x += xoffset_per_page;
		if (x >= info->var.xres) {
			y++;
			x -= info->var.xres;
		}
		y += yoffset_per_page;
		buffer += pixels_per_page;
	}

	/* tell the copy routines that the LCD controller is ready to receive data
 	  from the start of the buffer X,Y = (0,0) */
	par->last_buffer_start=(unsigned char *)info->fix.smem_start;
   return 0;
}
#endif

static int hat_fb_alloc(void)
{
	struct fb_info *fbinfo;
	struct hat_fb_par *par;
	fbinfo = framebuffer_alloc(sizeof(struct hat_fb_par), frameinfo->dev);
	if (!fbinfo) {
		/* goto error path */
		printk("fb allocate failed\n");
		return -ENOMEM;
	}
	par = fbinfo->par;
	par->spi = protocol_spi;
	par->info = fbinfo;
	par->frame_hz = 25;
	frameinfo->fb = fbinfo;
	return 0;
}


int hatpanels_fb_init_ide_layer(void)
{
	struct fb_info *fbinfo = NULL;
	struct hat_fb_par *par= NULL;
	int ret = 0;
    if (frameinfo == NULL) {
		printk("hatpanelsfb_info is invalid:0x%x\n", (unsigned int)frameinfo);
		return -EINVAL;
	}

	ret = hat_fb_alloc();
	if (ret != 0) {
		goto ERR_ALLOC;
	}
	fbinfo = frameinfo->fb;
	par = fbinfo->par;
	/* Initialize video memory */
	/*frame buffer is allocated from HDAL, so we don't need to allocate it in fb driver*/
    /* Just get proper buffer length */
#if GET_BUFF_MALLOC
	printk("IND, Buffer created by FB\n");
    if (hat_get_video_buf_addr( &fbinfo->fix.smem_start,&fbinfo->screen_base, &fbinfo->fix.smem_len)) {
			return -ENOMEM;
    }
#endif
#if CUSTOMIZE_MALLOC
    printk("IND, Buffer created by customize\n");
    ret = hat_fb_malloc_mmap(fbinfo);
	if(ret){
		goto ERR_ALLOC;
	}
#endif
    ret = hat_fb_list_malloc(fbinfo);
	if(ret){
		goto ERR_ALLOC;
	}
    ret = hat_fb_video_probe(fbinfo);
	if (ret) {
		goto ERR_REGISER_FB;
	}
#if DEFERRED_IO_WORK
	ret = hat_fb_pages_alloc(fbinfo);
	if(ret < 0)
	{
		printk("hat_fb_pages alloc fail\n");
		goto ERR_PAGES_FAIL;
	}
#endif
#if HAT_FB_CREATE_BUFFER_BY_FB
	ret = hat_fb_map_video_memory(fbinfo);
	if (ret) {
		printk("Failed to allocate video buffer: %d\n", ret);
		ret = -ENOMEM;
		return ret;
	}
#endif
	printk("pa:0x%x va:0x%x len:0x%x\n", (unsigned int)fbinfo->fix.smem_start, (unsigned int)fbinfo->screen_base, (unsigned int)fbinfo->fix.smem_len);
	memset(fbinfo->screen_base, 0x00, fbinfo->fix.smem_len);
	ret = register_framebuffer(fbinfo);
	if (ret) {
		printk("Register FB failed\n");
		goto ERR_REGISER_FB;
	}
	printk("%s frame buffer device\n", fbinfo->fix.id);
    return 0;
/*  nvt_fb_pan_display(&fbinfo->var, fbinfo);  */

ERR_REGISER_FB:
    dma_free_coherent(NULL, fbinfo->fix.smem_len, fbinfo->screen_base, fbinfo->fix.smem_start);
#if DEFERRED_IO_WORK
ERR_PAGES_FAIL:
#endif
    framebuffer_release(fbinfo);
ERR_ALLOC:
	return ret;
}



static int hatpanelsfb_probe(struct platform_device *pdev)
{
    int ret = 0;
    frameinfo = kzalloc(sizeof(struct hatpanelsfb_info), GFP_KERNEL);
    if(!frameinfo){
        printk("%s allocate failed \n",__func__);
        ret = -ENOMEM;
        return ret;
    }
    frameinfo->fb = NULL;
    frameinfo->dev = &pdev->dev;
    platform_set_drvdata(pdev, frameinfo);
	ret = hatpanels_fb_init_ide_layer();
	if(ret)
	{
		printk("hatpanels_fb_init_ide_layer error\n");
		goto ERR_OUT;
	}
    printk("hatpanelsfb_probe ok\n");
	return 0;
ERR_OUT:
	kfree(frameinfo);
	return ret;
}

/*
 *  Cleanup
 */
static int hatpanelsfb_remove(struct platform_device *pdev)
{
	struct fb_info *fbinfo = NULL;
	struct hat_fb_par *par= NULL;
	int i = 0;
	fbinfo = frameinfo->fb;
	par = fbinfo->par;
#if KERNEL_THREAD_WORK
	if(par->reflash_task){
		kthread_stop(par->reflash_task);
		par->reflash_task = NULL;
	}
#endif
    for(i = 0;i < MAX_FRAME_BUF;i++ )
	   kfree(frame_pbuf[i]);
	dma_free_coherent(NULL, fbinfo->fix.smem_len, fbinfo->screen_base, fbinfo->fix.smem_start);
	framebuffer_release(fbinfo);
	kfree(frameinfo);
	init = 0;
	return 0;
}

void hat_fb_start_reflash(void)
{
#if KERNEL_THREAD_WORK
	struct fb_info *fbinfo = NULL;
	struct hat_fb_par *par= NULL;
	fbinfo = frameinfo->fb;
	par = fbinfo->par;
	if(par->reflash_task)
	{
		printk("hat_fb_start_reflash thread still work !\n");
		return;
	}
	par->reflash_task = kthread_run(hat_fb_reflash_thread_func, (void *)fbinfo, "hat_lcd_refalsh_task");
	if(IS_ERR(par->reflash_task))
	{
		printk("unable create kernel thread!\n");
		PTR_ERR(par->reflash_task);
		par->reflash_task = NULL;
	}
	printk("hat_fb_start_reflash thread start !\n");
#endif
}

void hat_fb_stop_reflash(void)
{
#if KERNEL_THREAD_WORK
	struct fb_info *fbinfo = NULL;
	struct hat_fb_par *par= NULL;
	fbinfo = frameinfo->fb;
	par = fbinfo->par;
    if(par->reflash_task){
		kthread_stop(par->reflash_task);
	    par->reflash_task = NULL;
	}
	printk("hat_fb_stop_reflash thread  !\n");
#endif
}

void hat_fb_farme_hz_set(int farme_hz)
{
   	struct fb_info *fbinfo = NULL;
	struct hat_fb_par *par= NULL;
	fbinfo = frameinfo->fb;
	par = fbinfo->par;
	par->frame_hz = farme_hz;
	printk("set frame sleep =%d\n",par->frame_hz);
}


#ifdef CONFIG_PM
static int hatpanelsfb_suspend(struct platform_device *dev, pm_message_t state)
{
    return 0;
}

static int hatpanelsfb_resume(struct platform_device *dev)
{
    return 0;
}
#else
#define hatpanelsfb_suspend NULL
#define hatpanelsfb_resume  NULL
#endif

static struct platform_driver hatpanelsfb_driver = {
	.probe		= hatpanelsfb_probe,
	.remove		= hatpanelsfb_remove,
	.suspend	= hatpanelsfb_suspend,
	.resume		= hatpanelsfb_resume,
	.driver		= {
		.name	= "hat_lcd_fb",
        .owner = THIS_MODULE,
	},
};

int hat_panel_fb_drv_init(void)
{
    int ret = 0;
	if (init != 0) {
		printk("FB already initial\n");
		return -EALREADY;
	}
	init = 1;
     ret = platform_driver_register(&hatpanelsfb_driver);
    if (!ret) {
		hat_fb_device = platform_device_register_simple("hat_lcd_fb", 0, NULL, 0);
		if (IS_ERR(hat_fb_device)) {
			platform_driver_unregister(&hatpanelsfb_driver);
			ret = PTR_ERR(hat_fb_device);
			printk(" %s Device unregister err\n",__func__);
		}
	} else {
			printk(" %s driver register err\n",__func__);
	}
	return ret;

}

int hat_panel_fb_drv_deinit(void)
{
    platform_device_unregister(hat_fb_device);
	platform_driver_unregister(&hatpanelsfb_driver);
	return 0;
}

#if 0
static int __init hatpanles_entry(void)
{
   int ret = 0;
   ret = platform_driver_register(&hatpanelsfb_driver);
   return ret;
}

static void __exit hatpanles_exit(void)
{
  platform_driver_unregister(&hatpanelsfb_driver);
}

module_init(hatpanles_entry);
module_exit(hatpanles_exit);

MODULE_AUTHOR("Alex King <188101696@qq.com>");
MODULE_DESCRIPTION("Framebuffer driver for the hat-lcd");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:hat-lcd");

#endif
#endif
