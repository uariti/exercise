################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Node.cpp \
../src/Queue.cpp \
../src/linkedlist.cpp 

OBJS += \
./src/Node.o \
./src/Queue.o \
./src/linkedlist.o 

CPP_DEPS += \
./src/Node.d \
./src/Queue.d \
./src/linkedlist.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


