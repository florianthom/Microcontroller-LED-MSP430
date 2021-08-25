/********************************************************************************
 Titel:     Kontrollstrukturen, Switch
 LastEdit: 2019
 Author  : Prof. Dr. V.Iossifov, HTW Berlin
 System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

	Referenzen:
	Statemachine, Moore-Automat
	https://de.wikipedia.org/wiki/Moore-Automat
	www.mikrocontroller.net
	http://www.mikrocontroller.net/articles/Statemachine

Ampelsteuerung

Ampelphase: T = (65535 * 2*62,5 ns ) * (16 * 2*62,5 ns ) = ca. 16,2 Sek
ROT:  LED rot leuchtet staendig.
GELB: LEDs rot und gruen leuchten staendig.
GRÜN: LED gruen leuchtet staendig.

*******************************************************************************/

#include  <msp430g2553.h>

unsigned char state = 1;   // globale Variable, die den Status repraesentiert


void delay(volatile unsigned int i)
{

   while(i > 0) i--;
}

void delay_ms (volatile unsigned int i, volatile unsigned int j) {

	volatile unsigned int k = j;
	do {
		i--;
		{
			do
				k--;
			while(k != 0);
				k = j;
			}
	} while(i != 0);
}

void stateMachine()
{
volatile unsigned int gelb_phase;

  switch( state ) {
    case 1:
//  Ampel( GRUEN );

    	P1OUT &= ~BIT0;							// toggle P1.0 (red LED off)
        P1OUT ^= BIT6;                 			// set P1.0 (green LED on)
    //	P1OUT = P1OUT ^ BIT6;
    //	XOR bitweise
        state = 2;
    break;
 
    case 2:
//  Ampel( GELB );

    	P1OUT |= BIT0;                 			// set P1.0 (red LED on)
    //	P1OUT = P1OUT | BIT0;
    //	OR bitweise
    	state = 3;
    break;
 
     case 3:
//		Ampel( ROT );
    	 P1OUT &= ~BIT6;							// toggle P1.6 (green LED off)
    //	P1OUT = P1OUT & ~BIT6;
    //	AND bitweise
    	 P1OUT |= BIT0;                 			// set P1.0 (red LED on)
    //	P1OUT = P1OUT | BIT0;
    //	OR bitweise
    	 state = 1;
     break;

  }
}
 

void main (void)	{
	volatile unsigned int ampel_phase1;
	volatile unsigned int ampel_phase2;

	 WDTCTL = WDTPW + WDTHOLD;         	 // stop watchdog timer

	 P1DIR = BIT0+BIT6;                	 // P1.0 and P1.6 as output
	 P1OUT = 0x00;                     	 // LEDs off

  while( 1 ) {

    stateMachine();
    ampel_phase1 = 0xffff;
    ampel_phase2 = 0x0010;
    delay_ms(ampel_phase1, ampel_phase2);

  }
}
