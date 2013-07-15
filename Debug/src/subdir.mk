################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ConsoleBuffer.cpp \
../src/main.cpp \
../src/qtext.cpp 

OBJS += \
./src/ConsoleBuffer.o \
./src/main.o \
./src/qtext.o 

CPP_DEPS += \
./src/ConsoleBuffer.d \
./src/main.d \
./src/qtext.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	clang++ -I/opt/X11/include -I"/Users/drom/Documents/workspace/OGLText/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


