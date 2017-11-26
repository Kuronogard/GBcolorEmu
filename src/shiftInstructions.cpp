#include "shiftInstructions.hpp"

namespace gbcoloremu
{

bool Instr_RLCA::execute(RegisterBank &, MemoryController &, doubleRegValue_t , memValue8_t )
{
    // No operation
    return true;
}


bool Instr_RLA::execute(RegisterBank &, MemoryController &, doubleRegValue_t , memValue8_t )
{
    // No operation
    return true;
}


bool Instr_RRCA::execute(RegisterBank &, MemoryController &, doubleRegValue_t , memValue8_t )
{
    // No operation
    return true;
}


bool Instr_RRA::execute(RegisterBank &, MemoryController &, doubleRegValue_t , memValue8_t )
{
    // No operation
    return true;
}

} /* namespace gbcoloremu */
