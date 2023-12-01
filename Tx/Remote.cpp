#include "Remote.h"

Remote::Remote(int j1X, int j1Y,
               int j2X, 
               int j3X, int j3Y,
               int j4X, 
               int j5X, 
               int j6Y, 
               int s1Pin, int s2Pin, int s3Pin)
    : joystick1(j1X, j1Y),
      joystick2(j2X, 0),
      joystick3(j3X, j3Y),
      joystick4(j4X, 0),
      joystick5(j5X, 0),
      joystick6(0, j6Y),
      s1(s1Pin),
      s2(s2Pin),
      s3(s3Pin) {}

void Remote::initialize() {
    
}

void Remote::readValues() {
    joystick1.getHorizontal();
    joystick1.getVertical();

    joystick2.getHorizontal();

    joystick3.getHorizontal();
    joystick3.getVertical();

    joystick4.getHorizontal();
    joystick5.getHorizontal();
    
    joystick6.getVertical();

    s1.isOn();
    s2.isOn();
    s3.isOn();
}

Joystick& Remote::getJoystick1() {
    return joystick1;
}

Joystick& Remote::getJoystick2() {
    return joystick2;
}

Joystick& Remote::getJoystick3() {
    return joystick3;
}

Joystick& Remote::getJoystick4() {
    return joystick4;
}

Joystick& Remote::getJoystick5() {
    return joystick5;
}

Joystick& Remote::getJoystick6() {
    return joystick6;
}

Switch& Remote::getSwitch1() {
    return s1;
}

Switch& Remote::getSwitch2() {
    return s2;
}

Switch& Remote::getSwitch3() {
    return s3;
}
