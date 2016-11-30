################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/qshan/practice.c 

OBJS += \
./src/qshan/practice.o 

C_DEPS += \
./src/qshan/practice.d 


# Each subdirectory must supply rules for building sources it contributes
src/qshan/%.o: ../src/qshan/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/fshan/workspace/ctest_qshan/src/qshan" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


