/*
 * fsm_automatic.c
 *
 *  Created on: Oct 24, 2022
 *      Author: 84977
 */

#include "fsm_automatic.h"
#include "global.h"
#include "software_timer.h"
#include "button.h"
#include "main.h"
#define RED 0
#define AMBER 1
#define GREEN 2

#define button1 0
#define button2 1
#define button3 2

static uint8_t lightbufferMod[3]={1,1,1};
static uint8_t lightbufferRun[3]={5,2,3};
static uint8_t mode;

static int time1=0;
static int time2=0;
int indexled=0;
int initial_flag=0;
int led_buffer [4];

void update7SEG (int index) {
	switch (index)	{
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		display7SEG(led_buffer[0]);
		display7SEGforled2(led_buffer[2]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		display7SEG(led_buffer[1]);
		display7SEGforled2(led_buffer[3]);
		break;
	default:
		break;
	}
 }
void updatebuffer(int number1, int number2)
{
	led_buffer[0]=number1/10;
	led_buffer[1]=number1%10;

	led_buffer[2]=number2/10;
	led_buffer[3]=number2%10;
}

void initial()
{
	status=AUTO_RED;
	status2=AUTO_GREEN;
	time1=lightbufferRun[0];
	time2=lightbufferRun[2];
	setTimer1(1000);
	mode=1;
	segment_flag=1;
	updatebuffer(time1, time2);
}
void  traffic()
{
	if(status==AUTO_RED)
	{
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
		if(time1==0)
		{
			status=AUTO_GREEN;
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
			time1=lightbufferRun[2];
		}
	}
	else if(status==AUTO_YELLOW)
	{
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
		if(time1==0)
		{
			status=AUTO_RED;
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
			time1=lightbufferRun[0];
		}
	}
	else if(status==AUTO_GREEN)
	{
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, RESET);
		if(time1==0)
		{
			status=AUTO_YELLOW;
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
			time1=lightbufferRun[1];
		}
	}
	if(status2==AUTO_RED)
	{
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
		if(time2==0)
		{
			status2=AUTO_GREEN;
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);
			time2=lightbufferRun[2];
		}
	}
	else if(status2==AUTO_YELLOW)
	{
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
		if(time2==0)
		{
			status2=AUTO_RED;
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, RESET);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
			time2=lightbufferRun[0];
		}
	}
	else if(status2==AUTO_GREEN)
	{
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, RESET);
		if(time2==0)
		{
			status2=AUTO_YELLOW;
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, RESET);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
			time2=lightbufferRun[1];
		}
	}
	if((mode==1) &&(timer1_flag==1))
	{
		time1--;
		time2--;
		setTimer1(1000);
	}
}
void  increasedTime(uint8_t led)
{
	lightbufferMod[led]++;
	if(lightbufferMod[led]>99)
	{
		lightbufferMod[led]=1;
	}
}
void updateMode()
{
	mode++;
	if(mode>4) mode=1;
}
void copyModtoRun()
{
	for(int i=0;i<3;i++)
	{
		lightbufferRun[i]=lightbufferMod[i];
	}
}
void blinkLed(uint8_t led)
{
	if((mode!=1)&&(blink_flag==1))
	{
		if(led==0)
		{
			HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
			HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
		}
		else if(led==1)
		{
			HAL_GPIO_TogglePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin);
			HAL_GPIO_TogglePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin);
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
			HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
		}
		else if(led==2)
		{
			HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
			HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
			HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
			HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
			HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
		}
		setBlink(500);
	}
}
void fsm_automatic()
{


	if(is_button_pressed(button1))
	{
		updateMode();
		indexled=0;
		initial_flag=1;
	}
	switch(mode)
	{
	case 1:
		if(initial_flag==1)
		{
			initial_flag=0;
			status=AUTO_RED;
			status2=AUTO_GREEN;
			time1=lightbufferRun[0];
			time2=lightbufferRun[2];
			indexled=0;
			setTimer1(1000);
		}
		else
		{traffic();
		updatebuffer(time1, time2);
		}
		break;
	case 2:

		if(initial_flag==1)
		{setTimer2(5000);
		blink_flag=1;
		initial_flag=0;
		HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin, SET);
		HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin, SET);
		}
		blinkLed(RED);
		if(is_button_pressed(button2))
		{
			status=MAN_RED;
			status2=MAN_RED;
			setTimer2(5000);
			increasedTime(0);
		}
		if(is_button_pressed(button3))
		{
			copyModtoRun();
			mode=1;
			indexled=0;
			time1=lightbufferRun[0];
			time2=lightbufferRun[2];
			status=AUTO_RED;
			status2=AUTO_GREEN;
			initial_flag=1;
		}
		if(timer2_flag==1)
		{
			status=AUTO_RED;
			status2=AUTO_GREEN;
			mode=1;
			initial_flag=1;
		}
		updatebuffer(mode, lightbufferMod[0]);
		break;
	case 3:
		if(initial_flag==1)
		{setTimer2(5000);
		blink_flag=1;
		initial_flag=0;
		HAL_GPIO_WritePin(LED_YELLOW_1_GPIO_Port, LED_YELLOW_1_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_2_GPIO_Port, LED_YELLOW_2_Pin, SET);
		}
		blinkLed(AMBER);
		if(is_button_pressed(button2))
		{
			status=MAN_YELLOW;
			status2=MAN_YELLOW;
			setTimer2(5000);
			increasedTime(1);
		}
		if(is_button_pressed(button3))
		{
			copyModtoRun();
			mode=1;
			indexled=0;
			time1=lightbufferRun[0];
			time2=lightbufferRun[2];
			status=AUTO_RED;
			status2=AUTO_GREEN;
			initial_flag=1;
		}
		if(timer2_flag==1)
		{
			status=AUTO_RED;
			status2=AUTO_GREEN;
			mode=1;
			initial_flag=1;
		}
		updatebuffer(mode, lightbufferMod[1]);
		break;
	case 4:
		if(initial_flag==1)
		{setTimer2(5000);
		blink_flag=1;
		initial_flag=0;
		HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, SET);
		}
		blinkLed(GREEN);
		if(is_button_pressed(button2))
		{
			status=MAN_GREEN;
			status2=MAN_GREEN;
			setTimer2(5000);
			increasedTime(2);

		}
		if(is_button_pressed(button3))
		{
			copyModtoRun();
			mode=1;
			indexled=0;
			time1=lightbufferRun[0];
			time2=lightbufferRun[2];
			status=AUTO_RED;
			status2=AUTO_GREEN;
			initial_flag=1;
		}
		if(timer2_flag==1)
		{
			status=AUTO_RED;
			status2=AUTO_GREEN;
			mode=1;
			initial_flag=1;
		}
		updatebuffer(mode, lightbufferMod[2]);
		break;
	}
	if(segment_flag==1)
	{
	update7SEG(indexled++);
	if(indexled>1)
	{
		indexled=0;
	}
	setTimer3(500);
	}
}
