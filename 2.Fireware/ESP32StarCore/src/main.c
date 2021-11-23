#include "driver/gpio.h"

#define BLINK_GPIO 22
int app_main()
 {
    esp_err_t ret = 0;
    ret = gpio_set_direction(BLINK_GPIO,GPIO_MODE_OUTPUT);
    if(ret != ESP_OK ){
        printf("gpio_set_direction fail\n ");
        return -1;
    }
    ret = gpio_set_level(BLINK_GPIO,0);
    return ret;
 }