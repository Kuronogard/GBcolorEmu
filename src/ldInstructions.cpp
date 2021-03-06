#include "ldInstructions.hpp"


namespace gbcoloremu
{

bool Instr_LD_r_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode )
{
    regValue_t reg = (opcode >> 3) & 0x7;   // 000r rr110
    regValue_t value = memory.read(pc+1);
    registers.setValue(reg, value);
    return true;
}


bool Instr_LD_r_r::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t regSrc = opcode & 0x7;   // 01dd dsss
    regValue_t regDst = (opcode >> 3) & 0x7;
    regValue_t value = registers.getValue(regSrc);
    registers.setValue(regDst, value);
    return true;
}


bool Instr_LD_r_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t regDst = (opcode >> 3) & 0x7;
    memValue8_t value = memory.read(registers.getHL());
    registers.setValue(regDst, value);
    return true;
}


bool Instr_LD_HL_r::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t opcode )
{
    regValue_t regSrc = opcode & 0x7;
    memory.write(registers.getHL(), registers.getValue(regSrc));
    return true;
}


bool Instr_LD_HL_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    memory.write(registers.getHL(), memory.read(pc+1));
    return true;
}


bool Instr_LD_A_BC::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.A = memory.read(registers.getBC());
    return true;
}


bool Instr_LD_A_DE::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.A = memory.read(registers.getDE());
    return true;
}


bool Instr_LD_A_nn::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    registers.A = memory.read(memory.readDouble(pc+1));
    return true;
}


bool Instr_LD_BC_A::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    memory.write(registers.getBC(), registers.A);
    return true;
}


bool Instr_LD_DE_A::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    memory.write(registers.getDE(), registers.A);
    return true;
}


bool Instr_LD_nn_A::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    memory.write(memory.readDouble(pc+1), registers.A);
    return true;
}


bool Instr_LD_A_io::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    registers.A = memory.read(0xFF00 + memory.read(pc+1));
    return true;
}


bool Instr_LD_io_A::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    memory.write(0xFF00 + memory.read(pc+1), registers.A);
    return true;
}


bool Instr_LD_A_C::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.A = memory.read(0xFF00 + registers.C);
    return true;
}


bool Instr_LD_C_A::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    memory.write(0xFF00 + registers.C, registers.A);
    return true;
}


bool Instr_LDI_HL_A::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    memory.write(registers.getHL(), registers.A);
    registers.setHL(registers.getHL()+1);
    return true;
}


bool Instr_LDD_HL_A::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    memory.write(registers.getHL(), registers.A);
    registers.setHL(registers.getHL()-1);
    return true;
}


bool Instr_LDI_A_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.A = memory.read(registers.getHL());
    registers.setHL(registers.getHL()+1);
    return true;
}


bool Instr_LDD_A_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.A = memory.read(registers.getHL());
    registers.setHL(registers.getHL()-1);
    return true;
}


bool Instr_LD_rr_nn::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode)
{
    regValue_t reg = (opcode >> 4) & 0x3;
    registers.setDoubleValue(reg, memory.readDouble(pc+1));
    return true;
}


bool Instr_LD_nn_SP::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    memAddr_t addr = memory.readDouble(pc+1);
    memory.writeDouble(addr, registers.SP);
    return true;
}


bool Instr_LD_SP_HL::execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t )
{
    registers.SP = registers.getHL();
    return true;
}


bool Instr_LD_HL_SP::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    registers.setHL(registers.SP + memory.read(pc+1));
    return true;
}


bool Instr_PUSH::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t opcode)
{
    regValue_t reg = (opcode >> 4) & 0x3;
    registers.SP = registers.SP-2;
    switch(reg) {
    case 0: memory.writeDouble(registers.SP, registers.getBC()); break;
    case 1: memory.writeDouble(registers.SP, registers.getDE()); break;
    case 2: memory.writeDouble(registers.SP, registers.getHL()); break;
    case 3: memory.writeDouble(registers.SP, registers.getAF()); break;
    }

    return true;
}


bool Instr_POP::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t opcode)
{
    regValue_t reg = (opcode >> 4) & 0x3;
    switch(reg) {
    case 0: registers.setBC(memory.readDouble(registers.SP)); break;
    case 1: registers.setDE(memory.readDouble(registers.SP)); break;
    case 2: registers.setHL(memory.readDouble(registers.SP)); break;
    case 3: registers.setAF(memory.readDouble(registers.SP)); break;
    }
    registers.SP = registers.SP+2;

    return true;
}

} /* namespace gbcoloremu */
