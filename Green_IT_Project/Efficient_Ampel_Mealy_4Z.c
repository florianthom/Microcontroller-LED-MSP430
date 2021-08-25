/*

    ULP-Advisor Recommendations (9):
        1. (ULP 13.1) Detected loop counting up. Recommend loops count down as detecting zeros is easier, line 99
            - recommendation example:
                    for (i = 5000; i>0; i--) // In instead of: (i = 0; i <5000; i++)
            - own solution:
                    - replace loop with interrupt

        2. (ULP 13.1) Detected loop counting up. Recommend loops count down as detecting zeros is easier, line 106
            - recommendation example:
                    for (i = 5000; i>0; i--) // In instead of: (i = 0; i <5000; i++)
            - own solution:
                    - use of that loop was to decrease the frequency (herz), this lower frequency/this delay was realized within the loop descript in 1.. So this loop got deleted.

        3. (ULP 11.2) Assignment of higher bits (constants) to "P1OUT" within a loop. Recommend using lower 4 bits to allow use of constant generators, line 141
            -recommendation example:
                    void main(void)
                    {
                      unsigned int i, variable=FLAG_1;
                      P1DIR |= BIT2;                   // Use P1.2 for bit-banging, change direction to output
                      P1DIR &= ~BIT2;                  // Reset pin P1.2
                      for (i=0;i < 1000;i++)
                      {
                         //Execute application code
                         P1DIR ^= BIT2;                // Toggle port pin P1.2, leverage BIT2 constant generator
                      }
                    }
            - own solution:
                - the loop got replaced by a ISR (Interrupt Service Routine)
                - so this advice got solved indirectly by solving advice 1


        4. (ULP 11.2) Assignment of higher bits (constants) to "P1OUT" within a loop. Recommend using lower 4 bits to allow use of constant generators, line 150
            -recommendation example:
                    void main(void)
                    {
                      unsigned int i, variable=FLAG_1;
                      P1DIR |= BIT2;                   // Use P1.2 for bit-banging, change direction to output
                      P1DIR &= ~BIT2;                  // Reset pin P1.2
                      for (i=0;i < 1000;i++)
                      {
                         //Execute application code
                         P1DIR ^= BIT2;                // Toggle port pin P1.2, leverage BIT2 constant generator
                      }
                    }
            - own solution:
                - the loop got replaced by a ISR (Interrupt Service Routine)
                - so this advice got solved indirectly by solving advice 1

        5. (ULP 5.1) Detected modulo operation(s). Recommend moving them to RAM during run time or not using as these are processing/power intensive, line 120
            - referred line=  blinkMode = (blinkMode + 1)%4;
            - recommendation
                - key idea behind RAM-executed functions is to link thefunctions to a memory section with the following attribute: "load= FLASH_AREA, run = RAM_AREA" defined in the linker command file.
                    - 1. Create a load = FLASH, run = RAM memory section inthe device linker command file.
                        - Before RAM : origin = 0x2400, length = 0x2000, After: RAM_EXECUTE : origin = 0x2400, length = 0x0200
                    - 2. Relocate user-generated functions:
                        -   #pragma CODE_SECTION(FunctionName,".run_from_ram")
                            void FunctionName(void)
                            {
            - own solution
                - the idea behind the referred line (line 106) is to select the new state in the mealy-state-machine
                - so this advices got solved by installing a new mechanism to get the new state
                    - specific: to get/to store new state the variable blinkMode does not just increment with each state, but stores the following state when switching to a new state: example shows process when switching to state 0:
                     - if( blinkMode == 0 ) {
                            blinkMask = BIT0;
                            P1OUT &= ~BIT6;
                            blinkMode = 1;
                        }

        6. (ULP 2.1) Detected SW delay loop using empty loop. Recommend using a timer module instead, line 106
            - recommendation
                 void main(void)
                 {
                   WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
                   P1DIR |= 0x01;                            // P1.0 output
                   CCTL0 = CCIE;                             // CCR0 interrupt enabled
                   CCR0 = 50000;
                   TACTL = TASSEL_2 + MC_2;                  // SMCLK, contmode

                   _BIS_SR(LPM0_bits + GIE);                 // Enter LPM0 w/ interrupt
                 }

                 // Timer A0 interrupt service routine
                 #pragma vector=TIMER0_A0_VECTOR
                 __interrupt void Timer_A (void)
                 {
                   P1OUT ^= 0x01;                            // Toggle P1.0
                   CCR0 += 50000;                            // Add Offset to CCR0
                 }
            - own solution:
                - see point 9.

        7. (ULP 4.1) Detected uninitialized Port 3 in this project. Recommend initializing all unused ports to eliminate wasted current consumption on unused pins., line -
            - recommendation example
                    P1DIR = 0xFF;
                    P1OUT = 0x00;
            - own solution
                -   P3DIR = 0xFF;
                    P3OUT = 0x00;

        8. (ULP 4.1) Detected uninitialized Port 2 in this project. Recommend initializing all unused ports to eliminate wasted current consumption on unused pins., line -
            - recommendation example
                    P1DIR = 0xFF;
                    P1OUT = 0x00;
            - own solution
                    P2DIR = 0xFF;
                    P2OUT = 0x00;

        9. (ULP 1.1) Detected no uses of low power mode state changing instructions, line -
            - recommendation example

                void main(void)
                {
                    BCSCTL1 |= DIVA_2;                        // ACLK/4
                    WDTCTL = WDT_ADLY_1000;                   // WDT 1s/4 interval timer
                    IE1 |= WDTIE;                             // Enable WDT interrupt
                    P1DIR = 0xFF;                             // All P1.x outputs
                    P1OUT = 0;                                // All P1.x reset
                    P2DIR = 0xFF;                             // All P2.x outputs
                    P2OUT = 0;                                // All P2.x reset

                    while(1)
                    {
                        int i;
                        P1OUT |= 0x01;                            // Set P1.0 LED on
                        for (i = 5000; i>0; i--);              // Delay
                        P1OUT &= ~0x01;                       // Reset P1.0 LED off
                        __bis_SR_register(LPM3_bits + GIE);       // Enter LPM3
                    }
                }

                #pragma vector=WDT_VECTOR
                __interrupt void watchdog_timer (void)
                {
                 __bic_SR_register_on_exit(LPM3_bits);                 // Clear LPM3 bits from 0(SR)
                }


            - own solution
                BCSCTL1 |= 0x87;
                BCSCTL2 |= DIVS_2;
                TACTL = TASSEL_2 + MC_1 + ID_3;
                CCTL0 = CCIE;
                CCR0 = ccr0_init;
                __bis_SR_register(LPM0_bits + GIE); // LowPower0 + Global Interrupt Enabled
                //[...]
                #pragma vector=TIMER0_A0_VECTOR
                __interrupt void Timer_A (void)
                {
                    // [...]
                }

 */



#include <msp430g2553.h>


// reduce number, to which timer counts up, with devisor 2 to get 2 hz

const int ccr0_init = 6947; // 6947; //7812;
int buttonPushed = 0;
int blinkMode = 0;
int blinkMask = BIT0;



int main(void) {



    WDTCTL = WDTPW + WDTHOLD;



    // disable left undefined ports
    P1DIR = 0xFF;
    P1OUT = 0x00;

    P2DIR = 0xFF;
    P2OUT = 0x00;

    P3DIR = 0xFF;
    P3OUT = 0x00;



    // entprellen der green-led
    P1DIR = BIT0;
    // entprellen der red-led
    P1DIR = BIT6;

    // initialize button
    P1REN = BIT3;
    P1OUT = BIT3;

    // set green and red leds as Output
    P1DIR = BIT0 + BIT6;

    // Basic Clock System control register 1
    // disable of XT1-Oscillator -> use DCO (digitally controlled oscillator)
    BCSCTL1 |= 0x87;

    // Basic Clock System control register 2
    // SMCLK divided by 2^2=4
    BCSCTL2 |= DIVS_2;

    // tactl=timer a control
    // tassel_2: use smclk, mc_1: continous up mode, id_3:
    TACTL = TASSEL_2 + MC_1 + ID_3;

    // sets the Capture/Compare control 0 to enable Timer Interrupts. CCIE means „Capture/Control Interrupt Enable“.
    CCTL0 = CCIE;
    CCR0 = ccr0_init;

    __bis_SR_register(LPM0_bits + GIE); // LowPower0 + Global Interrupt Enabled

}

// ISR
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{

        // If you press the button, then P1IN = 0. By default, P1IN will be 1.
        if(( P1IN & BIT3 ) == 0 )
        {
            // important since if the hold the key, the leds should just go into the next state and not shine both (without buttonPushed-function they will)
            if( !buttonPushed )
            {
                buttonPushed = 1;

                if( blinkMode == 0 ) {
                    /* blink green (bit 0) only */
                    blinkMask = BIT0;

                    /* make sure green (pin 6) is off */
                    // Clear single bit, preserve others
                    P1OUT &= ~BIT6;
                    blinkMode = 1;
                }
                else if( blinkMode == 1 ) {
                    /* blink red (pin 6) only */
                    blinkMask = BIT6;

                    /* make sure red (pin 0) is off */
                    // Clear single bit, preserve others
                    P1OUT &= ~BIT0;
                    blinkMode = 2;

                }
                else if( blinkMode == 2 ) {
                    /* blink both together */
                    blinkMask = BIT0 + BIT6;

                    /* make sure both are on, important is here that both are at the same status, either on or off */
                    // the blinking is independent of this constant setting (but only after both led's got set initially to the same level)
                    P1OUT |= BIT0 + BIT6;
                    blinkMode = 3;

                }
                else
                {
                    /* blink both alternately */
                    blinkMask = BIT0 + BIT6;

                    /* make sure red is off and green is on */
                    // Clear single bit, preserve others
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




/*
    Results:
        inefficient:

            +------+----------+-------------+---------------+---------------+--------------+
            | Time |  Energy  | Power(Mean) | Voltage(Mean) | Current(Mean) | Battery Life |
            +------+----------+-------------+---------------+---------------+--------------+
            |   10 | 66.819mJ | 6.8344 mW   | 3.2753V       | 2.0874mA      |          98h |
            +------+----------+-------------+---------------+---------------+--------------+

        efficient:

            +------+----------+-------------+---------------+---------------+--------------+
            | Time |  Energy  | Power(Mean) | Voltage(Mean) | Current(Mean) | Battery Life |
            +------+----------+-------------+---------------+---------------+--------------+
            |   10 | 56.175mJ | 6.1339mW    | 3.2735V       | 1.8735mA      | 117h         |
            +------+----------+-------------+---------------+---------------+--------------+

        comparison:

            +------+----------+-------------+---------------+---------------+--------------+
            | Time |  Energy  | Power(Mean) | Voltage(Mean) | Current(Mean) | Battery Life |
            +------+----------+-------------+---------------+---------------+--------------+
            |   10 | 66.819mJ | 6.8344 mW   | 3.2753V       | 2.0874mA      | 98h          |
            |   10 | 56.175mJ | 6.1339mW    | 3.2735V       | 1.8735mA      | 117h         |
            +------+----------+-------------+---------------+---------------+--------------+

            +--------+----------+-------------+---------------+---------------+--------------+
            |  Time  |  Energy  | Power(Mean) | Voltage(Mean) | Current(Mean) | Battery Life |
            +--------+----------+-------------+---------------+---------------+--------------+
            | 10     | 66.819mJ | 6.8344 mW   | 3.2753V       | 2.0874mA      | 98h          |
            | 10     | 56.175mJ | 6.1339mW    | 3.2735V       | 1.8735mA      | 117h         |
            | Delta: | 15.9%    | 10.2%       | 7.5%          | 0.0%          | 18.9%        |
            +--------+----------+-------------+---------------+---------------+--------------+


 */

