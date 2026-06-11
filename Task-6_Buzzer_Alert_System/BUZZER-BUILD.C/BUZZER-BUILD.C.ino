#include "pico/stdlib.h"

#define BUZZER 15

int main() {

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    while (true) {
        gpio_put(BUZZER, 1); 
        sleep_ms(1000);

        gpio_put(BUZZER, 0); 
        sleep_ms(1000);
    }

    return 0;
}