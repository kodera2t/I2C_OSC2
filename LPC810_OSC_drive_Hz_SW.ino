#include <Wire.h>
#define OSC 0x14
unsigned int i,j,base_frequency,frequency,data1,data2,data3,duty_ratio,param;


void setup() {
  base_frequency=65000;
  frequency=2000;
  data1=base_frequency>>8;
  data2=base_frequency&0xff;
  duty_ratio=50;
    Wire.begin() ;
    i2c_write(OSC, data2, data1, duty_ratio);
delay(1000);
}

void loop() {
  /// changing frequency from 100 Hz to 5 kHz
  for(j=0;j<10;j++){
  for(i=100;i<7000;i=i+10){
  data1=i>>8;
  data2=i&0xff;
    i2c_write(OSC, data2, data1, duty_ratio);
  }
    for(i=7000;i>100;i=i-10){
  data1=i>>8;
  data2=i&0xff;
    i2c_write(OSC, data2, data1, duty_ratio);
  }
  }
delay(1000);/// one second break
/// changing duty ratio from 10 to 90 % at at 2 kHz
  for(j=0;j<8;j++){
  for(i=10;i<90;i=i+10){
    frequency=1000;
  data1=frequency>>8;
  data2=frequency&0xff;
  delay(200);
    i2c_write(OSC, data2, data1, i);
  }
  for(i=90;i>0;i=i-10){
    frequency=2000;
  data1=frequency>>8;
  data2=frequency&0xff;
  delay(200);
    i2c_write(OSC, data2, data1, i);
  }
  }
  j=0;
/// changing duty ratio from 1 to 100 % by 10% step for 30kHz, at .. as fast as possible
// This part will generate triangle wave for pwm modulation frequency
  while(j<1000){
  for(i=1;i<100;i=i+20){
  base_frequency=30000;
  data1=base_frequency>>8;
  data2=base_frequency&0xff;
  i2c_write(OSC, data2, data1, i);
  }
  for(i=100;i>0;i=i-20){
  base_frequency=30000;
  data1=base_frequency>>8;
  data2=base_frequency&0xff;
    i2c_write(OSC, data2, data1, i);
  }
j++;  
}
delay(1000); /// one second break
j=0;
/// changing duty ratio from 1 to 100 % by 10 % step for 30 kHz, at .. as fast as possible
/// This part will generate saw-tooth waveform for pwm modulation frequency with doubled to above.
  while(j<1000){
  for(i=1;i<100;i=i+20){
    base_frequency=30000;
  data1=base_frequency>>8;
  data2=base_frequency&0xff;
    i2c_write(OSC, data2, data1, i);
  }
j++;  
}
delay(1000);/// one second break

}


void i2c_write(int device_address, int value1, int value2, int value3)
{
  Wire.beginTransmission(device_address);
  Wire.write(value1);
    //delay(1);
  Wire.write(value2);
    //delay(1);
  Wire.write(value3);
    //delay(1);
  Wire.endTransmission();
}
