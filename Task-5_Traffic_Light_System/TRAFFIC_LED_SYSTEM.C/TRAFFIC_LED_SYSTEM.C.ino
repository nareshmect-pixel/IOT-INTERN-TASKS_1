#include "pico/stdlib.h"

#define RED_LED 16
#define YELLOW_LED 17
#define GREEN_LED 18

int main() {

    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);

    gpio_init(YELLOW_LED);
    gpio_set_dir(YELLOW_LED, GPIO_OUT);

    gpio_init(GREEN_LED);
    gpio_set_dir(GREEN_LED, GPIO_OUT);

    while (true) {

        // Green ON
        gpio_put(GREEN_LED, 1);
        gpio_put(YELLOW_LED, 0);
        gpio_put(RED_LED, 0);
        sleep_ms(5000);

        // Yellow ON
        gpio_put(GREEN_LED, 0);
        gpio_put(YELLOW_LED, 1);
        gpio_put(RED_LED, 0);
        sleep_ms(2000);

        // Red ON
        gpio_put(GREEN_LED, 0);
        gpio_put(YELLOW_LED, 0);
        gpio_put(RED_LED, 1);
        sleep_ms(5000);
    }

    return 0;
}