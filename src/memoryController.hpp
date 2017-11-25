
#ifndef __MEMORY_CONTROLLER_HPP
#define __MEMORY_CONTROLLER_HPP

#include <cstdint>
#include <vector>

#include "types.hpp"
#include "lcdpalettes.hpp"

using namespace std;

#define SIZE_8KB  (8192)   // 2^3 * 2^10
#define SIZE_16KB (16384)  // 2^4 * 2^10
#define SIZE_OAM  (160)
#define SIZE_RAM  (127)

namespace gbcoloremu
{

class Cartridge {
public:
    memValue8_t _switchableROM16k[SIZE_16KB];    // 4000 - 7FFF
    memValue8_t _ROM16[SIZE_16KB];               // 0000 - 3FFF

};


class MemoryController {
private:

    const int ROM16_start               = 0x0000;
    const int ROM16_end                 = 0x3FFF;
    const int switchableROM16k_start    = 0x4000;
    const int switchableROM16k_end      = 0x7FFF;
    const int videoRAM8k_start          = 0x8000;
    const int videoRAM8k_end            = 0x9FFF;
    const int switchableRAM8k_start     = 0xA000;
    const int switchableRAM8k_end       = 0xBFFF;
    const int internalRAM8k_start       = 0xC000;
    const int internalRAM8k_end         = 0xDFFF;
    const int internalRAM8kEcho_start   = 0xE000;
    const int internalRAM8kEcho_end     = 0xFDFF;
    const int spriteAttrMemory_start    = 0xFE00;
    const int spriteAttrMemory_end      = 0xFE9F;
    const int internalRAM_start         = 0xFF80;
    const int internalRAM_end           = 0xFFFE;
    const int interruptEnableReg_addr   = 0xFFFF;

/*
0000, 0008, 0010, 0018, 0020, 0028, 0030, 0038    restart address for instructions RST $<addr>
0040   Vertical Blank Interrupt Start Address
0048   LCDC Status Interrupt Start Address
0050   Timer Overflow Interrupt Start Address
0058   Serial TRansfer Completion Interrupt Start Address
0060   High-to-low of P10-P13 Interrupt Start Address
*/


/*
    enum
    {
        ROM16_ADDR              = 0x0000,
        switchableROM16k_ADDR   = 0x4000,
        videoRAM8k_ADDR         = 0x8000,
        switchableRAM8k_ADDR    = 0xA000,
        internalRAM8k_ADDR      = 0xC000,
        internalRAM8kEcho_ADDR  = 0xE000,
        spriteAttrMemory_ADDR   = 0xFE00,
        unusable_0              = 0xFEA0,
        internalRAM             = 0xFF80
    };
*/

    memValue8_t _interruptEnableReg;            // FFFF

    // Internal memory
    memValue8_t _internalRAM[SIZE_RAM];         // FF80 - FFFE

    // Empty but unusable for I/O               FF4C - FF7F
    // I/O ports                                FF00 - FF4B
    // Empty but unusable for I/O               FEA0 - FEFF

    memValue8_t _spriteAttrMemory[SIZE_OAM];    // FE00 - FE9F
    //memValue8_t _internalRAM8kEcho[];         // E000 - FDFF
    memValue8_t _internalRAM8k[SIZE_8KB];       // C000 - DFFF
    memValue8_t _switchableRAM8k[SIZE_8KB];     // A000 - BFFF
    memValue8_t _videoRAM8k[SIZE_8KB];          // 8000 - 9FFF

    // 32KB Cartridge
    Cartridge _cartridge;
    //_cartridge.switchableROM16k;    // 4000 - 7FFF
    //_cartridge.ROM16;               // 0000 - 3FFF

    /*
     * FF47 bgPalette
     * FF48 objPalette0
     * FF49 objPalette1
     * FF68 bgColorPaletteIndex
     * FF69 bgColorPalette
     * FF6A objColorPaletteIndex
     * FF6B objColorPalette
     */
    LCDpalettes lcdPalettes;

public:

    MemoryController();
    ~MemoryController();

    bool configCartridge(Cartridge& cartridge);
    memValue8_t read(memAddr_t address);
    memValue16_t readDouble(memAddr_t address);
    bool write(memAddr_t adress, memValue8_t value);
    bool writeDouble(memAddr_t address, memValue16_t value);


};

} /* namespace gbcoloremu */


#endif /* __MEMORY_CONTROLLER_HPP */
