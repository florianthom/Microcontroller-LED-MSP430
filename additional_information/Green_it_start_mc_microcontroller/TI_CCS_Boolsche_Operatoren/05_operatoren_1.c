/*
Title    :  Arithmetische Operatoren
LastEdit: 2019
Author  : Prof. Dr. V. Iossifov, HTW Berlin
System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
 
Aufgabe:	 
- Das 05_operatoren_1.c Programm uebersetzen und binden.
- Das 05_operatoren_1.c - Führen Sie das Programm aus.
---------------------------------------------------------------------------
*/
/*

Schwerpunkte:  - Arbeit mit ganzzahligen Daten
               - Arithmetik mit - | + | * | % | /
               - Ausgabe mit verschiedener Formatierung

---------------------------------------------------------------------------

Aufgabe: - Ueberlegen Sie, was durch die folgenden Anweisungen
           berechnet wird.
           Ergaenzen Sie danach das Programm um Ausgabeanweisungen,
           uebersetzen Sie es und ueberpruefen Sie Ihre Loesungen.
         - Verwenden Sie verschiedene Ausgabeformate, geben Sie
           ein Ergebnis z.B. Hexadezimal oder Oktal aus.

---------------------------------------------------------------------------
*/

/* Man unterscheidet unäre und binäre Operatoren. Unäre Operatoren besitzen nur
einen Operanden, binäre Operatoren zwei Operanden. Ein unärer Operator ist
beispielsweise der & -Operator, ein binärer Operator der Geteilt-Operator (/ ). Es
gibt auch Operatoren, die sich beiden Gruppen zuordnen lassen. Ein Beispiel hierfür
sind Plus (+ ) und Minus (- ). Sie können als Vorzeichen vorkommen und sind
dann unäre Operatoren oder als Rechenzeichen und sind dann binäre Operatoren.
Sehr häuﬁg kommen im Zusammenhang mit Operatoren auch die Begriffe L- und
R-Wert vor. Diese Begriffe stammen ursprünglich von Zuweisungen. Der Ope-
rand links des Zuweisungsoperators wird als L-Wert (engl. L value) bezeichnet,
der Operand rechts als R-Wert (engl. R value). Verallgemeinert gesprochen sind
L-Werte Operanden, denen man einen Wert zuweisen kann, R-Werten kann kein
Wert zugewiesen werden. Alle beschreibbaren Variablen sind also L-Werte. Kon-
stanten, Literale* und konstante Zeichenketten (String Literalen) hingegen sind
R-Werte. Je nach Operator dürfen bestimmte Operanden nur L-Werte sein. Beim
Zuweisungsoperator muss beispielsweise der erste Operand ein L-Wert sein.  

a = 35;
In der Zuweisung ist der erste Operand die Variable a (ein L-Wert), der zweite
Operand das Literal 35 (ein R-Wert). Nicht erlaubt hingegen ist die Zuweisung
35 = a; //Fehler 

*Literale in Programmiersprachen:
Als Literal (lateinisch littera ‚Buchstabe‘) bezeichnet man in Programmiersprachen eine 
Zeichenfolge, die zur direkten Darstellung der Werte von Basistypen (z. B. Ganzzahlen, 
Gleitkommazahlen, Zeichenketten) definiert bzw. zulässig ist.

Quelle:
https://de.wikipedia.org/wiki/Literallle:
*/


// include sollte in visual studio anders aussehen
#include <msp430.h>
#include <math.h>

int main(void) {

    WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
	volatile int x, y, z;


	x = -3 + 4 * 5 - 6;  /* x = 11 */

  /* Sie koennen sich die Ergebnisse der folgenden Ausdruecke nach dem gleichen
     Muster ansehen.
  */
	x = 3 + 4 % 5 - 6;   /* x = 1 , beachte: % Divisionsrest */
	//linksassoziativ
	x = -3 * 4 % -6;     /* x = 0   da -12 ganzzahlig durch -6 dividierbar */

	//linksassoziativ
	x = (7 + 6) % 5 / 2; /* x = 1  */
	//linksassoziativ
	x = 2;
	x *= 3 + 2;          /* x = 10 */

	//linksassoziativ
//	x = x * (3 + 2);          /* x = 10 */
	x *= y = z = 4;      /* x = 40  y = 4  z = 4 */

	//rechtsassoziativ
	z = 4;
	y = z;
	x = x * y;

	z = 1;
	x = y == z;          /* x = 1  */

	return 0;
}

