#include "WifiHandler.h"

// REPLACE WITH desired Loop delay
#define ping 50
// REPLACE WITH SENDER MAC Address
uint8_t senderMacAddress[] = {0x08, 0x3a, 0xf2, 0x2d, 0x48, 0x18};

WiFiHandler wifiHandler;

int16_t arr[5] = {0,0,0,0,0};

//const int ledPins[] = {2, 4, 5, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33};
//const int ledPins[] = {2, 4, 5,             15, 16, 17, 18, 19};
//const int ledPins[] = {                                         21, 22, 23};
const int ledPins[] = {         12, 13, 14,                                 25, 26, 27, 32, 33};                                          
const int numPins = sizeof(ledPins) / sizeof(ledPins[0]);
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
    Serial.begin(115200);
    
    if (!wifiHandler.init()) {
        Serial.println("WiFi initialization failed");
        return;
    }
        for (int i = 0; i < numPins; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop() {
    delay(ping);  
    for (int i = 0; i < numPins; i++) {
        Serial.println("------------------------------------------");
        Serial.println(ledPins[i]);
        ledcSetup(ledChannel, freq, resolution);
        ledcAttachPin(ledPins[i], ledChannel);
        for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){
        // changing the LED brightness with PWM
            ledcWrite(ledChannel, dutyCycle);
            delay(15); 
        }  
        ledcWrite(ledChannel, 0);
        ledcDetachPin(ledPins[i]);
    }
}
