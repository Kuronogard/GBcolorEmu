#include "arithInstructions.hpp"

namespace gbcoloremu
{

// DAA instruction macros
#define U(reg)  ((reg >> 4) & 0xF)
#define L(reg)  ((reg & 0xF))
#define U90 ( (U(registers.A) == 0x0) || (U(registers.A) >= 0x9) )
#define U08 ( (U(registers.A) <= 0x8) )
#define U09 ( (U(registers.A) <= 0x9) )
#define UAF ( (U(registers.A) >= 0xA) && (U(registers.A) <= 0xF) )
#define U9F ( (U(registers.A) >= 0x9) && (U(registers.A) <= 0xF) )
#define U02 ( (U(registers.A) <= 0x2) )
#define U03 ( (U(registers.A) <= 0x3) )
#define U7F ( (U(registers.A) >= 0x7) && (U(registers.A) <= 0xF) )
#define U67 ( (U(registers.A) >= 0x6) && (U(registers.A) <= 0x7) )
#define L09 ( (L(registers.A) <= 0x9) )
#define LAF ( (L(registers.A) >= 0xA) && (L(registers.A) <= 0xF) )
#define L03 ( (L(registers.A) <= 0x3) )
#define L09 ( (L(registers.A) <= 0x9) )
#define L6F ( (L(registers.A) >= 0x6) && (L(registers.A) <= 0xF) )

#define FC  (registers.getFlagC())
#define FH  (registers.getFlagH())
#define FN  (registers.getFlagN())

void operationADD(RegisterBank &registers, regValue_t regValue)
{
    registers.resetFlagN();

    if (((registers.A & 0xF) + (regValue & 0xF)) & 0x10 ) registers.setFlagH();
    else registers.resetFlagH();

    if (((int)registers.A + (int)regValue) & ~0x0FF) registers.setFlagC();
    else registers.resetFlagC();

    if ((registers.A + regValue) == 0) registers.setFlagZ();
    else registers.resetFlagZ();

    registers.A = registers.A + regValue;
}

void operationADC(RegisterBank &registers, regValue_t regValue)
{
    regValue_t carry = registers.getFlagC();
    registers.resetFlagN();

    if (((registers.A & 0xF) + (regValue & 0xF) + carry) & 0x10 ) registers.setFlagH();
    else registers.resetFlagH();

    if (((int)registers.A + (int)regValue + (int)carry) & ~0x0FF) registers.setFlagC();
    else registers.resetFlagC();

    if ((registers.A + regValue + carry) == 0) registers.setFlagZ();
    else registers.resetFlagZ();

    registers.A = registers.A + regValue + carry;
}

void operationSUB(RegisterBank &registers, regValue_t regValue)
{
    registers.setFlagN();

    if (((registers.A & 0xF) - (regValue & 0xF)) & 0x10 ) registers.setFlagH();
    else registers.resetFlagH();

    if (((int)registers.A - (int)regValue) & ~0x0FF) registers.setFlagC();
    else registers.resetFlagC();

    if ((registers.A - regValue) == 0) registers.setFlagZ();
    else registers.resetFlagZ();

    registers.A = registers.A - regValue;
}

void operationSBC(RegisterBank &registers, regValue_t regValue)
{
    regValue_t carry = registers.getFlagC();
    registers.setFlagN();

    if (((registers.A & 0xF) - (regValue & 0xF) - carry) & 0x10 ) registers.setFlagH();
    else registers.resetFlagH();

    if (((int)registers.A - (int)regValue - (int)carry) & ~0x0FF) registers.setFlagC();
    else registers.resetFlagC();

    if ((registers.A - regValue - carry) == 0) registers.setFlagZ();
    else registers.resetFlagZ();

    registers.A = registers.A - regValue - carry;
}

void operationAND(RegisterBank &registers, regValue_t regValue)
{
    registers.resetFlagN();
    registers.setFlagH();
    registers.resetFlagC();

    if ((registers.A & regValue) == 0) registers.setFlagZ();
    else registers.resetFlagZ();

    registers.A = registers.A & regValue;
}

void operationXOR(RegisterBank &registers, regValue_t regValue)
{
    registers.resetFlagN();
    registers.resetFlagH();
    registers.resetFlagC();

    if ((registers.A ^ regValue) == 0) registers.setFlagZ();
    else registers.resetFlagZ();

    registers.A = registers.A ^ regValue;
}

void operationOR(RegisterBank &registers, regValue_t regValue)
{
    registers.resetFlagN();
    registers.resetFlagH();
    registers.resetFlagC();

    if ((registers.A | regValue) == 0) registers.setFlagZ();
    else registers.resetFlagZ();

    registers.A = registers.A | regValue;
}

void operationCP(RegisterBank &registers, regValue_t regValue)
{
    registers.resetFlagN();
    registers.resetFlagH();
    registers.resetFlagC();

    if (registers.A == regValue) registers.setFlagZ();
    else registers.resetFlagZ();
}


bool Instr_ADD_A_r::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t regValue = registers.getValue(opcode & 0x07);
    operationADD(registers, regValue);
    return true;
}


bool Instr_ADD_A_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    regValue_t regValue = memory.read(pc+1);
    operationADD(registers, regValue);
    return true;
}


bool Instr_ADD_A_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    regValue_t regValue = memory.read(registers.getHL());
    operationADD(registers, regValue);
    return true;
}


bool Instr_ADC_A_r::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t regValue = registers.getValue(opcode & 0x07);
    operationADC(registers, regValue);
    return true;
}


bool Instr_ADC_A_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    regValue_t regValue = memory.read(pc+1);
    operationADC(registers, regValue);
    return true;
}


bool Instr_ADC_A_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    regValue_t regValue = memory.read(registers.getHL());
    operationADC(registers, regValue);
    return true;
}


bool Instr_SUB_A_r::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t regValue = registers.getValue(opcode & 0x07);
    operationSUB(registers, regValue);
    return true;
}


bool Instr_SUB_A_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    regValue_t regValue = memory.read(pc+1);
    operationSUB(registers, regValue);
    return true;
}


bool Instr_SUB_A_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    regValue_t regValue = memory.read(registers.getHL());
    operationSUB(registers, regValue);
    return true;
}


bool Instr_SBC_A_r::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t regValue = registers.getValue(opcode & 0x07);
    operationSBC(registers, regValue);
    return true;
}


bool Instr_SBC_A_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    regValue_t regValue = memory.read(pc+1);
    operationSBC(registers, regValue);
    return true;
}


bool Instr_SBC_A_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    regValue_t regValue = memory.read(registers.getHL());
    operationSBC(registers, regValue);
    return true;
}


bool Instr_AND_A_r::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode)
{
    regValue_t regValue = registers.getValue(opcode & 0x07);
    operationAND(registers, regValue);
    return true;
}


bool Instr_AND_A_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    regValue_t regValue = memory.read(pc+1);
    operationAND(registers, regValue);
    return true;
}


bool Instr_AND_A_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    regValue_t regValue = memory.read(registers.getHL());
    operationAND(registers, regValue);
    return true;
}


bool Instr_XOR_A_r::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode)
{
    regValue_t regValue = registers.getValue(opcode & 0x07);
    operationXOR(registers, regValue);
    return true;
}


bool Instr_XOR_A_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    regValue_t regValue = memory.read(pc+1);
    operationXOR(registers, regValue);
    return true;
}


bool Instr_XOR_A_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    regValue_t regValue = memory.read(registers.getHL());
    operationXOR(registers, regValue);
    return true;
}


bool Instr_OR_A_r::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t regValue = registers.getValue(opcode & 0x07);
    operationOR(registers, regValue);
    return true;
}


bool Instr_OR_A_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    regValue_t regValue = memory.read(pc+1);
    operationOR(registers, regValue);
    return true;
}


bool Instr_OR_A_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    regValue_t regValue = memory.read(registers.getHL());
    operationOR(registers, regValue);
    return true;
}


bool Instr_CP_A_r::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t regValue = registers.getValue(opcode & 0x07);
    operationCP(registers, regValue);
    return true;
}


bool Instr_CP_A_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    regValue_t regValue = memory.read(pc+1);
    operationCP(registers, regValue);
    return true;
}


bool Instr_CP_A_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    regValue_t regValue = memory.read(registers.getHL());
    operationCP(registers, regValue);
    return true;
}


bool Instr_INC_r::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t reg = (opcode >> 3) & 0x07;
    regValue_t regValue = registers.getValue(reg);

    if ((regValue + 1) == 0) registers.setFlagZ();
    else registers.resetFlagZ();

    registers.resetFlagN();

    if (((regValue & 0x7) + 1) & 0x7) registers.setFlagH();
    else registers.resetFlagH();

    registers.setValue(reg, regValue+1);
    return true;
}


bool Instr_INC_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    memValue8_t regValue = memory.read(registers.getHL());

    if ((regValue + 1) == 0) registers.setFlagZ();
    else registers.resetFlagZ();

    registers.resetFlagN();

    if (((regValue & 0x7) + 1) & 0x7) registers.setFlagH();
    else registers.resetFlagH();

    memory.write(registers.getHL(), regValue+1);
    return true;
}


bool Instr_DEC_r::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t reg = (opcode >> 3) & 0x07;
    regValue_t regValue = registers.getValue(reg);

    if ((regValue - 1) == 0) registers.setFlagZ();
    else registers.resetFlagZ();

    registers.setFlagN();

    if (((regValue & 0x7) - 1) & 0x7) registers.setFlagH();
    else registers.resetFlagH();

    registers.setValue(reg, regValue-1);
    return true;
}


bool Instr_DEC_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    memValue8_t regValue = memory.read(registers.getHL());

    if ((regValue - 1) == 0) registers.setFlagZ();
    else registers.resetFlagZ();

    registers.resetFlagN();

    if (((regValue & 0x7) - 1) & 0x7) registers.setFlagH();
    else registers.resetFlagH();

    memory.write(registers.getHL(), regValue-1);
    return true;
}


bool Instr_DAA::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    regValue_t op;
    bool carry;

    registers.resetFlagH();

    if      ( !FN && !FC && U90 && !FH && L09 ) {
        op = 0x00; carry = false;
    }
    else if ( !FN && !FC && U08 && !FH && LAF ) {
        op = 0x06; carry = false;
    }
    else if ( !FN && !FC && U09 && FH && L03 ) {
        op = 0x06; carry = false;
    }
    else if ( !FN && !FC && UAF && !FH && L09 ) {
        op = 0x60; carry = true;
    }
    else if ( !FN && !FC && U9F && !FH && LAF ) {
        op = 0x66; carry = true;
    }
    else if ( !FN && !FC && UAF && FH && L03 ) {
        op = 0x66; carry = true;
    }
    else if ( !FN && FC && U02 && !FH && L09 ) {
        op = 0x60; carry = true;
    }
    else if ( !FN && FC && U02 && !FH && LAF ) {
        op = 0x66; carry = true;
    }
    else if ( FN && !FC && U09 && !FH && L09 ) {
        op = 0x00; carry = false;
    }
    else if ( FN && !FC && U08 && FH && L6F ) {
        op = 0xFA; carry = false;
    }
    else if ( FN && FC && U7F && !FH && L09 ) {
        op = 0xA0; carry = true;
    }
    else if ( FN && FC && U67 && FH && L6F ) {
        op = 0x9A; carry = true;
    }

    registers.A = registers.A + op;

    if (registers.A == 0) registers.setFlagZ();
    else registers.resetFlagZ();

    if (carry) registers.setFlagC();
    else registers.resetFlagC();

    return true;
}


bool Instr_SCF::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    registers.resetFlagN();
    registers.resetFlagH();
    registers.setFlagC();
    return true;
}


bool Instr_CPL::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    registers.setFlagN();
    registers.setFlagH();
    registers.A = ~registers.A;
    return true;
}


bool Instr_CCF::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    registers.resetFlagN();
    registers.resetFlagH();
    if (registers.getFlagC()) registers.resetFlagC();
    else registers.setFlagC();
    return true;
}


bool Instr_ADD_HL_rr::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode)
{
    regValue_t reg = (opcode >> 4) & 0x3;
    regValue_t regValue = registers.getDoubleValue(reg);

    registers.resetFlagN();

    if (((registers.getHL() & 0xF) + (regValue & 0xF)) & 0x10) registers.setFlagH();
    else registers.resetFlagH();

    if (((int)registers.getHL() + (int)regValue) & ~0x0FF) registers.setFlagC();
    else registers.resetFlagC();

    registers.setHL(registers.getHL() + regValue);
    return true;
}


bool Instr_INC_rr::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t reg = (opcode >> 4) & 0x3;
    doubleRegValue_t regValue = registers.getDoubleValue(reg);
    registers.setDoubleValue(reg, regValue+1);
    return true;
}


bool Instr_DEC_rr::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t reg = (opcode >> 4) & 0x3;
    doubleRegValue_t regValue = registers.getDoubleValue(reg);
    registers.setDoubleValue(reg, regValue-1);
    return true;
}

} /* namespace gbcoloremu */
