; vector.asm
;
; Created on: 02.10.2019
; Author: 	V.Iossifov, HTW Berlin
;
; Built with Code Composer Essentials Version: Version: 5.2/7.4
;******************************************************************



;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------
Num:	.equ 6
; Bereich für Assemblerkonstanten (ähnlich wie #define). Beispiel:
; N:			.equ 10				; Legt N = 10 als Konstante fest

result:		.usect ".bss", Num * 2, 2		; 16 Bit Vektor erzeugen
; Bereich in dem Variablen festgelegt werden können. Beispiele:
bytevar:	.usect  ".bss", 1		; char Variable (8 Bit)
intvar:		.usect  ".bss", 2		; short Variable (16 Bit)
longvar:	.usect  ".bss", 4		; long Variable (32 Bit)
array:		.usect  ".bss", 10		; Array mit N = 10 Bytes

vector:	.byte 1, 2, 3, 4, 5, 6			; 8 Bit Vektor Konstante
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

;*********************************************************************************
; Hauptprogramm
;*********************************************************************************

		mov #Num, r4					; Anzahl der Elemente zuweisen
		mov.w #vector, r5				; Adresse der Quelle zuweisen
		mov.w #result + 2*Num, r6		; Endadresse des Ziels zuweisen
loop:	mov.w @r5+, r7					; Nächstes (erstes) Element lesen
		add.w r7, r7					; Element verdoppeln
		mov.w r7, -2(r6)				; Ergebnis ans Ende des Zielvektors
		sub.w #2, r6					; Zielpointer rückwärts weitersetzen
		sub.b #1, r4					; Schleifenzähler dekrementieren
		jne loop						; Wiederholen, bis alles kopiert
stop:	jmp stop


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
