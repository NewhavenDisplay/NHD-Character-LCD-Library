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
    NHD_Character_LCD();
    void initLCD(uint8_t columns, uint8_t rows,
                 uint8_t RS, uint8_t enable, uint8_t RW,
                 uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7);
    void initLCD(uint8_t columns, uint8_t rows,
                 uint8_t RS, uint8_t enable, uint8_t enable2, uint8_t RW,
                 uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7);
    void initLCD(uint8_t columns, uint8_t rows,
                 uint8_t RS, uint8_t enable, uint8_t RW,
                 uint8_t D0, uint8_t D1, uint8_t D2, uint8_t D3,
                 uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7);
    void initLCD(uint8_t columns, uint8_t rows,
                 uint8_t RS, uint8_t enable, uint8_t enable2, uint8_t RW,
                 uint8_t D0, uint8_t D1, uint8_t D2, uint8_t D3,
                 uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7);
    void command(uint8_t data);
    void write(unsigned char *data);
    void write(uint8_t data);
    void clearScreen();
    void home();
    void setCursor(int x, int y);
    void scrollScreenLeft();
    void scrollScreenRight();
    void moveCursorLeft();
    void moveCursorRight();
    void setCursorBehavior(uint8_t movement, uint8_t direction);
    void backspace();
    void setEntryMode(uint8_t incDec, uint8_t displayShift);
    void setDisplayMode(uint8_t display, uint8_t cursor, uint8_t cursorBlink);
    void setFunctionMode(uint8_t interface, uint8_t lines, uint8_t font);

private:
    /**
     * Set the connected LCD's row and column count
     * and clear the LCD screen.
     */
    void startLCD(uint8_t columns, uint8_t rows);
    void wakeup();
    void wakeup4x40();

    // Display Values.
    int _columns;
    int _rows;
    uint8_t _rowOffsets[4];
};

#endif