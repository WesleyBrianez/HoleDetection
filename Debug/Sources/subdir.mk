################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/Events.c \
../Sources/SerialDebug.c \
../Sources/SerialGL.c \
../Sources/SerialJN.c \
../Sources/Util.c \
../Sources/apiAccel.c \
../Sources/main.c 

OBJS += \
./Sources/Events.o \
./Sources/SerialDebug.o \
./Sources/SerialGL.o \
./Sources/SerialJN.o \
./Sources/Util.o \
./Sources/apiAccel.o \
./Sources/main.o 

C_DEPS += \
./Sources/Events.d \
./Sources/SerialDebug.d \
./Sources/SerialGL.d \
./Sources/SerialJN.d \
./Sources/Util.d \
./Sources/apiAccel.d \
./Sources/main.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"C:/Users/wleyb/wkp_kds/HoleDetector/Static_Code/PDD" -I"C:/Users/wleyb/wkp_kds/HoleDetector/Static_Code/IO_Map" -I"C:/Users/wleyb/wkp_kds/HoleDetector/Sources" -I"C:/Users/wleyb/wkp_kds/HoleDetector/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


