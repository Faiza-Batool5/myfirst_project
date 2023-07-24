#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#define LED_PIN  GPIO_NUM_2
//#define BUTTON_PIN  GPIO_NUM_25 
void gpio_blink(void *pvparameter)
{
 gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

 //gpio_pulldown_en(25);
 while(1) {       
        
            gpio_set_level(LED_PIN, 1);  
            vTaskDelay(1000 / portTICK_PERIOD_MS);       // Turn the LED on
            gpio_set_level(LED_PIN, 0); 
            vTaskDelay(1000 / portTICK_PERIOD_MS);        // Turn the LED off
        }
      
}
void app_main(void)
{
xTaskCreate(gpio_blink, 1024*2, NULL, 3, NULL)
}
   