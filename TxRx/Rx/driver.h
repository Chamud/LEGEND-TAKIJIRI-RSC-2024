#ifndef driver_h
#define driver_h

class driver {
public:
    driver();
    driver(int pinA, int pinB);
    void run(int val);
private:
    int pinA;
    int pinB;
};

#endif