;
; asm_red_zero_green.asm
;
;Created on: 14.11.2016
;Author: Prof. Dr. Vesselin Iossifov
;
; Die Einstellungen des CCS zum ASM/C-Projekt finden Sie in der Datei "Einstellungen des CCS zum ASM_C-Projekt.pdf"
; Diese und alle anderen Einstellungen duerfen, auch versehentlich, nicht geÃ¤ndert werden!
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
	.global set_port

delay: 	.equ	0xFFFF
set_port:
	mov.b 	#0x00, &P1OUT
	mov.b 	#0x41, &P1DIR

	xor.b	#01h,&P1OUT              ; Toggle 0x01 bit Port 1 output to RED
	call	#delay_ms
	xor.b	#01h,&P1OUT              ; Toggle 0x01 bit Port 1 output to ZERO
	call	#delay_ms
	xor.b	#40h,&P1OUT              ; Toggle 0x06 bit Port 6 output to GREEN
	call	#delay_ms
	xor.b	#40h,&P1OUT              ; Toggle 0x01 bit Port 6 output to ZERO
	ret


;*****************************************************************
; Unterprogramm verzögert um die Zeit, die in r5 vorgegeben ist.

delay_ms:	mov.w	#delay, r5

loop: 		sub.w 	#1, r5
			tst.w 	r5
			jne 	loop
			ret

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

            .end



