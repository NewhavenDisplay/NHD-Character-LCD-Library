/*
 * Wiring Reference
 * 
 * E2 pin to digital pin 13 (4x40 display)
 * RS pin to digital pin 12
 * Enable pin to digital pin 11
 * R/W pin to digital pin 10
 * D0 pin to digital pin 9
 * D1 pin to digital pin 8
 * D2 pin to digital pin 7
 * D3 pin to digital pin 6
 * D4 pin to digital pin 5
 * D5 pin to digital pin 4
 * D6 pin to digital pin 3
 * D7 pin to digital pin 2
 */

#include <NHD_Character_LCD.h>

NHD_Character_LCD lcd;

void setup()
{
    //lcd.initLCD(16, 2, 12, 11, 10, 5, 4, 3, 2); // For <4x40 LCD using 4-bit mode
    //lcd.initLCD(40, 4, 12, 11, 13, 10, 5, 4, 3, 2); // For 4x40 LCD using 4-bit mode
    //lcd.initLCD(16, 2, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2); // For <4x40 LCD using 8-bit mode

    lcd.initLCD(40, 4, 12, 11, 13, 10, 9, 8, 7, 6, 5, 4, 3, 2); // For 4x40 LCD using 8-bit mode
    lcd.write(0, 0, (unsigned char*)"Hello World!");
}

void loop()
{
    lcd.scrollScreenRight();
    delay(500);
}