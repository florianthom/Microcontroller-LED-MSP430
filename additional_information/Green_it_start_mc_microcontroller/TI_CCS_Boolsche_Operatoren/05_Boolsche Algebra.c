/*
 Title: 	05_Boolsche Algebra.c
 LastEdit: 	24/10/2019
 System  : 	ANSI-C-Compiler, TI CCS
 Autor: Prof. Dr. Vesselin Iossifov
---------------------------------------------------------------------------
*/

#include <msp430.h>
#include <math.h>


void ueberlauf()
{
    volatile int i8 = 120;

    volatile int i;
	for( i=0; i<10; i++ )
	{
//		printf( "%d\n", i8 );
		i8 = i8 + 1;
	}
}

int main(void) {

     WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer

	volatile int u8, v8, w8, x8;
	volatile int i8, j8, k8;

	ueberlauf();

	u8 = 0xFFFF;
	v8 = !0;		// Boole'sche Negation (Wahrheitswerte 0=false)
	w8 = ~0xAA;		// Bitweise Negation 
	x8 = -0xAA;		// Zweierkomplement

	u8 = 0xAA & 0x3B;	// bitweise UND
	v8 = 0xAA | 0xFC;	// bitweise ODER
	w8 = 0xAA ^ 0xFB;	// bitweise XOR

	i8 = 0xAA & 0x3B;	// bitweise UND
	j8 = 0xAA | 0xFC;	// bitweise ODER
	k8 = 0xAA ^ 0xFB;	// bitweise XOR

	return 0;
}
