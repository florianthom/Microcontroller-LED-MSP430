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
- Das 05_operatoren_Logik3.c Programm uebersetzen und binden.
- Das 05_operatoren_Logik3.c -  Aufgabe: Beispiele fuer ganzzahlige Ausdruecke
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
    Ausgabe. Die Ein- und Ausgaben sind durch einfaches Kopieren erstellbar.
    Fuehren Sie einen ausfuehrlichen Test durch mehrfache Ausfuehrung
    des Programms durch. Testen Sie auch Grenzfaelle.
---------------------------------------------------------------------------
*/


#include <msp430.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int main(void) {

 WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer

volatile int a=5, b=10, TrueOrFalse;


 /* Geben Sie fuer jede Anweisung den Wert von "TrueOrFalse"
  mit Hilfe der Funktion "printf" aus.
  Pruefen Sie die Wirkung eines jeden Operators und vergleichen Sie mit
  der Darstellung im Skript von Dreyer "Programmieren in C" */

 /* Relationsoperatoren */
 TrueOrFalse = a > b;


 TrueOrFalse = a != b;


 TrueOrFalse = 99.0 == 99;


 TrueOrFalse = b / a < 0;


 TrueOrFalse = ++a == b != a * 2;

 /* Logische Ausdruecke */
 TrueOrFalse =  a < 7 && 7 < b;


 TrueOrFalse =  a < 7 < b;


 TrueOrFalse = !(TRUE || TRUE);


 TrueOrFalse = !TRUE || TRUE;


 TrueOrFalse = a < b && a > -10;


 TrueOrFalse = b - 5 || !3;


 TrueOrFalse = (1 || 1) + (a || ++b);


 TrueOrFalse = FALSE || TRUE && FALSE || !TRUE;


 /* lazy evaluation */
 TrueOrFalse = ( a < b ) || (a != 8);  /* (a != 8) wird nur ausgewertet, wenn a>b false ist  */
 
 TrueOrFalse = ( a > b ) && (a == --b);       /* --b nur wenn a>b true ist */


 return 0;
}

