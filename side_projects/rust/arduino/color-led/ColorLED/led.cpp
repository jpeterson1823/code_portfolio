#include "Arduino.h"
#include "led.hpp"

ColorLED::ColorLED(int rpin, int bpin, int gpin)
    : rpin(rpin), bpin(bpin), gpin(gpin) {
    pinMode(rpin, OUTPUT);
    pinMode(bpin, OUTPUT);
    pinMode(gpin, OUTPUT);
}

void ColorLED::setColor(Color color) {
    analogWrite(this->rpin, color.red);
    analogWrite(this->bpin, color.blue);
    analogWrite(this->gpin, color.green);
}

void ColorLED::off() {
    digitalWrite(this->rpin, LOW);
    digitalWrite(this->bpin, LOW);
    digitalWrite(this->gpin, LOW);
}
