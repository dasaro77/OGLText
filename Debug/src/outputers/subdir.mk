################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/outputers/QTextOutputer.cpp 

OBJS += \
./src/outputers/QTextOutputer.o 

CPP_DEPS += \
./src/outputers/QTextOutputer.d 


# Each subdirectory must supply rules for building sources it contributes
src/outputers/%.o: ../src/outputers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	clang++ -I/opt/X11/include -I"/Users/drom/Documents/workspace/OGLText/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


