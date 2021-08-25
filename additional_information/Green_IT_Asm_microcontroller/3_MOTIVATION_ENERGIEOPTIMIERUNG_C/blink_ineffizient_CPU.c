/*
 * blink_ineffizient_CPU.c
 */

 //******************************************************************************
 //  MSP430G2xx3 Demo - Timer_A, Toggle P1.0, CCR0 Cont. Mode ISR, DCO SMCLK
 //
 //  Description: Toggle P1.0 using software and TA_0 ISR. Toggles every
 //  50000 SMCLK cycles. SMCLK provides clock source for TACLK.
 //  During the TA_0 ISR, P1.0 is toggled and 50000 clock cycles are added to
 //  CCR0. TA_0 ISR is triggered every 50000 cycles. CPU is normally off and
 //  used only during TA_ISR.
 //  ACLK = n/a, MCLK = SMCLK = TACLK = default DCO
 //
 //           MSP430G2xx3
 //         ---------------
 //     /|\|            XIN|-
 //      | |               |
 //      --|RST        XOUT|-
 //        |               |
 //        |           P1.0|-->LED
 //
 //  Autor: V.Iossifov
 //  HTW Berlin
 //  December 2019
 //  Built with CCS Version 7.4.0
 //******************************************************************************


#include <msp430.h>				


void main(void)
{
	WDTCTL = WDTPW | WDTHOLD;		// stop watchdog timer
//	P1DIR |= 0x01;					// configure P1.0 as output

	volatile unsigned int i;		// volatile to prevent optimization
    volatile int a = 2, b = 3, c;


	while(1)
	{
//		P1OUT ^= 0x01;				// toggle P1.0
	    c = a + b;
		for(i=10000; i>0; i--);     // delay
	}
}
