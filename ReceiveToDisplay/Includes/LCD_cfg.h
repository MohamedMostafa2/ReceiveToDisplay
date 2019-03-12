/*H**********************************************************************
* FILENAME :LCD_cfg.h
*
* DESCRIPTION :
*       LCD 16x2 Driver
*
* PUBLIC FUNCTIONS :
*       void LCD_init (void)
*       void LCD_sendCommand (uint8 LCD_Command)
*       void LCD_displayChar (uint8 LCD_Char)
*       void LCD_displayString (uint8* LCD_String, uint8 LCD_StringSize)
*       void LCD_displayStringRowColumn (uint8 LCD_Line, uint8 LCD_Digit, uint8* LCD_String, uint8 LCD_StringSize)
*       void LCD_clear (void)
*       void LCD_gotoRowColumn (uint8 LCD_Line , uint8 LCD_DigitPosition)
*
* NOTES :
*       These Driver For LCD Model LMB161ABC
*       See Data Sheet For More Information
*       http://www.ram-e-shop.com/ds/lcd/LMB161ABC.pdf
*
*
* AUTHOR :    Mohamed AbdelKarim        START DATE :    19 Feb 19
*
* CHANGES : None
*
*
*H*/

#ifndef __LCD_CFG_H__
#define __LCD_CFG_H__

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#define LCD_RS  GPIO_PIN_2
#define LCD_RW  GPIO_PIN_3
#define LCD_E   GPIO_PIN_4

#define LCD_D4  GPIO_PIN_4
#define LCD_D5  GPIO_PIN_5
#define LCD_D6  GPIO_PIN_6
#define LCD_D7  GPIO_PIN_7

#define MIN_LCD_DIGITS  0U
#define MAX_LCD_DIGITS  16U

#define DELAY_2_MS      2U   /* 1 Milli Second*/


#endif
