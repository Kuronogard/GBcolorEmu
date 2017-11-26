#include "miscInstructions.hpp"

namespace gbcoloremu
{

bool Instr_NOP::execute(RegisterBank &, MemoryController &, doubleRegValue_t , memValue8_t )
{
    // No operation
    return true;
}

bool Instr_STOP::execute(RegisterBank &, MemoryController &, doubleRegValue_t , memValue8_t )
{
    // Halt CPU
    return true;
}

bool Instr_HALT::execute(RegisterBank &, MemoryController &, doubleRegValue_t , memValue8_t )
{
    // Halt CPU until an interrupt occurs
    return true;
}


bool Instr_PREFIX_CB::execute(RegisterBank &, MemoryController &, doubleRegValue_t , memValue8_t )
{
    // prefix CB instructions
    return true;
}

bool Instr_DI::execute(RegisterBank &, MemoryController &, doubleRegValue_t , memValue8_t )
{
    // Disable interrupts
    return true;
}


bool Instr_EI::execute(RegisterBank &, MemoryController &, doubleRegValue_t , memValue8_t )
{
    // Enable interrupts
    return true;
}

} /* namespace gbcoloremu */
