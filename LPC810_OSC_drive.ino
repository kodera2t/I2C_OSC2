#include <Wire.h>
#define OSC 0x14
int i;
void setup() {
    Wire.begin() ;
}

void loop() {
  for(i=1;i<50;i++){
i2c_write(OSC,i);
delay(1000);
  }
}

void i2c_write(int device_address, int memory_address)
{
  Wire.beginTransmission(device_address);
  Wire.write(memory_address);
  Wire.endTransmission();
  delay(3);
}


