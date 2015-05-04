################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc8xx.c \
../src/crp.c \
../src/i2cs.c \
../src/main.c \
../src/mrt.c \
../src/mtb.c \
../src/sysinit.c 

OBJS += \
./src/cr_startup_lpc8xx.o \
./src/crp.o \
./src/i2cs.o \
./src/main.o \
./src/mrt.o \
./src/mtb.o \
./src/sysinit.o 

C_DEPS += \
./src/cr_startup_lpc8xx.d \
./src/crp.d \
./src/i2cs.d \
./src/main.d \
./src/mrt.d \
./src/mtb.d \
./src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DNDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -D__USE_LPCOPEN -DNO_BOARD_LIB -D__LPC8XX__ -I"/Users/kodera2t/LPCXpresso/workspace/lpc_chip_8xx/inc" -Os -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


