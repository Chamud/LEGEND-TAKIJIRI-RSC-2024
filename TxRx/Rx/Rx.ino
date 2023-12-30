#include "WifiHandler.h"
#include "driver.h"

// REPLACE WITH desired Loop delay
#define ping 50
// REPLACE WITH SENDER MAC Address
uint8_t senderMacAddress[] = {0x08, 0xd1, 0xf9, 0xeb, 0x35, 0x58};

WiFiHandler wifiHandler;

int loglevel = 4;

int16_t arr[4] = {0,0,0,0};

#define M1A 12
#define M1B 13
#define M2A 14
#define M2B 25
#define M3A 26
#define M3B 27
#define M4A 32
#define M4B 33
driver M1;
driver M2;
driver M3;
driver M4;

void setup() {
    Serial.begin(115200);
    
    if (!wifiHandler.init()) {
        Serial.println("WiFi initialization failed");
        return;
    }
    pinMode(M1A, OUTPUT);
    pinMode(M1B, OUTPUT);
    M1 = driver(M1A, M1B);

    pinMode(M2A, OUTPUT);
    pinMode(M2B, OUTPUT);
    M2 = driver(M2A, M2B);

    pinMode(M3A, OUTPUT);
    pinMode(M3B, OUTPUT);
    M3 = driver(M3A, M3B);

    pinMode(M4A, OUTPUT);
    pinMode(M4B, OUTPUT);
    M4 = driver(M4A, M4B);
}

void loop() {
    delay(ping);  
}
