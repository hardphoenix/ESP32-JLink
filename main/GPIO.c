#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include <esp_log.h>
#include "sdkconfig.h"
#include "driver/gpio.h"


#define LED_PIN             ((1ULL<<GPIO_NUM_2))


void GPIO_INIT(void)
{
    gpio_config_t gpio_led;

    gpio_led.intr_type= GPIO_INTR_DISABLE;
    gpio_led.mode= GPIO_MODE_OUTPUT;
    gpio_led.pin_bit_mask = LED_PIN;
    gpio_led.pull_down_en =0;
    gpio_led.pull_up_en=0;
    gpio_set_direction(GPIO_NUM_2,GPIO_MODE_OUTPUT);
    gpio_config(&gpio_led);
}

static void gpio_Task(void)
{
    GPIO_INIT();

    while (1)
    {
        gpio_set_level(GPIO_NUM_2,1);
        printf("LED ON\r\n");
        vTaskDelay(pdMS_TO_TICKS(100));
        gpio_set_level(GPIO_NUM_2,0);
        printf("LED OFF\r\n");
        vTaskDelay(pdMS_TO_TICKS(100));
    }
}

void app_main(void)
{
    xTaskCreate(gpio_Task,"GPIOTask",1024*2,NULL,5,NULL);     /*Make Task LED Blink*/
}
