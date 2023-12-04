// Switch.cpp

#include "Switch.h"
#include "Arduino.h"

Switch::Switch(int pin) {
    this->pin = pin;
}

bool Switch::isOn() {
    return (pin != 0); 
}
