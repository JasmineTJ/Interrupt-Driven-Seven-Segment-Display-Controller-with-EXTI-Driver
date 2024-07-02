################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Exti/Exti.c 

C_DEPS += \
./Exti/Exti.d 

OBJS += \
./Exti/Exti.o 


# Each subdirectory must supply rules for building sources it contributes
Exti/%.o: ../Exti/%.c Exti/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GNU Arm Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=soft -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -ffreestanding -Wall -Wextra -g -DNDEBUG -DSTM32F401xE -DHSE_VALUE=8000000 -I"../include" -I"../system/include" -I"../system/include/cmsis" -I"../system/include/stm32f4-hal" -I"C:\Users\ashra\eclipse-workspace\Lab8\Lib" -I"C:\Users\ashra\eclipse-workspace\Lab8\Rcc" -I"C:\Users\ashra\eclipse-workspace\Lab8\Gpio" -I"C:\Users\ashra\eclipse-workspace\Lab8\Nvic" -I"C:\Users\ashra\eclipse-workspace\Lab8\Exti" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


