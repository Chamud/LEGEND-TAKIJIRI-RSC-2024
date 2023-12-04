// Joystick.cpp

#include "Joystick.h"
#include "Arduino.h"

Joystick::Joystick(int pinHorizontal, int pinVertical) {
    this->pinHorizontal = pinHorizontal;
    this->pinVertical = pinVertical;
    this->valHorizontal = 0;
    this->valVertical = 0;
    
    if (pinHorizontal != 0) {
        pinMode(pinHorizontal, INPUT);
    }
    
    if (pinVertical != 0) {
        pinMode(pinVertical, INPUT);
    }
}

void Joystick::readHorizontal() {
    if (pinHorizontal != 0) {
        valHorizontal = analogRead(pinHorizontal);
    }
}

void Joystick::readVertical() {
    if (pinVertical != 0) {
        valVertical = analogRead(pinVertical);
    }
    
}

int Joystick::getHorizontal() {
    return valHorizontal;
}

int Joystick::getVertical() {
    return valVertical;
}
