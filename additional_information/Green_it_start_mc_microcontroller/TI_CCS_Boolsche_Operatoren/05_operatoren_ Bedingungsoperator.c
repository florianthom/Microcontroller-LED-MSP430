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
- Das 05_operatoren_ Bedingungsoperator.c - F�hren Sie das Programm aus.
---------------------------------------------------------------------------
*/

/*
Der Bedingungsoperator liefert abh�ngig von einer Bedingung einen von zwei
m�glichen Ergebniswerten. Er hat drei Operanden: Die Bedingung, den Wert f�r
den Fall, dass die Bedingung zutrifft und den Wert f�r den Fall dass sie nicht zutrifft.

Die Syntax ist
bedingung ? wert_wenn_wahr : wert_wenn_falsch
*/

#include <msp430.h>
#include <math.h>

void main(void) {

    WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
	volatile int a,b,c;

//F�r eine einfache if-Anweisung wie die folgende:
//Falls a gr��er als b ist, wird a zur�ckgegeben, ansonsten b.

	if (a > b)
		return a;
	else
		return b;
//kann daher k�rzer geschrieben werden

	return (a > b) ? a : b;

// Falls a gr��er als b ist, wird a zur�ckgegeben, ansonsten b.

/*
Der Bedingungsoperator ist nicht, wie oft angenommen, eine verk�rzte Schreibwei-
se f�r if-else. Die wichtigsten Unterschiede sind:
	� Der Bedingungsoperator hat im Gegensatz zu if-else einen Ergebniswert und
	  kann daher z.B. in Formeln und Funktionsaufrufen verwendet werden
	� Bei if-Anweisungen kann der else-Teil entfallen, der Bedingungsoperator verlangt
	  stets eine Angabe von beiden Ergebniswerten
*/

//Selbstverst�ndlich k�nnen Ausdr�cke mit diesem Operator beliebig geschachtelt
//werden. Das Maximum von drei Zahlen erhalten wir beispielsweise so:

return a > b ? (a > c ? a : c) : (b > c ? b : c);

//An diesem Beispiel sehen wir auch sofort einen Nachteil des Bedingungsoperators:
//Es ist sehr un�bersichtlich, verschachtelten Code mit ihm zu schreiben.

return 0;

}
