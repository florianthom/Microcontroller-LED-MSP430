
#include <msp430.h>

/**
 * Main
 */
int main(void) {
    WDTCTL = WDTPW + WDTHOLD;           // Stop WDT

//    P1DIR &= 0x00;                        // P1DIR reset
//    P1OUT &= 0x00;                        // P1OUT reset
    P1DIR |=  0x01;                    // P1DIR P1.0 -- LED

//    P1DIR |= (1 << 4);                    // P1DIR P1.4 -- CLOCK
//    P1SEL |= (1 << 4);                    // P1SEL P1.4 -- CLOCK

    // dcoctl=dco controll register
    // The DCO is an integrated digitally controlled oscillator. The DCO frequency can be adjusted by software using the DCOx, MODx, and RSELx bits.
    //      The four RSELx bits select one of sixteen nominal frequency ranges for the DCO. These ranges are defined for an individual device in the device-specific data sheet.
    //          - The three DCOx bits divide the DCO range selected by the RSELx bits into 8 frequency steps, separated by approximately 10%.
    //          - The five MODx bits, switch between the frequency selected by the DCOx bits and the next higher frequency set by DCOx+1. When DCOx = 07h, the MODx bits have no effect because the DCO is already at the highest setting for the selected RSELx range.
    // After a PUC, RSELx = 7 and DCOx = 3
    // dco = internal oscillator = digital controller escillator
    // 1.5 mhz (-0.8mhz)
    // can be configured to be used by the smclk (sub-main clock)
    // p. 283 family guide, p.29 device guide
    // bit 7-5= dco frequency select: these bits select which of the eight descrete dco frequencies within the range defined by the RSELx setting is selected
    // set frequency to around 1.5mhz
    // default =3= 0.8-1.5MHz, here=7 (higher than 0.8-1.5Mhz) (since we only view at the last 3 bits) -> can be omitted if we reduce ccr0 i guess
//    DCOCTL |= 0xE0;                        // DC0 CTL     = 1110 0000 // 224

    // BCSCTL1 = Basic clock system control register 1
    // "p. 283 family guide
    // bit 7: turns off the xt2 oscillator -> 1=off -> not used for mclk or smclk
    //      - smclk use dco oscillator: since we turn off xt2, we indirectly choose that we want to use dcoclk oscillator with the smclk clock
    // bit 3-0: = RSEL = range select: 16 different frequency ranges are available
    //  - default: 7, here: 7
    BCSCTL1 |= 0x87;                    // BCS CTL1     = 1000 0111 // 135

    // BCSCTL2 = Basic Clock System control register 2
    // bit 2-1 for smckl
    // bits(2-1): 10 (means bit 2 is 1 and bit 1 is 0) equals division of 4
    BCSCTL2 |= DIVS_2;                    // SMCLK divided by 2^2=4 // DIVS_2= (0x04) = Bit2 (of Bit0-Bit7)

    // tassel_2: use smclk, mc_1: continous up mode, id_3: /* Timer A input divider: 3 (Bits) = /8 (division by 8) */
    TACTL = TASSEL_2 + MC_1 + ID_3;        // TA0 CTL = 1011 01000
    CCTL0 = CCIE;                        // TA0 CCTL0
//    CCR0 = 24198;                        // TA0 CCR0 value is 24198 (0x5E86)
    CCR0 = 15625;                        // TA0 CCR0 value is 24198 (0x5E86)


    __bis_SR_register(LPM0_bits + GIE); // LowPower0 + Global Interrupt Enabled
}

/**
 * Timer A0 interrupt service routine
 */
#pragma vector=TIMER0_A0_VECTOR
__interrupt void timer(void) {
    P1OUT ^= 0x01;
}
