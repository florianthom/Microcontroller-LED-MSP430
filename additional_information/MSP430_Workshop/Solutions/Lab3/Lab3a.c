#include  "msp430g2553.h"

#ifndef TIMER0_A1_VECTOR
#define TIMER0_A1_VECTOR    TIMERA1_VECTOR
#define TIMER0_A0_VECTOR    TIMERA0_VECTOR
#endif

void main(void)
{
	WDTCTL = WDTPW + WDTHOLD;		// watchdog timer setup

	P1DIR = 0x40;					// I/O setup
	P1OUT = 0;

	BCSCTL3 |= LFXT1S_2;			// clock system setup
	IFG1 &= ~OFIFG;
	_bis_SR_register(SCG1 + SCG0);
	BCSCTL2 |= SELM_3 + DIVM_3;
	
	while(1)
	{
	  P1OUT = 0x40; 			    // LED on
	  _delay_cycles(100);
	  P1OUT = 0; 			    	// LED off
	  _delay_cycles(5000);
	}
}
