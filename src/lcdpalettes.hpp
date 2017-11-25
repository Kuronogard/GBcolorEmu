#ifndef LCDPALETTES_H
#define LCDPALETTES_H


#include "types.hpp"

/*
 * palettes for the LCD display
 * It imitates the interface of the real hardware, so the memory controller
 * does not need to know the meaning of any of the related registers.
 */

namespace gbcoloremu {


class bwPalette
{
public:

private:
    uint8_t color0;
    uint8_t color1;
    uint8_t color2;
    uint8_t color3;
};


class LCDpalettes
{
public:
    LCDpalettes();


    void setBgPalette(memValue8_t value);
    memValue8_t getBgPalette();


    void setObjPalette0(memValue8_t value);
    memValue8_t getObjPalette0();


    void setObjPalette1(memValue8_t value);
    memValue8_t getObjPalette1();


    // set/get bg/obj color palette bytes indexed by
    // bg/obj Index variable
    void setBgColorPalette(memValue8_t value);
    memValue8_t getBgColorPalette();


    void setObjColorPalette(memValue8_t value);
    memValue8_t getObjColorPalette();

    // bg/obj indexes
    void setbgColorIndex(memValue8_t index);
    memValue8_t getbgColorIndex();


    void setObjColorIndex(memValue8_t index);
    memValue8_t getObjColorIndex();


    // Autoincrement option for writes in color bg/obj palettes
    void bgColorAutoincrement(bool autoincrement);
    bool bgColorAutoincrementOn();

    void objColorAutoincrement(bool autoincrement);
    bool objColorAutoincrementOn();



private:

    // Palette data for grayscale graphics
    // bit 7-6: color 3
    // bit 5-4: color 2
    // bit 3-2: color 1
    // bit 1-0: color 0
    // Colors 3-1 can be one of (0:white, 1:light grey, 2:dark grey, 3:black)
    uint8_t bgPalette;
    uint8_t objPalette0;
    uint8_t objPalette1;

    // Palette data for color graphics (GBC)
    // 8 palettes with 4 colors each (the same as in grayscale graphics)
    // each color has 2 Bytes
    // bit 15: unused
    // bit 14-10: blue
    // bit  9-5 : green
    // bit  4-0 : red
    uint8_t bgColorPalette[64];  // 2 Bytes x 4 colors x 8 palettes = 64 bytes
    uint8_t objColorPalette[64];

    // Indexes used for secuential R/W access to bgColorPalette and objColorPalette bytes
    uint8_t bgColorIndex;
    uint8_t objColorIndex;

    // Configure index to autoincrement
    bool bgIndexAutoincrement;
    bool objIndexAutoincrement;


};

}

#endif // LCDPALETTES_H
