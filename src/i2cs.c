/*
 * i2cs.c
 *
 *  Created on: 2015/01/27
 *      Author: Tetsuya Suzuki
 */

#include "chip.h"

uint8_t i2csRxBuf[16];
uint8_t i2csTxBuf[16];
uint8_t i2csRxCount;
uint8_t i2csTxCount;
uint8_t i2csRxLimit;
uint8_t i2csTxLimit;

void (*i2csCallback)(uint8_t, uint8_t) = NULL;

void i2csSetupCallback(void (*pFunc)(uint8_t, uint8_t)) {
	i2csCallback = pFunc;
}

void i2csSetup(uint8_t addr, uint8_t rxn, uint8_t txn){
	i2csRxLimit = rxn;
	i2csTxLimit = txn;

	Chip_I2C_Init(LPC_I2C);
	Chip_I2CS_SetSlaveAddr(LPC_I2C, 0, addr);
	Chip_I2CS_EnableSlaveAddr(LPC_I2C, 0);

	Chip_I2CS_ClearStatus(LPC_I2C, I2C_STAT_SLVDESEL);
	Chip_I2C_EnableInt(LPC_I2C, I2C_INTENSET_SLVPENDING | I2C_INTENSET_SLVDESEL);
	Chip_I2CS_Enable(LPC_I2C);
	NVIC_EnableIRQ(I2C_IRQn);
}

void slaveStart(uint8_t adrs){
	i2csRxCount = 0;
	i2csTxCount = 0;
}

uint8_t slaveSend(uint8_t *data){
	*data = i2csTxBuf[i2csTxCount++];
	if(i2csTxCount > i2csTxLimit)
		return 0;
	return -1;
}

uint8_t slaveRecv(uint8_t data){
	i2csRxBuf[i2csRxCount++] = data;
	if(i2csRxCount > i2csRxLimit)
		return -1;
	return 0;
}

void slaveDone(void){
	if (i2csCallback != NULL)
		i2csCallback(i2csRxCount, i2csTxCount);
}

const static I2CS_XFER_T i2csCallBacks = {
	&slaveStart,
	&slaveSend,
	&slaveRecv,
	&slaveDone
};

void I2C_IRQHandler(void){
	uint32_t state = Chip_I2C_GetPendingInt(LPC_I2C);

	while (state & (I2C_INTENSET_SLVPENDING | I2C_INTENSET_SLVDESEL)) {
		Chip_I2CS_XferHandler(LPC_I2C, &i2csCallBacks);
		state = Chip_I2C_GetPendingInt(LPC_I2C);
	}
}
