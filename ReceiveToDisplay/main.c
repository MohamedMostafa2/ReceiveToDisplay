
#include "Includes/LCD.h"

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

int main(void)
{

uint8 counter = 0;
    for(counter = 0 ; counter < 10 ;counter++)
    {
        LCD_initTask();
        SysCtlDelay(1000);
    }
    LCD_displayChar('Z');
    while(1)
    {

    }
	return 0;
}
