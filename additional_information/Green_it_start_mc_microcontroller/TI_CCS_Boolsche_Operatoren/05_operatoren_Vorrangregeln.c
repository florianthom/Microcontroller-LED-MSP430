/*
Title	   : 05_operatoren_Vorrangregeln.c
LastEdit: 2019
Author  : Prof. Dr. V.Iossifov, HTW Berlin
System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

Schwerpunkte:  - Arbeit mit logischen Operatoren
               - Verwendung von  -- | ++ | ||  |  &&
               - Vorrangregeln bei der Auswertung von Ausdruecken

---------------------------------------------------------------------------

Aufgabe: - Ueberlegen Sie, was durch die folgenden Anweisungen
           berechnet wird.
           Ergaenzen Sie danach das Programm um Ausgabeanweisungen,
           uebersetzen Sie es und ueberpruefen Sie Ihre Loesungen.

---------------------------------------------------------------------------
*/
#include <msp430.h>
#include <math.h>

int main(void) {

    WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
	volatile int x, y, z, ergebnis;


	x = 2; y = 1; z = 0;
	x = x && y || z;
	y = x || !y && z;

	x = y = 1;
	z = x ++ -1;
	z += - x ++ + ++ y;
	z = x / ++ x;


	/* Die Ausgabe, die Sie hier erhalten, ist compilerabhaengig, deshalb
	   sollte man solche Ausdruecke in eigenen Programmen vermeiden. 
	   Sehen Sie sich an, wie die Ausgabe aussieht.   */
	{
     volatile int i=1;
ergebnis = i || i++|| i++|| i++|| i;   /* Was wird ausgegeben...   */
ergebnis = i && ++i && ++i && ++i && i;   /* und was passiert jetzt ? */
    }

	return 0;
}
