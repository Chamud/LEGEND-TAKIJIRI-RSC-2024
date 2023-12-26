// Data.h
#ifndef DATA_H
#define DATA_H

class Data {
public:
  Data();
  Data(int d1, int d2);
  
  int getData1();
  void setData1(int d1);

  int getData2();
  void setData2(int d2);
  void printData();

private:
  int data1;
  int data2;
};

#endif
