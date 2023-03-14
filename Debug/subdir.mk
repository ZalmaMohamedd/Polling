################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Poller.c \
../PollerTimer.c \
../PollingDataClient.c \
../SPI_2.c \
../TC72_Tempr.c \
../gpio.c \
../lcd.c \
../main.c \
../pwm.c \
../spi.c 

C_DEPS += \
./Poller.d \
./PollerTimer.d \
./PollingDataClient.d \
./SPI_2.d \
./TC72_Tempr.d \
./gpio.d \
./lcd.d \
./main.d \
./pwm.d \
./spi.d 

OBJS += \
./Poller.o \
./PollerTimer.o \
./PollingDataClient.o \
./SPI_2.o \
./TC72_Tempr.o \
./gpio.o \
./lcd.o \
./main.o \
./pwm.o \
./spi.o 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


