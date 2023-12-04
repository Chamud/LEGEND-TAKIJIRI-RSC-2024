// Joystick.cpp

#include "Joystick.h"
#include "Arduino.h"

Joystick::Joystick(int pinHorizontal, int pinVertical) {
    this->pinHorizontal = pinHorizontal;
    this->pinVertical = pinVertical;
}

int Joystick::getHorizontal() {
    return pinHorizontal;
}

int Joystick::getVertical() {
    return pinVertical;
}
