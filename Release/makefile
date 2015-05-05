################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: I2C_OSC_1Hz.axf

# Tool invocations
I2C_OSC_1Hz.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -L"/Users/kodera2t/LPCXpresso/workspace/lpc_chip_8xx/Release" -Xlinker -Map="I2C_OSC_1Hz.map" -Xlinker --gc-sections -mcpu=cortex-m0 -mthumb -T "osc810_Release.ld" -o "I2C_OSC_1Hz.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) I2C_OSC_1Hz.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "I2C_OSC_1Hz.axf" ; arm-none-eabi-objcopy -O ihex I2C_OSC_1Hz.axf I2C_OSC_1Hz.hex ; # checksum -d I2C_OSC_1Hz.bin
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
