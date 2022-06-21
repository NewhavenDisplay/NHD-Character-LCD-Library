# NHD Character LCD Arduino Code Library
This library is written for Newhaven Display's family of character LCDs using the ST7066U controller IC.
Upon release, this library will be available on the Arduino Library Manager.

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

## Estimated Development Timeline
Total Estimated Project Time: **2 Months**\
*NOTE: These times are just an estimate and are subject to change.*

1. Initial Planning | **2 Days**
   1. Establish development timeline
   2. Establish preliminary library structure
   3. Establish intended library complexity
   4. Establish required documentation practices/requirements
   5. Establish where library indication will appear on NHD website.
2. Initial Development | **1 Week**
   1. Write a basic code library that works with any NHD character LCD using ST7066U.
   2. Review code structure and implementation.
   3. Create initial documentation.
3. Feature Implementation | **1 Week**
   1. Write any necessary features into code library. (Commands, command combinations, nice-to-haves, etc.)
   2. Test all new features.
4. Display Family Testing | **2 Weeks**
   1. Test code with all variations of NHD character LCDs.
   2. Create compatibiltiy spreadsheet.
   3. Identify additional logic/functions/features required to accomodate for all NHD character LCDs.
   4. Review library structure and use. Ensure easy usability after library is compatible with all NHD character LCDs.
   5. Make library compatible with all variations of NHD character LCDs.
   6. Re-test all variations of NHD character LCDs.
5. Structure Review | **2 Days**
   1. Review overall structure of library for readability, complexity, and ease-of-use.
6. Library Finalization | **2 Days**
   1. Perform any final refactoring, documentation, re-organization necessary after structure review.
7. Library Testing | **1 Week**
   1. Functional testing
   2. Non-functional testing
8. Create Library Examples | **1 Week**
   1. Create suite of example programs to package with library.
   2. May be able to convert testing sketches (or parts of tests) to examples.
9.  Documentation | **1 Week**
    1.  Review and improve documentation.
10. Prepare to submit to Arduino Library Manager | **3 Days**
    1.  Ensure library meets [acceptance criteria](https://github.com/arduino/library-registry/blob/main/FAQ.md#submission-requirements) for the Arduino Library Manager.
11. Final Library Review | **2 Days**
12. Submit Library to Arduino Library Manager | **1 Day**
    1.  Follow [instructions to add library to registry](https://github.com/arduino/library-registry#instructions).
13. Postmortem / Lessons Learned