#include "NHD_Character_LCD.h"

// Globals

// Flags
bool is4x40 = false; // Default set for non-4x40

/**
 * isTop == true : Use E/E1 for enable.
 * ifTop == false : Use E2 for enable. (seen on 4x40 COB LCDs)
 */
bool isTop = true; // Default set for non-4x40

// Display Values.
int _columns;
int _rows;
uint8_t _rowOffsets[4];

// Pin Assignments
uint8_t _dataPins[8];
uint8_t _RS;
uint8_t _enable;
uint8_t _enable2;
uint8_t _RW;

enum interface {
  parallel8bit,
  parallel4bit
};
interface _interface;

NHD_Character_LCD::NHD_Character_LCD()
{
    
}

/**
 * Initialize a NHD COB LCD for:
 * - 4-bit parallel interface
 * - One enable signal. (< 4x40)
 */
void NHD_Character_LCD::initLCD(uint8_t columns, uint8_t rows, 
             uint8_t RS, uint8_t enable, uint8_t RW, 
             uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7)
{
  startLCD(columns, rows);
  _interface = parallel4bit;

  _RS = RS;
  _enable = enable;
  _RW = RW;

  pinMode(enable, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(RW, OUTPUT);

  _dataPins[4] = D4;
  _dataPins[5] = D5;
  _dataPins[6] = D6;
  _dataPins[7] = D7;

  // Set all data pins to output mode.
  for(int i = 4; i < 8; i++)
  {
    pinMode(_dataPins[i], OUTPUT);
  }

  wakeup();
  command(0x20);
  command(0x28); // Function set: 4-bit / 2-line
  command(0x10); // Set cursor moving
  command(0x0F); // Display ON : Cursor ON : Cursor blinking
  command(0x06); // Entry mode set
  clearScreen();
}

/**
 * Initialize a 4x40 NHD COB LCD for:
 * - 4-bit parallel interface.
 * - Two enable signals. (2 top and 2 bottom rows)
 */
void NHD_Character_LCD::initLCD(uint8_t columns, uint8_t rows, 
             uint8_t RS, uint8_t enable, uint8_t enable2, uint8_t RW, 
             uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7)
{
  startLCD(columns, rows);
  _interface = parallel4bit;

  _RS = RS;
  _enable = enable;
  _enable2 = enable2;
  _RW = RW;

  pinMode(enable, OUTPUT);
  pinMode(enable2, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(RW, OUTPUT);

  _dataPins[4] = D4;
  _dataPins[5] = D5;
  _dataPins[6] = D6;
  _dataPins[7] = D7;

  // Set all data pins to output mode.
  for(int i = 4; i < 8; i++)
  {
    pinMode(_dataPins[i], OUTPUT);
  }
  
  wakeup4x40();
  setTop(); 
  command(0x20);
  command(0x28); // Function set: 4-bit / 2-line
  command(0x10); // Set cursor moving
  command(0x0F); // Display ON : Cursor ON : Cursor blinking
  command(0x06); // Entry mode set
  clearScreen();
  
  setBottom(); 
  command(0x20);
  command(0x28);
  command(0x10);
  command(0x0F);
  command(0x06);
  clearScreen(); 
}

/**
 * Initialize a NHD COB LCD for:
 * - 8-bit parallel interface
 * - One enable signal. (< 4x40)
 */
void NHD_Character_LCD::initLCD(uint8_t columns, uint8_t rows, 
             uint8_t RS, uint8_t enable, uint8_t RW, 
             uint8_t D0, uint8_t D1, uint8_t D2, uint8_t D3, 
             uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7)
{
  startLCD(columns, rows);
  _interface = parallel8bit;

  _RS = RS;
  _enable = enable;
  _RW = RW;

  pinMode(enable, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(RW, OUTPUT);

  _dataPins[0] = D0;
  _dataPins[1] = D1;
  _dataPins[2] = D2;
  _dataPins[3] = D3;
  _dataPins[4] = D4;
  _dataPins[5] = D5;
  _dataPins[6] = D6;
  _dataPins[7] = D7;

  // Set all data pins to output mode.
  for(int i = 0; i < 8; i++)
  {
    pinMode(_dataPins[i], OUTPUT);
  }

  digitalWrite(enable, LOW);
  delay(100);
  wakeup();
  command(0x38); // Function set: 8-bit / 2-line
  command(0x10); // Set cursor moving
  command(0x0E); // Display ON : Cursor ON
  command(0x06); // Entry mode set
  clearScreen();
}

/**
 * Initialize a 4x40 NHD COB LCD for:
 * - 8-bit parallel interface.
 * - Two enable signals. (2 top and 2 bottom rows)
 */
void NHD_Character_LCD::initLCD(uint8_t columns, uint8_t rows, 
             uint8_t RS, uint8_t enable, uint8_t enable2, uint8_t RW, 
             uint8_t D0, uint8_t D1, uint8_t D2, uint8_t D3, 
             uint8_t D4, uint8_t D5, uint8_t D6, uint8_t D7)
{
  startLCD(columns, rows);
  _interface = parallel8bit;

  _RS = RS;
  _enable = enable;
  _enable2 = enable2;
  _RW = RW;

  pinMode(enable, OUTPUT);
  pinMode(enable2, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(RW, OUTPUT);

  _dataPins[0] = D0;
  _dataPins[1] = D1;
  _dataPins[2] = D2;
  _dataPins[3] = D3;
  _dataPins[4] = D4;
  _dataPins[5] = D5;
  _dataPins[6] = D6;
  _dataPins[7] = D7;

  // Set all data pins to output mode.
  for(int i = 0; i < 8; i++)
  {
    pinMode(_dataPins[i], OUTPUT);
  }

  wakeup4x40();

  setTop(); 
  command(0x38); // Function set: 8-bit / 2-line
  //command(0x10); // Set cursor moving
  setCursorBehavior(MOVE_CURSOR, MOVE_RIGHT);
  setDisplayMode(DISPLAY_ON, CURSOR_ON, CURSOR_BLINK_OFF);
  setEntryMode(DDRAM_INCREMENT, NO_DISPLAY_SHIFT);
  clearScreen();

  setBottom();
  command(0x38);
  //command(0x10);
  setCursorBehavior(MOVE_CURSOR, MOVE_RIGHT);
  setDisplayMode(DISPLAY_ON, CURSOR_ON, CURSOR_BLINK_OFF);
  setEntryMode(DDRAM_INCREMENT, NO_DISPLAY_SHIFT);
  clearScreen();
}

/**
 * Set the connected LCD's row and column count
 * and clear the LCD screen.
 */
void NHD_Character_LCD::startLCD(uint8_t columns, uint8_t rows)
{
  _columns = columns;
  _rows = rows;

  if((columns == 40) && (rows == 4))
  {
    is4x40 = true;

    _rowOffsets[0] = 0x00;
    _rowOffsets[1] = 0x40;
    _rowOffsets[2] = 0x00;
    _rowOffsets[3] = 0x40;
  } else {
    is4x40 = false;

    _rowOffsets[0] = 0x00;
    _rowOffsets[1] = 0x40;
    _rowOffsets[2] = columns;
    _rowOffsets[3] = 0x40 + columns;
  }
}

void NHD_Character_LCD::wakeup()
{
  command(0x30);
  delay(30);
  command(0x30);
  delay(10);
  command(0x30);
  delay(10);
}

void NHD_Character_LCD::wakeup4x40()
{
  delay(15);
  setTop(); command(0x30);
  setBottom(); command(0x30);
  delay(5);
  setTop(); command(0x30);
  setBottom(); command(0x30);
  delay(5);
  setTop(); command(0x30);
  setBottom(); command(0x30);
  delay(5);
}

void NHD_Character_LCD::set8bitDataPins(uint8_t data)
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(_dataPins[i], (data >> i) & 0x01);
  }
}

void NHD_Character_LCD::set4bitDataPins(uint8_t data)
{
  for (int i = 4; i < 8; i++)
  {
    digitalWrite(_dataPins[i], (data >> i - 4) & 0x01);
  }
}

void NHD_Character_LCD::setTop()
{
  isTop = true;
}

void NHD_Character_LCD::setBottom()
{
  isTop = is4x40 ? false : true;
}

/**
 * Send a command data byte via 8-bit or 4-bit interface.
 */
void NHD_Character_LCD::command(uint8_t data)
{
  if(_interface == parallel8bit)
  {
    set8bitDataPins(data);
    setCommandMode();
    setWriteMode();
    dataLatch();
  } else if(_interface == parallel4bit)
  {
    set4bitDataPins(data >> 4);
    setCommandMode();
    setWriteMode();
    dataLatch();

    set4bitDataPins(data);
    dataLatch();
  }
}

void NHD_Character_LCD::setCommandMode()
{
  digitalWrite(_RS, LOW); // Set command mode
}

void NHD_Character_LCD::setDataMode()
{
  digitalWrite(_RS, HIGH);
}

void NHD_Character_LCD::setWriteMode()
{
  digitalWrite(_RW, LOW); // Set write mode
}

void NHD_Character_LCD::setReadMode()
{
  digitalWrite(_RW, HIGH); // Set read mode
}

void NHD_Character_LCD::dataLatch()
{
  if(isTop)
  {
    digitalWrite(_enable, HIGH);
    delay(1);
    digitalWrite(_enable, LOW);
  } else {
    digitalWrite(_enable2, HIGH);
    delay(1);
    digitalWrite(_enable2, LOW);
  }
}

/**
 * Send a string of characters.
 */
void NHD_Character_LCD::write(unsigned char* data)
{
  while(*data != '\0')
  {
    write(*data);
    data++;
  }
}

/**
 * Send one byte of data via 8-bit or 4-bit interface.
 */
void NHD_Character_LCD::write(uint8_t data)
{
  if(_interface == parallel8bit)
  {
    set8bitDataPins(data);
    setDataMode();
    setWriteMode();
    dataLatch();
  } else if(_interface = parallel4bit)
  {
    set4bitDataPins(data >> 4);
    setDataMode();
    setWriteMode();
    dataLatch();

    set4bitDataPins(data);
    dataLatch();
  }
}

// For 8-bit parallel
uint8_t NHD_Character_LCD::readBusyFlagAC()
{
  digitalWrite(_RS, LOW);
  digitalWrite(_RW, HIGH);

  digitalWrite(_enable, HIGH);
  delay(1);
  digitalWrite(_enable, LOW);

  // Read data
  uint8_t rxData;
  int pos = 7;
  for(int i = 0; i < 8; i++)
  {
    rxData |= (digitalRead(_dataPins[i]) << pos);
    Serial.print(digitalRead(_dataPins[i]));

    pos--;
  }
  
  Serial.print(" RBF:");
  Serial.println(rxData);

  return rxData;
}

void NHD_Character_LCD::clearScreen()
{
  command(CLEAR_SCREEN);
  delay(5);
}

void NHD_Character_LCD::home()
{
  command(HOME);
  delay(5);
}

void NHD_Character_LCD::setCursor(int x, int y)
{
  uint8_t DDRAM_addr = (_rowOffsets[y] + x) | 0x80;
  command(DDRAM_addr);
  delay(1);
}

void NHD_Character_LCD::scrollScreenLeft()
{
  command(0b00011000);
}

void NHD_Character_LCD::scrollScreenRight()
{
  command(0b00011100);
}

void NHD_Character_LCD::moveCursorLeft()
{
  command(0b00010000);
}

void NHD_Character_LCD::moveCursorRight()
{
  command(0b00010100);
}

void NHD_Character_LCD::setCursorBehavior(uint8_t movement, uint8_t direction)
{
  command(CURSOR_BEHAVIOR | movement | direction);
}

void NHD_Character_LCD::backspace()
{
  moveCursorLeft();
  write(' ');
  moveCursorLeft();
}

/*
Entry mode set:
setCursorMoveRight
setCursorMoveLeft
enableShift
disableShift
*/

void NHD_Character_LCD::setEntryMode(uint8_t incDec, uint8_t displayShift)
{
  command(SET_ENTRY_MODE | incDec | displayShift);
}

/*
Display ON/OFF Control:
displayON
displayOFF
showCursor
enableBlinkingCursor
*/

void NHD_Character_LCD::setDisplayMode(uint8_t display, uint8_t cursor, uint8_t cursorBlink)
{
  command(DISPLAY_MODE | display | cursor | cursorBlink);
}

void NHD_Character_LCD::setFunctionMode(uint8_t interface, uint8_t lines, uint8_t font)
{
  command(0x20 | interface | lines | font);
}

/*
Read busy flag
Read CGRAM
Read DDRAM
*/