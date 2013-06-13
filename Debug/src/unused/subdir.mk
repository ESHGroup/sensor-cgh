################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/unused/PointSource.cpp \
../src/unused/PointSource_test.cpp 

OBJS += \
./src/unused/PointSource.o \
./src/unused/PointSource_test.o 

CPP_DEPS += \
./src/unused/PointSource.d \
./src/unused/PointSource_test.d 


# Each subdirectory must supply rules for building sources it contributes
src/unused/%.o: ../src/unused/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


