#include "platform_stm32.h"
//注意初始化的函数只能用一个
#ifdef _STM32_HAL_BUILD_
struct protocol_info info;

static int protocal_spi_send(bool a0, unsigned char *buf, unsigned int len)
{
	HAL_StatusTypeDef ret = 0;

	if(NULL == buf)
	{
		printf("%s:%d input param error!", __FUNCTION__,__LINE__);
		return HAL_ERROR;
	}

	if(SEND_SPI_COMMOND == a0)
	{
		OLED_DC_DOWN();
	}
	else
	{
		OLED_DC_UP();
	}

	ret = HAL_SPI_Transmit(&hspi3,buf,len,500);
	if(ret != HAL_OK)
	{
       printf( "protocal_spi_send fail ret = %d!", ret);
	}
	return ret;
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


static int protocol_spi_init(void)
{
    //bindind work function
    protocol_lcd.sendCommand = protocal_spi_Command_send;
	protocol_lcd.sendParameter = protocal_spi_Parameter_send;
	protocol_lcd.sendOneParameter = protocal_spi_OneParameter_send;
	protocol_lcd.lcd_delay = HAL_Delay;
    protocol_lcd.type = LCD_TRANSFER_SPI;
	return 0;
}
int protocol_spi_probe(void)
{
	protocol_spi_init();
	lcd_common_binding(LCD_TYPE_SSD1306);
	lcd_common_funciton.lcd_init();
	return 0;
}

/*
HAL_StatusTypeDef HAL_SRAM_Read_16b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint16_t *pDstBuffer,
                                    uint32_t BufferSize);
HAL_StatusTypeDef HAL_SRAM_Write_16b(SRAM_HandleTypeDef *hsram, uint32_t *pAddress, uint16_t *pSrcBuffer,
                                     uint32_t BufferSize);
 */
static int protocol_fsmc_Parameter_read(unsigned char *buf)
{
	//HAL_StatusTypeDef ret;

	//ret = HAL_SRAM_Read_16b(&hsram1,FSMC_BANK1_4,buf,2);

	 return 0;
}

static int protocol_fsmc_Parameter_send(unsigned char *buf)
{
	//HAL_StatusTypeDef ret;

	//	ret = HAL_SRAM_Write_16b(&hsram1,FSMC_BANK1_4,buf,2);
   return 0;
}

static int protocol_fsmc_init(void)
{
	 //bindind work function
	protocol_lcd.sendFSMCParameter = protocol_fsmc_Parameter_send;

}



int protocol_fsmc_probe(void)
{

	return 0;
}

int protocol_i2c_probe(void)
{
	return 0;
}

#endif