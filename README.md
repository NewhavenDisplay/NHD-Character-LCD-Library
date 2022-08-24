# NHD Character LCD Arduino Code Library
This library is written for Newhaven Display's family of character LCDs using the ST7066U controller IC.
Upon release, this library will be available on the Arduino Library Manager.

## Library Download and Installation
1. To download. Click on `Code -> Download ZIP` in the top right corner.
2. Rename the uncompressed folder `NHD-Character-LCD-Library`. 
3. Check that the `NHD-Character-LCD-Library` folder contains `NHD_Character_LCD.cpp` and `NHD_Character_LCD.h`
4. Place the `NHD-Character-LCD-Library` library folder in your `/libraries/` folder. You may need to create the libraries subfolder if its your first library. 
5. Restart the IDE.

## NHD Website Code Library Options
- Create article for library to explain that library is available through the library manager and provide link to library's GitHub page.
- Add "Code Library" link to product page that takes user to code library article.
- Create "Code Libraries" section and add articles there.

## Library Structure
Initial library structure will be: 
NHD_Character_LCD → Interface (4/8-bit parallel)
NHD_Character_LCD class will inherit Interface class.

Users will only include NHD_Character_LCD in their Arduino sketch and only have access to the class constructor, display commands, write data, write command, read.

## Library Complexity
Library is intended to be only as complex as it needs to be.
Overall goal of library is to make the entire library as accessible as possible.

For example, initialization sequences will not call command functions, it will use the command write function to send byte commands to the display. This will match the sequence seen in NHD specs, making it an easy 1:1 comparison for customers and NHD employees. Comments will be included to describe each initialization step.

The library will be modular. Command functions will not rely on interface functions to do anything except accept byte data.

Command functions will match the command list seen in the ST7066U spec sheet. We will also have command combination functions if they add value to the customer's experience.

## Documentation Practices
- Doxygen?
- Function comments
- Readme file
- Reference schematics
- Class diagram?
- 
