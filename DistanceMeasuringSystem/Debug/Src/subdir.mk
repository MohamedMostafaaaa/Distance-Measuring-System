################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/GPIO_program.c \
../Src/Global_Interrupt.c \
../Src/Ultra_sonic.c \
../Src/icu.c \
../Src/lcd.c \
../Src/main.c 

OBJS += \
./Src/GPIO_program.o \
./Src/Global_Interrupt.o \
./Src/Ultra_sonic.o \
./Src/icu.o \
./Src/lcd.o \
./Src/main.o 

C_DEPS += \
./Src/GPIO_program.d \
./Src/Global_Interrupt.d \
./Src/Ultra_sonic.d \
./Src/icu.d \
./Src/lcd.d \
./Src/main.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o: ../Src/%.c Src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


