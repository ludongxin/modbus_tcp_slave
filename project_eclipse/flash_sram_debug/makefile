################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include gen/hwconf/subdir.mk
-include gen/subdir.mk
-include compiler_arm-none-eabi-gcc/source/subdir.mk
-include EPC6450-AWI/source/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := EPC6450-AWI-MODBUS_TCP_SLAVE
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
EPC6450-AWI-MODBUS_TCP_SLAVE.hex \

SECONDARY_SIZE += \
EPC6450-AWI-MODBUS_TCP_SLAVE.siz \


# All Target
all: EPC6450-AWI-MODBUS_TCP_SLAVE.elf secondary-outputs

# Tool invocations
EPC6450-AWI-MODBUS_TCP_SLAVE.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU RISC-V Cross C++ Linker'
	riscv32-unknown-elf-g++ -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 -T D:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/../../../../../platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/hpm_flash_xip_sram.ld -nostartfiles -Xlinker --gc-sections -LD:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/../../../../../components/d4fcb97a-aw_modbus/libs/gcc-riscv32.debug -LD:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/../../../../../frameworks/64cf32e2-aworks_lp/components/kernel/awbus/libs/gcc-riscv32.debug -LD:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/../../../../../platforms/platform-hpm-aworks-lp/libs -LD:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/../../../../../components/24eb128d-aw_modbus_adapter/libs/gcc-riscv32.debug -LD:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/../.axioenvs/application.modbus_tcp_slave/build/gcc-riscv32.debug/lib -Wl,-Map,"EPC6450-AWI-MODBUS_TCP_SLAVE.map" -o "EPC6450-AWI-MODBUS_TCP_SLAVE.elf" -Wl,--start-group  $(OBJS) $(USER_OBJS) $(LIBS)  -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

EPC6450-AWI-MODBUS_TCP_SLAVE.hex: EPC6450-AWI-MODBUS_TCP_SLAVE.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Create Flash Image'
	riscv32-unknown-elf-objcopy -O ihex "EPC6450-AWI-MODBUS_TCP_SLAVE.elf"  "EPC6450-AWI-MODBUS_TCP_SLAVE.hex"
	@echo 'Finished building: $@'
	@echo ' '

EPC6450-AWI-MODBUS_TCP_SLAVE.siz: EPC6450-AWI-MODBUS_TCP_SLAVE.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: GNU RISC-V Cross Print Size'
	riscv32-unknown-elf-size --format=berkeley "EPC6450-AWI-MODBUS_TCP_SLAVE.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(OBJS)$(C_UPPER_DEPS)$(CXX_DEPS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS)$(CPP_DEPS) EPC6450-AWI-MODBUS_TCP_SLAVE.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
