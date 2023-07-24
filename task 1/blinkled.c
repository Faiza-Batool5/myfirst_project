#include <stdio.h>
#include "esp_timer.h"
#include "driver/gpio.h"
#define LED_PIN  GPIO_NUM_2
milis()
{
    esp_timer_get-time();
}
int current_time = milis();
int delay = 1000;
stoptime = current_time + delay;
while(stoptime>= milis())
{
}
void app_main(void)
{
 gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

 while(1) {       
        
        gpio_set_level(LED_PIN, 1);   
        milis();      // Turn the LED on
        
        gpio_set_level(LED_PIN, 0); 
        milis();       // Turn the LED off
       
}
}

   