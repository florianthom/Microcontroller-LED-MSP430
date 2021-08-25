/*
 Titel: 	Kontrollstrukturen,   While-Schleife
 LastEdit: 2019
 Author  : Prof. Dr. V.Iossifov, HTW Berlin
 System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
 
Aufgabe:	 
- Das 06_Kontrollstrukturen_While-Schleife.c Programm uebersetzen und binden.
- Das 06_Kontrollstrukturen_While-Schleife.c - Führen Sie das Programm aus.
---------------------------------------------------------------------------


Ersetzen einer for-Schleife

Eine for-Schleife kann immer durch eine while-Schleife ersetzt werden. So ist
beispielsweise unser for-Schleifenbeispiel aus dem ersten Abschnitt mit der
folgenden while-Schleife äquivalent:
*/

#include <msp430.h>
#include <math.h>

int main(void) {

    WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer


    volatile int x, ergebnis;

	while(x <= 5)
	{
	    ergebnis =  x;
		++x;
	}

return 0;
}

