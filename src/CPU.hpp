
#ifndef __CPU_HPP
#define __CPU_HPP

#include "memoryController.hpp"
#include "registerBank.hpp"
#include "instruction.hpp"

namespace gbcoloremu
{


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
    Instruction *decode(memValue8_t opcode);

    bool run();

};

} /* namespace gbcoloremu */


#endif /* __CPU_HPP */
