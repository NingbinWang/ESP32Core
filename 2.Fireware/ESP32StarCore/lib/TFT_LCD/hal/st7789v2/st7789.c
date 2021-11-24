/*
 * Copyright (C) 2020 Tuubu Digital Technology Co., Ltd.
 *
 * Description: spi lcd  driver for linux platform.
 *
 *
 * Author: Alex King
 * Data:2021/07/29
 * 
 * @file   st7789.c
 * @brief   This file defines st7789 driver work.
 * 
 */
#include "st7789.h"
#include "st7789_commands.h"
#ifdef SETUP_ST7789V2
#include "logo.h"
void st7789_drvinit2(void)//T24P21
{
    //set display order 0x36
    protocol_lcd.sendCommand(ST7789_MADCTL);
    protocol_lcd.sendOneParameter(0x00);
    //0x3a
    protocol_lcd.sendCommand(ST7789_COLMOD);
    protocol_lcd.sendOneParameter(0x05);      //16bit/pixel
     //0xb2
    protocol_lcd.sendCommand(ST7789_PORCTRL);  //proch setting
    protocol_lcd.sendOneParameter(0x05);       //BPA back porch setting in normal mode
    protocol_lcd.sendOneParameter(0x05);       //Front porch setting in normal mode 
    protocol_lcd.sendOneParameter(0x00);       // disable separate porch
    protocol_lcd.sendOneParameter(0x33);       //Back porch setting in idle mode. Front porch setting in idle mode
    protocol_lcd.sendOneParameter(0x33);        //Back porch setting in partial mode .Front porch setting in partial mode.
    //0xb7
    protocol_lcd.sendCommand(ST7789_GCTRL);
    protocol_lcd.sendOneParameter(0x35); //VGH 13.26 VGLS -10.43 默认值
    //0xb8
    protocol_lcd.sendCommand(ST7789_GTADJ);
    protocol_lcd.sendOneParameter(0x2a);
    protocol_lcd.sendOneParameter(0x2b);
    protocol_lcd.sendOneParameter(0x2f);//Gate on timing adjustment Gate on timing=300ns+GTA[5:0]*400ns
    //0xbb
    protocol_lcd.sendCommand(ST7789_VCOMS);
    protocol_lcd.sendOneParameter(0x20);//VCOM Setting default 0x20
    //0xc0
     protocol_lcd.sendCommand(ST7789_LCMCTRL);
    protocol_lcd.sendOneParameter(0x2c); 
    //0xc2
    protocol_lcd.sendCommand(ST7789_VDVVRHEN);
    protocol_lcd.sendOneParameter(0x01); //VDV and VRH register value comes from command write
    //0xc3
    protocol_lcd.sendCommand(ST7789_VRHS);
    protocol_lcd.sendOneParameter(0x0b);//4.1+( vcom+vcom offset+vdv) 
    //0xc4
    protocol_lcd.sendCommand(ST7789_VDVSET);
    protocol_lcd.sendOneParameter(0x20);// default 0x20
    //0xc6
     protocol_lcd.sendCommand(ST7789_FRCTR2);
    protocol_lcd.sendOneParameter(0x14); //FR in normal mode 57HZ
    //0xd0
    protocol_lcd.sendCommand(ST7789_PWCTRL1);
    protocol_lcd.sendOneParameter(0xa4);//default
    protocol_lcd.sendOneParameter(0xa1);//default
    //0xe7
    protocol_lcd.sendCommand(ST7789_SPI2EN);
    protocol_lcd.sendOneParameter(0x10);//enable 2 data lane mode commands in command table 2 can not be read in serial interface
    //0xe8
    protocol_lcd.sendCommand(ST7789_PWCTRL2);
    protocol_lcd.sendOneParameter(0x03);//BCLK DIV 6
    //0xe9
    protocol_lcd.sendCommand(ST7789_EQCTRL);
    protocol_lcd.sendOneParameter(0x00);
    protocol_lcd.sendOneParameter(0x00);
    protocol_lcd.sendOneParameter(0x00);

    //0xe0
    protocol_lcd.sendCommand(ST7789_PVGAMCTRL);//Positive Voltage Gamma Control
    protocol_lcd.sendOneParameter(0xd0);
    protocol_lcd.sendOneParameter(0x06);
    protocol_lcd.sendOneParameter(0x0b);
    protocol_lcd.sendOneParameter(0x0a);
    protocol_lcd.sendOneParameter(0x09);
    protocol_lcd.sendOneParameter(0x05);
    protocol_lcd.sendOneParameter(0x2e);
    protocol_lcd.sendOneParameter(0x43);
    protocol_lcd.sendOneParameter(0x44);
    protocol_lcd.sendOneParameter(0x09);
    protocol_lcd.sendOneParameter(0x16);
    protocol_lcd.sendOneParameter(0x15);
    protocol_lcd.sendOneParameter(0x23);
    protocol_lcd.sendOneParameter(0x27);
    //0xe1
    protocol_lcd.sendCommand(ST7789_NVGAMCTRL);//Negative Voltage Gamma Control
    protocol_lcd.sendOneParameter(0xd0);
    protocol_lcd.sendOneParameter(0x06);
    protocol_lcd.sendOneParameter(0x0b);
    protocol_lcd.sendOneParameter(0x09);
    protocol_lcd.sendOneParameter(0x08);
    protocol_lcd.sendOneParameter(0x06);
    protocol_lcd.sendOneParameter(0x2e);
    protocol_lcd.sendOneParameter(0x44);
    protocol_lcd.sendOneParameter(0x44);
    protocol_lcd.sendOneParameter(0x3a);
    protocol_lcd.sendOneParameter(0x15);
    protocol_lcd.sendOneParameter(0x15);
    protocol_lcd.sendOneParameter(0x23);
    protocol_lcd.sendOneParameter(0x26);
    //0x2a
    protocol_lcd.sendCommand(ST7789_CASET); //Column Address Set
    protocol_lcd.sendOneParameter(0x00);
    protocol_lcd.sendOneParameter(0x00);
    protocol_lcd.sendOneParameter(0x00);
    protocol_lcd.sendOneParameter(0xef);
    //0x2b
     protocol_lcd.sendCommand(ST7789_RASET);//Row Address Set
    protocol_lcd.sendOneParameter(0x00);
    protocol_lcd.sendOneParameter(0x00);
    protocol_lcd.sendOneParameter(0x01);
    protocol_lcd.sendOneParameter(0x3f);
    //0x11
    protocol_lcd.sendCommand(ST7789_SLPOUT);
    protocol_lcd.lcd_delay(120);
    //0x21
   protocol_lcd.sendCommand(ST7789_INVON);
    //0x29
   protocol_lcd.sendCommand(ST7789_DISPON);
    //0x2c
   //protocol_lcd.sendCommand(ST7789_RAMWR);
   protocol_lcd.sendCommand(ST7789_RAMWR);
}

void st7789_drvinit(void)//T24P197
{   
     protocol_lcd.sendCommand(ST7789_SLPOUT);
     protocol_lcd.lcd_delay(120);
    //set display order 0x36
     protocol_lcd.sendCommand(ST7789_MADCTL);
     protocol_lcd.sendOneParameter(0x00);
    //0x3a
    protocol_lcd.sendCommand(ST7789_COLMOD);
    protocol_lcd.sendOneParameter(0x55);      //16bit/pixel
     //0xb2
    protocol_lcd.sendCommand(ST7789_PORCTRL);  //proch setting
    protocol_lcd.sendOneParameter(0x0C);       //BPA back porch setting in normal mode
    protocol_lcd.sendOneParameter(0x0C);       //Front porch setting in normal mode 
    protocol_lcd.sendOneParameter(0x00);       // disable separate porch
    protocol_lcd.sendOneParameter(0x33);       //Back porch setting in idle mode. Front porch setting in idle mode
    protocol_lcd.sendOneParameter(0x33);        //Back porch setting in partial mode .Front porch setting in partial mode.
    //0xb7
    protocol_lcd.sendCommand(ST7789_GCTRL);
    protocol_lcd.sendOneParameter(0x75); //VGH 13.26 VGLS -10.43 默认值
    //0xbb
    protocol_lcd.sendCommand(ST7789_VCOMS);
    protocol_lcd.sendOneParameter(0x13);//VCOM Setting default 0x20
    //0xc0
     protocol_lcd.sendCommand(ST7789_LCMCTRL);
    protocol_lcd.sendOneParameter(0x2c); 
    //0xc2
    protocol_lcd.sendCommand(ST7789_VDVVRHEN);
    protocol_lcd.sendOneParameter(0x01); //VDV and VRH register value comes from command write
    //0xc3
    protocol_lcd.sendCommand(ST7789_VRHS);
    protocol_lcd.sendOneParameter(0x13);//4.1+( vcom+vcom offset+vdv) 
    //0xc4
    protocol_lcd.sendCommand(ST7789_VDVSET);
    protocol_lcd.sendOneParameter(0x20);// default 0x20
    //0x44
     protocol_lcd.sendCommand(ST7789_TESCAN);
    protocol_lcd.sendOneParameter(0x00);
    protocol_lcd.sendOneParameter(0x1a);
    //0xc6
     protocol_lcd.sendCommand(ST7789_FRCTR2);
    protocol_lcd.sendOneParameter(0x1A); //FR in normal mode 57HZ
    //0xd0
    protocol_lcd.sendCommand(ST7789_PWCTRL1);
    protocol_lcd.sendOneParameter(0xa4);//default
    protocol_lcd.sendOneParameter(0xa1);//default
        //0x09
    protocol_lcd.sendCommand(ST7789_RDDST);
    protocol_lcd.sendOneParameter(0x00);
    protocol_lcd.sendOneParameter(0x00);
    protocol_lcd.sendOneParameter(0x00);
    protocol_lcd.sendOneParameter(0x02);
    protocol_lcd.sendOneParameter(0x00);
     //0xd6
    protocol_lcd.sendCommand(0xD6);
    protocol_lcd.sendOneParameter(0xa1);//default
    //0x21
     protocol_lcd.sendCommand(ST7789_INVON);
 
    //0xe0
    protocol_lcd.sendCommand(ST7789_PVGAMCTRL);//Positive Voltage Gamma Control
    protocol_lcd.sendOneParameter(0xd0);
    protocol_lcd.sendOneParameter(0x08);
    protocol_lcd.sendOneParameter(0x10);
    protocol_lcd.sendOneParameter(0x0d);
    protocol_lcd.sendOneParameter(0x0c);
    protocol_lcd.sendOneParameter(0x07);
    protocol_lcd.sendOneParameter(0x37);
    protocol_lcd.sendOneParameter(0x53);
    protocol_lcd.sendOneParameter(0x4c);
    protocol_lcd.sendOneParameter(0x39);
    protocol_lcd.sendOneParameter(0x15);
    protocol_lcd.sendOneParameter(0x15);
    protocol_lcd.sendOneParameter(0x2a);
    protocol_lcd.sendOneParameter(0x2d);
    //0xe1
    protocol_lcd.sendCommand(ST7789_NVGAMCTRL);//Negative Voltage Gamma Control
    protocol_lcd.sendOneParameter(0xd0);
    protocol_lcd.sendOneParameter(0x0d);
    protocol_lcd.sendOneParameter(0x12);
    protocol_lcd.sendOneParameter(0x08);
    protocol_lcd.sendOneParameter(0x08);
    protocol_lcd.sendOneParameter(0x15);
    protocol_lcd.sendOneParameter(0x34);
    protocol_lcd.sendOneParameter(0x34);
    protocol_lcd.sendOneParameter(0x4A);
    protocol_lcd.sendOneParameter(0x36);
    protocol_lcd.sendOneParameter(0x12);
    protocol_lcd.sendOneParameter(0x13);
    protocol_lcd.sendOneParameter(0x2b);
    protocol_lcd.sendOneParameter(0x2f);
    //0x35
    protocol_lcd.sendCommand(ST7789_TEON);
    protocol_lcd.sendOneParameter(0x00);
       //0xb0
    protocol_lcd.sendCommand(ST7789_RAMCTRL);
    protocol_lcd.sendOneParameter(0x00);
     protocol_lcd.sendOneParameter(0xf8);
	    //0x29
   // protocol_lcd.sendCommand(ST7789_DISPON);
    //0x2c
   //protocol_lcd.sendCommand(ST7789_RAMWR);
}


void st7789_drv_memory_data_access(unsigned int xStart,unsigned int yStart,unsigned int xEnd,unsigned int yEnd)
{
  protocol_lcd.sendCommand(ST7789_CASET);
  protocol_lcd.sendOneParameter(xStart&0xff00);
  protocol_lcd.sendOneParameter(xStart&0x00ff);
  protocol_lcd.sendOneParameter(xEnd&0xff00);
  protocol_lcd.sendOneParameter(xEnd&0x00ff);
  protocol_lcd.sendCommand(ST7789_RASET);
  protocol_lcd.sendOneParameter(yStart&0xff00);
  protocol_lcd.sendOneParameter(yStart&0x00ff);
  protocol_lcd.sendOneParameter(yEnd&0xff00);
  protocol_lcd.sendOneParameter(yEnd&0x00ff);
}


void st7789_drv_send_data(unsigned char *data, int size){
     protocol_lcd.sendCommand(ST7789_RAMWR);
     protocol_lcd.sendParameter(data,size);
}

void st7789_drv_show_cmd(void){
     protocol_lcd.sendCommand(ST7789_RAMWR);
}

void st7789_drv_show_data(unsigned char *data, int size){
     protocol_lcd.sendParameter(data,size);
}

void st7789_drvpitcure_logo(void)
{
    protocol_lcd.sendCommand(ST7789_RAMWR);
    protocol_lcd.sendParameter(gImage_logo,sizeof(gImage_logo));
	    //0x29
    protocol_lcd.sendCommand(ST7789_DISPON);
}
#endif