#include <Arduino.h>
#include "WifiHandler.h"

// REPLACE WITH desired Loop delay
#define ping 2000
// REPLACE WITH RECEIVER MAC Address
uint8_t broadcastAddress[] = {0xc4, 0xde, 0xe2, 0xc0, 0x7f, 0xdc};

WifiHandler wifiHandler(broadcastAddress);

int16_t arr[5] = {12,56,76,255,34};

void setup() {
    Serial.begin(115200);
    
    if (!wifiHandler.init()) {
        Serial.println("WiFi initialization failed");
        return;
    }else{
        Serial.println("WiFi initialization OK");
    }
}

void loop() {
    wifiHandler.sendData(arr);
    delay(ping);
}
