################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/.axioenvs/application.modbus_tcp_slave/build/gcc-riscv32.debug/gen/hwconf/awbl_hwconf_all.c 

O_SRCS += \
D:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/.axioenvs/application.modbus_tcp_slave/build/gcc-riscv32.debug/gen/hwconf/awbl_hwconf_all.o 

OBJS += \
./gen/hwconf/awbl_hwconf_all.o 

C_DEPS += \
./gen/hwconf/awbl_hwconf_all.d 


# Each subdirectory must supply rules for building sources it contributes
gen/hwconf/awbl_hwconf_all.o: D:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/.axioenvs/application.modbus_tcp_slave/build/gcc-riscv32.debug/gen/hwconf/awbl_hwconf_all.c gen/hwconf/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU RISC-V Cross C Compiler'
	riscv32-unknown-elf-gcc -march=rv32imafdc -mabi=ilp32d -msmall-data-limit=8 -mno-save-restore -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wall -Wextra -Wno-unused-parameter -Wno-unused-function -Wno-unused-but-set-variable -Wno-unused-label  -g3 @../inputs.txt  -DAXIO_FRAMEWORK_NAME="aworks_lp" -DAXIO_FRAMEWORK_VERSION=8025 -DAW_IMG_PRJ_BUILD -DAXIO_C -DAXIO_CPP -DAWORKS -DAXIO_AWORKS -DCPP_GCC -DAW_GCC -DLIB_AW_MB_MASTER_TCP_ENABLE -DLIB_AW_MB_TCP_ENABLE -DLIB_AW_MB_MASTER_RTU_ENABLE -DLIB_AW_MB_MASTER_ASCII_ENABLE -DLIB_AW_MB_SERIAL_RTU_ENABLE -DLIB_AW_MB_SERIAL_ASCII_ENABLE -DSDRAM -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include0 -ID:/aworks_lp_hpm6450_general_sdk-0.9.1/demos/component/modbus/modbus_tcp_slave/project_eclipse/_include_files/include1 -std=gnu11 -msmall-data-limit=8 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


