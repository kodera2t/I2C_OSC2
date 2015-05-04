/*
 * i2cs.h
 *
 *  Created on: 2015/01/27
 *      Author: Tetsuya Suzuki
 */

#ifndef I2CS_H_
#define I2CS_H_
#ifdef __cplusplus
extern "C" {
#endif

extern uint8_t i2csRxBuf[16]; //matrix for receiving data
extern uint8_t i2csTxBuf[16]; //matrix for sending data

void i2csSetupCallback(void (*pFunc)(uint8_t rxn, uint8_t txn));//prototype for communication completion function
void i2csSetup(uint8_t addr, uint8_t rxn, uint8_t txn); // Setup I2C slave mode

#ifdef __cplusplus
}
#endif
#endif /* I2CS_H_ */
