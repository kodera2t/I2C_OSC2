#include <Wire.h>
#define OSC 0x14
#define LED2 0x15
int i;
void setup() {
    Wire.begin() ;
}

void loop() {
  for(i=1;i<50;i++){
i2c_write(OSC,i);
delay(1000);
  }
//i2c_write(OSC,2);
//delay(1000);
//i2c_write(OSC,3);
//delay(1000);
//i2c_write(OSC,4);
//delay(1000);
//i2c_write(OSC,5);
//delay(1000);
//i2c_write(OSC,6);
//delay(1000);
//i2c_write(OSC,7);
//delay(1000);
//i2c_write(OSC,8);
//delay(1000);
}

void i2c_write(int device_address, int memory_address)
{
  Wire.beginTransmission(device_address);
  Wire.write(memory_address);
  Wire.endTransmission();
  delay(3);
}


