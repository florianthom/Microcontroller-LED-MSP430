/*
 Titel: 	Operatoren, Inkrement- und Dekrement-Operator
LastEdit: 2019
Author  : Prof. Dr. V.Iossifov, HTW Berlin
System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
	 
Aufgabe:	 
- Das 05_operatoren_Inkrement- und Dekrement.c - Programm uebersetzen und binden.
- Das 05_operatoren_Inkrement- und Dekrement.c - Führen Sie das Programm aus.
---------------------------------------------------------------------------
*/
#include <msp430.h>
#include <math.h>

void main(void) {

 WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
/*
Der Operator kann sowohl vor als auch nach dem Operanden stehen. Steht der
Operator vor dem Operand, spricht man von einem Präﬁx, steht er hinter dem
Operand bezeichnet man ihn als Postﬁx. Je nach Kontext unterscheiden sich die
beiden Varianten, wie das folgende Beispiel zeigt:
*/
volatile int x = 10, i, j,  ergebnis = ++x;


/*
Die zweite Zeile kann gelesen werden als: "Erhöhe zunächst x um eins, und weise
dann den Wert der Variablen zu". Nach der Zuweisung besitzt sowohl die Variable
ergebnis wie auch die Variable x den Wert 11.
*/
x = 10;
ergebnis = x++;

/*
Die zweite Zeile kann nun gelesen werden als: "Weise der Variablen ergebnis
den Wertx zu und erhöhe anschließend x um eins." Nach der Zuweisung hat die
Variable ergebnis deshalb den Wert 10, die Variable x den Wert 11.
*/

/*
Der ++- bzw. ---Operator sollte, wann immer es möglich ist, präﬁx verwendet
werden, da schlechte und ältere Compiler den Wert des Ausdruckes sonst (unnötiger
Weise) zuerst kopieren, dann erhöhen und dann in die Variable zurückschreiben. So
wird aus
*/
//int i, j;
i++;

// schnell
j = i;
j = j + 1;
i = j;
/*
wobei der Mehraufwand hier deutlich ersichtlich ist. Auch wenn man später zu
C++ wechseln will, sollte man sich von Anfang an den Präﬁxoperator angewöhnen,
da die beiden Anwendungsweisen dort fundamental anders sein können.
*/

return 0;

}
