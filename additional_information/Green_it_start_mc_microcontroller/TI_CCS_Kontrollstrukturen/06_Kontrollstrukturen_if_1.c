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
- Das 06_Kontrollstrukturen_if.c Programm uebersetzen und binden.
- Das06_Kontrollstrukturen_if.c - Führen Sie das Programm aus.
---------------------------------------------------------------------------
*/

/*
Beginnen wir mit der if -Anweisung. Sie hat die folgende Syntax:

	if(expression) statement;

Optional kann eine alternative Anweisung angegeben werden, wenn die Bedingung
expression nicht erfüllt wird:

	if(expression)
		statement;
	else
		statement;

Mehrere Fälle müssen verschachtelt abgefragt werden:
	if(expression1)
		statement;
	else
		if(expression2)
			statement;
		else
			statement;

*/



#include <msp430.h>
#include <math.h>

int main(void) {

    WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
    P1OUT = 0x00;                          // LEDs off
    // Konstanten sind in Header definiert
    P1DIR = BIT0+BIT6;                     // P1.0 and P1.6 as output
    //geht auch
    // P1DIR = 0x01+BIT6

    volatile int i, zahl = 5;

    for(;;)	{


        if(zahl > 5)	{
            P1OUT |= BIT0;                          // set P1.0 (red LED on)
        }
        else	{//kann auch unter bestimmten Bedingungen weggelassen werden.
            P1OUT &= ~BIT0;                         // toggle P1.0 (red LED off)
            P1OUT ^= BIT6;                          // set P1.0 (green LED on)
        }

        P1OUT &= ~BIT6;                         // toggle P1.6 (green LED off)

    }
  return 0;
}

/*
Wir nehmen zunächst einmal an, dass der Benutzer die Zahl 7 eingibt. In diesem
Fall ist der Ausdruck zahl > 5 true (wahr) und liefert eine 1 zurück. Da dies ein
Wert ungleich 0 ist, wird die auf if folgende Zeile ausgeführt und "Die Zahl ist
größer als 5" ausgegeben. Anschließend wird die Bearbeitung mit der Anweisung
printf("Tschüß! Bis zum nächsten mal\n") fortgesetzt .
Wenn wir annehmen, dass der Benutzer eine 3 eingegeben hat, so ist der Ausdruck
zahl > 5 false (falsch) und liefert eine 0 zurück. Deshalb wird printf("Die
Zahl ist größer als 5") nicht ausgeführt und nur "Tschüß! Bis zum
nächsten mal" ausgegeben.
Wir können die if -Anweisung auch einfach lesen als: "Wenn zahl größer als
5 ist, dann gib "Die Zahl ist größer als 5" aus". In der Praxis wird man sich keine
Gedanken machen, welches Resultat der Ausdruck zahl > 5 hat.

*/
