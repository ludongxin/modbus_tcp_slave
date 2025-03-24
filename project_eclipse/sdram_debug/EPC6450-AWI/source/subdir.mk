################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_init.c \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_mac_address.c \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_mem_space.c \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_nvram_segment.c \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_pm.c \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_vram_mem.c \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/xip_cfg.c 

S_UPPER_SRCS += \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_sdram_cfg.S 

OBJS += \
./EPC6450-AWI/source/aw_board_init.o \
./EPC6450-AWI/source/aw_board_mac_address.o \
./EPC6450-AWI/source/aw_board_mem_space.o \
./EPC6450-AWI/source/aw_board_nvram_segment.o \
./EPC6450-AWI/source/aw_board_pm.o \
./EPC6450-AWI/source/aw_board_sdram_cfg.o \
./EPC6450-AWI/source/aw_board_vram_mem.o \
./EPC6450-AWI/source/xip_cfg.o 

S_UPPER_DEPS += \
./EPC6450-AWI/source/aw_board_sdram_cfg.d 

C_DEPS += \
./EPC6450-AWI/source/aw_board_init.d \
./EPC6450-AWI/source/aw_board_mac_address.d \
./EPC6450-AWI/source/aw_board_mem_space.d \
./EPC6450-AWI/source/aw_board_nvram_segment.d \
./EPC6450-AWI/source/aw_board_pm.d \
./EPC6450-AWI/source/aw_board_vram_mem.d \
./EPC6450-AWI/source/xip_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
EPC6450-AWI/source/aw_board_init.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_init.c EPC6450-AWI/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

EPC6450-AWI/source/aw_board_mac_address.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_mac_address.c EPC6450-AWI/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

EPC6450-AWI/source/aw_board_mem_space.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_mem_space.c EPC6450-AWI/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

EPC6450-AWI/source/aw_board_nvram_segment.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_nvram_segment.c EPC6450-AWI/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

EPC6450-AWI/source/aw_board_pm.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_pm.c EPC6450-AWI/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

EPC6450-AWI/source/aw_board_sdram_cfg.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_sdram_cfg.S EPC6450-AWI/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross Assembler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt -x assembler-with-cpp -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

EPC6450-AWI/source/aw_board_vram_mem.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/aw_board_vram_mem.c EPC6450-AWI/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

EPC6450-AWI/source/xip_cfg.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/platforms/platform-hpm-aworks-lp/boards/EPC6450-AWI/source/xip_cfg.c EPC6450-AWI/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


