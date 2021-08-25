
/* *****************************************************************************
 File:    msp430_C_Mealy_4Z.c

 AMPEL AUF ROT:  LED Rot leuchtet staendig
 AMPEL AUF GELB: Beide LEDs Rot und Gruen leuchten im Wechsel 16 Mal mit einer Wechselfrequenz von F = ca. 1Hz
 AMPEL AUF GRUEN: LED Gruen leuchtet staendig
 Ampelphase ROT/GRUEN (also rot-gelb-phase): T = 65535 * (4 * 3 Microsekunde + 16 * 3 * 3 Microsekunde ) = ca. 10,2 Sek; Ampelphase GELB: Wechselfrequenz von F = 1/(60000* 3*3 Microsekunde)*2 = ca. 1Hz


 Quellen:
 https://de.wikipedia.org/wiki/Mealy-Automat
 www.mikrocontroller.net
 http://www.mikrocontroller.net/articles/Statemachine

 MINIMIEREN SIE DIE ENERGIEAUFNAHME DES CODES MIT DEN ERFAHRUNGEN AUS VORLESUNG/LABOR

 elektronik-wissen
     - pullup-Widerstand: zieht die elektische Spannung hinauf auf einen bestimmten Wert; ziehen Dieser Eingang wird dann auch als high-active bezeichnet
     - pulldown-Widerstand: zieht die elektrische Spannung hinunter, meist auf GND; Dieser Eingang wird dann auch als low-active bezeichnet

 Board hardware
     - has 2 Buttons: left is user-programmable, right is reset-button (auch Taster genannt)
     - name conventions: (P<PORT>.<PIN/BIT>) e.g. P1.3 = Port1 - PIN/BIT 3
     - P1.0: green-led
     - P1.1: rxd ("Receive Data") -> Teil der UART (Universal Asynchronous Resceiver and Transmitter)
     - P1.2: txd ("Transmit Data") -> Teil der UART (Universal Asynchronous Resceiver and Transmitter)
     - P1.3: user-programmable button is connected to this port+pin of the chip
     - P1.4:
     - P1.5: SCK ("Serial Clock") -> Teil des Serial Peripheral Interface (SCK gehört zusamen mit MISO und MOSI ('serial clock', 'master in-slave out, 'master out-slave in') zur SPI.)
     - P1.6: red-led; scl (SDA und SCL sind 'serial data' und 'serial clock' für den I2C-Bus.)
     - P1.7: sda (SDA und SCL sind 'serial data' und 'serial clock' für den I2C-Bus.)
     - registers are auto 0 at main-begin (in theory)


 Ports:
     - msp430 has 2 ports (P1 and P2) wich are able to process interrupts
     - each port has registers to store data to the current port e.g. P1 -> P1DIR  (=P1DIR is a register that configures the direction (DIR) of a port pin as an output or an input.)
     - "Each of the preipherals inside of our LaunchPad, including our GPIO module, are
        controlled by one or more register. And based on the 1s and 0s that populate any given register, our peripherals may act or behave in a different manner."

 Registers:
     - all 8 Bit / PIN
     - for each port: 9 registers: PxDIR, PxREN, PxOUT, PxIN, PxSEL, PxSEL2, PxIE, PxIES, PxIFG ...
        - PxDIR= Das Richtungsregister. Bit = 0: zugehörige Leitung ist ein (hochohmiger) Eingang; Bit=1: zugehörige Leitung ist Ausgang.
        - PxREN= controlls resistors (Widerstände)): Das Resistor Enable Flag Register, macht nur sin wenn Pin als Eingang (über PxDIR) definiert.
                 Bit = 1 aktiviert die eingebauten Pullup- oder Pulldown-Widerstände; Bit = 0 deaktiviert.
                 Diese ziehen offene Eingänge auf definierte Potentiale. Beachte um zu definieren, ob der Pin einen Pullup oder Pulldown bekommt, wird
                 das PxOUT Register genutzt (macht nur für Pin als Eingang Sinn). Bit = 1 Pullup; Bit = 0 Pulldown.
        - PxOUT= Das Ausgangspufferregister, wenn Pin als Ausgang (über PxDIR) definiert. Bit = 0: zugehörige Ausgangsleitung wird auf LOW geschaltet; Bit = 1: Leitung wird HIGH geschaltet.
        - P1IN= Das Eingangspufferregister, wenn Pin als Eingang (über PxDIR) definiert. Wenn zugehörige Eingangsleitung LOW ist: Bit = 0; wenn Eingangsleitung HIGH ist: Bit=1.
                Kann damit die Eingangsleitung abfragen ob Spannung anliegt.
                - If you press the button, then P1IN = 0. By default, P1IN will be 1.
        - PxSEL= Das Port Select Register. Bit = 1 aktiviert für diese Leitung die erste alternative Leitungsfunktion; Bit = 0 belässt die Leitung als GPIO.
        - PxSEL2= Das Port Select Register 2. Bit = 1 aktiviert für diese Leitung die zweite alternative Leitungsfunktion. Dazu muss vorher auch PxSEL aktiviert werden. Beachte existiert nicht bei alle Derivate als Option!
        - PxIES= Das Interrupt Edge Select Register. Auswahl, ob der Interruptauslösung bei ansteigender Flanke (Wechsel von LOW auf HIGH) dazu Bit=0 oder bei fallender Flanke Bit=1 setzen.
        - PxIFG= Das Interrupt Flag Register. Bit=1 zeigt an, ob über diese Leitung ein Interrupt ausgelöst wurde.

Oscillator and Clock
    - there is always a difference between the clock and the oscillator
    - clock is based on an oscillator
    - cpu is controlles by a clock (which is based on a oscillator)
    - difference: oscillator has always around same frequence but e.g. we want to divide that frequence by a divider of e.g. 8
        - this can be configured in a clock for example
    - since the cpu-speed is based on a clock, we usually dont want to use that clock
        - since if the devide the speed that clock -> the cpu runs slower
    - oscillator examples: LFCT1CLK, DCOCLK
    - clocks examples: ACLK, MCLK (used for CPU), SMCLK

 Bitwise operators:
     - &: And: if both bits at same position are 1: 1 else 0
     - |: OR: if either of the bits is 1 (if both also): 1 else 0 (so only if both are 0)
     - ^: XOR: bitwise xor i.e. if bits differ: 1 else 0
     - ~: Bitwise Complement: inverses bit-sequence -> 0 to 1 and 1 to 0


 Änderungen
     -low_power_PxOUT_16();


Herz berechnen:
T=Periodendauer in Sekunde(-n)
Frequenz f = 1/T
Frequenz wird in Herz angegeben

1Mhz=default
1Mhz=~1mio instructions per second
1 µS = 1 Mikrosekunde = 10^-6 Sekunden = 0,000.001

1Mio instructions/s -> 1 instruction per 0,000.001 Seconds = per 1 µS

*******************************************************************************/



#include <msp430g2553.h>

// does not matter since we use MC_2-mode -> he runs till 0xFFFF
// nethertheless it has effect (even since we are in MC_2-mode)
//const int ccr0_init = 500;

/* a flag to tell us when we've handled a button event */
int buttonPushed = 0;

/* we'll toggle between different modes */
int blinkMode = 0;

/* which lights we need to blink -- start green only */
int blinkMask = BIT0;



int main(void) {




    /* Clear and hold the watch dog timer so it doesn't reset our chip */
    // stop using the watchdog
    // This line of code turns off the watchdog timer, which can reset the device after a certain period of time.
    WDTCTL = WDTPW + WDTHOLD;



    // disable left undefined ports
    P1DIR = 0xFF;
    P1OUT = 0x00;

    P2DIR = 0xFF;
    P2OUT = 0x00;

    P3DIR = 0xFF;
    P3OUT = 0x00;




    // SW Entprellen (see e.g.: http://www.mathe-mit-methode.com/schlaufuchs_web/elektrotechnik/mikrocontroller_lernmaterial/microcontroller_allgemein/mikrocontroller_ext_hardware/mikrocontroller_taster.html#oben)
    // Initialisieren der Register für Port1
    P1DIR = BIT0; // entprellen der green-led
    P1DIR = BIT6; // entprellen der red-led



    // P1.3 = 1 =  Enable resistor (Widerstand): In order to make the button work, we have to add pull-up resistor to make it normally high.
    // By writing this line, internal resistor (inside the chip) will be enabled, connecting P1.3 to the power supply (3.6V) or ground (0V). This is defined in next line.
    P1REN = BIT3;
    // if we analyse carefully, P1.3 is an input pin, and it is quite not logical to assign the pin any output state. In fact, this line of code define the connectivity of the internal resistor.
    // If P1OUT = BIT3, then the internal resistor is connected to 3.6V. In other words, the pin now is normally high, and the internal resistor is known as pull-up resistor.
    P1OUT = BIT3;



    /* Configure pins 0,6 on port 1 as output pins */
    // P1DIR is a register that configures the direction (DIR) of a port pin as an output or an input.
    // P1DIR = <PIN7><PIN6><PIN5><PIN4><PIN3><PIN2><PIN1><PIN0> // 1 Pin = 1 bit
    // output = set bit to 1 (or ON / HIGH), input = set bit to 0 (or OFF / LOW)
    // BIT0=0x0001=Green LED - BIT6=0x0040=Red LED
    // = a word of 8 bits
    P1DIR = BIT0 + BIT6;


    // P1OUT is another register which holds the status of the LED.
    // '1' specifies that it's ON or HIGH, while '0' specifies that it's OFF or LOW
    // Clear single bit, preserve others
    /* make sure red (pin 6) is turned off */
//    P1OUT &= ~BIT6;


    // CCR0 interrupt enabled
    // This sets the Capture/Compare control 0 to enable Timer Interrupts. CCIE means „Capture/Control Interrupt Enable“.
    CCTL0 = CCIE;
    // This sets the Capture/Compare Register 0 value to 50000. This is the value to reach for firing the Interrupt. With this value you can control the time that must be over between each Interrupt Event of the CCR0 Interrupt handler.
//    CCR0 = ccr0_init;
    // Bevor man einen Timer benutzen kann, muss er den eigenen Funktionsanforderungen entsprechend konfiguriert werden. Dazu steht ein 16 Bit breites Register, das Timer-A-Control- Register, kurz TACTL zur Verfügung
    // Tassel_2 -> SMCLK, MC_2 -> contmode
    // Tassel_2: With TASSEL_2 we select the SMCLK what is the SubsystemMasterCLocK. There are some other Clocks available
    // TASSEL_1 /* Timer A clock source select: 1 - ACLK  */
    // SMCLK: In einem ersten Schritt ist die Taktquelle des Timers festzulegen.
    //  -> possible sources:
    //      - MCLK: Master clock: high frequency; used in cpu; driven by the internal digitally controlled RC-oscillator (DCO)
    //      - SMCLK: Sub-Main-Clock des Basic-Clock-Moduls: middle frequency; driven by the internal digitally controlled RC-oscillator (DCO)
    //      - ACLK: Auxiliary-Clock : low frequency -> maybe for realtime clock or something like that
    // MC_2: according to the importet header file mc_2 is the so called conitnous mode (contmode)
    // contmode: Das Zählregister wird kontinuierlich bis zum höchsten Wert 0xFFFF hochgezählt, beginnt dann wieder bei 0x0000
    //  -> demnach ist eigentlich ccr0 garnicht festzulegen, da ignoriert
    //  -> für ccr muss der up-mode gewählt werden: Das Zählregister wird bis zum Wert des TACCR0-Registers hochgezählt, beginnt dann wieder bei 0x0000
//    TACTL = TASSEL_2 + MC_2;
    TACTL = TASSEL_1 + MC_2 + TAIE;













    // Enter LPM0 w/ interrupt
    // It means that the Microcontroller sets the bits that are definded for LPM0 (LowPowerMode 0). That is the part LPM0_bits. And it also enable all Interrups (GIE = General Interrupt Enable).

//    Active Mode (AM) – Not a low power mode but rather the mode in which everything is turned on, except perhaps for some peripherals
//    LPM0 – CPU and MCLK are shutoff. SMCLK and ACLK remain active.
//    LPM1 – CPU and MCLK are off, as in LPM1, but DCO and DC generator are disabled if the DCO is not used for SMCLK. ACLK is active.
//    LPM2 – CPU, MCLK, SMCLK and DCO are disabled, while DC generator is still enabled. ACLK is active.
//    LPM3 – CPU, MCLK, SMCLK, DCO and DC generator are disabled. ACLK is active.
//    LPM4 – CPU and all clocks disabled
    _BIS_SR(LPM3_bits + GIE);


//    any non-zero value is TRUE and 0 is FALSE.
    /* infinite loop */
//    for( ; ; )
//    {
//
//    }
}


// #pragma vector=TIMER0_A0_VECTOR -> line cant be changed
// __interrupt void Timer_Asfasdf (void) -> line (name) can be changed
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{

//    CCR0 += ccr0_init;                            // Add Offset to CCR0

//    int j;

    // in each step of the loop the key-press can be determinated, but only 1 key press per iteration
    // following is wrong: with one full loop (0-100) one key-press can be determined
//    for( j = 0; j < 100; j++ )
//    {

        /* The following two lines implement a very crude delay loop.
         * The actual length of the delay can vary significantly.
         * This approach may not work with all compilers.
         */
        // could be implemented to overcome the "bouncing switch" - problem (http://www.mathe-mit-methode.com/schlaufuchs_web/elektrotechnik/mikrocontroller_lernmaterial/microcontroller_allgemein/mikrocontroller_ext_hardware/mikrocontroller_taster.html#oben)
//        volatile int i;
//        for( i = 0; i < 200; i++ );




        // ISR
        /* Switch 1 is connected to pin 3.  If it is low, then change the
         * blinking behavior (unless it we have handled the press already)
         */
        // If you press the button, then P1IN = 0. By default, P1IN will be 1.
        if(( P1IN & BIT3 ) == 0 )
        {
            // important since if the hold the key, the leds should just go into the next state and not shine both (without buttonPushed-function they will)
            if( !buttonPushed )
            {
                /* remember so we don't try to handle this press again */
                // if button pushed, we set buttonPushed to 1
                buttonPushed = 1;


                // +1 since we want to go to the next mode
//                blinkMode = (blinkMode + 1)%4;

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


//    }

    /* blink the lights */
    // the if-condition above sets the blinkmask (and maybe single bits)
    //  (1) and because of the ^ (XOR), after finishing the outer for-loop (inner loop of the infinite-loop), the set P1Out to the blinkMask
    //  (2) after the next finish of said for-loop the led bits are set to 0 (because led-bits of blinkMask and P1OUT are same and then get XOR'd)
    //  (3) after the 3rd finish of the said for-loop the bits are set to blinkmask agains
    //  (4) after the 4rd finish of the for-loop ... (see step 2)
    // thats why it blinks
    P1OUT ^= blinkMask;


}



