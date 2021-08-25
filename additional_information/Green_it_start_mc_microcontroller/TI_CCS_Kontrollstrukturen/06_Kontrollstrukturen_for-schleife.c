/*
 Titel: 	Kontrollstrukturen,  for-schleife
 LastEdit: 2019
 Author  : Prof. Dr. V.Iossifov, HTW Berlin
 System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
 
Aufgabe:	 
- Das 06_Kontrollstrukturen_for-schleife.c Programm uebersetzen und binden.
- Das 06_Kontrollstrukturen_for-schleife.c - F�hren Sie das Programm aus.
---------------------------------------------------------------------------
*/


/*
In der Regel besitzen for-Schleifen einen Schleifenz�hler. Dies ist eine Variable,
zu der bei jedem Durchgang ein Wert addiert oder subtrahiert wird (oder die durch
andere Rechenoperationen ver�ndert wird). Der Schleifenz�hler wird �ber den
ersten Ausdruck initialisiert. Mit dem zweiten Ausdruck wird �berpr�ft, ob die
Schleife fortgesetzt oder abgebrochen werden soll. Letzterer Fall tritt ein, wenn die-
ser den Wert 0 annimmt � � also der Ausdruck false (falsch) ist. Der letzte Ausdruck
dient schlie�lich dazu, den Schleifenz�hler zu ver�ndern.



*/
#include <msp430.h>
#include <math.h>

int main(void) {

    WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
	volatile int i;

	for(i = 5; i >= 0; --i);


/*
Die Schleife beginnt mit dem Wert 1 (i = 1) und erh�ht den Schleifenz�hler i bei
jedem Durchgang um 1 (++i). Solange der Wert i kleiner oder gleich 5 ist (i <= 5),
wird die Schleife durchlaufen. Ist i gleich 6 und daher die Aussage i <= 5 falsch,
wird der Wert 0 zur�ckgegeben und die Schleife abgebrochen. Insgesamt wird also
die Schleife 5mal durchlaufen. Wenn das Programm kompiliert und ausgef�hrt wird, 
erscheint die folgende Ausgabe auf dem Monitor:
1 2 3 4 5
*/

return 0;
}

/*
Damit die for -Schleife noch etwas klarer wird, wollen wir uns noch ein paar
Beispiele ansehen:
for(i = 0; i < 7; i += 1.5)
Der einzige Unterschied zum letzten Beispiel besteht darin, dass die Schleife nun in
1,5er Schritten durchlaufen wird. Der nachfolgende Befehl oder Anweisungsblock
wird insgesamt 5mal durchlaufen. Dabei nimmt der Schleifenz�hler i die Werte 0,
1.5, 3, 4.5 und 6 an. (Die Variable i muss hier nat�rlich einen Gleitkommadatentyp
haben.)

	for(i = 20; i > 5; i -= 5)

Diesmal z�hlt die Schleife r�ckw�rts. Sie wird dreimal durchlaufen. Der Schleifen-
z�hler nimmt dabei die Werte 20, 15 und 10 an. Und noch ein letztes Beispiel:
	
	for(i = 1; i < 20; i *= 2)

Prinzipiell lassen sich f�r die Schleife alle Rechenoperationen benutzen. In diesem
Fall wird in der Schleife die Multiplikation benutzt. Sie wird 5mal durchlaufen.
Dabei nimmt der Schleifenz�hler die Werte 1, 2, 4, 8 und 16 an.
Wie Sie aus der Syntax unschwer erkennen k�nnen, sind die Ausdr�cke in den
runden Klammern optional. So ist beispielsweise
	
	for(;;)

korrekt. Da nun der zweite Ausdruck immer wahr ist, und damit der Schleifenkopf
niemals den Wert 0 annehmen kann, wird die Schleife unendlich oft durchlaufen.
Eine solche Schleife wird auch als Endlosschleife bezeichnet, da sie niemals endet
(in den meisten Betriebssystemen gibt es eine M�glichkeit das dadurch "stillste-
hende" Programm mit einer Tastenkombination abzubrechen). Endlosschleifen
k�nnen beabsichtigt (siehe dazu auch weiter unten die break-Anweisung) oder
unbeabsichtigte Programmierfehler sein.
*/
