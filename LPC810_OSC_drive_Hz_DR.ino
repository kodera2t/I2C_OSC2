#include <Wire.h>
#define OSC 0x14
unsigned int i,j,frequency,data1,data2,data3,duty_ratio;


void setup() {
  frequency=2000;
  data1=frequency>>8;
  data2=frequency&0xff;
  duty_ratio=40;
    Wire.begin() ;
    i2c_write(OSC, data2, data1, duty_ratio);

}

void loop() {
/// changing frequency from 100 Hz to 5 kHz
  for(j=0;j<4;j++){
  for(i=100;i<5000;i=i+10){
  data1=i>>8;
  data2=i&0xff;
    i2c_write(OSC, data2, data1, duty_ratio);
  }
    for(i=5000;i>0;i=i-10){
  data1=i>>8;
  data2=i&0xff;
    i2c_write(OSC, data2, data1, duty_ratio);
  }
  }

/// changing duty ratio from 10 to 90 % at at 2 kHz
  for(j=0;j<4;j++){
  for(i=10;i<90;i=i+10){
    frequency=2000;
  data1=frequency>>8;
  data2=frequency&0xff;
  delay(300);
    i2c_write(OSC, data2, data1, i);
  }
  for(i=90;i>0;i=i-10){
    frequency=2000;
  data1=frequency>>8;
  data2=frequency&0xff;
  delay(300);
    i2c_write(OSC, data2, data1, i);
  }
  }
}


void i2c_write(int device_address, int value1, int value2, int value3)
{
  Wire.beginTransmission(device_address);
  Wire.write(value1);
    delay(1);
  Wire.write(value2);
    delay(1);
  Wire.write(value3);
    delay(1);
  Wire.endTransmission();
}
