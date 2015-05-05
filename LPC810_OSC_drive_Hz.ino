#include <Wire.h>
#define OSC 0x14
int i,frequency,data1,data2,data3;


void setup() {
  frequency=1000;
  data1=frequency>>8;
  data2=frequency&0xff;
    Wire.begin() ;
    i2c_write(OSC, data2, data1);
}

void loop() {
  for(i=1;i<7000;i=i+10){
//  data1=i>>16;
  data1=i>>8;
  data2=i&0xff;
    i2c_write(OSC, data2, data1);
  }
    for(i=7000;i>0;i=i-10){
//  data1=i>>16;
  data1=i>>8;
  data2=i&0xff;
    i2c_write(OSC, data2, data1);
  }
}


void i2c_write(int device_address, int value1, int value2)
{
  Wire.beginTransmission(device_address);
  Wire.write(value1);
    delay(5);
  Wire.write(value2);
    delay(5);
  Wire.endTransmission();
}
