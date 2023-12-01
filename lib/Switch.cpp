// Switch.cpp

#include "Switch.h"
#include "Arduino.h"

Switch::Switch(int pin) {
    this->pin = pin;
    pinMode(pin, INPUT);
}

bool Switch::isOn() {
    return digitalRead(pin) == HIGH; // On when High
}
