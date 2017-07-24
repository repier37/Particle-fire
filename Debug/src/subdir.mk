################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Particle\ Fire\ explosion.cpp \
../src/Particle.cpp \
../src/SDLTest.cpp \
../src/Screen.cpp \
../src/Swarm.cpp 

OBJS += \
./src/Particle\ Fire\ explosion.o \
./src/Particle.o \
./src/SDLTest.o \
./src/Screen.o \
./src/Swarm.o 

CPP_DEPS += \
./src/Particle\ Fire\ explosion.d \
./src/Particle.d \
./src/SDLTest.d \
./src/Screen.d \
./src/Swarm.d 


# Each subdirectory must supply rules for building sources it contributes
src/Particle\ Fire\ explosion.o: ../src/Particle\ Fire\ explosion.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/SDL2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Particle Fire explosion.d" -MT"src/Particle\ Fire\ explosion.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/usr/include/SDL2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


