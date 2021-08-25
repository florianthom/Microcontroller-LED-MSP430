/*
Titel: 	Operatoren,  Rangfolge und Assoziativität
LastEdit: 2019
Author  : Prof. Dr. V.Iossifov, HTW Berlin
System  : ANSI-C-Compiler / TI CCS
---------------------------------------------------------------------------
Schwerpunkte:  	- Programmaufbau
               	- Arbeiten mit dem Compiler

---------------------------------------------------------------------------
	 
Aufgabe:	 
- Das 05_operatoren_ Rangfolge und Assoziativität.c Programm uebersetzen und binden.
- Das 05_operatoren_ Rangfolge und Assoziativität.c- Führen Sie das Programm aus.
---------------------------------------------------------------------------
*/
//C-Programmierung: Liste der Operatoren nach Priorität
//https://de.wikibooks.org/wiki/C-Programmierung:_Liste_der_Operatoren_nach_Priorit%C3%A4t
//https://msdn.microsoft.com/de-de/library/126fe14k.aspx

//Rangfolge und Assoziativität

#include <msp430.h>
#include <math.h>



int _a() {
	volatile int a=1, b=2;
	a = a+b;
	return (a);
}
int _b() {
    volatile int  c=1, b=2;
	b = c+b;
	return (b);
}


int _c() {
    volatile int a=1, c=2;
	c = c+a;
	return (c);
}



int main(void) {

 WDTCTL = WDTPW + WDTHOLD;            // stop watchdog timer


/*
Wie Sie bereits im ersten Kapitel gesehen haben, besitzen der Mal- und der Geteilt-
Operator eine höhere Rangfolge (auch als Priorität bezeichnet) als der Plus- und
der Minus-Operator. Diese Regel ist Ihnen sicher noch aus der Schule als "Punkt
vor Strich" bekannt.
Was ist mit einem Ausdruck wie beispielsweise:
*/
volatile int x = 6, a = 6, b =3, d = 2, i =7, ergebnis;
volatile int c = sizeof(x) + ++a / 3;

/*
In C hat jeder Operator eine Rangfolge, nach der der Compiler einen Ausdruck
auswertet. Diese Rangfolge ﬁnden Sie in der Referenz dieses Buches.
Der sizeof() - sowie der Präﬁx-Operator haben die Priorität 14, + die Priorität
12 und / die Priorität 13
*/

//Folglich wird der Ausdruck wie folgt ausgewertet:

c = sizeof(x);

c = (sizeof(x)) + ((++a) / 3);

/*
Neben der Priorität ist bei Operatoren mit der gleichen Priorität auch die Reihenfol-
ge (auch als Assoziativität bezeichnet) der Auswertung von Bedeutung. So muss
beispielsweise der Ausdruck
*/

ergebnis = 4 / 2 / 2;

//von links nach rechts ausgewertet werden:

ergebnis = (4 / 2) / 2; // ergibt 1

//Wird die Reihenfolge dieser Auswertung geändert, so ist das Ergebnis falsch:

ergebnis = 4 / (2 / 2); // ergibt 4

//In diesem Beispiel ist die Auswertungsreihenfolge

ergebnis = (4 / 2) / 2;

//also linksassoziativ.

//Nicht alle Ausdrücke werden aber von links nach rechts ausgewertet, wie das
//folgende Beispiel zeigt:

ergebnis = a = b = c = d;

//Durch Klammerschreibweise verdeutlicht, wird dieser Ausdruck vom Compiler von
//rechts nach links ausgewertet:

ergebnis = a = (b = (c = d));
//Der Ausdruck ist also rechtsassoziativ.

//Dagegen lässt sich auf das folgende Beispiel die Assoziativitätsregel nicht anwenden:

ergebnis = 5 + 4 * 8 + 2;

//Sicher sieht man bei diesem Beispiel sofort, dass es wegen "Punkt vor Strich" keinen
//Sinn macht, eine bestimmte Bewertungsreihenfolge festzulegen. 

/*
Fast alle C-Programme besitzen sogenannte Nebenwirkungen (engl. side effect;
teilweise auch mit Seiteneffekt übersetzt). Als Nebenwirkungen bezeichnet man
die Veränderung des Zustandes des Rechnersystems durch das Programm. Typi-
sche Beispiele hierfür sind Ausgabe, Eingabe und die Veränderung von Variablen.
Beispielsweise führt i++ zu einer Nebenwirkung - die Variable wird um eins
erhöht.
Der C-Standard legt im Programm bestimmte Punkte fest, bis zu denen Nebenwir-
kungen ausgewertet sein müssen. Solche Punkte werden als Sequenzpunkte (engl.
sequence point) bezeichnet. In welcher Reihenfolge die Nebenwirkungen vor dem
Sequenzpunkt auftreten und welche Auswirkungen dies hat, ist nicht deﬁniert.
Die folgenden Beispiele sollten dies verdeutlichen:
*/

i = 3;
a = i + i++;

/*
Da der zweite Operand der Addition ein Postﬁx-Inkrement-Operator ist, wird dieser
zu 3 ausgewertet. Je nachdem, ob der erste Operand vor oder nach Einsetzen der
Nebenwirkung ausgewertet wird (also ob i noch 3 oder schon 4 ist), ergibt die
Addition 6 oder 7. Da sich der Sequenzpunkt aber am Ende der Zeile beﬁndet,
ist beides möglich und C-konform. Um es nochmals hervorzuheben: Nach dem
Sequenzpunkt besitzt i in jedem Fall den Wert 4. Es ist allerdings nicht deﬁniert,
wann i inkrementiert wird. Dies kann vor oder nach der Addition geschehen.
*/


//Beispiel:

x = _a() + _b() - _c();

x = _a();
x = x + _b();
x = x - _c();
/*
Wie wir oben gesehen haben, ist festgelegt, dass der Ausdruck von links nach rechts
ausgewertet wird ((_a() + _b()) - _c() ), da der Ausdruck rechtsassoziativ
ist. Allerdings steht damit nicht fest, welche der Funktionen als erstes aufgerufen
wird. Der Aufruf kann in den Kombinationen _a, _b, _c oder _a, _c, _b oder _b, _a, _c
oder _b, _c, _a oder _c, _a, _b oder _c, _b, _a erfolgen. Welche Auswirkungen dies auf die
Programmausführung hat, ist undeﬁniert.
*/
return 0;
}
