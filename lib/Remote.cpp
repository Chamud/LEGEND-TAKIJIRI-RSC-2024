#include <Arduino.h>
#include "Remote.h"

Remote::Remote(int j1X, int j1Y,
               int j2X, 
               int j3X, int j3Y,
               int j4X, 
               int j5X, 
               int j6Y, 
               int s1Pin, 
               int s2Pin, 
               int s3Pin)
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

Remote::Remote()
    : joystick1(0, 0), 
      joystick2(0, 0),  
      joystick3(0, 0),  
      joystick4(0, 0),  
      joystick5(0, 0),  
      joystick6(0, 0),  
      s1(0),           
      s2(0),            
      s3(0) {} 

void Remote::readValues() {
    
    joystick1.readHorizontal();
    joystick1.readVertical();

    joystick2.readHorizontal();

    joystick3.readHorizontal();
    joystick3.readVertical();

    joystick4.readHorizontal();
    joystick5.readHorizontal();
    
    joystick6.readVertical();

    s1.readOn();
    s2.readOn();
    s3.readOn();
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

void Remote::printValues() {
    Serial.println("\nRemote Object Values:");
    Serial.println("===================================");
    Serial.println("Joystick\tHorizontal\tVertical");
    Serial.println("-----------------------------------");
    printJoystickValues("Joystick1", joystick1);
    printJoystickValues("Joystick2", joystick2);
    printJoystickValues("Joystick3", joystick3);
    printJoystickValues("Joystick4", joystick4);
    printJoystickValues("Joystick5", joystick5);
    printJoystickValues("Joystick6", joystick6);
    Serial.println("-----------------------------------");
    Serial.println("Switch\t\tState");
    Serial.println("-----------------------------------");
    printSwitchValues("Switch1", s1);
    printSwitchValues("Switch2", s2);
    printSwitchValues("Switch3", s3);
    Serial.println("===================================");
}

void Remote::printJoystickValues(const char* name, Joystick& joystick) {
    Serial.print(name);
    Serial.print("\t");
    Serial.print(joystick.getHorizontal());
    Serial.print("\t\t");
    Serial.println(joystick.getVertical());
}

void Remote::printSwitchValues(const char* name, Switch& switchObj) {
    Serial.print(name);
    Serial.print("\t\t");
    Serial.println(switchObj.isOn() ? "ON" : "OFF");
}