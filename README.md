# I2C_OSC2
Sometimes simple signal generator is required for some experiment or circuit and for such purpose generally famous 555 is widely utilised but if you get to know and make this simple device, your 555 in parts box might be fired..! 

Usage is quite simple, along my arduino sketch, 

i2c_write(0x14,5) 

will generate 5 kHz squared-wave and 0x14 is the I2C address of programmed LPC810. (you can change if needed) 

The source code and driving arduino sketch of this very cost effective and useful device is fully released on github 

Have fun!
