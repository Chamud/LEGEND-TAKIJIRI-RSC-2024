// Switch.cpp

#include "Switch.h"
#include "Arduino.h"

Switch::Switch(int pin) {
    this->pin = pin;
    this-> valPin = false;
    pinMode(pin, INPUT);
}

bool Switch::isOn() {
    return valPin; 
}

void Switch::readOn() {
    valPin = digitalRead(pin) == HIGH; ;
}
