# Microcontroller-LED-MSP430
This project is a result of the coursework in module called "Green IT". The given project involves: Reverse engineering of a given code piece, energy/performance analysis of this code and reprogramming of this code to use Microcontroller Timer (Low-Power-Function).
The underlying context is a LED-light problem. The LEDs of the microcontroller have to blink in a period of around 2.25 Hz. This functionlity was already properly implemented and the code was known. The task at hand was to analyse the code and to make it more energy efficient. The solution is given by several optimization. The biggest challenge was to introduce the usage of timer of the microcontroller to the code. Here the timer A of the MSP430g2553 was used. This timer was configured to use the smclk ("Sub-Main Clock") in the "continues up" mode. This clock in turn was configured to use the "DCO" (Digitally Controlled Oscillator) (which ticks at around 1Mhz) by disabling of the XT1-Oscillator. The DCO was setup to count to 6947 (formular can be seen in file) to get the said 2.25Mhz. The result can be viewed at Green_IT_Project/Efficient_Ampel_Mealy_4Z.c with some background information at Green_IT_Project/Work_Efficient_Ampel_Mealy_4Z.c.

## Learned
- Basic handling of a microcontroller in general
- Handling of individual register of a microcontroller in general
- MSP430g2553
- Code Composer Studio
- Texas Instruments EnergyTrace Technology
- Ultra-Low Power Advisor

## Prerequisites
- Basic understanding of a microcontroller, especially about timer usage in a low-power modus

## Build with
- Microcontroller from the family TI MSP430
  - recommended: MSP430gs553
- Code Composer Studio (CCS)

## Acknowledgements
- Thanks to my professor Prof. Dr. V. Iossifov @ "Verband der Elektrotechnik, Elektronik und Informationstechnik Berlin-Brandenburg (ETV)" who taught us the required basics of microcontroller from the bottom up.
