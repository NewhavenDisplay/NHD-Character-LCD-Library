#include "LCD_Interface.h"

LCD_Interface::LCD_Interface()
{

}

void LCD_Interface::set8bitDataPins(uint8_t data)
{
    for (int i = 0; i < 8; i++)
    {
        digitalWrite(this->_dataPins[i], (data >> i) & 0x01);
    }
}

void LCD_Interface::set4bitDataPins(uint8_t data)
{
    for (int i = 4; i < 8; i++)
    {
        digitalWrite(this->_dataPins[i], (data >> i - 4) & 0x01);
    }
}

void LCD_Interface::setCommandMode()
{
    digitalWrite(this->_RS, LOW); // Set command mode
}

void LCD_Interface::setDataMode()
{
    digitalWrite(this->_RS, HIGH);
}

void LCD_Interface::setWriteMode()
{
    digitalWrite(this->_RW, LOW); // Set write mode
}

void LCD_Interface::setReadMode()
{
    digitalWrite(this->_RW, HIGH); // Set read mode
}

void LCD_Interface::dataLatch()
{
    if (this->_isTop)
    {
        digitalWrite(this->_enable, HIGH);
        delay(1);
        digitalWrite(this->_enable, LOW);
    }
    else
    {
        digitalWrite(this->_enable2, HIGH);
        delay(1);
        digitalWrite(this->_enable2, LOW);
    }
}

// For 8-bit parallel
uint8_t LCD_Interface::readBusyFlagAC()
{
    setCommandMode();
    setReadMode();

    digitalWrite(this->_enable, HIGH);
    delay(1);
    digitalWrite(this->_enable, LOW);

    // Read data
    uint8_t rxData;
    int pos = 7;
    for (int i = 0; i < 8; i++)
    {
        rxData |= (digitalRead(_dataPins[i]) << pos);
        Serial.print(digitalRead(_dataPins[i]));

        pos--;
    }

    Serial.print(" RBF:");
    Serial.println(rxData);

    return rxData;
}

void LCD_Interface::setTop()
{
    this->_isTop = true;
}

void LCD_Interface::setBottom()
{
    this->_isTop = this->_is4x40 ? false : true;
}