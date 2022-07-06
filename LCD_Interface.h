#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdint.h>
#include <Arduino.h>

class LCD_Interface
{
public:

    /**
     * Construct a new lcd interface object.
     */
    LCD_Interface();

    /**
     * Set all 8 data pins to desired states based on 
     * input data variable.
     * 
     * @param data Desired data to put on data pins.
     * @return none
     */
    void set8bitDataPins(uint8_t data);

    /**
     * Set the top 4 data pins to desired states based on
     * input data variable.
     * This function is inteded to be used multiple times
     * when using 4-bit parallel interface.
     * 
     * @param data Desired data to put on data pins.
     * @return none
     */
    void set4bitDataPins(uint8_t data);

    /**
     * Set the interface to command mode to send
     * command bytes to LCD.
     * 
     * @return none
     */
    void setCommandMode();

    /**
     * Set the interface to data mode to send
     * data bytes to LCD.
     * 
     * @return none
     */
    void setDataMode();

    /**
     * Set the interface to write data to the LCD.
     * 
     * @return none
     */
    void setWriteMode();

    /**
     * Set the interface to read data from the LCD.
     * 
     * @return none
     */
    void setReadMode();

    /**
     * Toggle the appropriate enable signal to capture
     * data on the data bus.
     * 
     * @return none
     */
    void dataLatch();

    /*
    Read busy flag
    Read CGRAM
    Read DDRAM
    */

    /**
     * Read the LCD's busy flag and address counter.
     * 
     * @return uint8_t The LCD's busy flag and address counter. 
     */
    uint8_t readBusyFlagAC();

    /**
     * Set the interface to write to the top of a 4x40 LCD.
     * 
     * @return none 
     */
    void setTop();

    /**
     * Set the interface to write to the bottom of a 4x40 LCD.
     * 
     * @return none
     */
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