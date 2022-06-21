#include "LCD_Interface.h"

LCD_Interface::LCD_Interface()
{

}

void LCD_Interface::set8bitDataPins(uint8_t data)
{
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(_dataPins[i], (data >> i) & 0x01);
    }
}

void LCD_Interface::set4bitDataPins(uint8_t data)
{
    for (int i = 4; i < 8; i++)
    {
        digitalWrite(_dataPins[i], (data >> i - 4) & 0x01);
    }
}