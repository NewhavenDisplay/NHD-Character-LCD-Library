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
    void setCommandMode();
    void setDataMode();
    void setWriteMode();
    void setReadMode();
    void dataLatch();
    uint8_t readBusyFlagAC();
    void setTop();
    void setBottom();
    
    /**
     * isTop == true : Use E/E1 for enable.
     * isTop == false : Use E2 for enable. (seen on 4x40 COB LCDs)
     */
    bool _isTop = true; // Default set for non-4x40
    bool _is4x40 = false; // Default set for non-4x40

    uint8_t _dataPins[8];

    // Pin Assignments
    uint8_t _RS;
    uint8_t _enable;
    uint8_t _enable2;
    uint8_t _RW;

    enum interface
    {
        parallel8bit,
        parallel4bit
    };
    interface _interface;
private:
    
};

#endif