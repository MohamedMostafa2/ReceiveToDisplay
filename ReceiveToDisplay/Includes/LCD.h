/*H**********************************************************************
* FILENAME :LCD.h
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

#ifndef __LCD_H__
#define __LCD_H__

#include "DataTypes.h"

enum LCD_CMD{
        LCD_CMD_ClearDisplayScreen_e        = 0x01U,
        LCD_CMD_ReturnHome_e                = 0x02U,
        LCD_CMD_DecrementCursor_e           = 0x04U,
        LCD_CMD_IncrementCursor_e           = 0x06U,
        LCD_CMD_ShiftDisplayRight_e         = 0x05U,
        LCD_CMD_ShiftDisplayLeft_e          = 0x07U,
        LCD_CMD_DisplayOffCursorOff_e       = 0x08U,
        LCD_CMD_DisplayOffCursorON_e        = 0x0AU,
        LCD_CMD_DisplayONCursorOff_e        = 0x0CU,
        LCD_CMD_DisplayONCursorBlinking_e   = 0x0EU,
        LCD_CMD_DisplayOffCursorBlinking_e  = 0x0FU,
        LCD_CMD_Shift_CursorPositionLeft_e  = 0x10U,
        LCD_CMD_Shift_CursorPositionRight_e = 0x14U,
        LCD_CMD_Shift_EntireDisplayLeft_e   = 0x18U,
        LCD_CMD_Shift_EntireDisplayRight_e  = 0x1CU,
        LCD_CMD_Cursor_Beginning_1st_line_e = 0x80U,
        LCD_CMD_CursorBeginning_2nd_line_e  = 0xC0U,
        LCD_CMD_4_BitMode3_e                = 0x28U,
        LCD_CMD_8_BitMode_e                 = 0x38U,
        LCD_CMD_4_BitMode_e                 = 0x33U,
        LCD_CMD_4_BitMode2_e                = 0x32U,
    };

enum ShiftBits{

    Zero_Bits_e = 0U,
    OneBit_e    = 1U,
    TwoBits_e   = 2U,
    ThreeBits_e = 3U,
    FourBits_e  = 4U,
    FiveBits_e  = 5U,
    SixBits_e   = 6U,
    SevenBits_e = 7U,

    };

enum BitNumbers{

    BitNum_0_e = 0U,
    BitNum_1_e = 2U,
    BitNum_2_e = 4U,
    BitNum_3_e = 8U,
    BitNum_4_e = 16U,
    BitNum_5_e = 32U,
    BitNum_6_e = 64U,
    BitNum_7_e = 128U,

    };

enum SectionNumber{

    Section_1_e = 1U,
    Section_2_e = 2U,
    Section_3_e = 3U,
    Section_4_e = 4U,
    Section_5_e = 5U,
    Section_6_e = 6U,
    Section_7_e = 7U,

    };

#define FIRST_BIT   1U

#define LINE_TWO    2U

#define LOW                 0U
#define ONE                 1U
#define LCD_INT_COMPLETE    0U

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
extern void LCD_initTask (void);


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
extern void LCD_sendCommand (uint8 LCD_Command);



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
extern void LCD_displayChar (uint8 LCD_Char);



/************************************************************************
* Function Name : LCD_displayString
*
* Parameter
*           I/P : LCD_String , LCD_StringSize
*           O/P : None
*           I/O : None
*
* Return : None
*
* Description : Display String on LCD
*               Display Each Char in String Using LCD_displayChar Function
*
************************************************************************/
extern void LCD_displayString (uint8* LCD_String, uint8 LCD_StringSize);



/************************************************************************
* Function Name : LCD_displayStringRowColumn
*
* Parameter
*           I/P : LCD_Line , LCD_Digit
*           O/P : None
*           I/O : None
*
* Return : None
*
* Description : Display String In Specific Position on LCD
*               1- Set Cursor On Specific Position Using LCD_gotoRowColumn Function
*               2- Display String Using LCD_displayString Function
*
************************************************************************/
extern void LCD_displayStringRowColumn (uint8 LCD_Line, uint8 LCD_Digit, uint8* LCD_String, uint8 LCD_StringSize);



/************************************************************************
* Function Name : LCD_clear
*
* Parameter
*           I/P : None
*           O/P : None
*           I/O : None
*
* Return : None
*
* Description : Clear LCD Display
*
************************************************************************/
extern void LCD_clear (void);

/************************************************************************
* Function Name : LCD_gotoRowColumn
*
* Parameter
*           I/P : LCD_Line
*           O/P : None
*           I/O : None
*
* Return : None
*
* Description : Set Cursor on Specific Position
*               1- Check That is Digit Position Between Min_LCD_Digits and Max_LCD_Digits
*               2- Check if LCD_Line = Two , Then Set Cursor on Line Two + Digit Position
*                   any Other Value set Cursor on Line One + Digit Position
*
************************************************************************/
extern void LCD_gotoRowColumn (uint8 LCD_Line , uint8 LCD_DigitPosition);

#endif
