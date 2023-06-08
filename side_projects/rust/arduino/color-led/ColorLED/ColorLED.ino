#include "led.hpp"

ColorLED led(8, 9, 10);

void setup() {
}

void loop() {
    led.setColor(Color {255, 255, 255});
    delay(500);
    led.off();
    delay(100);
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    delay(500);
    led.off();
    delay(100);
}
