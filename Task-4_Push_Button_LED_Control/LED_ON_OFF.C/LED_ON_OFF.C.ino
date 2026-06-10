#include "pico/stdlib.h"

#define LED_PIN 15
#define BUTTON_PIN 14

int main() {

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    bool led_state = false;

    while (1) {

        if (gpio_get(BUTTON_PIN) == 0) {

            led_state = !led_state;   

            gpio_put(LED_PIN, led_state);

            sleep_ms(300); 
        }
    }
}