#include "driver.h"
#include "Arduino.h"

//const int ledPins[] = {2, 4, 5, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33};

const int freq = 5000;
const int resolution = 12;

driver::driver(){

}

driver::driver(int pinA, int pinB){
    this->pinA = pinA;
    this->pinB = pinB;
 
    ledcSetup(pinA, freq, resolution);
    ledcSetup(pinB, freq, resolution);
    ledcAttachPin(pinA, pinA);
    ledcAttachPin(pinB, pinB);
}

void driver::run(int val){
    if(val>3){
        ledcWrite(pinA, val);
        ledcWrite(pinB, 0);
    }else if(val<-3){
        ledcWrite(pinA, 0);
        ledcWrite(pinB, -val);
    }else{
        ledcWrite(pinA, 0);
        ledcWrite(pinB, 0);
    }
}