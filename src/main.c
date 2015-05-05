/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/


// TODO: insert other include files here
#include "chip.h"
#include "mrt.h"
#include "i2cs.h"


// TODO: insert other definitions and declarations here
#define I2C_ADDR (0x14)

void changeFreq(uint8_t rxn, uint8_t txn){
	uint32_t fr;
//	uint32_t sw;
	if(rxn){
//		fr=1000*(i2csRxBuf[0]);///frequency inside
		fr=(i2csRxBuf[1]<<8) | i2csRxBuf[0];
		Chip_SCTPWM_SetRate(LPC_SCT, fr);
		Chip_SCTPWM_SetDutyCycle(LPC_SCT, 1, Chip_SCTPWM_PercentageToTicks(LPC_SCT, 50));
		Chip_SCTPWM_Start(LPC_SCT);
	}

}
//void PININT7_IRQHandler(void){
//	Chip_PININT_ClearIntStatus(LPC_PININT, PININTCH7);
//
//	mrtOneshot(MRT_MS(100), changeFreq);
//}


int main(void) {
#if defined (__USE_LPCOPEN)
//#if !defined(NO_BOARD_LIB)
//    // Read clock settings and update SystemCoreClock variable
//    SystemCoreClockUpdate();
//    // Set up and initialize all required blocks and
//    // functions related to the board hardware
//    Board_Init();
//    // Set the LED to the state of "On"
//    Board_LED_Set(0, true);
//#endif
#endif


    // TODO: insert code here
	SystemCoreClockUpdate();

	//Pin assign
	Chip_Clock_EnablePeriphClock(SYSCTL_CLOCK_SWM);
	Chip_SWM_DisableFixedPin(SWM_FIXED_SWCLK);
	Chip_SWM_DisableFixedPin(SWM_FIXED_SWDIO);
	Chip_SWM_DisableFixedPin(SWM_FIXED_RST);
 	Chip_SWM_MovablePinAssign(SWM_I2C_SDA_IO, 0);
	Chip_SWM_MovablePinAssign(SWM_I2C_SCL_IO, 1);
	//Chip_SWM_MovablePinAssign(SWM_CTIN_0_I, 4);
	//Chip_Clock_DisablePeriphClock(SYSCTL_CLOCK_SWM);
// 4-pin is set as output
//	Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 0, 2);
	Chip_SWM_MovablePinAssign(SWM_CTOUT_0_O, 2);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 0, 3);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 0, 4);
	Chip_GPIO_SetPinDIROutput(LPC_GPIO_PORT, 0, 5);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 3);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 4);
	Chip_GPIO_SetPinOutLow(LPC_GPIO_PORT, 0, 5);


	//I2C setup
	i2csSetupCallback(changeFreq);
	i2csSetup(I2C_ADDR, 2, 0);

	//SCT setup
	Chip_SCTPWM_Init(LPC_SCT);
	Chip_SCTPWM_SetRate(LPC_SCT, 1000);
	Chip_SCTPWM_SetDutyCycle(LPC_SCT, 1, Chip_SCTPWM_PercentageToTicks(LPC_SCT, 50));
	Chip_SCTPWM_SetOutPin(LPC_SCT, 1, 0);
	Chip_SCTPWM_Start(LPC_SCT);


	mrtSetup();

//	Chip_SYSCTL_SetPinInterrupt(7, 3);
//	Chip_PININT_SetPinModeEdge(LPC_PININT, PININTCH7);
//	Chip_PININT_EnableIntHigh(LPC_PININT, PININTCH7);
//	Chip_PININT_EnableIntLow(LPC_PININT, PININTCH7);
//	NVIC_EnableIRQ(PININT7_IRQn);


	while(1)
		__WFI();
    return 0 ;
}
