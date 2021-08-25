/*
 * blink_effizient_LED.c
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
 //  Autor: D. Dang
 //  Texas Instruments Inc.
 //  December 2010

 //  Revised: V.Iossifov
 //  HTW Berlin
 //  December 2019
 //  Built with CCS Version 7.4.0
 //******************************************************************************

#include <msp430.h>

 void main(void)
 {
   WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
   P1DIR |= 0x01;                            // P1.0 output



//LOW POWER ADVICE:  Rule 4.1 Terminate unused GPIOs
// When an unused port pin is left undefined or non-terminated,
//the floating voltage or shoot-through current on the pin can
//increase the overall current consumption

//************************************
       P2DIR = 0xFF;
       P2OUT = 0x00;

       P3DIR = 0xFF;
       P3OUT = 0x00;
//************************************

//LOW POWER ADVICE: Rule 2.1 Leverage timer module for delay loops

/*
 * The MSP430 offers various types of timers & clocks that can be configured
to function without CPU intervention. When a delay is required, one of
the timer peripherals can be leveraged to generate such delay without the
CPU staying active. This method significantly reduces the power consumption
of the device. These timers can enable the MSP430 microcontroller to stay
in a Low Power Mode until the timer wakes up the CPU
*/

//Abhilfe
//Leverage one of the MSP430 Low Power Modes, and use one of the timer modules
//in your MSP430 device to wake up after a set amount of time.

//**********************************************************************
   CCTL0 = CCIE;                             // CCR0 interrupt enabled
   CCR0 = 65000;
   TACTL = TASSEL_2 + MC_2;                  // SMCLK, contmode

   _BIS_SR(LPM0_bits + GIE);                 // Enter LPM0 w/ interrupt
 }

 // Timer A0 interrupt service routine
 #pragma vector=TIMER0_A0_VECTOR
 __interrupt void Timer_A (void)
 {
   P1OUT ^= 0x01;                            // Toggle P1.0
   CCR0 += 65000;                            // Add Offset to CCR0
 }
//***********************************************************************




