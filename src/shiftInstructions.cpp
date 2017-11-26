#include "shiftInstructions.hpp"

namespace gbcoloremu
{

bool Instr_RLCA::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    regValue_t temp = (registers.A >> 7) & 0x1;

    registers.resetFlagH();
    registers.resetFlagN();
    registers.resetFlagZ();

    if (temp) registers.setFlagC();
    else registers.resetFlagC();

    registers.A = ((registers.A << 1) & ~0x1) | temp;
    return true;
}


bool Instr_RLA::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    regValue_t temp = registers.getFlagC();

    registers.resetFlagH();
    registers.resetFlagN();
    registers.resetFlagZ();

    if (registers.A & 0x8) registers.setFlagC();
    else registers.resetFlagC();

    registers.A = ((registers.A << 1) & ~0x1) | temp;
    return true;
}


bool Instr_RRCA::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    regValue_t temp = registers.A & 0x1;

    registers.resetFlagH();
    registers.resetFlagN();
    registers.resetFlagZ();

    if (temp) registers.setFlagC();
    else registers.resetFlagC();

    registers.A = ((registers.A >> 1) & ~0x8) | (temp << 7);
    return true;
}


bool Instr_RRA::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    regValue_t temp = registers.getFlagC();

    registers.resetFlagH();
    registers.resetFlagN();
    registers.resetFlagZ();

    if (registers.A & 0x1) registers.setFlagC();
    else registers.resetFlagC();

    registers.A = ((registers.A >> 1) & ~0x8) | (temp << 7);
    return true;
}

} /* namespace gbcoloremu */
