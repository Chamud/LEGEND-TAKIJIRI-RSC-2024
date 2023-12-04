// Joystick.h

#ifndef JOYSTICK_H
#define JOYSTICK_H

class Joystick {
public:
    Joystick(int pinHorizontal, int pinVertical);
    int getHorizontal();
    int getVertical();
    void readHorizontal();
    void readVertical();

private:
    int pinHorizontal;
    int pinVertical;
    int valHorizontal;
    int valVertical;
};

#endif
