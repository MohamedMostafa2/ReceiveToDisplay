/*
 * LCD.c
 *
 *  Created on: Mar 12, 2019
 *      Author: AVE-LAP-049
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "../Includes/LCD.h"
#include "../Includes/LCD_cfg.h"

/************************************************************************
* Function Name : LCD_init
*
* Parameter
*           I/P : None
*           O/P : None
*           I/O : None
*
* Return : None
*
* Description : Initialize LCD
*               1- Set Pins (RS,RW,E,D4,D5,D6,D7) to Output
*               2- Set LCD To 4 Bit Mode
*               3- Display On and Cursor Blinking
*               4- Clear Display Screen
*               5- Let Cursor Begin From 1st Line
*
************************************************************************/
void LCD_init (void){

    volatile uint32_t ui32Loop=0;

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); /* Enable the GPIOA port that is used for the on-board LCD. */
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC); /* Enable the GPIOC port that is used for the on-board LCD. */

    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA))
    {
    }
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC))
    {
    }
    /* Set pin RS to Output*/
    /* Set pin R/W to Output*/
    /* Set pin E to Output*/
    GPIOPinTypeGPIOOutput(GPIO_PORTA_BASE, LCD_RS | LCD_RW | LCD_E);


    /* Set pin D4 to Output*/
    /* Set pin D5 to Output*/
    /* Set pin D6 to Output*/
    /* Set pin D7 to Output*/
    GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, LCD_D4 | LCD_D5 | LCD_D6 | LCD_D7);


    /* Set LCD To 4 Bit Mode */
    LCD_sendCommand(LCD_CMD_4_BitMode_e);

    /* Dummy Delay */
    SysCtlDelay(2000);

    /* Set LCD To 4 Bit Mode */
    LCD_sendCommand(LCD_CMD_4_BitMode2_e);

    /* Dummy Delay */
    SysCtlDelay(2000);

    /* Set LCD To 4 Bit Mode */
    LCD_sendCommand(LCD_CMD_4_BitMode3_e);

    /* Dummy Delay */
    SysCtlDelay(2000);

    /* Set LCD To 4 Bit Mode */
    LCD_sendCommand(LCD_CMD_DisplayONCursorOff_e);

    /* Dummy Delay */
    SysCtlDelay(2000);

    /* Set LCD To 4 Bit Mode */
    LCD_sendCommand(LCD_CMD_ReturnHome_e);

    /* Dummy Delay */
    SysCtlDelay(2000);

    /* Set LCD To 4 Bit Mode */
    LCD_sendCommand(LCD_CMD_Cursor_Beginning_1st_line_e);

    /* Dummy Delay */
    SysCtlDelay(2000);

}


/************************************************************************
* Function Name : LCD_sendCommand
*
* Parameter
*           I/P : LCD_Command
*           O/P : None
*           I/O : None
*
* Return : None
*
* Description : Send Command To LCD
*               1-  Clear RS Pin to Send Command
*               2-  Clear RW Pin to Set Read Mode
*               3-  Put MSB Command On LCD Data Pins
*               4-  Clear Display Screen
*               5-  Enable LCD To Latch Command
*               6-  Delay 2 ms
*               7-  Disable LCD
*               8-  Put LSB Command On LCD Data Pins
*               9-  Enable LCD To Latch Command
*               10- Delay 2 ms
*               11- Disable LCD
************************************************************************/
void LCD_sendCommand (uint8 LCD_Command){

    volatile uint32_t ui32Loop=0;

    /* Clear RS Pin to Send Command */
    GPIOPinWrite(GPIO_PORTA_BASE, LCD_RS, LOW);

    /* Clear RW Pin to Set Read Mode */
    GPIOPinWrite(GPIO_PORTA_BASE, LCD_RW, LOW);

    /* Put MSB Command On LCD Data Pins */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D4, ( LCD_Command & BitNum_4_e )); /* Command Bit (4) = LCD Data pin (4) */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D5, ( LCD_Command & BitNum_5_e )); /* Command Bit (5) = LCD Data pin (5) */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D6, ( LCD_Command & BitNum_6_e )); /* Command Bit (6) = LCD Data pin (6) */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D7, ( LCD_Command & BitNum_7_e )); /* Command Bit (7) = LCD Data pin (7) */

    GPIOPinWrite(GPIO_PORTA_BASE, LCD_E, LCD_E); /* Enable LCD To Latch Command */

    /* Dummy Delay */
    SysCtlDelay(2000);

    GPIOPinWrite(GPIO_PORTA_BASE, LCD_E, LOW);  /* Disable LCD */

    /* Put LSB Command On LCD Data Pins */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D4, ( (LCD_Command<<FourBits_e) & BitNum_4_e )); /* Command Bit (4) = LCD Data pin (4) */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D5, ( (LCD_Command<<FourBits_e) & BitNum_5_e )); /* Command Bit (5) = LCD Data pin (5) */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D6, ( (LCD_Command<<FourBits_e) & BitNum_6_e )); /* Command Bit (6) = LCD Data pin (6) */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D7, ( (LCD_Command<<FourBits_e) & BitNum_7_e )); /* Command Bit (7) = LCD Data pin (7) */



    GPIOPinWrite(GPIO_PORTA_BASE, LCD_E, LCD_E); /* Enable LCD To Latch Command */

    /* Dummy Delay */
    SysCtlDelay(2000);

    GPIOPinWrite(GPIO_PORTA_BASE, LCD_E, LOW);  /* Disable LCD */

    /* Dummy Delay */
    SysCtlDelay(2000);


}


/************************************************************************
* Function Name : LCD_displayChar
*
* Parameter
*           I/P : LCD_Char
*           O/P : None
*           I/O : None
*
* Return : None
*
* Description : Display Char on LCD
*               1-  Clear RS Pin to Send Command
*               2-  Clear RW Pin to Set Read Mode
*               3-  Put MSB Char On LCD Data Pins
*               6-  Enable LCD To Latch Command
*               7-  Delay 2 ms
*               8-  Disable LCD
*               9-  Put LSB Char On LCD Data Pins
*               10- Enable LCD To Latch Command
*               11- Delay 2 ms
*               12- Disable LCD
*
************************************************************************/
void LCD_displayChar (uint8 LCD_Char){

    volatile uint32_t ui32Loop;

    GPIOPinWrite(GPIO_PORTA_BASE, LCD_RS, LCD_RS); /* Set RS Pin to Send Data */

    GPIOPinWrite(GPIO_PORTA_BASE, LCD_RW, LOW); /* Clear RW Pin to Set Read Mode */

    /* Put MSB Char On LCD Data Pins */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D4, ( LCD_Char & BitNum_4_e )); /* Data Bit (4) = LCD Data pin (4) */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D5, ( LCD_Char & BitNum_5_e )); /* Data Bit (5) = LCD Data pin (5) */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D6, ( LCD_Char & BitNum_6_e )); /* Data Bit (6) = LCD Data pin (6) */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D7, ( LCD_Char & BitNum_7_e )); /* Data Bit (7) = LCD Data pin (7) */

    GPIOPinWrite(GPIO_PORTA_BASE, LCD_E, LCD_E); /* Enable LCD To Latch Command */

    /* Dummy Delay */
    SysCtlDelay(2000);

    GPIOPinWrite(GPIO_PORTA_BASE, LCD_E, LOW);  /* Disable LCD */

    /* Put LSB Char On LCD Data Pins */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D4, ( (LCD_Char<<FourBits_e) & BitNum_4_e )); /* Data Bit (0) = LCD Data pin (4) */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D5, ( (LCD_Char<<FourBits_e) & BitNum_5_e )); /* Data Bit (1) = LCD Data pin (5) */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D6, ( (LCD_Char<<FourBits_e) & BitNum_6_e )); /* Data Bit (2) = LCD Data pin (6) */
    GPIOPinWrite(GPIO_PORTC_BASE, LCD_D7, ( (LCD_Char<<FourBits_e) & BitNum_7_e )); /* Data Bit (3) = LCD Data pin (7) */

    GPIOPinWrite(GPIO_PORTA_BASE, LCD_E, LCD_E); /* Enable LCD To Latch Command */

    /* Dummy Delay */
    SysCtlDelay(2000);

    GPIOPinWrite(GPIO_PORTA_BASE, LCD_E, LOW);  /* Disable LCD */

}




