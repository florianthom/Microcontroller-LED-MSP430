/*
 Titel: 	Kontrollstrukturen,  Bedingter Ausdruck
 LastEdit: 2019
 Author  : Prof. Dr. V.Iossifov, HTW Berlin
 System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
	 
Aufgabe:	 
- Das 06_Kontrollstrukturen_ Bedingter Ausdruck.c Programm uebersetzen und binden.
- Das 06_Kontrollstrukturen_ Bedingter Ausdruck.c - Führen Sie das Programm aus.
---------------------------------------------------------------------------
*/

#include <msp430.h>
#include <math.h>

int main(void) {

 WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
 volatile int x = 20, y;

/*
Der Ausdruck x >= 10 ist wahr und liefert deshalb eine 1. Da dies ein Wert
ungleich 0 ist, ist das Resultat des bedingten Ausdrucks 100.
Der obige bedingte Ausdruck entspricht*/

 if(x >= 10){
	x = 100;
//	y = 50;
 }
 else
	x = 200;

/*
Die Klammern in unserem Beispiel sind nicht unbedingt notwendig, da Vergleich-
soperatoren einen höheren Vorrang haben als der ?: -Operator. Allerdings werden
sie von vielen Programmierern verwendet, da sie die Lesbarkeit verbessern.
*/
    x = 9;
    x = (x >= 10) ? 100 : 200;

 // x = (x >= 10) 
 //	? bedeutet "if"
 //wenn (x >= 10) WAHR, dann x == 100
 //: bedeutet "else"
 //wenn (x >= 10) UNWAHR, dann x == 200;


 y = (x >= 10) ? 100 : 200;

 x = 10;

 if(x > 10)
	x = 100;

 else if(x < 10 )
	x = 200;
//else if(x < 10 )	DARF MEHRMALS VORKOMMEN!!!
	//x = 200;
 else
	x = 300;

 x = 10;

 if(x > 10)
	x = 100;
 else
	if(x < 10)
		x = 200;
	else
		x = 300;

return 0;
}

