/*
 Titel: 	Kontrollstrukturen,   Do-While-Schleife
 LastEdit: 2019
 Author  : Prof. Dr. V.Iossifov, HTW Berlin
 System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
	 
Aufgabe:	 
- Das 06_Kontrollstrukturen_Do-While-Schleife.c Programm uebersetzen und binden.
- Das 06_Kontrollstrukturen_Do-While-Schleife.c - Führen Sie das Programm aus.
---------------------------------------------------------------------------
*/
/*
Im Gegensatz zur while -Schleife ﬁndet bei der Do-while-Schleife die Über-
prüfung der Wiederholungsbedingung am Schleifenende statt. So kann garantiert
werden, dass die Schleife mindestens einmal durchlaufen wird. Sie hat die folgende
Syntax:

	do
		statement
	while (expression);

Das folgende Programm addiert solange Zahlen auf, bis der Anwender eine 0
eingibt:

*/
#include <msp430.h>
#include <math.h>

int main(void) {

    WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
	float zahl = 3.14, ergebnis = 0;


	do
	{
		ergebnis += zahl;
	}
	while (zahl != 0);

return 0;
}

/*
Die Überprüfung, ob die Schleife fortgesetzt werden soll, ﬁndet in Zeile 14 statt.
Mit do in Zeile 8 wird die Schleife begonnen, eine Prüfung ﬁndet dort nicht statt,
weshalb der Block von Zeile 9 bis 13 in jedem Fall mindestens einmal ausgeführt
wird.

Wichtig: Beachten Sie, dass das while mit einem Semikolon abgeschlossen
werden muss, sonst wird das Programm nicht korrekt ausgeführt!

*/

