
#ifndef __CPU_HPP
#define __CPU_HPP

#include "memoryController.hpp"
#include "registerBank.hpp"
#include "instruction.hpp"

namespace gbcoloremu
{


class GbaEmuCpu
{
public:

    GbaEmuCpu();
    ~GbaEmuCpu();

    bool loadCartridge(Cartridge& cartridge);
    Instruction *decode(memValue8_t opcode);

    bool run();

private:

    uint8_t delayCycles;

    registerBank registers;
    MemoryController memoryController;

    Instruction *instructions[256] =
    {
        NULL,   // 0x00
        NULL,   // 0x01
        NULL,   // 0x02
        NULL,   // 0x03
        NULL,   // 0x04
        NULL,   // 0x05
        NULL,   // 0x06
        NULL,   // 0x07
        NULL,   // 0x08
        NULL,   // 0x09
        NULL,   // 0x0A
        NULL,   // 0x0B
        NULL,   // 0x0C
        NULL,   // 0x0D
        NULL,   // 0x0E
        NULL,   // 0x0F
        NULL,   // 0x10
        NULL,   // 0x11
        NULL,   // 0x12
        NULL,   // 0x13
        NULL,   // 0x14
        NULL,   // 0x15
        NULL,   // 0x16
        NULL,   // 0x16
        NULL,   // 0x17
        NULL,   // 0x18
        NULL,   // 0x19
        NULL,   // 0x1A
        NULL,   // 0x1B
        NULL,   // 0x1C
        NULL,   // 0x1D
        NULL,   // 0x1E
        NULL,   // 0x1F
        NULL,   // 0x20
        NULL,   // 0x21
        NULL,   // 0x22
        NULL,   // 0x23
        NULL,   // 0x24
        NULL,   // 0x25
        NULL,   // 0x26
        NULL,   // 0x27
        NULL,   // 0x28
        NULL,   // 0x29
        NULL,   // 0x30
        NULL,   // 0x31
        NULL,   // 0x32
        NULL,   // 0x33
        NULL,   // 0x34
        NULL,   // 0x35
        NULL,   // 0x36
        NULL,   // 0x37
        NULL,   // 0x38
        NULL,   // 0x39
        NULL,   // 0x3A
        NULL,   // 0x3B
        NULL,   // 0x3C
        NULL,   // 0x3D
        NULL,   // 0x3E
        NULL,   // 0x3F
        NULL,   // 0x40
        NULL,   // 0x41
        NULL,   // 0x42
        NULL,   // 0x43
        NULL,   // 0x44
        NULL,   // 0x45
        NULL,   // 0x46
        NULL,   // 0x47
        NULL,   // 0x48
        NULL,   // 0x49
        NULL,   // 0x4A
        NULL,   // 0x4B
        NULL,   // 0x4C
        NULL,   // 0x4D
        NULL,   // 0x4E
        NULL,   // 0x4F
        NULL,   // 0x50
        NULL,   // 0x51
        NULL,   // 0x52
        NULL,   // 0x53
        NULL,   // 0x54
        NULL,   // 0x55
        NULL,   // 0x56
        NULL,   // 0x57
        NULL,   // 0x58
        NULL,   // 0x59
        NULL,   // 0x5A
        NULL,   // 0x5B
        NULL,   // 0x5C
        NULL,   // 0x5D
        NULL,   // 0x5E
        NULL,   // 0x5F
        NULL,   // 0x60
        NULL,   // 0x61
        NULL,   // 0x62
        NULL,   // 0x63
        NULL,   // 0x64
        NULL,   // 0x65
        NULL,   // 0x66
        NULL,   // 0x67
        NULL,   // 0x68
        NULL,   // 0x69
        NULL,   // 0x6A
        NULL,   // 0x6B
        NULL,   // 0x6C
        NULL,   // 0x6D
        NULL,   // 0x6E
        NULL,   // 0x6F
        NULL,   // 0x70
        NULL,   // 0x71
        NULL,   // 0x72
        NULL,   // 0x73
        NULL,   // 0x74
        NULL,   // 0x75
        NULL,   // 0x76
        NULL,   // 0x77
        new Instr_LDAA(),   // 0x78
        NULL,   // 0x79
        NULL,   // 0x7A
        NULL,   // 0x7B
        NULL,   // 0x7C
        NULL,   // 0x7D
        NULL,   // 0x7E
        NULL,   // 0x7F
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL,   // 0x00
        NULL    // 0x00
    };

};

} /* namespace gbcoloremu */


#endif /* __CPU_HPP */
