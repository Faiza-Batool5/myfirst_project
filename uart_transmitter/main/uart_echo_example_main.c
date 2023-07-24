#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "esp_log.h"
//transmitter code
#define TXD_PIN 17
#define RXD_PIN 16
#define UART_NUM UART_NUM_2
#define UART_BAUD_RATE 115200
#define BUF_SIZE (1024)

void app_main(void)
{
    // Configure UART
    uart_config_t uart_config = {
        .baud_rate = UART_BAUD_RATE,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
     };
    uart_driver_install(UART_NUM, BUF_SIZE * 2, 0, 0, NULL, 0);
    uart_param_config(UART_NUM, &uart_config);
    uart_set_pin(UART_NUM, TXD_PIN, RXD_PIN, UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);

    while (1) {
        const char* message = "Hello from ESP32 ONE!\n";
        uart_write_bytes(UART_NUM, message, strlen(message));
        vTaskDelay(1000 / portTICK_PERIOD_MS); // Wait for 1 second (adjust as needed)
    }
}