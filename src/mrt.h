/*
 * mrt.h
 *
 *  Created on: 2014/10/15
 *      Author: Tetsuya Suzuki
 */

#ifndef __MRT_H_
#define __MRT_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MRT_MS(ms) (SystemCoreClock / 1000 * ms)
#define MRT_US(us) (SystemCoreClock / 1000000 * us)

inline void mrtRepeatStart();
inline void mrtRepeatStop();

void mrtSetup(void);
void mrtRepeat(uint32_t clks, void(*pFunc)(void));
void mrtOneshot(uint32_t clks, void(*pFunc)(void));
inline void mrtWait(uint32_t clks);
inline void mrtSetupSleep(void);
void mrtSleep(uint32_t clks);

#ifdef __cplusplus
}
#endif
#endif /* __MRT_H_ */
