#include <stdio.h>
#include "pico/stdlib.h"

#define TRIG 3
#define ECHO 2
#define BUZZER 15

float get_distance()
{
    gpio_put(TRIG, 0);
    sleep_us(2);

    gpio_put(TRIG, 1);
    sleep_us(10);
    gpio_put(TRIG, 0);

    while (!gpio_get(ECHO));

    absolute_time_t start = get_absolute_time();

    while (gpio_get(ECHO));

    absolute_time_t end = get_absolute_time();

    int64_t duration =
        absolute_time_diff_us(start, end);

    float distance =
        duration * 0.0343 / 2.0;

    return distance;
}

int main()
{
    stdio_init_all();

    gpio_init(TRIG);
    gpio_set_dir(TRIG, GPIO_OUT);

    gpio_init(ECHO);
    gpio_set_dir(ECHO, GPIO_IN);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    while (true)
    {
        float distance = get_distance();

        printf("Distance = %.2f cm\n",
               distance);

        if(distance <= 5.0)
        {
            gpio_put(BUZZER, 1);
        }
        else
        {
            gpio_put(BUZZER, 0);
        }

        sleep_ms(500);
    }
}