
#ifndef __VIDEO_CONTROLLER_HPP
#define __VIDEO_CONTROLLER_HPP

#include "memoryController.hpp"

// Screen buffer (background) 256x256 pixels -> 32x32 tiles (8x8 pixel/tiles)
// only 160x144 pixels displayed on screen -> SCROLLX and SCROLLY are the left upper corner
// background wraps around the screen

// Background Tile Map:  32 rows of 32 bytes (each contains the number of a tile to be displayed)

// Sprite Pattern Table: ($8000 - $8FFF)

// Tile Data Table :($8000 - $8FFF) or ($8800 - 97FF)
        // $8000 - $8FFF: patterns numbered from 0 to 255
        // $8800 - $97FF: patterns numbered from -128 to 127

// Window overlayng the background (WINDPOSX and WINDPOSY are the left upper corner)

namespace gbcoloremu
{
class VideoController {

    memValue8_t SCROLLX; // Coordinates of background memory displayed in the left upper corner
    memValue8_t SCROLLY;

    memValue8_t WINDPOSX; //
    memValue8_t WINDPOSY;

    // LCDC ($FF40) register
    bool lcdEnabled;            // bit 7
    bool windowMapSelect;       // bit 6
    bool windowEnable;          // bit 5
    bool bgMapSelect;           // bit 3
    bool tileSelect;            // bit 4
    bool spriteSize;            // bit 2
    bool spriteEnable;          // bit 1
    bool bgEnable;              // bit 0


    // STAT ($FF41) register
    bool interruptAtHblank;         // bit 6
    bool interruptAtVblank;         // bit 5
    bool interruptAtOAM;            // bit 4
    bool interruptAtTransfering;    // bit 3
    bool coincidenceFlag;           // bit 2
    memValue8_t mode;               // bit1-0


    // SCY ($FF42) register
    memValue8_t scrollY;

    // SCX ($FF43) register
    memValue8_t scrollX;

    // LY ($FF44) register
    memValue8_t currentLCDCY;

    // LYC ($FF45) register
    memValue8_t currentLCDCYcompare;

    // GBP ($FF47)
    memValue8_t dotData11;


    // 32*8 x 32*8 = 27100 pixels in the screen
    memValue8_t _virtualScreen[27100];

    // Tile Data Table
    // 8x8 pixel/tile 2bit color  => 16 bytes/tile
    // 256 tiles

    //
    // 1: . . 2 2 2 . 2 .  ---> byte1: 0 0 0 0 0 0 0 0   (Color for each pixel is taken by byte1/byte2 colummns, NOT ROWS)
    //                          byte2: 0 0 1 1 1 0 1 0
    //
    memValue8_t _charRAM[6144];             // $8000-97FF

    // Background Tile Maps
    memValue8_t _bgMap1[1024];              // $9800-$9BFF
    memValue8_t _bgMap2[1024];              // $9C00-$9FFF

    // Byte 1: X location (offset 8)   // To put a sprite in the top left, it must be at (8, 16)
    // Byte 2: Y location (offset 16)
    // Byte 3: Tile number (0-255)
    // Byte 4 Attributes
        // [bit 7.  0: display on top of bg and window,  1: hidden behind colors 1, 2 and 3]
        // [bit 6.  0: none,  1: vertically flipped]
        // [bit 5.  0: none,  1: horizontally flipped]
        // [bit 4.  0: sprite colors taken from OBJ0PAL,  1: sprite colors taken from OBJ1PAL]
    memValue8_t _ObjectAttrMemory[160];    // $FE00-$FE9F


    // [measured in cycles]
    // horizontal render + horizontal blank
    // vertical render + vertical blank


    // sprites with the same x coordinate are shown with prioity based on table ordering (last -> highest priority)
    // sprites with different x coordinate are shown with priority based on x ( lowest x -> highst priority)


    // 2 color palettes
    // each color is BGR ranging from 0 to 31, so 3x5 = 15 (+ 1) bits = 16 bits (2 Bytes) per color
    // 2 x 4 = 8 bytes per palette
    memValue16_t _palette_OBJ0PAL[4];
    memValue16_t _palette_OBJ1PAL[4];


private:


    void drawLine();
public:

};

} /* namespace gbcoloremu */


#endif /* __VIDEO_CONTROLLER_HPP */
