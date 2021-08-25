/*
 Titel: 	Kontrollstrukturen,  for-schleife verschachtelt
 LastEdit: 2019
 Author  : Prof. Dr. V.Iossifov, HTW Berlin
 System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------

Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
	 
Aufgabe:	 
- Das 06_Kontrollstrukturen_for-schleife-verschachtelt.c Programm uebersetzen und binden.
- Das 06_Kontrollstrukturen_for-schleife-verschachtelt.c - Führen Sie das Programm aus.
---------------------------------------------------------------------------
*/


/*
Mehrere Befehle hinter einer for-Anweisung müssen immer in Blockklammern
eingeschlossen werden:
	for(i = 1; i < 5; i++)
	{
		printf("\nEine Schleife: ");
		printf("%d ", i);
	}

*/

/*
Schleifen lassen sich auch schachteln, das heißt, innerhalb einer Schleife dürfen
sich eine oder mehrere weitere Schleifen beﬁnden. Beispiel:
*/


#include <msp430.h>
#include <math.h>

int main(void) {

    WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer
    volatile int i, j, Zahl = 1, ergebnis;

	for (i = 11; i >= 0; i--)
	{
		for (j = 10; j >= 0; j--)
		    ergebnis =  Zahl++;
	}

return 0;
}

/*
Nach der Kompilierung und Übersetzung des Programms erscheint die folgende
Ausgabe:
1	2	3	4	5	6	7	 8	9	10
11	12	13	14	15	16	17	18	19	20
21	22	23	24	25	26	27	28	29	30
31	32	33	34	35	36	37	38	39	40
41	42	43	44	45	46	47	48	49	50
51	52	53	54	55	56	57	58	59	60
61	62	63	64	65	66	67	68	69	70
71	72	73	74	75	76	77	78	79	80
81	82	83	84	85	86	87	88	89	90
91	92	93	94	95	96	97	98	99	100
101 102 103 104 105 106 107 108 109 110


*/
