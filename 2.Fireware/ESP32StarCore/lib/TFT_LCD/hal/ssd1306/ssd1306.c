#include "../../framework/ssd1306_fonts.h"
#include "ssd1306.h"
#include "ssd1306_commands.h"

#ifdef SETUP_SSD1306
void ssd1306_drvlcdfill(unsigned int bmp_data){
	unsigned int y = 0, x = 0;
	for(y = 0;y < 8;y++)
	{
		protocol_lcd.sendCommand(SSD1306_SETPAGE+y);
		protocol_lcd.sendCommand(0x01);
		protocol_lcd.sendCommand(SSD1306_SETHIGHCOLUMN);
		for(x = 0;x< protocol_lcd.width;x++)
			protocol_lcd.sendOneParameter(bmp_data);
	}
}

void ssd1306_drv_SetPos(unsigned int x,unsigned int y)
{
	protocol_lcd.sendCommand(SSD1306_SETPAGE+(y>>3));
	protocol_lcd.sendCommand(((x&0xf0)>>4)|SSD1306_SETHIGHCOLUMN);
	protocol_lcd.sendCommand((x&0xf)|0x01);
}
void ssd1306_drvinit(void){
	//OLED_RES_UP();
	protocol_lcd.lcd_delay(50);
	//OLED_RES_DOWN();
	protocol_lcd.lcd_delay(50);
	//OLED_RES_UP();
	//0xae
	protocol_lcd.sendCommand(SSD1306_DISPLAYOFF); //--turn off oled panel
	//0x00
	protocol_lcd.sendCommand(SSD1306_SETLOWCOLUMN);//---set low column address
	//0x10
	protocol_lcd.sendCommand(SSD1306_SETHIGHCOLUMN);//---set high column address
	//0x40
	protocol_lcd.sendCommand(SSD1306_SETSTARTLINE);//--set start line address Set Mapping RAM Display Start Line (0x00~0x3F)
	//0x81
	protocol_lcd.sendCommand(SSD1306_SETCONTRAST);//--set contrast control register
	//0xcf
	protocol_lcd.sendCommand(0xcf); // Set SEG Output Current Brightness
	//0xa1
	protocol_lcd.sendCommand(SSD1306_SEGREMAP2);//--Set SEG/Column Mapping     0xa0左右反置 0xa1正常
	//0xc8
	protocol_lcd.sendCommand(SSD1306_COMSCANDEC);//Set COM/Row Scan Direction   0xc0上下反置 0xc8正常
	//0xa6
	protocol_lcd.sendCommand(SSD1306_NORMALDISPLAY);//--set normal display
	//0xa8
	protocol_lcd.sendCommand(SSD1306_SETMULTIPLEX);//--set multiplex ratio(1 to 64)
	//0x3f
	protocol_lcd.sendCommand(0x3f);//--1/64 duty
	//0xd3
	protocol_lcd.sendCommand(SSD1306_SETDISPLAYOFFSET);//-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	//0x00
	protocol_lcd.sendCommand(SSD1306_SETLOWCOLUMN);//-not offset
	//0xd5
	protocol_lcd.sendCommand(SSD1306_SETDISPLAYCLOCKDIV);//--set display clock divide ratio/oscillator frequency
	//0x80
	protocol_lcd.sendCommand(0x80);//--set divide ratio, Set Clock as 100 Frames/Sec
	//0xd9
	protocol_lcd.sendCommand(SSD1306_SETPRECHARGE);//--set pre-charge period
	//0xf1
	protocol_lcd.sendCommand(0xf1);//Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	//0xda
	protocol_lcd.sendCommand(SSD1306_SETCOMPINS);//--set com pins hardware configuration
	//0x12
	protocol_lcd.sendCommand(0x12);
	//0xdb
	protocol_lcd.sendCommand(SSD1306_SETVCOMDETECT);//--set vcomh
	//0x40
	protocol_lcd.sendCommand(SSD1306_SETSTARTLINE);//Set VCOM Deselect Level
	//0x20
	protocol_lcd.sendCommand(SSD1306_MEMORYMODE);//-Set Page Addressing Mode (0x00/0x01/0x02)
	//0x02
	protocol_lcd.sendCommand(0x02);
	//0x8d
	protocol_lcd.sendCommand(SSD1306_CHARGEPUMP);////--set Charge Pump enable/disable
	//0x14
	protocol_lcd.sendCommand(0x14);//--set(0x10) disable
	//0xa4
	protocol_lcd.sendCommand(SSD1306_DISPLAYALLON_RESUME);//// Disable Entire Display On (0xa4/0xa5)
	//0xa6
	protocol_lcd.sendCommand(SSD1306_NORMALDISPLAY);// Disable Inverse Display On (0xa6/a7)
	//0xaf
	protocol_lcd.sendCommand(SSD1306_DISPLAYON);////--turn on oled panel
	ssd1306_drvlcdfill(0x00);
	ssd1306_drv_SetPos(0,0);
}

//==============================================================
//函数名：LCD_P6x8Str(u8 x,u8 y,u8 *p)
//功能描述：写入一组标准ASCII字符串
//参数：显示的位置（x,y），y为页范围0～7，要显示的字符串
//返回：无
//==============================================================
void ssd1306_P6x8Str(unsigned char x,u8 y,unsigned char *ch,const unsigned char *F6x8)
{
	unsigned char c=0,i=0,j=0;

	while (*(ch+j)!='\0')
	{
		c =*(ch+j)-32;
		if(x>126)
		{
			x=0;
			y++;
		}
		//LCD_Set_Pos(x,y);
		for(i=0;i<6;i++)
		{
			//LCD_WrDat(*(F6x8+c*6+i));
		}
		x+=6;
		j++;
	}
}
//==============================================================
//函数名：LCD_P8x16Str(u8 x,u8 y,u8 *p)
//功能描述：写入一组标准ASCII字符串
//参数：显示的位置（x,y），y为页范围0～63，要显示的字符串
//返回：无
//==============================================================
void ssd1306_P8x16Str(unsigned char x,unsigned char y,unsigned char *ch,const unsigned char *F8x16)
{
  unsigned char c=0,i=0,j=0;

  while (*(ch+j)!='\0')
  {
    c =*(ch+j)-32;
    if(x>120)
	{
		x=0;
		y++;
	}
   // LCD_Set_Pos(x,y);
  	for(i=0;i<8;i++)
  	{
  	  	//LCD_WrDat(*(F8x16+c*16+i));
  	}
  	LCD_Set_Pos(x,y+8);
  	for(i=0;i<8;i++)
  	{
  	  	//LCD_WrDat(*(F8x16+c*16+i+8));
  	}
  	x+=8;
  	j++;
  }
}

#endif
