/*
 * SHOW_LCD.c
 *
 *  Created on: Mar 31, 2014
 *      Author: Anh Huy
 */
#include "control.h"
void Init_LCD(void);
unsigned char *LCDSeg = (unsigned char *) &LCDM3;
int LCD_SIZE=11;
int show_lcd(void){
	volatile unsigned char a; volatile unsigned int i;
	WDTCTL = WDTPW + WDTHOLD;
	Init_LCD();
	for (i=0;i<LCD_SIZE;i++)
	{
		LCDSeg[i]=0xff;
	}
	return 0;
}
// Initialize the LCD system
void Init_LCD(void){
	int n;
	for (n=0;n<LCD_SIZE;n++)
	{
		*(LCDSeg+n) = 0;
	}
	P5SEL = 0x1C; // BIT4 | BIT3 |BIT2 = 1 P5.4, P.3, P5.2 = 1
	LCDAVCTL0 = 0x00;
	LCDAPCTL0 = 0x7E;
	LCDACTL = 0x7d;
}




