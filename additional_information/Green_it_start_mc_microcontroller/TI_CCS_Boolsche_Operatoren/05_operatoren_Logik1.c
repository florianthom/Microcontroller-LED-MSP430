/*
Title	   : Boolesche Ausdruecke
LastEdit: 2019
Author  : Prof. Dr. V.Iossifov, HTW Berlin
System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------
Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
Aufgabe:	 
- Das 05_operatoren_Logik1.c Programm uebersetzen und binden.
- Das 05_operatoren_Logik1.c -  Aufgabe: Beispiele fuer ganzzahlige Ausdruecke
                                 Verfolgen Sie mit dem Debugger die Wertänderungen
                                 der Variablen.
---------------------------------------------------------------------------
*/
/*


Schwerpunkte:  
   - Arbeit mit logischen Operatoren
   - Verwendung von  -- | ++ | ||  |  &&
   - Vorrangregeln bei der Auswertung von Ausdruecken
   - lazy Evaluation bei booleschen Ausdruecken

---------------------------------------------------------------------------

Aufgabe: 
Ueberlegen Sie, was durch die folgenden Anweisungen berechnet wird. Was 
steht jeweils nach der Abarbeitung eines booleschen Ausdruckes in x, y 
bzw. z?
Ist der boolesche Ausdruck wahr oder falsch?
Ergaenzen Sie danach das Programm um Ausgabeanweisungen, uebersetzen Sie 
es und ueberpruefen Sie Ihre Loesungen.

---------------------------------------------------------------------------
*/

#include <msp430.h>
#include <math.h>

void main(void) {

 WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer

  volatile int x, y, z;
  volatile int Ergebnis; /* das Ergebnis, das sich bei Auswertung der Ausdruecke ergibt */

  /* Beispiele fuer lazy Evaluation: d.h. Ausdruecke werden nur ausgewertet, wenn 
     das Ergebnis der Auswertung wirklich benoetigt wird. Achtung, dass kann 
     Probleme geben, wenn man auf die (evtl. gar nicht veraenderten!) Variablen
     an anderen Stellen im Programm zurueckgreift. Man nennt sowas 'Seiteneffekt'
     ein Fehler, der schwer zu finden ist, weil er nicht immer auftritt und 
     ausserdem noch abhaengig vom verwendeten Compiler ist, d.h. ein Programm
     kann prima laufen bis es mal mit einem anderen Compiler uebersetzt wird.
     Die sicherste Variante, um solche Probleme zu vermeiden, besteht darin, auf solche
     Ausdruecke  zu verzichten und statt dessen etwas ausfuehrlicher zu schreiben,
     was man eigentlich ausdruecken will, z,B. wuerde man fuer 
  
      ++x || ++y && ++z;

      besser schreiben
      
        x++;    man koennte auch ++x schreiben, das aendert hier nichts 
        y++;    dito 
        z++;    dito 
        Jetzt haben sich die Inhalte der Variablen x, y, z garantiert geaendert.
        x || y && z;
  */


  /* Die Ergebnisse, die sich bei der Auswertung der folgenden Anweisungen ergeben,
     sind vom verwendeten Compiler abhaengig. Sehen Sie sich an, wie Ihr Compiler
     mit den Anweisungen umgeht, indem Sie zusaetzliche Ausgaben in das Programm
     einfuegen.   
  */

  x = 45;
  y = 35;

  z = 13 & 03;	//Bitweise UND!!1101 & 0011 == 0001
  z = x & y;	//				0011
				//				----
				//				0001

  z = 45 && 35;	//Datentypweise UND!!WAHR && WAHR == WAHR
  z = 45 && 00;	//Datentypweise UND!!WAHR && UNWAHR == UNWAHR

  z = 13 | 00;	//Bitweise ODER!!1101 | 0000 == 1101
  y = 0;
  z = x | y;	//				        0000
				//				        ----
				//				        1101

  z = 45 || 00;	//Datentypweise ODER!!WAHR || FALSCH == WAHR

	x = y = z = 1;

  Ergebnis = ++x || ++y && ++z;
  z = 0;
  x = y = 1;
  Ergebnis = x++ || (y++ && z++);

  z = 0;
  x = y = 1;
  Ergebnis = z++ && (y++ || x++);

  /* Sie koennen sich die Ergebnisse der folgenden Ausdruecke nach dem gleichen
     Muster ansehen.
  */

	x = y = z = 1;
	++x && ++y || ++z;

	x = y = z = 1;
	++x && ++y && ++z;

	x = y = z = -1;
	++x || ++y && ++z;

	x = y = z = -1;
	++x && ++y || ++z;

	x = y = z = -1;
	++x && ++y && ++z;
	
	return 0;

}
