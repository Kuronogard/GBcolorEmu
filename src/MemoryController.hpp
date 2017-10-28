
#ifndef __MEMORY_CONTROLLER_HPP
#define __MEMORY_CONTROLLER_HPP

#include <cstdint>
#include <vector>

using namespace std;

namespace gbcoloremu
{

using memAddr_t = uint16_t;
using memValue8_t = uint8_t;
using memValue16_t = uint16_t;

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

    memValue8_t _interruptEnableReg;          // FFFF

    // Internal memory
    vector<memValue8_t> _internalRAM;         // FF80 - FFFE

    // Empty but unusable for I/O               FF4C - FF7F
    // I/O ports                                FF00 - FF4B
    // Empty but unusable for I/O               FEA0 - FEFF

    vector<memValue8_t> _spriteAttrMemory;    // FE00 - FE9F
    vector<memValue8_t> _internalRAM8kEcho;   // E000 - FDFF
    vector<memValue8_t> _internalRAM8k;       // C000 - DFFF
    vector<memValue8_t> _switchableRAM8k;     // A000 - BFFF
    vector<memValue8_t> _videoRAM8k;          // 8000 - 9FFF

    // 32KB Cartridge
    vector<memValue8_t> _switchableROM16k;    // 4000 - 7FFF
    vector<memValue8_t> _ROM16;               // 0000 - 3FFF


public:

    MemoryController();
    ~MemoryController();

    memValue8_t read(memAddr_t address);
    bool write(memAddr_t adress, memValue8_t value);

};

} /* namespace gbcoloremu */


#endif /* __MEMORY_CONTROLLER_HPP */
