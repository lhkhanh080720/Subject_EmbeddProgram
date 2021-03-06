/*
 * main.c
 *
 *  Created on: Feb 18, 2022
 *      Author: USER
 */

#include "include.h"

uint8_t i = 0;

void SysTick_ISR()
{
    GPIOPinWrite(LedPort, LedR, ~GPIOPinRead(LedPort, LedR));
}

void UARTInt_Handler()
{
    UARTIntClear(UART0_BASE, UARTIntStatus(UART0_BASE, true));
    switch (UARTCharGet(UART0_BASE))
    {
        case 'O':
            GPIOPinWrite(LedPort, LedG, LedG);
            i = 0;
            break;
        case 'F':
            GPIOPinWrite(LedPort, LedG, 0);
            i = 0;
            break;
        case 'T':
            i = 1;
            break;
    }
}

int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_12_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    Config_Led();
    Config_UART();

    SysTickPeriodSet(SysCtlClockGet());
    SysTickIntRegister(&SysTick_ISR);
    SysTickIntEnable();
    SysTickEnable();

    UARTIntRegister(UART0_BASE, &UARTInt_Handler); //khai bao tac vu ngat
    UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT); // nhan tin hieu thuc thi ngat

    while(1)
    {
        if(i)
        {
            GPIOPinWrite(LedPort, LedG, ~GPIOPinRead(LedPort, LedG));
            SysCtlDelay(SysCtlClockGet()/3);
        }
    }
}
