
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
    for(counter = 0 ; counter < 20 ;counter++)
    {
        LCD_initTask();
        SysCtlDelay(1000);
    }
    /*for(counter = 0 ; counter < 4 ;counter++)
    {
        LCD_displayCharTask('B');
        SysCtlDelay(1000);
    }*/
    LCD_displayChar('B');
    for(counter = 0 ; counter < 100 ;counter++)
     {
         SysCtlDelay(1000);
     }
    LCD_sendCommand(LCD_CMD_ClearDisplayScreen_e);
    for(counter = 0 ; counter < 100 ;counter++)
        {
            SysCtlDelay(1000);
        }
    LCD_displayChar('A');
    while(1)
    {

    }
	return 0;
}
