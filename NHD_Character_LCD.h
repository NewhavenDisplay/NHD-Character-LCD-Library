#ifndef NHD_CHARACTER_LCD_H
#define NHD_CHARACTER_LCD_H

#include <stdint.h>
#include <Arduino.h>
#include "LCD_Interface.h"

#define SET_ENTRY_MODE 0x04
#define DDRAM_INCREMENT 0x02
#define DDRAM_DECREMENT 0x00
#define DISPLAY_SHIFT 0x01
#define NO_DISPLAY_SHIFT 0x00

#define CLEAR_SCREEN 0x01

#define HOME 0x02

#define FUNCTION_SET 0x20

#define DISPLAY_MODE 0x08
#define DISPLAY_ON 0x04
#define DISPLAY_OFF 0x00
#define CURSOR_ON 0x02
#define CURSOR_OFF 0x00
#define CURSOR_BLINK_ON 0x01
#define CURSOR_BLINK_OFF 0x00

#define CURSOR_BEHAVIOR 0x10
#define SHIFT_DISPLAY 0x08
#define MOVE_CURSOR 0x00
#define MOVE_RIGHT 0x04
#define MOVE_LEFT 0x00

class NHD_Character_LCD: public LCD_Interface
{
public:

    /**
     * Construct a new NHD_Character_LCD object.
     */
    NHD_Character_LCD();

    /**
     * Initialize a NHD COB LCD for:
     * - 4-bit parallel interface
     * - One enable signal. (< 4x40)
     * 
     * @param columns Number of columns on LCD.
     * @param rows Number of rows on LCD.
     * @param RS Desired Arduino pin number for RS signal.
     * @param enable Desired Arduino pin number for E signal.
     * @param RW Desired Arduino pin number for R/W signal.
     * @param D4 Desired Arduino pin number for D4 signal.
     * @param D5 Desired Arduino pin number for D5 signal.
     * @param D6 Desired Arduino pin number for D6 signal.
     * @param D7 Desired Arduino pin number for D7 signal.
     * @return none
     */
    void initLCD(uint8_t columns, uint8_t rows,
                 uint8_t RS, uint8_t enable, uint8_t RW,
                 uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7);

    /**
     * Initialize a 4x40 NHD COB LCD for:
     * - 4-bit parallel interface.
     * - Two enable signals. (2 top and 2 bottom rows)
     * 
     * @param columns Number of columns on LCD.
     * @param rows Number of rows on LCD.
     * @param RS Desired Arduino pin number for RS signal.
     * @param enable Desired Arduino pin number for E signal.
     * @param enable2 Desired Arduino pin number for E2 signal.
     * @param RW Desired Arduino pin number for R/W signal.
     * @param D4 Desired Arduino pin number for D4 signal.
     * @param D5 Desired Arduino pin number for D5 signal.
     * @param D6 Desired Arduino pin number for D6 signal.
     * @param D7 Desired Arduino pin number for D7 signal.
     * @return none
     * 
     */
    void initLCD(uint8_t columns, uint8_t rows,
                 uint8_t RS, uint8_t enable, uint8_t enable2, uint8_t RW,
                 uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7);

    /**
     * Initialize a NHD COB LCD for:
     * - 8-bit parallel interface
     * - One enable signal. (< 4x40)
     * 
     * @param columns Number of columns on LCD.
     * @param rows Number of rows on LCD.
     * @param RS Desired Arduino pin number for RS signal.
     * @param enable Desired Arduino pin number for E signal.
     * @param RW Desired Arduino pin number for R/W signal.
     * @param D0 Desired Arduino pin number for D0- signal.
     * @param D1 Desired Arduino pin number for D1 signal.
     * @param D2 Desired Arduino pin number for D2 signal.
     * @param D3 Desired Arduino pin number for D3 signal.
     * @param D4 Desired Arduino pin number for D4 signal.
     * @param D5 Desired Arduino pin number for D5 signal.
     * @param D6 Desired Arduino pin number for D6 signal.
     * @param D7 Desired Arduino pin number for D7 signal.
     * @return none
     */
    void initLCD(uint8_t columns, uint8_t rows,
                 uint8_t RS, uint8_t enable, uint8_t RW,
                 uint8_t D0, uint8_t D1, uint8_t D2, uint8_t D3,
                 uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7);

    /**
     * Initialize a 4x40 NHD COB LCD for:
     * - 8-bit parallel interface.
     * - Two enable signals. (2 top and 2 bottom rows)
     * 
     * @param columns Number of columns on LCD.
     * @param rows Number of rows on LCD.
     * @param RS Desired Arduino pin number for RS signal.
     * @param enable Desired Arduino pin number for E signal.
     * @param enable2 Desired Arduino pin number for E2 signal.
     * @param RW Desired Arduino pin number for R/W signal.
     * @param D0 Desired Arduino pin number for D0- signal.
     * @param D1 Desired Arduino pin number for D1 signal.
     * @param D2 Desired Arduino pin number for D2 signal.
     * @param D3 Desired Arduino pin number for D3 signal.
     * @param D4 Desired Arduino pin number for D4 signal.
     * @param D5 Desired Arduino pin number for D5 signal.
     * @param D6 Desired Arduino pin number for D6 signal.
     * @param D7 Desired Arduino pin number for D7 signal.
     * @return none
     */
    void initLCD(uint8_t columns, uint8_t rows,
                 uint8_t RS, uint8_t enable, uint8_t enable2, uint8_t RW,
                 uint8_t D0, uint8_t D1, uint8_t D2, uint8_t D3,
                 uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7);
    
    /**
     * Send a command data byte via 8-bit or 4-bit interface.
     * 
     * @param data Command byte to send to display.
     * @return none
     */
    void command(uint8_t data);

    /**
     * Send a string of characters.
     * 
     * @param data String of characters to write to display.
     * @return none
     */
    void write(unsigned char *data);

    void write(int x, int y, unsigned char *data);

    /**
     * Send one byte of data via 8-bit or 4-bit interface.
     * 
     * @param data Data byte to send to display.
     * @return none
     */
    void write(uint8_t data);

    /**
     * Clear the LCD screen.
     * 
     * @return none
     */
    void clearScreen();

    /**
     * Send the cursor back to the home position. (0, 0)
     * 
     * @return none
     */
    void home();

    /**
     * Set the cursor to the desired (x, y) location.
     * 
     * @param x The desired column to place the cursor.
     * @param y The desired row
     * @return none
     */
    void setCursor(int x, int y);

    /**
     * Shift the display to the left.
     * The cursor follows the display shift.
     * 
     * @return none
     */
    void scrollScreenLeft();

    /**
     * Shift the display to the right.
     * The cursor follows the display shift.
     * 
     * @return none
     */
    void scrollScreenRight();

    /**
     * Shift the cursor to the left.
     * 
     * @return none
     */
    void moveCursorLeft();

    /**
     * Shift the cursor to the right.
     * 
     * @return none
     */
    void moveCursorRight();

    /**
     * Perform a backspace action on the LCD.
     * 
     * @return none
     */
    void backspace();

    /**
     * Set the desired entry mode for the LCD.
     * This sets the moving direction for the cursor and display.
     * 
     * @param incDec Desired setting for the I/D bit.
     * @param displayShift Desired setting for the display shift bit.
     * @return none
     */
    void setEntryMode(uint8_t incDec, uint8_t displayShift);

    /**
     * Set the desired display mode for the LCD.
     * This controls the display/cursor/blink ON/OFF registers.
     * 
     * @param display Turn the display ON or OFF.
     * @param cursor Turn the cursor ON or OFF.
     * @param cursorBlink Set the cursor to blink or stay steady.
     * @return none
     */
    void setDisplayMode(uint8_t display, uint8_t cursor, uint8_t cursorBlink);

    /**
     * Set the desired function mode for the LCD.
     * This controls various settings on the LCD.
     * 
     * @param interface Set the desired interface mode.
     * @param lines Set the number of lines on the LCD.
     * @param font Set the desired font type.
     * @return none
     */
    void setFunctionMode(uint8_t interface, uint8_t lines, uint8_t font);

private:

    /**
     * Set the connected LCD's row and column count
     * and clear the LCD screen.
     * 
     * @param columns Number of columns on connected LCD.
     * @param rows Number of rows on connected LCD.
     * @return none
     */
    void startLCD(uint8_t columns, uint8_t rows);

    /**
     * Send a wakeup sequence for a non-4x40 character LCD.
     * 
     * @return none
     */
    void wakeup();

    /**
     * Send a wakeup sequence for a 4x40 character LCD.
     * 
     * @return none
     */
    void wakeup4x40();

    // Display Values.
    int _columns;
    int _rows;
    uint8_t _rowOffsets[4];
};

#endif