/*
 * State.c
 *
 *  Created on: Apr 13, 2022
 *      Author: USER
 */
#include "State.h"

static state_t State;

void ledCtrl(uint8_t x)
{
	HAL_GPIO_WritePin(LEDR_GPIO_Port, LEDR_Pin, x);
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

void stateSystemUpdate(void)
{
	switch(State)
	{
		case S0:
		{
			if(SW() == SW_PRESS)
				State = S1;
			else if(SW() == SW_NONPRESS)
				State = S0;
			break;
		}
		case S1:
		{
			if(SW() == SW_PRESS)
				State = S1;
			else if(SW() == SW_NONPRESS)
				State = S2;
			break;
		}
		case S2:
		{
			if(SW() == SW_PRESS)
				State = S3;
			else if(SW() == SW_NONPRESS)
				State = S2;
			break;
		}
		case S3:
		{
			if(SW() == SW_PRESS)
				State = S3;
			else if(SW() == SW_NONPRESS)
				State = S0;
			break;
		}
	}

	switch(State)
	{
		case S0:
		case S3:
		{
			ledCtrl(OFF);
			break;
		}
		case S1:
		case S2:
		{
			ledCtrl(ON);
			break;
		}	
	}
}

