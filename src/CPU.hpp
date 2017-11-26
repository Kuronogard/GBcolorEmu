#ifndef __CPU_HPP
#define __CPU_HPP

#include <iostream>
#include <chrono>

#include "memoryController.hpp"
#include "registerBank.hpp"
#include "instruction.hpp"
#include "ldInstructions.hpp"
#include "arithInstructions.hpp"

#define DEFAULT_FREQ_MHZ (4.194304)

#define DEFAULT_PERIOD_NS (1000 * 1./DEFAULT_FREQ_MHZ)

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

    void initInstructions();
    void printInstructions();
    friend std::ostream &operator<<(std::ostream &os, const GbaEmuCpu& obj);

private:

    uint8_t delayCycles;
    long int cyclePeriod_ns = DEFAULT_PERIOD_NS;

    RegisterBank registers;
    MemoryController memoryController;

    Instruction *instructions[256];


};

} /* namespace gbcoloremu */


#endif /* __CPU_HPP */
