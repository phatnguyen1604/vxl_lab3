

#include "software_timer.h"
#include "main.h"
int timer1_flag=0;
int timer1_counter=0;
int blink_flag=0;
int blink_counter=0;
int timer2_flag=0;
int timer2_counter=0;
int segment_counter=0;
int segment_flag=0;
int button_counter=0;
int button_flag=0;
void setBlink(int duration)
{
	blink_counter=duration/10;
	blink_flag=0;
}
void setTimer1(int duration)
{
	timer1_counter=duration/10;
	timer1_flag=0;
}
void setTimer2(int duration)
{
	timer2_counter=duration/10;
	timer2_flag=0;
}
void setTimer3(int duration)
{
	segment_counter=duration/10;
	segment_flag=0;
}
void setButton(int duration)
{
	button_counter=duration/10;
	button_flag=0;
}
void timerRun()
{
	if(timer1_counter>0)
	{
		timer1_counter--;
		if(timer1_counter<=0)
		{
			timer1_flag=1;
		}
	}
	if(timer2_counter>0)
		{
			timer2_counter--;
			if(timer2_counter<=0)
			{
				timer2_flag=1;
			}
		}
	if(segment_counter>0)
	{
		segment_counter--;
		if(segment_counter<=0)
		{
			segment_flag=1;
		}
	}
	if(blink_counter>0)
	{
		blink_counter--;
		if(blink_counter<=0)
		{
			blink_flag=1;
		}
	}
	if(button_counter>0)
	{
		button_counter--;
		if(button_counter<=0)
		{
			button_flag=1;
		}
	}
}
