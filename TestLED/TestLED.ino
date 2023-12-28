// Filename: TestLED.ino

const int ledPins[] = {2, 4, 5, 12, 13, 14, 15, 16, 17, 18, 19, 21, 22, 23, 25, 26, 27, 32, 33};
const int numPins = sizeof(ledPins) / sizeof(ledPins[0]);

void setup() {
  for (int i = 0; i < numPins; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < numPins; i++) {
    Serial.println("------------------------------------------");
    Serial.println(i);
    digitalWrite(ledPins[i], HIGH); // Turn on LED
    delay(1000);                     // Wait for 1 second
    digitalWrite(ledPins[i], LOW);  // Turn off LED
    delay(100);                      // Brief delay between LEDs
  }
}
