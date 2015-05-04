/*
 * mrt.c
 *
 *  Created on: 2014/10/15
 *      Author: Tetsuya Suzuki
 */

#include "chip.h"

void (*pfRepeat)(void) = NULL;
void (*pfOneshot)(void) = NULL;
volatile bool sleeping;

void MRT_IRQHandler(void){
	uint32_t intf;

	intf = Chip_MRT_GetIntPending();
	Chip_MRT_ClearIntPending(intf);

	if(intf & MRT0_INTFLAG)
		if(pfRepeat != NULL)
			pfRepeat();

	if(intf & MRT2_INTFLAG)
		if(pfOneshot != NULL)
			pfOneshot();

	if(intf & MRT3_INTFLAG)
		sleeping = false;
}

void mrtSetup(){
	Chip_MRT_Init();
	Chip_MRT_SetMode(LPC_MRT_CH0, MRT_MODE_REPEAT);
	Chip_MRT_SetMode(LPC_MRT_CH2, MRT_MODE_ONESHOT);
	Chip_MRT_SetMode(LPC_MRT_CH3, 2 << 1);
	Chip_MRT_SetEnabled(LPC_MRT_CH2);
	Chip_MRT_SetEnabled(LPC_MRT_CH3);

	NVIC_EnableIRQ(MRT_IRQn);
}

void mrtRepeat(uint32_t clks, void(*pFunc)(void)){
	Chip_MRT_SetInterval(LPC_MRT_CH0, clks);
	pfRepeat = pFunc;

	Chip_MRT_SetEnabled(LPC_MRT_CH0);
}

inline void mrtRepeatStart(){
	Chip_MRT_SetEnabled(LPC_MRT_CH0);
}

inline void mrtRepeatStop(){
	Chip_MRT_SetDisabled(LPC_MRT_CH0);
}

void mrtOneshot(uint32_t clks, void(*pFunc)(void)){
	Chip_MRT_SetInterval(LPC_MRT_CH2, clks);
	pfOneshot = pFunc;
}

inline void mrtWait(uint32_t clks){
	Chip_MRT_SetInterval(LPC_MRT_CH3, clks);
}

inline void mrtSetupSleep(){
	Chip_MRT_SetMode(LPC_MRT_CH3, MRT_MODE_ONESHOT);
}

void mrtSleep(uint32_t clks){
	sleeping = true;
	Chip_MRT_SetInterval(LPC_MRT_CH3, clks);

	while(sleeping) __WFI();
}
