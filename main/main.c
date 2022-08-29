#include <stdio.h>
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
//宏定义
#define D4 12
#define D5 13
#define GPIO_OUTPUT_PIN_SET ((1 << D4) | (1 << D5))
static bool s_led_state = 0; // gpio的状态
//初始化gpio
static void config_led(void)
{
    gpio_config_t io_conf = {};
    io_conf.intr_type = GPIO_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SET;
    io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
    io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
    gpio_config(&io_conf);
}

//闪灯程序
static void blink_led(void)
{
    //gpio_reset_pin((GPIO_NUM_12 | GPIO_NUM_13));
    gpio_set_level(GPIO_NUM_13, s_led_state);
    gpio_set_level(GPIO_NUM_12, s_led_state);
}
void app_main(void)
{
    config_led();
    while (1)
    {
        blink_led();
        s_led_state = !s_led_state;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
