################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
LAB10a.obj: ../LAB10a.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/TI/ccsv5/tools/compiler/msp430/bin/cl430" -vmsp --abi=coffabi -O0 -g --include_path="C:/TI/ccsv5/ccs_base/msp430/include" --include_path="C:/MSP430_LaunchPad/Labs/Lab10a-2553" --include_path="C:/MSP430_LaunchPad/Labs/Lab10a-2553/Library" --include_path="C:/TI/ccsv5/tools/compiler/msp430/include" --gcc --define=__MSP430G2553__ --diag_warning=225 --display_error_number --printf_support=minimal --preproc_with_compile --preproc_dependency="LAB10a.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

structure.obj: ../structure.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/TI/ccsv5/tools/compiler/msp430/bin/cl430" -vmsp --abi=coffabi -O0 -g --include_path="C:/TI/ccsv5/ccs_base/msp430/include" --include_path="C:/MSP430_LaunchPad/Labs/Lab10a-2553" --include_path="C:/MSP430_LaunchPad/Labs/Lab10a-2553/Library" --include_path="C:/TI/ccsv5/tools/compiler/msp430/include" --gcc --define=__MSP430G2553__ --diag_warning=225 --display_error_number --printf_support=minimal --preproc_with_compile --preproc_dependency="structure.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


