// project folder: C:\Users\s0558_000\workspace_v10\Green_it_start_mc_microcontroller
// builded main under debug-folder

#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
    // = für alle microcontroller gleich
    // sinn: falls sich microcontroller aufhängt, kann man ihn ja nicht mehr stoppen und hat oft keinen
    // Zugriff mehr
    // Sinn: watchdog timer unterbricht den controller immer wieder selbst
    //          -> in der Entwicklung kontroproduktiv, deswegen ausschalten
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	return 0;
}
