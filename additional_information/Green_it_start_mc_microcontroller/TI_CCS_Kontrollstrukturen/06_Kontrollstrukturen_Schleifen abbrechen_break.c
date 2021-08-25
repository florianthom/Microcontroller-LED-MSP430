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
- Das 06_Kontrollstrukturen_Schleifen abbrechen_break.c Programm uebersetzen und binden.
- Das 06_Kontrollstrukturen_Schleifen abbrechen_break.c - Führen Sie das Programm aus.
---------------------------------------------------------------------------
*/


/*
Die break-Anweisung beendet eine Schleife und setzt bei der ersten Anweisung
nach der Schleife fort. Nur innerhalb einer Wiederholungsanweisung, wie in for-,
while-, do-while-Schleifen oder innerhalb einer switch-Anweisung ist eine break-
Anweisung funktionsfähig. Sehen wir uns dies an folgendem Beispiel an:

*/

#include <msp430.h>
#include <math.h>

int main(void) {

    WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
    P1OUT = 0x00;                          // LEDs off
    P1DIR = BIT0+BIT6;                     // P1.0 and P1.6 as output

    volatile int i, eingabe = 6666, passwort = 2323;

	while (1) {
		
		if (passwort == eingabe) {
            P1OUT ^= BIT6;                 // Passwd korrekt! set P1.0 (green LED on)
			break;
		} else {
	        P1OUT &= ~BIT6;                // toggle P1.6 (green LED off)
            P1OUT |= BIT0;                 // Passwd nicht korrekt!set P1.0 (red LED on)
		}
	    P1OUT = 0x00;
	}

return 0;
}

/*
Wie Sie sehen ist die while-Schleife als Endlosschleife konzipiert. Hat man das
richtige Passwort eingegeben, so wird die printf-Anweisung ausgegeben und an-
schließend wird diese Endlosschleife, durch die break-Anweisung, verlassen. Die
nächste Anweisung, die dann ausgeführt wird, ist die printf-Anweisung unmittelbar
nach der Schleife. Ist das Passwort aber inkorrekt, so wird der else-Block mit den
weiteren printf-Anweisungen in der while-Schleife ausgeführt. Anschließend wird
die while-Schleife wieder ausgeführt.

*/
