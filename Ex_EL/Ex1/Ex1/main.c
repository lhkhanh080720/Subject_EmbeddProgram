

/**
 * main.c
 */
#include "include.h"

int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    Config_Led();
    Config_SW();
    uint8_t i, j;
    while(1)
    {
        i = (!GPIOPinRead(SWPort, SW1) ? LedR : 0);
        GPIOPinWrite(LedPort, LedR , i);
        j = (!GPIOPinRead(SWPort, SW2) ? LedG : 0);
        GPIOPinWrite(LedPort, LedG , j);
    }
}
