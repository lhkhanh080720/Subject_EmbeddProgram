/*
 * State.c
 *
 *  Created on: Apr 13, 2022
 *      Author: USER
 */
#include "State.h"
#include "stm32f4xx.h"

static state_t State;
extern uint32_t genTimerCount;

void ledCtrl(uint8_t x)
{
	HAL_GPIO_WritePin(LEDG_GPIO_Port, LEDG_Pin, x);
}

SW_t SW(void)
{
	SW_t status;
	if(HAL_GPIO_ReadPin(SW_GPIO_Port, SW_Pin) == GPIO_PIN_RESET)
		status = SW_NONPRESS;
	else if(HAL_GPIO_ReadPin(SW_GPIO_Port, SW_Pin) == GPIO_PIN_SET)
		status = SW_PRESS;
	return status;
}

void initState(void)
{
	State = S0;
}

void stateSystemUpdate()
{
	switch(State)
	{
		case S0:
		{
			if(SW() == SW_PRESS)
			{
				State = S1;
				genTimerCount = 3000;
			}
			else if(SW() == SW_NONPRESS)
				State = S0;
			break;
		}
		case S1:
		{
			if(genTimerCount == 0)
				State = S2;
			else if(SW() == SW_NONPRESS)
				State = S0;
			else if(SW() == SW_PRESS)
				State = S1;
			break;
		}
		case S2:
		{
			if(SW() == SW_NONPRESS)
				State = S2;
			else if(SW() == SW_PRESS)
			{
				State = S3;
				genTimerCount = 6000;
			}
			break;
		}
		case S3:
		{
			if(genTimerCount == 0)
				State = S0;
			else if(SW() == SW_NONPRESS)
				State = S2;
			else if(SW() == SW_PRESS)
				State = S3;
			break;
		}
	}

	switch(State)
	{
		case S0:
		case S1:
		{
			ledCtrl(OFF);
			break;
		}
		case S2:
		case S3:
		{
			ledCtrl(ON);
			break;
		}	
	}
}

