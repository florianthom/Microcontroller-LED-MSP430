/*
Title      : Boolesche Ausdruecke
LastEdit: 2019
Author  : Prof. Dr. V.Iossifov, HTW Berlin
System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------
Schwerpunkte:   - Programmaufbau
                - Arbeiten mit dem Compiler

---------------------------------------------------------------------------
Aufgabe:
- Das 05_operatoren_Logik2.c Programm uebersetzen und binden.
- Das 05_operatoren_Logik2.c -  Aufgabe: Beispiele fuer ganzzahlige Ausdruecke
                                Verfolgen Sie mit dem Debugger die Wertänderungen
                                der Variablen.
---------------------------------------------------------------------------

Schwerpunkte:
   - Arbeit mit logischen Operatoren
   - Verwendung von  -- | ++ | ||  |  &&
   - Vorrangregeln bei der Auswertung von Ausdruecken
   - lazy Evaluation bei booleschen Ausdruecken

---------------------------------------------------------------------------
Aufgabe: 
    Gegeben sind die int-Variablen a und b. Formulieren Sie boolesche 
	 Ausdruecke mit diesen beiden Variablen so, dass bei den folgenden 
	 Aufgaben der vorgegebene Wahrheitswert herauskommt. Geben Sie die 
	 Ergebnisse aus und stellen Sie fest, welcher Wert in der Sprache C einer 
	 Variablen bei "wahr" bzw "falsch" zugewiesen wird..
	
	 Es soll wahr herauskommen, wenn:

		- eine von beiden Variablen 0 ist
		- beide Variablen 0 sind
		- eine Variable negativ ist
		- solange a maximal den gleichen Wert wie b hat
		- die Differenz beider Variablen kleiner als 5 ist.

	Es soll falsch herauskommen, wenn:

		- a und b verschiedene Werte haben
		- b maximal den gleichen Wert wie a hat
		- beide positiv sind
		- eine oder beide 0 sind
		- a maximal 2 ist und b minimal 3 ist.
	
	Schreiben Sie zu jeder Aufgabe eine Eingabe mit Kommentar und eine
	Ausgabe.
	Die Ein- und Ausgaben sind durch einfaches Kopieren erstellbar.
	Fuehren Sie einen ausfuehrlichen Test durch mehrfache Ausfuehrung
	des Programms durch. Testen Sie auch Grenzfaelle.
---------------------------------------------------------------------------
*/


#include <msp430.h>
#include <math.h>

int main(void) {

 WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer

volatile int a, b, ergebnis;

/* Es soll wahr herauskommen, wenn:   */

/*	- eine von beiden Variablen 0 ist	*/
ergebnis =  a==0 || b==0;

/* 	- beide Variablen 0 sind */
ergebnis =   a==0 && b==0;

/* 	- eine Variable negativ ist */
/*      ?? Aufgabe ungenau: genau eine, hoechstens eine ?? */
ergebnis =  a<0 || b<0;
                    		

/* 	- solange a maximal den gleichen Wert wie b hat */
ergebnis =   a<=b;

/* 	- die Differenz beider Variablen kleiner als 5 ist.*/
ergebnis =   (a-b) < 5;


/*  Es soll falsch herauskommen, wenn:    */

/* - a und b verschiedene Werte haben */
ergebnis =   (a == b);

/* - b maximal den gleichen Wert wie a hat */
ergebnis =   !(b <= a);


/*        - beide positiv sind */
ergebnis =   !(a>0 && b>0);

/*        - eine oder beide 0 sind  */
ergebnis =   !((a == 0) || (b == 0));


/*        - a maximal 2 ist und b minimal 3 ist. */
ergebnis =   !((a<= 2) && (b>=3));



return	0;

}


#if 0

/* Bei der Zusammenstellung von Testdaten versucht man, mit moeglichst
   wenigen Testfaellen moeglichste viele Anweisungen zu ueberpruefen.
   Die Daten sollte man unbedingt mit Kommentaren versehen, so dass man
   auch spaeter noch nachvollziehen kann, welcher Test mit welchem Ziel
   durchgeführt wurde.
   Beachten Sie, dass Testdaten in einigen Faellen redundant sind, d.h.
   man haette darauf verzichten koennen, z.B. muss man fuer Aufgabe 4
   nur drei Faelle ueberpruefen, a<b, a=b, a>b
*/
         
/*
  a  |  b  |  bei Aufgabe  | Nachweiss, dass Aussage (entspricht Testziel)
-----|-----|---------------|----------------------------------------------

Ueberlegung: Man muss in einigen Faellen ueberpruefen, was bei Gleichheit 
             passiert. In einigen Faellen ist der Sonderfall 0 (null)
             wichtig. Also werden beide Situationen beruecksichtigt, indem
             Gleichheit mit a=0 und b=0 getestet wird.

     |     |               |
  0  |  0  |      1        | falsch, da a = b
  0  |  0  |      2        | wahr, da a und b gleich 0
  0  |  0  |      3        | falsch, da a und b > 0
  0  |  0  |      4        | wahr, da a gleich b
  0  |  0  |      5        | wahr, da null < 5

Ueberlegung: Es fehlen noch einige Nachweise fuer das Verhalten bei 0 (null).
             Ausserdem sollen in einigen Faellen neg.Werte einbezogen werden. 
             Desweiteren braucht man Daten, bei denen gilt a > b

     |     |               |
  0  | -1  |      1        | wahr, da a=0, b!=0
  0  | -1  |      2        | falsch, da b != 0
  0  | -1  |      3        | wahr, da b negativ
  0  | -1  |      4        | falsch, da a nicht < b
  0  | -1  |      5        | wahr, da 1 < 5

Ueberlegung: Siehe oben, Hier verwendet man Daten fuer die gilt a < b
     |     |               |
  -1 |  0  |      1        | wahr, da a!=0, b=0
  -1 |  0  |      2        | falsch, da a != 0
  -1 |  0  |      3        | wahr, da a negativ
  -1 |  0  |      4        | wahr, da a  < b
  -1 |  0  |      5        | wahr, da -1 < 5

Ueberlegung: Es muss ueberprueft werden was passiert, wenn beide Zahlen negativ
             sind. Ausserdem fehlt noch ein Testfall fuer (a-b) < 5, d.h. der Nachweis
             dass sich  bei (a-b) > 5 die Aussage 'falsch' ergibt. 
     |     |               |
  -1 |  -10|      1        | falsch, da a!=0 und b!=0
  -1 |  -10|      2        | falsch, da sowohl a!=0 als auch b!=0
  -1 |  -10|      3        | wahr, da sowohl a als auch b negativ
  -1 |  -10|      4        | falsch, da -1 > -10 
  -1 |  -10|      5        | falsch, da 9 < 5  falsch ergibt

*/

/* Stellen Sie eine aehnliche Tabelle fuer den Test des zweiten Programmteils
   zusammen.
*/

#endif
