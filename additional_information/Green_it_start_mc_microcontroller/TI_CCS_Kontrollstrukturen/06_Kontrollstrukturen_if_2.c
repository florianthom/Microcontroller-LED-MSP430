/*
 Titel: 	Kontrollstrukturen, Bedingungen IF
 LastEdit: 2019
 Author  : Prof. Dr. V.Iossifov, HTW Berlin
 System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
 
Aufgabe:	 
- Das 06_Kontrollstrukturen_if_2.c Programm uebersetzen und binden.
- Das06_Kontrollstrukturen_if_2.c - Führen Sie das Programm aus.
---------------------------------------------------------------------------
*/

//Das zweite Beispiel, das wir uns ansehen, besitzt neben if auch ein else if
//und ein else :

#include <msp430.h>
#include <math.h>

int main(void) {

    WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
    P1OUT = 0x00;                          // LEDs off
    P1DIR = BIT0+BIT6;                     // P1.0 and P1.6 as output

    volatile int i, zahl = 1;

	if(zahl > 0)
        P1OUT |= BIT0;                          // set P1.0 (red LED on)
	else if(zahl < 0){
        P1OUT &= ~BIT0;                         // toggle P1.0 (red LED off)
        P1OUT ^= BIT6;                          // set P1.0 (green LED on)
	}
	else
        P1OUT |= BIT0;                          // set P1.0 (red LED on)

return 0;
}


/*
Nehmen wir an, dass der Benutzer die Zahl -5 eingibt. Der Ausdruck zahl >
0 ist in diesem Fall falsch, weshalb der Ausdruck ein false liefert (was einer 0
entspricht). Deshalb wird die darauffolgende Anweisung nicht ausgeführt. Der Aus-
druck zahl < 0 ist dagegen erfüllt, was wiederum bedeutet, dass der Ausdruck
wahr ist (und damit eine 1 liefert) und so die folgende Anweisung ausgeführt wird.
Nehmen wir nun einmal an, der Benutzer gibt eine 0 ein. Sowohl der Ausdruck
zahl > 0 als auch der Ausdruck zahl < 0 sind dann nicht erfüllt. Der if -
und der if - else -Block werden deshalb nicht ausgeführt. Der Compiler trifft
anschließend allerdings auf die else -Anweisung. Da keine vorherige Bedingung
zutraf, wird die anschließende Anweisung ausgeführt.
Wir können die if - else if - else –Anweisung auch lesen als: "Wenn
zahl größer ist als 0, gib "Positive Zahl" aus, ist zahl kleiner als 0, gib
"Negative Zahl" aus, ansonsten gib "Zahl gleich Null" aus."
Fassen wir also nochmals zusammen: Ist der Ausdruck in der if oder if -
else -Anweisung erfüllt (wahr), so wird die nächste Anweisung bzw. der nächste
Anweisungsblock ausgeführt. Trifft keiner der Ausdrücke zu, so wird die Anweisung
bzw. der Anweisungsblock, die else folgen, ausgeführt.
*/

