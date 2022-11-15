/*
 * button.c
 *
 *  Created on: Oct 24, 2022
 *      Author: 84977
 */

#include "main.h"
#include "software_timer.h"
#include "button.h"

#define BUTTON_IS_PRESSED 	GPIO_PIN_RESET
#define BUTTON_IS_RELEASED 	GPIO_PIN_SET

static GPIO_PinState buttonStatus [3]={BUTTON_IS_RELEASED,BUTTON_IS_RELEASED,BUTTON_IS_RELEASED};
static GPIO_PinState longPressButton1 [3];
static GPIO_PinState longPressButton2 [3];
static GPIO_PinState longPressButton3 [3]={BUTTON_IS_RELEASED,BUTTON_IS_RELEASED,BUTTON_IS_RELEASED};

static uint16_t buttonAddress[3]={Button1_Pin,Button2_Pin,Button3_Pin};
static GPIO_TypeDef* buttonPort[3]={Button1_GPIO_Port,Button2_GPIO_Port,Button3_GPIO_Port};
int DURATION;
void button_reading(void)
{
	for(uint8_t i=0;i<3;i++)
	{
		longPressButton2[i]=longPressButton1[i];
		longPressButton1[i]=HAL_GPIO_ReadPin(buttonPort[i], buttonAddress[i]);
		if(longPressButton1[i]==longPressButton2[i])
		{
			if(longPressButton3[i]!=longPressButton1[i])
			{
				longPressButton3[i]=longPressButton1[i];
				if(longPressButton1[i]==BUTTON_IS_PRESSED)
				{buttonStatus[i]=BUTTON_IS_PRESSED;
				DURATION=100;
				}
			}
			else
			{	DURATION--;
				if(DURATION<=0)
				{
					longPressButton3[i]=BUTTON_IS_RELEASED;
				}
			}
		}
	}
}
int is_button_pressed(int index)
{
	if(buttonStatus[index]==BUTTON_IS_PRESSED)
	{
		buttonStatus[index]=BUTTON_IS_RELEASED;
		return 1;
	}
	else return 0;
}
