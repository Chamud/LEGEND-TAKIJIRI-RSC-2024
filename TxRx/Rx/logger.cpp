#include "logger.h"

extern int loglevel;

logger::logger() {
}

void logger::log(String text, int level){
    if (level > loglevel) return;
    Serial.print(text);
}

void logger::logln(String text, int level){
    if (level > loglevel) return;
    Serial.println(text);
}