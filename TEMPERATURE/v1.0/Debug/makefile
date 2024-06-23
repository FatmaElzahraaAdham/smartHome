################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Temperature_smartHome.lss \

FLASH_IMAGE += \
Temperature_smartHome.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Temperature_smartHome.elf secondary-outputs

# Tool invocations
Temperature_smartHome.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Temperature_smartHome.map -mmcu=atmega32 -o "Temperature_smartHome.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Temperature_smartHome.lss: Temperature_smartHome.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Temperature_smartHome.elf  >"Temperature_smartHome.lss"
	@echo 'Finished building: $@'
	@echo ' '

Temperature_smartHome.hex: Temperature_smartHome.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Temperature_smartHome.elf  "Temperature_smartHome.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Temperature_smartHome.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Temperature_smartHome.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Temperature_smartHome.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
