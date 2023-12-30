#ifndef driver_h
#define driver_h

class driver {
public:
    driver();
    static void go(int val);
    static void rev(int val);
    static void breaks();
    static void rest();
};

#endif