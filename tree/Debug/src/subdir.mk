################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/BTNode.cpp \
../src/BinaryTree.cpp \
../src/IntNode.cpp \
../src/Node.cpp \
../src/tree.cpp 

OBJS += \
./src/BTNode.o \
./src/BinaryTree.o \
./src/IntNode.o \
./src/Node.o \
./src/tree.o 

CPP_DEPS += \
./src/BTNode.d \
./src/BinaryTree.d \
./src/IntNode.d \
./src/Node.d \
./src/tree.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


