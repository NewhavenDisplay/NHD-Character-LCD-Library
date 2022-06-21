#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdint.h>
#include <Arduino.h>

class LCD_Interface
{
public:
    LCD_Interface();
    void set8bitDataPins(uint8_t data);
    void set4bitDataPins(uint8_t data);

    
    uint8_t _dataPins[8];
private:
    
};

#endif