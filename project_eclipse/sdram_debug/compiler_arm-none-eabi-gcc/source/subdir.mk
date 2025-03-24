################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/libc.c \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/libc_mem.c \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/libc_time.c \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/posix_file.c \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/syscalls.c 

CPP_SRCS += \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/cppEabiLib.cpp \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/cppMemLib.cpp \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/cppRuntime.cpp \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/cppSupLib.cpp 

OBJS += \
./compiler_arm-none-eabi-gcc/source/cppEabiLib.o \
./compiler_arm-none-eabi-gcc/source/cppMemLib.o \
./compiler_arm-none-eabi-gcc/source/cppRuntime.o \
./compiler_arm-none-eabi-gcc/source/cppSupLib.o \
./compiler_arm-none-eabi-gcc/source/libc.o \
./compiler_arm-none-eabi-gcc/source/libc_mem.o \
./compiler_arm-none-eabi-gcc/source/libc_time.o \
./compiler_arm-none-eabi-gcc/source/posix_file.o \
./compiler_arm-none-eabi-gcc/source/syscalls.o 

C_DEPS += \
./compiler_arm-none-eabi-gcc/source/libc.d \
./compiler_arm-none-eabi-gcc/source/libc_mem.d \
./compiler_arm-none-eabi-gcc/source/libc_time.d \
./compiler_arm-none-eabi-gcc/source/posix_file.d \
./compiler_arm-none-eabi-gcc/source/syscalls.d 

CPP_DEPS += \
./compiler_arm-none-eabi-gcc/source/cppEabiLib.d \
./compiler_arm-none-eabi-gcc/source/cppMemLib.d \
./compiler_arm-none-eabi-gcc/source/cppRuntime.d \
./compiler_arm-none-eabi-gcc/source/cppSupLib.d 


# Each subdirectory must supply rules for building sources it contributes
compiler_arm-none-eabi-gcc/source/cppEabiLib.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/cppEabiLib.cpp compiler_arm-none-eabi-gcc/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C++ Compiler'
	riscv32-unknown-elf-g++ -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu++11 -fabi-version=0 -msmall-data-limit=8 -MMD -MP -fpermissive -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

compiler_arm-none-eabi-gcc/source/cppMemLib.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/cppMemLib.cpp compiler_arm-none-eabi-gcc/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C++ Compiler'
	riscv32-unknown-elf-g++ -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu++11 -fabi-version=0 -msmall-data-limit=8 -MMD -MP -fpermissive -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

compiler_arm-none-eabi-gcc/source/cppRuntime.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/cppRuntime.cpp compiler_arm-none-eabi-gcc/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C++ Compiler'
	riscv32-unknown-elf-g++ -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu++11 -fabi-version=0 -msmall-data-limit=8 -MMD -MP -fpermissive -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

compiler_arm-none-eabi-gcc/source/cppSupLib.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/cppSupLib.cpp compiler_arm-none-eabi-gcc/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C++ Compiler'
	riscv32-unknown-elf-g++ -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu++11 -fabi-version=0 -msmall-data-limit=8 -MMD -MP -fpermissive -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

compiler_arm-none-eabi-gcc/source/libc.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/libc.c compiler_arm-none-eabi-gcc/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

compiler_arm-none-eabi-gcc/source/libc_mem.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/libc_mem.c compiler_arm-none-eabi-gcc/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

compiler_arm-none-eabi-gcc/source/libc_time.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/libc_time.c compiler_arm-none-eabi-gcc/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

compiler_arm-none-eabi-gcc/source/posix_file.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/posix_file.c compiler_arm-none-eabi-gcc/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

compiler_arm-none-eabi-gcc/source/syscalls.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/frameworks/64cf32e2-aworks_lp/app/applications/compiler_arm-none-eabi-gcc/source/syscalls.c compiler_arm-none-eabi-gcc/source/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


