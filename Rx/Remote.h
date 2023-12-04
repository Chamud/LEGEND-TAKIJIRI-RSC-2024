#ifndef REMOTE_H
#define REMOTE_H

#include "Joystick.h"
#include "Switch.h"

class Remote {
public:
    Remote( int j1X, int j1Y,
            int j2X, 
            int j3X, int j3Y,
            int j4X, 
            int j5X, 
            int j6Y, 
            int s1Pin, 
            int s2Pin, 
            int s3Pin);

    Remote();
    void initialize();
    Remote readValues();
    void printValues();

    Joystick& getJoystick1();
    Joystick& getJoystick2();
    Joystick& getJoystick3();
    Joystick& getJoystick4();
    Joystick& getJoystick5();
    Joystick& getJoystick6();
    Switch& getSwitch1();
    Switch& getSwitch2();
    Switch& getSwitch3();

private:
    Joystick joystick1;
    Joystick joystick2;
    Joystick joystick3;
    Joystick joystick4;
    Joystick joystick5;
    Joystick joystick6;
    Switch s1;
    Switch s2;
    Switch s3;
    void printJoystickValues(const char* name, Joystick& joystick);
    void printSwitchValues(const char* name, Switch& switchObj);
};

#endif
