################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Keypad/Keypad.c 

OBJS += \
./Keypad/Keypad.o 

C_DEPS += \
./Keypad/Keypad.d 


# Each subdirectory must supply rules for building sources it contributes
Keypad/%.o: ../Keypad/%.c Keypad/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"D:\SD\Eclipse-Workspaces\eclipse-general\embedded23-ws\Lab8_Project\Lib" -I"D:\SD\Eclipse-Workspaces\eclipse-general\embedded23-ws\Lab8_Project\Rcc" -I"D:\SD\Eclipse-Workspaces\eclipse-general\embedded23-ws\Lab8_Project\Gpio" -I"D:\SD\Eclipse-Workspaces\eclipse-general\embedded23-ws\Lab8_Project\Keypad" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


