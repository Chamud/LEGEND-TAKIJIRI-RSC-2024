#include <Arduino.h>
#include "WifiHandler.h"

// REPLACE WITH desired Loop delay
#define ping 10
// REPLACE WITH RECEIVER MAC Address 90:38:0C:ED:79:58
 uint8_t broadcastAddress[] = {0x90, 0x38, 0x0c, 0xed, 0x79, 0x58};
//uint8_t broadcastAddress[] = {0xc4, 0xde, 0xe2, 0xc0, 0x7f, 0xdc};

#define X1 32 // 550, 2670, 4095
#define Y1 33 // 460, 2750, 4095
#define X2 35 // 510, 2750, 4095
#define Y2 34 // 
#define B 25
#define deadrange 350
int LED = 26;

WifiHandler wifiHandler(broadcastAddress);

int16_t arr[8] = {0,0,0,0,0};

void setup() {
    Serial.begin(115200);
    pinMode(LED, OUTPUT);

    if (!wifiHandler.init()) {
        Serial.println("WiFi initialization failed");
        return;
    }else{
        Serial.println("WiFi initialization OK");
    }
    pinMode(B, INPUT);
}

void loop() {
    // arr[0] = analogRead(X1);
    // arr[1] = analogRead(Y1);
    // arr[2] = analogRead(X2);
    // arr[3] = analogRead(Y2);
    arr[0] = mapValues(analogRead(X1), 550, 2670, 4095);

    arr[1] = mapValues(analogRead(Y1), 460, 2750, 4095);

    arr[2] = mapValues(analogRead(X2), 510, 2750, 4095);

    arr[3] = 0; // mapValues(analogRead(Y2), 0, 2000, 4095);

    arr[4] = digitalRead(B);
    
    wifiHandler.sendData(arr);
    delay(ping);
}


int mapValues(int input, int inMin, int inMid, int inMax) {
    int outMin = -4095;
    int outMid = 0;
    int outMax = 4095;

    if(input > inMid + deadrange){
        input = std::min(std::max(input, inMid), inMax);
        return static_cast<int>((input - inMid) * (static_cast<double>(outMax - outMid) / (inMax - inMid)) + outMid);
    }else if(input < inMid - deadrange){
        input = std::min(std::max(input, inMin), inMid);
        return static_cast<int>((input - inMin) * (static_cast<double>(outMid - outMin) / (inMid - inMin)) + outMin);
    }else return 0;

}
