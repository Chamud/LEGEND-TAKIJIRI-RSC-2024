#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "PCA9547.h"
PCA9547 i2cSelect;

unsigned int ch = 0;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

#define OLED_RESET    -1
#define SCREEN_ADDRESS 0x3C

int count = 0;

Adafruit_SSD1306 display1(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_SSD1306 display2(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void display1init(){
  if(!display1.begin(SSD1306_PAGEADDR, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display1.display();
}
void display2init(){
  if(!display2.begin(SSD1306_PAGEADDR, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  display2.display();
}

void display1show(String text){
  display1.clearDisplay();
  display1.setTextSize(1);
  display1.setTextColor(SSD1306_WHITE);
  display1.setCursor(0,0);
  display1.print(text);
  display1.display();
}

void display2show(String text){
  display2.clearDisplay();
  display2.setTextSize(1);
  display2.setTextColor(SSD1306_WHITE);
  display2.setCursor(0,0);
  display2.print(text);
  display2.display();
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  i2cSelect.attach(Wire);
  
  i2cSelect.enable(0);
  display1init();
  
  i2cSelect.enable(1);
  display2init();

  delay(500);
}

void loop() {
  i2cSelect.enable(0);
  display1show("Display 1 : " + (String)count);
  
  i2cSelect.enable(1);
  display2show("Display 2 : " + (String)count);

  
  delay(500);
  count++;
}
