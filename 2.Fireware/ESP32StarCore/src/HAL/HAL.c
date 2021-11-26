#include "HAL.h"
#include "driver/uart.h"
void HAL_Init()
{
 const uart_port_t uart_num = UART_NUM_0;
   uart_config_t uart_config = {
      .baud_rate = 115200,
      .data_bits = UART_DATA_8_BITS,
      .parity = UART_PARITY_DISABLE,
      .stop_bits = UART_STOP_BITS_1,
      .flow_ctrl = UART_HW_FLOWCTRL_CTS_RTS,
      .rx_flow_ctrl_thresh = 122,
    };
 ESP_ERROR_CHECK(uart_param_config(uart_num, &uart_config));

}