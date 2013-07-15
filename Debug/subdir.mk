################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ConsoleBuffer.cpp \
../QTextOutputer.cpp \
../main.cpp \
../qtext.cpp 

OBJS += \
./ConsoleBuffer.o \
./QTextOutputer.o \
./main.o \
./qtext.o 

CPP_DEPS += \
./ConsoleBuffer.d \
./QTextOutputer.d \
./main.d \
./qtext.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	clang++ -I/opt/X11/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


