#include <Arduino.h>
#include "WifiHandler.h"

// REPLACE WITH desired Loop delay
#define ping 500
// REPLACE WITH RECEIVER MAC Address 90:38:0C:ED:79:58
uint8_t broadcastAddress[] = {0x90, 0x38, 0x0c, 0xed, 0x79, 0x58};

#define X1 34
#define Y1 35
#define X2 32
#define Y2 33
#define B 25

WifiHandler wifiHandler(broadcastAddress);

int16_t arr[8] = {0,0,0,0,0};

void setup() {
    Serial.begin(115200);
    
    if (!wifiHandler.init()) {
        Serial.println("WiFi initialization failed");
        return;
    }else{
        Serial.println("WiFi initialization OK");
    }
    pinMode(B, INPUT);
}

void loop() {
    arr[0] = mapValues(analogRead(X1), 300, 3500);
    // arr[1] = mapValues(analogRead(Y1), 300, 3500);
    // arr[2] = mapValues(analogRead(X2), 300, 3500);
    // arr[3] = mapValues(analogRead(Y2), 300, 3500);
    arr[4] = digitalRead(B);
    wifiHandler.sendData(arr);
    delay(ping);
}


int mapValues(int input, int inMin, int inMax) {
    int outMin = -4095;
    int outMax = 4095;

    input = std::min(std::max(input, inMin), inMax);

    // Perform the linear mapping
    return static_cast<int>((input - inMin) * (static_cast<double>(outMax - outMin) / (inMax - inMin)) + outMin);
}
