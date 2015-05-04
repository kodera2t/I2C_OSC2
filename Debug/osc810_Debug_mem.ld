/*
 * GENERATED FILE - DO NOT EDIT
 * (c) Code Red Technologies Ltd, 2008-2015
 * (c) NXP Semiconductors 2013-2015
 * Linker script memory definitions
 * Created from LinkMemoryTemplate
 * By LPCXpresso v6.1.4 [Build 194] [2014-01-15]  on Mon May 04 17:35:48 JST 2015)
*/

MEMORY
{
  /* Define each memory region */
  MFlash4 (rx) : ORIGIN = 0x0, LENGTH = 0x1000 /* 4K bytes */
  RamLoc1 (rwx) : ORIGIN = 0x10000000, LENGTH = 0x400 /* 1K bytes */


}
  /* Define a symbol for the top of each memory region */
  __top_MFlash4 = 0x0 + 0x1000;
  __top_RamLoc1 = 0x10000000 + 0x400;



