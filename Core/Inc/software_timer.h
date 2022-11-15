/*
 * software_timer.h
 *
 *  Created on: Oct 24, 2022
 *      Author: 84977
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer1_counter;
extern int blink_flag;
extern int blink_counter;
extern int timer2_flag;
extern int timer2_counter;
extern int segment_flag;
extern int segment_counter;
extern int button_counter;
extern int button_flag;
void timerRun();
void setBlink(int duration);
void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
void setButton(int duration);

#endif /* INC_SOFTWARE_TIMER_H_ */
