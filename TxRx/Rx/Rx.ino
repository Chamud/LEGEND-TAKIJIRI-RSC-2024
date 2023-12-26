#include "WifiHandler.h"

// REPLACE WITH desired Loop delay
#define ping 1000
// REPLACE WITH SENDER MAC Address
uint8_t senderMacAddress[] = {0x08, 0x3a, 0xf2, 0x2d, 0x48, 0x18};

WiFiHandler wifiHandler;

int16_t arr[5] = {0,0,0,0,0};

void setup() {
    Serial.begin(115200);
    
    if (!wifiHandler.init()) {
        Serial.println("WiFi initialization failed");
        return;
    }
}

void loop() {
    delay(ping);    
}
