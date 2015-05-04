################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/cr_startup_lpc8xx.c \
../src/crp.c \
../src/mrt.c \
../src/mtb.c \
../src/osc810.c \
../src/sysinit.c 

OBJS += \
./src/cr_startup_lpc8xx.o \
./src/crp.o \
./src/mrt.o \
./src/mtb.o \
./src/osc810.o \
./src/sysinit.o 

C_DEPS += \
./src/cr_startup_lpc8xx.d \
./src/crp.d \
./src/mrt.d \
./src/mtb.d \
./src/osc810.d \
./src/sysinit.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DDEBUG -D__CODE_RED -DCORE_M0PLUS -D__MTB_DISABLE -D__MTB_BUFFER_SIZE=256 -D__USE_LPCOPEN -DNO_BOARD_LIB -D__LPC8XX__ -I"/Users/kodera2t/Documents/LPCXpresso_6.1.4/workspace/lpc_chip_8xx/inc" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m0 -mthumb -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


