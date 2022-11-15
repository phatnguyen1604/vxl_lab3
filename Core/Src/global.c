/*
 * global.c
 *
 *  Created on: Oct 24, 2022
 *      Author: 84977
 */
#include "global.h"
#include "main.h"
int status=0;
int status2=0;
int man_time=10000;
int blink_time=500;

void display7SEG (int time)
{
	if(time==0)
	{
		HAL_GPIO_WritePin(P_1_GPIO_Port, P_1_Pin, RESET);
		HAL_GPIO_WritePin(P_2_GPIO_Port, P_2_Pin, RESET);
		HAL_GPIO_WritePin(P_3_GPIO_Port, P_3_Pin, RESET);
		HAL_GPIO_WritePin(P_4_GPIO_Port, P_4_Pin, RESET);
		HAL_GPIO_WritePin(P_5_GPIO_Port, P_5_Pin, RESET);
		HAL_GPIO_WritePin(P_6_GPIO_Port, P_6_Pin, RESET);
		HAL_GPIO_WritePin(P_7_GPIO_Port, P_7_Pin, SET);
	}
	else if(time==1)
	{
		HAL_GPIO_WritePin(P_1_GPIO_Port, P_1_Pin, SET);
		HAL_GPIO_WritePin(P_2_GPIO_Port, P_2_Pin, RESET);
		HAL_GPIO_WritePin(P_3_GPIO_Port, P_3_Pin, RESET);
		HAL_GPIO_WritePin(P_4_GPIO_Port, P_4_Pin, SET);
		HAL_GPIO_WritePin(P_5_GPIO_Port, P_5_Pin, SET);
		HAL_GPIO_WritePin(P_6_GPIO_Port, P_6_Pin, SET);
		HAL_GPIO_WritePin(P_7_GPIO_Port, P_7_Pin, SET);
	}
	else if(time==2)
	{
		HAL_GPIO_WritePin(P_1_GPIO_Port, P_1_Pin, RESET);
		HAL_GPIO_WritePin(P_2_GPIO_Port, P_2_Pin, RESET);
		HAL_GPIO_WritePin(P_3_GPIO_Port, P_3_Pin, SET);
		HAL_GPIO_WritePin(P_4_GPIO_Port, P_4_Pin, RESET);
		HAL_GPIO_WritePin(P_5_GPIO_Port, P_5_Pin, RESET);
		HAL_GPIO_WritePin(P_6_GPIO_Port, P_6_Pin, SET);
		HAL_GPIO_WritePin(P_7_GPIO_Port, P_7_Pin, RESET);
	}
	else if(time==3)
	{
		HAL_GPIO_WritePin(P_1_GPIO_Port, P_1_Pin, RESET);
		HAL_GPIO_WritePin(P_2_GPIO_Port, P_2_Pin, RESET);
		HAL_GPIO_WritePin(P_3_GPIO_Port, P_3_Pin, RESET);
		HAL_GPIO_WritePin(P_4_GPIO_Port, P_4_Pin, RESET);
		HAL_GPIO_WritePin(P_5_GPIO_Port, P_5_Pin, SET);
		HAL_GPIO_WritePin(P_6_GPIO_Port, P_6_Pin, SET);
		HAL_GPIO_WritePin(P_7_GPIO_Port, P_7_Pin, RESET);
	}
	else if(time==4)
	{
		HAL_GPIO_WritePin(P_1_GPIO_Port, P_1_Pin, SET);
		HAL_GPIO_WritePin(P_2_GPIO_Port, P_2_Pin, RESET);
		HAL_GPIO_WritePin(P_3_GPIO_Port, P_3_Pin, RESET);
		HAL_GPIO_WritePin(P_4_GPIO_Port, P_4_Pin, SET);
		HAL_GPIO_WritePin(P_5_GPIO_Port, P_5_Pin, SET);
		HAL_GPIO_WritePin(P_6_GPIO_Port, P_6_Pin, RESET);
		HAL_GPIO_WritePin(P_7_GPIO_Port, P_7_Pin, RESET);
	}
	else if(time==5)
	{
		HAL_GPIO_WritePin(P_1_GPIO_Port, P_1_Pin, RESET);
		HAL_GPIO_WritePin(P_2_GPIO_Port, P_2_Pin, SET);
		HAL_GPIO_WritePin(P_3_GPIO_Port, P_3_Pin, RESET);
		HAL_GPIO_WritePin(P_4_GPIO_Port, P_4_Pin, RESET);
		HAL_GPIO_WritePin(P_5_GPIO_Port, P_5_Pin, SET);
		HAL_GPIO_WritePin(P_6_GPIO_Port, P_6_Pin, RESET);
		HAL_GPIO_WritePin(P_7_GPIO_Port, P_7_Pin, RESET);
	}
	else if(time==6)
	{
		HAL_GPIO_WritePin(P_1_GPIO_Port, P_1_Pin, RESET);
		HAL_GPIO_WritePin(P_2_GPIO_Port, P_2_Pin, SET);
		HAL_GPIO_WritePin(P_3_GPIO_Port, P_3_Pin, RESET);
		HAL_GPIO_WritePin(P_4_GPIO_Port, P_4_Pin, RESET);
		HAL_GPIO_WritePin(P_5_GPIO_Port, P_5_Pin, RESET);
		HAL_GPIO_WritePin(P_6_GPIO_Port, P_6_Pin, RESET);
		HAL_GPIO_WritePin(P_7_GPIO_Port, P_7_Pin, RESET);
	}
	else if(time==7)
	{
		HAL_GPIO_WritePin(P_1_GPIO_Port, P_1_Pin, RESET);
		HAL_GPIO_WritePin(P_2_GPIO_Port, P_2_Pin, RESET);
		HAL_GPIO_WritePin(P_3_GPIO_Port, P_3_Pin, RESET);
		HAL_GPIO_WritePin(P_4_GPIO_Port, P_4_Pin, SET);
		HAL_GPIO_WritePin(P_5_GPIO_Port, P_5_Pin, SET);
		HAL_GPIO_WritePin(P_6_GPIO_Port, P_6_Pin, SET);
		HAL_GPIO_WritePin(P_7_GPIO_Port, P_7_Pin, SET);
	}
	else if(time==8)
	{
		HAL_GPIO_WritePin(P_1_GPIO_Port, P_1_Pin, RESET);
		HAL_GPIO_WritePin(P_2_GPIO_Port, P_2_Pin, RESET);
		HAL_GPIO_WritePin(P_3_GPIO_Port, P_3_Pin, RESET);
		HAL_GPIO_WritePin(P_4_GPIO_Port, P_4_Pin, RESET);
		HAL_GPIO_WritePin(P_5_GPIO_Port, P_5_Pin, RESET);
		HAL_GPIO_WritePin(P_6_GPIO_Port, P_6_Pin, RESET);
		HAL_GPIO_WritePin(P_7_GPIO_Port, P_7_Pin, RESET);
	}
	else if(time==9)
	{
		HAL_GPIO_WritePin(P_1_GPIO_Port, P_1_Pin, RESET);
		HAL_GPIO_WritePin(P_2_GPIO_Port, P_2_Pin, RESET);
		HAL_GPIO_WritePin(P_3_GPIO_Port, P_3_Pin, RESET);
		HAL_GPIO_WritePin(P_4_GPIO_Port, P_4_Pin, RESET);
		HAL_GPIO_WritePin(P_5_GPIO_Port, P_5_Pin, SET);
		HAL_GPIO_WritePin(P_6_GPIO_Port, P_6_Pin, RESET);
		HAL_GPIO_WritePin(P_7_GPIO_Port, P_7_Pin, RESET);
	}
}

void display7SEGforled2(int time)
{

	if(time==0)
	{
		HAL_GPIO_WritePin(P1_1_GPIO_Port, P1_1_Pin, RESET);
		HAL_GPIO_WritePin(P1_2_GPIO_Port, P1_2_Pin, RESET);
		HAL_GPIO_WritePin(P1_3_GPIO_Port, P1_3_Pin, RESET);
		HAL_GPIO_WritePin(P1_4_GPIO_Port, P1_4_Pin, RESET);
		HAL_GPIO_WritePin(P1_5_GPIO_Port, P1_5_Pin, RESET);
		HAL_GPIO_WritePin(P1_6_GPIO_Port, P1_6_Pin, RESET);
		HAL_GPIO_WritePin(P1_7_GPIO_Port, P1_7_Pin, SET);
	}
	else if(time==1)
	{
		HAL_GPIO_WritePin(P1_1_GPIO_Port, P1_1_Pin, SET);
		HAL_GPIO_WritePin(P1_2_GPIO_Port, P1_2_Pin, RESET);
		HAL_GPIO_WritePin(P1_3_GPIO_Port, P1_3_Pin, RESET);
		HAL_GPIO_WritePin(P1_4_GPIO_Port, P1_4_Pin, SET);
		HAL_GPIO_WritePin(P1_5_GPIO_Port, P1_5_Pin, SET);
		HAL_GPIO_WritePin(P1_6_GPIO_Port, P1_6_Pin, SET);
		HAL_GPIO_WritePin(P1_7_GPIO_Port, P1_7_Pin, SET);
	}
	else if(time==2)
	{
		HAL_GPIO_WritePin(P1_1_GPIO_Port, P1_1_Pin, RESET);
		HAL_GPIO_WritePin(P1_2_GPIO_Port, P1_2_Pin, RESET);
		HAL_GPIO_WritePin(P1_3_GPIO_Port, P1_3_Pin, SET);
		HAL_GPIO_WritePin(P1_4_GPIO_Port, P1_4_Pin, RESET);
		HAL_GPIO_WritePin(P1_5_GPIO_Port, P1_5_Pin, RESET);
		HAL_GPIO_WritePin(P1_6_GPIO_Port, P1_6_Pin, SET);
		HAL_GPIO_WritePin(P1_7_GPIO_Port, P1_7_Pin, RESET);
	}
	else if(time==3)
	{
		HAL_GPIO_WritePin(P1_1_GPIO_Port, P1_1_Pin, RESET);
		HAL_GPIO_WritePin(P1_2_GPIO_Port, P1_2_Pin, RESET);
		HAL_GPIO_WritePin(P1_3_GPIO_Port, P1_3_Pin, RESET);
		HAL_GPIO_WritePin(P1_4_GPIO_Port, P1_4_Pin, RESET);
		HAL_GPIO_WritePin(P1_5_GPIO_Port, P1_5_Pin, SET);
		HAL_GPIO_WritePin(P1_6_GPIO_Port, P1_6_Pin, SET);
		HAL_GPIO_WritePin(P1_7_GPIO_Port, P1_7_Pin, RESET);
	}
	else if(time==4)
	{
		HAL_GPIO_WritePin(P1_1_GPIO_Port, P1_1_Pin, SET);
		HAL_GPIO_WritePin(P1_2_GPIO_Port, P1_2_Pin, RESET);
		HAL_GPIO_WritePin(P1_3_GPIO_Port, P1_3_Pin, RESET);
		HAL_GPIO_WritePin(P1_4_GPIO_Port, P1_4_Pin, SET);
		HAL_GPIO_WritePin(P1_5_GPIO_Port, P1_5_Pin, SET);
		HAL_GPIO_WritePin(P1_6_GPIO_Port, P1_6_Pin, RESET);
		HAL_GPIO_WritePin(P1_7_GPIO_Port, P1_7_Pin, RESET);
	}
	else if(time==5)
	{
		HAL_GPIO_WritePin(P1_1_GPIO_Port, P1_1_Pin, RESET);
		HAL_GPIO_WritePin(P1_2_GPIO_Port, P1_2_Pin, SET);
		HAL_GPIO_WritePin(P1_3_GPIO_Port, P1_3_Pin, RESET);
		HAL_GPIO_WritePin(P1_4_GPIO_Port, P1_4_Pin, RESET);
		HAL_GPIO_WritePin(P1_5_GPIO_Port, P1_5_Pin, SET);
		HAL_GPIO_WritePin(P1_6_GPIO_Port, P1_6_Pin, RESET);
		HAL_GPIO_WritePin(P1_7_GPIO_Port, P1_7_Pin, RESET);
	}
	else if(time==6)
	{
		HAL_GPIO_WritePin(P1_1_GPIO_Port, P1_1_Pin, RESET);
		HAL_GPIO_WritePin(P1_2_GPIO_Port, P1_2_Pin, SET);
		HAL_GPIO_WritePin(P1_3_GPIO_Port, P1_3_Pin, RESET);
		HAL_GPIO_WritePin(P1_4_GPIO_Port, P1_4_Pin, RESET);
		HAL_GPIO_WritePin(P1_5_GPIO_Port, P1_5_Pin, RESET);
		HAL_GPIO_WritePin(P1_6_GPIO_Port, P1_6_Pin, RESET);
		HAL_GPIO_WritePin(P1_7_GPIO_Port, P1_7_Pin, RESET);
	}
	else if(time==7)
	{
		HAL_GPIO_WritePin(P1_1_GPIO_Port, P1_1_Pin, RESET);
		HAL_GPIO_WritePin(P1_2_GPIO_Port, P1_2_Pin, RESET);
		HAL_GPIO_WritePin(P1_3_GPIO_Port, P1_3_Pin, RESET);
		HAL_GPIO_WritePin(P1_4_GPIO_Port, P1_4_Pin, SET);
		HAL_GPIO_WritePin(P1_5_GPIO_Port, P1_5_Pin, SET);
		HAL_GPIO_WritePin(P1_6_GPIO_Port, P1_6_Pin, SET);
		HAL_GPIO_WritePin(P1_7_GPIO_Port, P1_7_Pin, SET);
	}
	else if(time==8)
	{
		HAL_GPIO_WritePin(P1_1_GPIO_Port, P1_1_Pin, RESET);
		HAL_GPIO_WritePin(P1_2_GPIO_Port, P1_2_Pin, RESET);
		HAL_GPIO_WritePin(P1_3_GPIO_Port, P1_3_Pin, RESET);
		HAL_GPIO_WritePin(P1_4_GPIO_Port, P1_4_Pin, RESET);
		HAL_GPIO_WritePin(P1_5_GPIO_Port, P1_5_Pin, RESET);
		HAL_GPIO_WritePin(P1_6_GPIO_Port, P1_6_Pin, RESET);
		HAL_GPIO_WritePin(P1_7_GPIO_Port, P1_7_Pin, RESET);
	}
	else if(time==9)
	{
		HAL_GPIO_WritePin(P1_1_GPIO_Port, P1_1_Pin, RESET);
		HAL_GPIO_WritePin(P1_2_GPIO_Port, P1_2_Pin, RESET);
		HAL_GPIO_WritePin(P1_3_GPIO_Port, P1_3_Pin, RESET);
		HAL_GPIO_WritePin(P1_4_GPIO_Port, P1_4_Pin, RESET);
		HAL_GPIO_WritePin(P1_5_GPIO_Port, P1_5_Pin, SET);
		HAL_GPIO_WritePin(P1_6_GPIO_Port, P1_6_Pin, RESET);
		HAL_GPIO_WritePin(P1_7_GPIO_Port, P1_7_Pin, RESET);
	}
}
