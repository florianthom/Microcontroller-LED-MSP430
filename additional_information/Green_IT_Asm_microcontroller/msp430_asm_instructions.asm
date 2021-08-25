;
; msp430_asm_instructions.asm
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

; Arithmetikbefehle
			mov.w   #0009h,R5
			mov.w   #0006h,R6
            add.w   R5,R6

			mov.w   #0006h,R6
            dadd.w   R5,R6

            mov.w   #0006h,R6
            sub.w   R5,R6

; Logische und Registercontrol Befehle
			mov.b   #00001111b,R5
			mov.b   #00000011b,R6
            and.b   R5,R6

			mov.b   #00000011b,R6
            xor.b   R5,R6
            rra.b	R6
            swpb	R5

; Datenbefehle
			mov.w   #0006,R5
			mov.w   #0009h,R6
            cmp.w   R5,R6

; Sprungbefehle
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






