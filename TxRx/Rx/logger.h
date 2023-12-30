#ifndef logger_h
#define logger_h

#include <Arduino.h>

class logger {
public:
    logger();
    static void log(String text, int level);
    static void logln(String text, int level);
};
extern logger Logger;
#endif