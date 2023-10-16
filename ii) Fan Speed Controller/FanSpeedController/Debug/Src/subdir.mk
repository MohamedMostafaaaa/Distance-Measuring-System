################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC_program.c \
../Src/GPIO_program.c \
../Src/MOTOR.c \
../Src/PWM.c \
../Src/lcd.c \
../Src/main.c 

OBJS += \
./Src/ADC_program.o \
./Src/GPIO_program.o \
./Src/MOTOR.o \
./Src/PWM.o \
./Src/lcd.o \
./Src/main.o 

C_DEPS += \
./Src/ADC_program.d \
./Src/GPIO_program.d \
./Src/MOTOR.d \
./Src/PWM.d \
./Src/lcd.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


