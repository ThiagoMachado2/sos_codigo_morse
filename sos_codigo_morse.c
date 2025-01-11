#include "pico/stdlib.h"

#define LED_PIN 11

void blink_led(int duration) {
    gpio_put(LED_PIN, 1);
    sleep_ms(duration);
    gpio_put(LED_PIN, 0);
    sleep_ms(125);
}

void sos() {
    // Sequência de pontos (...)
    for (int i = 0; i < 3; i++) blink_led(200);

    sleep_ms(250);

    // Sequência de traços (---)
    for (int i = 0; i < 3; i++) blink_led(800);

    sleep_ms(250);

    for (int i = 0; i < 3; i++) blink_led(200);

    sleep_ms(3000);
}

int main() {
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    while (true) {
        sos();
    }

    return 0;
}