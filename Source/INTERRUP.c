/*
 * INTERRUP.c
 *
 *  Created on: Mar 31, 2014
 *      Author: Anh Huy
 */
#include "control.h"

#pragma vector=PORT1_VECTOR
__interrupt void Port_1 (void) {
   volatile unsigned int i;
   P2OUT ^= 0x04;                 //Toggle Port P2.2
   i=1500;                        //Delay, button debounce
   do (i--);
   while (i !=0);
   while (! (P1IN & 0x01));        //Wait for the release of the button
   i=1500;                        //Delay, button debounce
   do (i--);
   while (i !=0);
   P1IFG &= ~0x01;                //Clean P1.0 Interrupt Flag
}

int interrup(void){
   WDTCTL = WDTPW | WDTHOLD;      //Stop Watchdog Timer
   P2DIR |= 0x04;                 //Configure P2.2 as Output (LED1)
   P1DIR &= ~0x01;                //Configure P1.0 as Input (S1)
   P1IE |= 0x01;                  //Interrupt Enable in P1.0
   P1IES |= 0x01;                 //P1.0 Interrupt flag high-to-low transition
   _BIS_SR (LPM3_bits + GIE);     //Low Power Mode with interrupts enabled
   return 0;
}




