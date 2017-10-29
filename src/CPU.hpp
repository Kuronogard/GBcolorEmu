
#ifndef __CPU_HPP
#define __CPU_HPP

#include "memoryController.hpp"
#include "instruction.hpp"

namespace gbcoloremu
{

using regValue_t = uint8_t;
using doubleRegValue_t = uint16_t;



class registerBank
{
public:
    // Posible 16bit pairings  (15..8 | 7..0)
    //                              A - F
    //                              B - C
    //                              D - E
    //                              H - L

    // regF stores results of various math operations
    // PC points to the next instruction to be executed (initial value: 0x0100)
    // SP points to the current stack position (initial value: 0xFFFE)

    // SP grows downward in RAM memory.
    // It decrements automatically before something is put in it
    regValue_t A, B, C, D, E, F;
    regValue_t H, L;
    doubleRegValue_t SP, PC;
};



class GbaEmuCpu
{
private:

    uint8_t delayCycles;

    vector<Instruction> instructions;
    registerBank registers;
    MemoryController memoryController;

public:

    GbaEmuCpu();
    ~GbaEmuCpu();

    bool loadCartridge(Cartridge& cartridge);
    Instruction decode(memValue8_t opcode);

    bool run();

};

} /* namespace gbcoloremu */


#endif /* __CPU_HPP */
