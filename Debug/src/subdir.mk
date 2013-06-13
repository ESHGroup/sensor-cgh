################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DepthCapture.cpp \
../src/HoloFilm.cpp \
../src/ParseWavefrontObj.cpp \
../src/main.cpp 

OBJS += \
./src/DepthCapture.o \
./src/HoloFilm.o \
./src/ParseWavefrontObj.o \
./src/main.o 

CPP_DEPS += \
./src/DepthCapture.d \
./src/HoloFilm.d \
./src/ParseWavefrontObj.d \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


