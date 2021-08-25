#include <msp430g2553.h>

const int ccr0_init = 6947; // 6947; //7812;
int buttonPushed = 0;
int blinkMode = 0;
int blinkMask = BIT0;

int main(void) {
    WDTCTL = WDTPW + WDTHOLD;
    P1DIR = 0xFF;
    P1OUT = 0x00;
    P2DIR = 0xFF;
    P2OUT = 0x00;
    P3DIR = 0xFF;
    P3OUT = 0x00;
    P1DIR = BIT0;
    P1DIR = BIT6;
    P1REN = BIT3;
    P1OUT = BIT3;
    P1DIR = BIT0 + BIT6;
    BCSCTL1 |= 0x87;
    BCSCTL2 |= DIVS_2;
    TACTL = TASSEL_2 + MC_1 + ID_3;
    CCTL0 = CCIE;
    CCR0 = ccr0_init;
    __bis_SR_register(LPM0_bits + GIE);
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
        if(( P1IN & BIT3 ) == 0 )
        {
            if( !buttonPushed )
            {
                buttonPushed = 1;
                if( blinkMode == 0 ) {
                    blinkMask = BIT0;
                    P1OUT &= ~BIT6;
                    blinkMode = 1;
                }
                else if( blinkMode == 1 ) {
                    blinkMask = BIT6;
                    P1OUT &= ~BIT0;
                    blinkMode = 2;
                }
                else if( blinkMode == 2 ) {
                    blinkMask = BIT0 + BIT6;
                    P1OUT |= BIT0 + BIT6;
                    blinkMode = 3;
                }
                else
                {
                    blinkMask = BIT0 + BIT6;
                    P1OUT &= ~BIT0;
                    P1OUT |= BIT6;
                    blinkMode = 0;
                }
            }
        }
        else
        {
            buttonPushed = 0;
        }
    P1OUT ^= blinkMask;
}
