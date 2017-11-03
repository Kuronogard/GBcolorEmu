#include "lcdpalettes.hpp"

namespace gbcoloremu {

LCDpalettes::LCDpalettes()
{

}


void LCDpalettes::setBgPalette(memValue8_t value)
{
    bgPalette = value;
}

memValue8_t LCDpalettes::getBgPalette()
{
    return bgPalette;
}


void LCDpalettes::setObjPalette0(memValue8_t value)
{
    objPalette0 = value;
}

memValue8_t LCDpalettes::getObjPalette0()
{
    return objPalette0;
}


void LCDpalettes::setObjPalette1(memValue8_t value)
{
    objPalette1 = value;
}

memValue8_t LCDpalettes::getObjPalette1()
{
    return objPalette1;
}


// set/get bg/obj color palette bytes indexed by
// bg/obj Index variable
void LCDpalettes::setBgColorPalette(memValue8_t value)
{
    bgColorPalette[bgColorIndex] = value;
    if (bgIndexAutoincrement)
    {
        bgIndexAutoincrement++;
    }
}

memValue8_t LCDpalettes::getBgColorPalette()
{
    return bgColorPalette[bgColorIndex];
}


void LCDpalettes::setObjColorPalette(memValue8_t value)
{
    objColorPalette[objColorIndex] = value;
    if (objIndexAutoincrement)
    {
        objIndexAutoincrement++;
    }
}

memValue8_t LCDpalettes::getObjColorPalette()
{
    return objColorPalette[objColorIndex];
}

// bg/obj indexes
void LCDpalettes::setbgColorIndex(memValue8_t index)
{
    bgColorIndex = index & 0x7F;
    bgIndexAutoincrement = (index & 0x80);
}

memValue8_t LCDpalettes::getbgColorIndex()
{
    return bgColorIndex;
}


void LCDpalettes::setObjColorIndex(memValue8_t index)
{
    objColorIndex = index & 0x7F;
    objIndexAutoincrement = (index & 0x80);
}

memValue8_t LCDpalettes::getObjColorIndex()
{
    return objColorIndex;
}


// Autoincrement option for writes in color bg/obj palettes
void LCDpalettes::bgColorAutoincrement(bool autoincrement)
{
    objIndexAutoincrement = autoincrement;
}

bool LCDpalettes::bgColorAutoincrementOn()
{
    return bgIndexAutoincrement;
}

void LCDpalettes::objColorAutoincrement(bool autoincrement)
{
    objIndexAutoincrement = autoincrement;
}

bool LCDpalettes::objColorAutoincrementOn()
{
    return objIndexAutoincrement;
}

}
