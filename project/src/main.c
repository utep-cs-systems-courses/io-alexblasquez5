 #include <msp430.h>
 #include "libTimer.h"

int main(void) {

  P1DIR |= LEDS;
  P1OUT |= LED_GREEN;
  P1OUT |= LED_RED;



  P2REN |= SWITCHES;/* enables resistors for switches */

  P2IE |= SWITCHES;/* enable interrupts from switches */

  P2OUT |= SWITCHES;/* pull-ups for switches */

  P2DIR &= ~SWITCHES;/* set switches' bits for input */


  configureClocks();/* setup master oscillator, CPU & peripheral clocks */

  enableWDTInterrupts();/* enable periodic interrupt */


  or_sr(0x18);/* CPU off, GIE on */

}

