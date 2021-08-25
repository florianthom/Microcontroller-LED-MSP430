/*
 Titel: 	Operatoren,  Bedingungsoperator
 LastEdit: 2019
Author  : Prof. Dr. V.Iossifov, HTW Berlin
System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
	 
Aufgabe:	 
- Das 05_operatoren_ Bedingungsoperator.c Programm uebersetzen und binden.
- Das 05_operatoren_ Bedingungsoperator.c - Führen Sie das Programm aus.
---------------------------------------------------------------------------
*/

/*
Der Bedingungsoperator liefert abhängig von einer Bedingung einen von zwei
möglichen Ergebniswerten. Er hat drei Operanden: Die Bedingung, den Wert für
den Fall, dass die Bedingung zutrifft und den Wert für den Fall dass sie nicht zutrifft.

Die Syntax ist
bedingung ? wert_wenn_wahr : wert_wenn_falsch
*/

#include <msp430.h>
#include <math.h>

void main(void) {

    WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
	volatile int a,b,c;

//Für eine einfache if-Anweisung wie die folgende:
//Falls a größer als b ist, wird a zurückgegeben, ansonsten b.

	if (a > b)
		return a;
	else
		return b;
//kann daher kürzer geschrieben werden

	return (a > b) ? a : b;

// Falls a größer als b ist, wird a zurückgegeben, ansonsten b.

/*
Der Bedingungsoperator ist nicht, wie oft angenommen, eine verkürzte Schreibwei-
se für if-else. Die wichtigsten Unterschiede sind:
	• Der Bedingungsoperator hat im Gegensatz zu if-else einen Ergebniswert und
	  kann daher z.B. in Formeln und Funktionsaufrufen verwendet werden
	• Bei if-Anweisungen kann der else-Teil entfallen, der Bedingungsoperator verlangt
	  stets eine Angabe von beiden Ergebniswerten
*/

//Selbstverständlich können Ausdrücke mit diesem Operator beliebig geschachtelt
//werden. Das Maximum von drei Zahlen erhalten wir beispielsweise so:

return a > b ? (a > c ? a : c) : (b > c ? b : c);

//An diesem Beispiel sehen wir auch sofort einen Nachteil des Bedingungsoperators:
//Es ist sehr unübersichtlich, verschachtelten Code mit ihm zu schreiben.

return 0;

}
