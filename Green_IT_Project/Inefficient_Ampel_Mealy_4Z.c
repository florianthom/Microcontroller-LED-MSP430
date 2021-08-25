#include <msp430g2553.h>

#define LED BIT0
#define BUTTON BIT3

int main(void) {






    /* Clear and hold the watch dog timer so it doesn't reset our chip */
    WDTCTL = WDTPW + WDTHOLD;

    //SW Entprellen
        P1DIR = LED;
        P1REN = BUTTON;
        P1OUT = BUTTON;

    /* Configure pins 0,6 on port 1 as output pins */
    P1DIR = BIT0 + BIT6;

    /* a flag to tell us when we've handled a button event */
    int buttonPushed = 0;

    /* we'll toggle between different modes */
    int blinkMode = 0;

    /* which lights we need to blink -- start red only */
    int blinkMask = BIT0;

    /* make sure green (pin 6) is turned off */
    P1OUT &= ~BIT6;


    /* infinite loop */
    for( ; ; )
    {


        int j;
        /* delay while watching for button presses */
        for( j = 0; j < 100; j++ )
        {
            /* The following two lines implement a very crude delay loop.
             * The actual length of the delay can vary significantly.
             * This approach may not work with all compilers.
             */
            volatile int i;
            for( i = 0; i < 200; i++ );



            /* Switch 1 is connected to pin 3.  If it is low, then change the
             * blinking behavior (unless it we have handled the press already)
             */
            if(( P1IN & BIT3 ) == 0 )
            {
                if( !buttonPushed )
                {
                    /* remember so we don't try to handle this press again */
                    buttonPushed = 1;

                    blinkMode = (blinkMode + 1)%4;

                    if( blinkMode == 0 ) {
                        /* blink red (bit 0) only */
                        blinkMask = BIT0;

                        /* make sure green (pin 6) is off */
                        P1OUT &= ~BIT6;
                    }
                    else if( blinkMode == 1 ) {
                        /* blink green (pin 6) only */
                        blinkMask = BIT6;

                        /* make sure red (pin 0) is off */
                        P1OUT &= ~BIT0;
                    }
                    else if( blinkMode == 2 ) {
                        /* blink both together */
                        blinkMask = BIT0 + BIT6;

                        /* make sure both are on */
                        P1OUT |= BIT0 + BIT6;
                    }
                    else
                    {
                        /* blink both alternately */
                        blinkMask = BIT0 + BIT6;

                        /* make sure red is off and green is on */
                        P1OUT &= ~BIT0;
                        P1OUT |= BIT6;
                    }
                }
            }
            else
            {
                buttonPushed = 0;
            }


        }

        /* blink the lights */
        P1OUT ^= blinkMask;

    }
}
