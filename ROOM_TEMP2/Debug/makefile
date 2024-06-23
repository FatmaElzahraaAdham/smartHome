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
control_AnotherRoom_temp2.lss \

FLASH_IMAGE += \
control_AnotherRoom_temp2.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: control_AnotherRoom_temp2.elf secondary-outputs

# Tool invocations
control_AnotherRoom_temp2.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,control_AnotherRoom_temp2.map -mmcu=atmega32 -o "control_AnotherRoom_temp2.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

control_AnotherRoom_temp2.lss: control_AnotherRoom_temp2.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S control_AnotherRoom_temp2.elf  >"control_AnotherRoom_temp2.lss"
	@echo 'Finished building: $@'
	@echo ' '

control_AnotherRoom_temp2.hex: control_AnotherRoom_temp2.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex control_AnotherRoom_temp2.elf  "control_AnotherRoom_temp2.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: control_AnotherRoom_temp2.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 control_AnotherRoom_temp2.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) control_AnotherRoom_temp2.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
