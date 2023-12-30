#include <Arduino.h>
#include "WifiHandler.h"

// REPLACE WITH desired Loop delay
#define ping 50
// REPLACE WITH RECEIVER MAC Address 90:38:0C:ED:79:58
uint8_t broadcastAddress[] = {0x90, 0x38, 0x0c, 0xed, 0x79, 0x58};

WifiHandler wifiHandler(broadcastAddress);

int16_t arr[8] = {12,0,-2505,4005};

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
    int sensorValue = analogRead(34);
    arr[0] = sensorValue * 2 - 4095;
    wifiHandler.sendData(arr);
    delay(ping);
}
