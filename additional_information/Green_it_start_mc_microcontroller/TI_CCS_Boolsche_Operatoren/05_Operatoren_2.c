/*
LastEdit: 2019
Author  : Prof. Dr. V.Iossifov, HTW Berlin
System  : ANSI-C-Compiler / TI CCS

---------------------------------------------------------------------------
Schwerpunkte:   - Programmaufbau
                - Arbeiten mit dem Compiler

---------------------------------------------------------------------------
Aufgabe:
- Das 05_operatoren.c Programm uebersetzen und binden.
- Das 05_operatoren.c -  Aufgabe: Beispiele fuer ganzzahlige Ausdruecke
                         Verfolgen Sie mit dem Debugger die Wertänderungen
                         der Variablen.
---------------------------------------------------------------------------

*/

#include <msp430.h>
#include <math.h>

void main(void) {

 WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
 volatile int a = 3, b = 2, c = 0xa, d;


 /* Geben Sie fuer jede Anweisung die Werte von "a" und "d"
  mit Hilfe der Funktion "printf" aus.Pruefen Sie die Wirkung 
  eines jeden Operators und vergleichen Sie mit der Darstellung 
  im Skript von Dreyer "Programmieren in C" */

 d = a + b;

 d = d - a;
 d -= a;
 d = d * 3 + 5;
 //linksassoziativ

 d *= 3 + 5;
 //linksassoziativ

 a = a +1;
 a += 1;
 d = 10 - a++;

 d = 10 - ++a;
 d = a + b * c - d;

 d = (a + (d * c)) - d;

 return 0;
}

