################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
TI_CCS_C_ASM_FUNKTIONEN/%.obj: ../TI_CCS_C_ASM_FUNKTIONEN/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: MSP430 Compiler'
	"F:/CodeComposerStudio/ccs/tools/compiler/ti-cgt-msp430_20.2.0.LTS/bin/cl430" -vmsp --code_model=small --data_model=small --use_hw_mpy=none --include_path="F:/CodeComposerStudio/ccs/ccs_base/msp430/include" --include_path="C:/Users/s0558_000/workspace_v10/Green_IT_Asm_microcontroller" --include_path="F:/CodeComposerStudio/ccs/tools/compiler/ti-cgt-msp430_20.2.0.LTS/include" --advice:power=all --define=__MSP430G2553__ -g --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="TI_CCS_C_ASM_FUNKTIONEN/$(basename $(<F)).d_raw" --obj_directory="TI_CCS_C_ASM_FUNKTIONEN" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


