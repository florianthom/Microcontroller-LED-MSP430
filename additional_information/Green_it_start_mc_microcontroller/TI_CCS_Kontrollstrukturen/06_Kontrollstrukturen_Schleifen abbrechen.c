/*
 Titel: 	Kontrollstrukturen, Schleifen abbrechen
 LastEdit: 2019
 Author  : Prof. Dr. V.Iossifov, HTW Berlin
 System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
	 
Aufgabe:	 
- Das 06_Kontrollstrukturen_Schleifen abbrechen.c Programm uebersetzen und binden.
- Das 06_Kontrollstrukturen_Schleifen abbrechen.c - Führen Sie das Programm aus.
---------------------------------------------------------------------------
*/

#include <msp430.h>
#include <math.h>

int main(void) {

    WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
    P1OUT = 0x00;                          // LEDs off
    P1DIR = BIT0+BIT6;                     // P1.0 and P1.6 as output

    volatile int i;

	for(i = -10; i <= 10; i++)
	{
		if(i == 0){
		  P1OUT |= BIT0;                          // set P1.0 (red LED on)
		  continue;
		}

	}

return 0;
}

/*
Das Programm berechnet in ganzzahligen Schritten die Werte für 1/i im Intervall
[-10, 10]. Da die Division durch Null nicht erlaubt ist, springen wir mit Hilfe der
if-Bedingung wieder zum Schleifenkopf.

*/
