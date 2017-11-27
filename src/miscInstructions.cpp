#include "miscInstructions.hpp"

namespace gbcoloremu
{

bool Instr_NOP::execute(RegisterBank &, MemoryController &, doubleRegValue_t , memValue8_t )
{
    // No operation
    return true;
}

bool Instr_STOP::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    registers.cpuStopped = 1;
    return true;
}

bool Instr_HALT::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    registers.cpuHalted = 1;
    return true;
}


bool Instr_PREFIX_CB::execute(RegisterBank &, MemoryController &, doubleRegValue_t , memValue8_t )
{
    // prefix CB instructions
    return true;
}

bool Instr_DI::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    registers.intEnabled = 0;
    return true;
}


bool Instr_EI::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    registers.intEnabled = 1;
    return true;
}

} /* namespace gbcoloremu */
