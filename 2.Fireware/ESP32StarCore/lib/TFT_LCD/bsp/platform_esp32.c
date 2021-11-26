#include "platform_esp32.h"
#ifdef _ESP32_HAL_BUILD_
static int protocal_spi_send(unsigned char *buf, unsigned int len)
{
	
	return 0;
}


static int protocal_spi_Command_send(unsigned char cmd)
{
   return  0;
}

static int protocal_spi_Parameter_send(unsigned char *buf, unsigned int len)
{
   return  0;
}

static int protocal_spi_OneParameter_send(unsigned char data)
{
   return 0;
}


static int protocol_spi_init(void)
{
    //bindind work function
	return 0;
}
int protocol_spi_probe(void)
{
	protocol_spi_init();
	return 0;
}

int protocol_i2c_probe(void)
{
	return 0;
}

#endif