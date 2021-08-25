;
; msp430_asm_structure.asm
;
;Created on: 14.11.2016
;Author: Prof. Dr. Vesselin Iossifov
;
; Die Einstellungen des CCS V5 zum ASM/C-Projekt finden Sie in der Datei "Einstellungen des CCS zum ASM_C-Projekt.pdf"
; Diese und alle anderen Einstellungen dürfen, auch versehentlich, nicht geändert werden!
;

;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file

;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.

;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer

			mov.b   #11h,R4
			mov.w   #00AAh,R5
            and.w   R4,R5

            jmp     $
.end
;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack

;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET





