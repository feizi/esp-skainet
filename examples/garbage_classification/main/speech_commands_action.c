/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "driver/i2s.h"
#include <driver/gpio.h>

#include "residual.h"
#include "household_food.h"
#include "hazardous.h"
#include "recyclable.h"
#include "speech_commands_action.h"

typedef struct {
    char* name;
    const uint8_t* data;
    int length;
} dac_audio_item_t;

void led_init(int gpio)
{
    gpio_config_t io_conf;
    io_conf.intr_type = (gpio_int_type_t) GPIO_PIN_INTR_DISABLE;
    io_conf.mode = GPIO_MODE_OUTPUT;
    io_conf.pull_up_en = (gpio_pullup_t) 1;

    uint64_t test = ((uint64_t)1 << gpio);
    io_conf.pin_bit_mask = test;
    gpio_config(&io_conf);
    gpio_set_level(gpio, false);
}

void led_on(int gpio)
{
    gpio_set_level(gpio, true);
}

void led_off(int gpio)
{
    gpio_set_level(gpio, false);
}

esp_err_t iot_dac_audio_play(const uint8_t* data, int length, TickType_t ticks_to_wait)
{
    size_t bytes_write = 0;
    i2s_write(0, (const char*) data, length, &bytes_write, ticks_to_wait);
    return ESP_OK;
}
dac_audio_item_t playlist[] = {
    {"residual", residual, sizeof(residual)},
    {"household_food", household_food, sizeof(household_food)},
    {"hazardous", hazardous, sizeof(hazardous)},
    {"recyclable", recyclable, sizeof(recyclable)},
};

void speech_commands_action(int command_id)
{
    printf("Commands ID: %d.\n", command_id);
    switch (command_id) {
    case 0:
        iot_dac_audio_play(playlist[0].data, playlist[0].length, portMAX_DELAY);
        printf("干垃圾（Residual Waste）\n");
        break;
    case 1:
        iot_dac_audio_play(playlist[1].data, playlist[1].length, portMAX_DELAY);
        printf("湿垃圾（Household Food Waste）\n");
        break;
    case 2:
        iot_dac_audio_play(playlist[2].data, playlist[2].length, portMAX_DELAY);
        printf("有害垃圾（Hazardous Waste）\n");
        break;
    case 3:
        iot_dac_audio_play(playlist[3].data, playlist[3].length, portMAX_DELAY);
        printf("可回收垃圾（Recyclable Waste）\n");
        break;
    default:
        break;
    }
}