

/**
 * main.c
 */
#include "include.h"

int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    Config_Led();
    Config_SW();
    Config_UART();
    while(1)
    {
        if(!GPIOPinRead(SWPort, SW1))
        {
            UARTCharPut(UART0_BASE, 'P');
            while(!GPIOPinRead(SWPort, SW1));
            UARTCharPut(UART0_BASE, 'R');
        }
    }
}
