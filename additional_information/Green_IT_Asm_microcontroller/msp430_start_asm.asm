

;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------
; msp430_start_asm.asm
;
; Created on: 02.10.2019
;
; Author: Prof. Dr. Vesselin Iossifov
; Built with Code Composer Essentials Version: Version: 7.4
; Die Einstellungen des CCS V5 zum ASM/C-Projekt finden Sie in der Datei "Einstellungen des CCS zum ASM_C-Projekt.pdf"
; Diese und alle anderen Einstellungen dürfen, auch versehentlich, nicht geändert werden!
;
;******************************************************************

var:	.usect  ".bss", 2	; Variable (2 Byte)

; Bereich in dem Variablen festgelegt werden können. Beispiele:
bytevar:	.usect  ".bss", 1		; char Variable (8 Bit)
intvar:		.usect  ".bss", 2		; short Variable (16 Bit)
longvar:	.usect  ".bss", 4		; long Variable (32 Bit)
array:		.usect  ".bss", 10		; Array mit N = 10 Bytes

const:	.equ 500			; Konstante
; Bereich für Assemblerkonstanten (ähnlich wie #define). Beispiel:
; N:			.equ 10				; Legt N = 10 als Konstante fest

; Bereich in dem Konstanten festgelegt werden können. Beispiele:
byteconst:	.byte  11			; char Konstante = 11 (8 Bit)
intconst:	.short  22			; short Konstante = 22 (16 Bit)
longconst:	.long  44			; long Konstante = 44 (32 Bit)
arrayconst:	.byte  1, 2, 3		; Array mit 3 Bytes = {1, 2, 3}
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


		mov.w #const, &var
		call #count
stop:	jmp stop

count:	sub.w #1, &var
; Operand #1 ist in "unmittelbarer Adrssierung
; Operand &var ist in "Speicher indirect"
		jne count
		ret
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

