################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/console/Console.cpp \
../src/console/ConsoleBuffer.cpp 

OBJS += \
./src/console/Console.o \
./src/console/ConsoleBuffer.o 

CPP_DEPS += \
./src/console/Console.d \
./src/console/ConsoleBuffer.d 


# Each subdirectory must supply rules for building sources it contributes
src/console/%.o: ../src/console/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	clang++ -I/opt/X11/include -I"/Users/drom/Documents/workspace/OGLText/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


