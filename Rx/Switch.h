// Switch.h

#ifndef SWITCH_H
#define SWITCH_H

class Switch {
public:
    Switch(int pin);
    bool isOn();

private:
    int pin;
};

#endif
