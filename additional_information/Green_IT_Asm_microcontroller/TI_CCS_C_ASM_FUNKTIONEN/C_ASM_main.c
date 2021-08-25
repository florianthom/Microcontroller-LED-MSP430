/***********************************************************************
 1C_ASM_main.c                                           2001-02-18

 Mixing C and Assembler Code

 This software demonstrates how C and Assembler Code could be
 mixed to get the optimum of both programming languages

 Note 1: project must include assembly file "asm_red_zero_green.asm"

 Prof. Dr. Vesselin Iossifov, HTW Berlin
***********************************************************************/
#include   <MSP430g2553.h>       /* Processor specific definitions */

/* -------------------external Function Prototypes ------------------- */
extern void set_port(void);    /* Function Prototype for asm function */


/* main */

void main( void )
{
// === Initialize MSP430 ===============================
  IFG1=0;                    /* clear interrupt flag1 */
  WDTCTL=WDTPW+WDTHOLD;      /* stop WDT */

  while(1)
  {
     set_port();

  }
}

