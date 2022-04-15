/*
 * GPIO.c
 *
 *  Created on: Feb 13, 2022
 *      Author: USER
 */
#include "../include.h"
#include "GPIO.h"

extern void Config_Led()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(LedPort, LedR | LedG | LedB);
    GPIOPinWrite(LedPort, LedR | LedG | LedB , 0);
}

extern void Config_SW()
{
    SysCtlPeripheralEnable(SWPort);
    GPIOPinTypeGPIOInput(SWPort, SW1 | SW2);
    HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= GPIO_PIN_0;
    GPIOPadConfigSet(SWPort, SW1 | SW2, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
}

