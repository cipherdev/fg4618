/*
 * GPIO.c
 *
 *  Created on: Mar 31, 2014
 *      Author: Anh Huy
 */

#include "control.h"

void delay_s(unsigned long n){

	do{
		n--;
	}
	while(n != 0);

}
int gpio(void){
	WDTCTL = WDTPW | WDTHOLD;

	P1DIR &=~ 0x03;
	P2DIR |= 0x06;
	P5DIR |= 0x02;
	P2OUT &=~ 0x06;
	P5OUT &=~ 0x02;
	while(1){
		P2OUT |= 0x02;	// on off leb_1 green P2.1
		delay_s(2);
		P2OUT &=~ 0x02;
		delay_s(2);
		P2OUT ^= 0x04;	// on leb_2 orange P2.2
		delay_s(second);

		if(!(P1IN & 0x01)){
			P5OUT |= 0x02;	// on leb 4 red P5.1
		}
		if(!(P1IN & 0x02)){
			P5OUT &=~ 0x02;	// off leb 4 red P5.1
		}
	}
	//return 0;
}






