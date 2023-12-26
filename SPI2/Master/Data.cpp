// Data.cpp
#include "Data.h"
#include <Arduino.h>

Data::Data() {
  data1 = 0;
  data2 = 0;
}

Data::Data(int d1, int d2) {
  data1 = d1;
  data2 = d2;
}

int Data::getData1() {
  return data1;
}

void Data::setData1(int d1) {
  data1 = d1;
}

int Data::getData2() {
  return data2;
}

void Data::setData2(int d2) {
  data2 = d2;
}

void Data::printData() {
  Serial.print("Data1: ");
  Serial.print(data1);
  Serial.print("\tData2: ");
  Serial.println(data2);
}