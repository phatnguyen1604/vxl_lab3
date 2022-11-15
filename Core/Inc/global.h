/*
 * global.h
 *
 *  Created on: Oct 24, 2022
 *      Author: 84977
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"

#define INIT  		1
#define AUTO_RED 	2
#define AUTO_YELLOW 3
#define AUTO_GREEN 	4

#define MAN_RED     12
#define MAN_YELLOW 	13
#define MAN_GREEN 	14


extern int status;
extern int status2;
extern int man_time;
extern int blink_time;


void display7SEG(int time);
void display7SEGforled2(int time);

#endif /* INC_GLOBAL_H_ */
