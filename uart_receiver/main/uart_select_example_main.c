#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "esp_log.h"
//receiver


#define TXD_PIN 17
#define RXD_PIN 16
#define UART_NUM UART_NUM_2
#define UART_BAUD_RATE 115200
#define BUF_SIZE (1024)

static QueueHandle_t uart2_queue;

static void uart_event_task(void *pvParameters)
{
    uint8_t *data = (uint8_t *)malloc(BUF_SIZE);
    while (1)
    {
        if (xQueueReceive(uart2_queue, (void *)data, (portTickType)portMAX_DELAY))
        {
            ESP_LOGI("UART_RECEIVER", "Received: %s", data);
        }
    }
    free(data);
    data = NULL;
    vTaskDelete(NULL);
}

void app_main(void)
{
    // Configure UART
    uart_config_t uart_config = {
        .baud_rate = UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        //.source_clk = UART_SCLK_APB,
    };
    uart_driver_install(UART_NUM, BUF_SIZE * 2, BUF_SIZE * 2, 4, &uart2_queue, 0);
    uart_param_config(UART_NUM, &uart_config);
    uart_set_pin(UART_NUM, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    xTaskCreate(uart_event_task, "uart_event_task", 2048, NULL, 12, NULL);
}