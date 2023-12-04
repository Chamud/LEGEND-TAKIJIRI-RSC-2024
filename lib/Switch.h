// Switch.h

#ifndef SWITCH_H
#define SWITCH_H

class Switch {
public:
    Switch(int pin);
    bool isOn();
    void readOn();

private:
    int pin;
    bool valPin;
};

#endif
