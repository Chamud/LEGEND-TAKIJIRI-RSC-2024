// Joystick.cpp

#include "Joystick.h"
#include "Arduino.h"

Joystick::Joystick(int pinHorizontal, int pinVertical) {
    this->pinHorizontal = pinHorizontal;
    this->pinVertical = pinVertical;
    
    if (pinHorizontal != 0) {
        pinMode(pinHorizontal, INPUT);
    }
    
    if (pinVertical != 0) {
        pinMode(pinVertical, INPUT);
    }
}

int Joystick::getHorizontal() {
    if (pinHorizontal == 0) {
        return 0;
    }
    return analogRead(pinHorizontal);
}

int Joystick::getVertical() {
    if (pinVertical == 0) {
        return 0;
    }
    return analogRead(pinVertical);
}
