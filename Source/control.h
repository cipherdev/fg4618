/*
 * control.h
 *
 *  Created on: Mar 31, 2014
 *      Author: Anh Huy
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include <msp430fg4618.h>
#include "stdio.h"
#include "LCD.h"

#define  second 1000000

int gpio(void);
int interrup(void);
int time_clock(void);
int show_lcd(void);
//int time_clock_year(void);
#endif /* CONTROL_H_ */
