/*
 Titel: 	Operatoren,   Shift-Operator
 LastEdit: 2019
Author  : Prof. Dr. V. Iossifov, HTW Berlin
System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
 
Aufgabe:	 
- Shift-Operator - Programm uebersetzen und binden.
- Shift-Operator - Führen Sie das Programm aus.
---------------------------------------------------------------------------
*/
#include <msp430.h>
#include <math.h>

/*
Es stellt sich nun noch die Frage, weshalb man den Shift-Operator benutzen soll,
wenn eine Multiplikation mit zwei doch ebenso gut mit dem * -Operator machbar
wäre? Die Antwort lautet: Bei den meisten Prozessoren wird die Verschiebung der
Bits wesentlich schneller ausgeführt als eine Multiplikation. Deshalb kann es bei
laufzeitkritischen Anwendungen vorteilhaft sein, den Shift-Operator anstelle der
Multiplikation zu verwenden. Eine weitere praktische Einsatzmöglichkeit des Shift
Operators ﬁndet sich zudem in der Programmierung von Mikroprozessoren. Durch
einen Leftshift können digitale Eingänge einfacher und schneller geschaltet werden.
Man erspart sich hierbei mehrere Taktzyklen des Prozessors.

*/


int main(void) {

     WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer

volatile unsigned short int a = 128, b, ergebnis;

ergebnis =  b = a << 2);
ergebnis =   a = b >> 1);

return 0;

}
