#include "flowInstructions.hpp"

namespace gbcoloremu
{



bool Instr_JR_NZ_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    if (!registers.getFlagZ()) {
        registers.PC = pc + (int8_t)memory.read(pc+1);
        setNumDelayCycles(12);
    }
    else {
        setNumDelayCycles(8);
    }
    return true;
}


bool Instr_JR_NC_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    if (!registers.getFlagC()) {
        registers.PC = pc + (int8_t)memory.read(pc+1);
        setNumDelayCycles(12);
    }
    else {
        setNumDelayCycles(8);
    }
    return true;
}


bool Instr_JR_Z_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    if (registers.getFlagZ()) {
        registers.PC = pc + (int8_t)memory.read(pc+1);
        setNumDelayCycles(12);
    }
    else {
        setNumDelayCycles(8);
    }
    return true;
}


bool Instr_JR_C_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    if (registers.getFlagC()) {
        registers.PC = pc + (int8_t)memory.read(pc+1);
        setNumDelayCycles(12);
    }
    else {
        setNumDelayCycles(8);
    }
    return true;
}


bool Instr_JR_n::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    registers.PC = pc + (int8_t)memory.read(pc+1);
    return true;
}


bool Instr_RET_NZ::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    if (!registers.getFlagZ()) {
        registers.PC = memory.readDouble(registers.SP);
        registers.SP = registers.SP + 2;
        setNumDelayCycles(20);
    }
    else {
        setNumDelayCycles(8);
    }
    return true;
}


bool Instr_RET_NC::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    if (!registers.getFlagC()) {
        registers.PC = memory.readDouble(registers.SP);
        registers.SP = registers.SP + 2;
        setNumDelayCycles(20);
    }
    else {
        setNumDelayCycles(8);
    }
    return true;
}


bool Instr_RET_Z::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    if (registers.getFlagZ()) {
        registers.PC = memory.readDouble(registers.SP);
        registers.SP = registers.SP + 2;
        setNumDelayCycles(20);
    }
    else {
        setNumDelayCycles(8);
    }
    return true;
}


bool Instr_RET_C::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t)
{
    if (registers.getFlagC()) {
        registers.PC = memory.readDouble(registers.SP);
        registers.SP = registers.SP + 2;
        setNumDelayCycles(20);
    }
    else {
        setNumDelayCycles(8);
    }
    return true;
}


bool Instr_RET::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.PC = memory.readDouble(registers.SP);
    registers.SP = registers.SP + 2;
    return true;
}


bool Instr_RETI::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.PC = memory.readDouble(registers.SP);
    registers.SP = registers.SP + 2;
    // TODO: signal interrupt completion via I/O
    return true;
}


bool Instr_JP_NZ_nn::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    if (!registers.getFlagZ()) {
        registers.PC = memory.readDouble(pc+1);
        setNumDelayCycles(16);
    }
    else {
        setNumDelayCycles(12);
    }
    return true;
}


bool Instr_JP_NC_nn::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    if (!registers.getFlagC()) {
        registers.PC = memory.readDouble(pc+1);
        setNumDelayCycles(16);
    }
    else {
        setNumDelayCycles(12);
    }
    return true;
}


bool Instr_JP_Z_nn::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    if (registers.getFlagZ()) {
        registers.PC = memory.readDouble(pc+1);
        setNumDelayCycles(16);
    }
    else {
        setNumDelayCycles(12);
    }
    return true;
}


bool Instr_JP_C_nn::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    if (registers.getFlagC()) {
        registers.PC = memory.readDouble(pc+1);
        setNumDelayCycles(16);
    }
    else {
        setNumDelayCycles(12);
    }
    return true;
}


bool Instr_JP_nn::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    registers.PC = memory.readDouble(pc+1);
    return true;
}


bool Instr_JP_HL::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.PC = memory.readDouble(registers.getHL());
    return true;
}


bool Instr_CALL_NZ_nn::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    if (!registers.getFlagZ()) {
        registers.SP = registers.SP - 2;
        memory.writeDouble(registers.SP, registers.PC);
        registers.PC = memory.readDouble(pc+1);
        setNumDelayCycles(24);
    }
    else {
        setNumDelayCycles(12);
    }
    return true;
}


bool Instr_CALL_NC_nn::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    if (!registers.getFlagC()) {
        registers.SP = registers.SP - 2;
        memory.writeDouble(registers.SP, registers.PC);
        registers.PC = memory.readDouble(pc+1);
        setNumDelayCycles(24);
    }
    else {
        setNumDelayCycles(12);
    }
    return true;
}


bool Instr_CALL_Z_nn::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    if (registers.getFlagZ()) {
        registers.SP = registers.SP - 2;
        memory.writeDouble(registers.SP, registers.PC);
        registers.PC = memory.readDouble(pc+1);
        setNumDelayCycles(24);
    }
    else {
        setNumDelayCycles(12);
    }
    return true;
}


bool Instr_CALL_C_nn::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    if (registers.getFlagC()) {
        registers.SP = registers.SP - 2;
        memory.writeDouble(registers.SP, registers.PC);
        registers.PC = memory.readDouble(pc+1);
        setNumDelayCycles(24);
    }
    else {
        setNumDelayCycles(12);
    }
    return true;
}


bool Instr_CALL_nn::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
{
    registers.SP = registers.SP - 2;
    memory.writeDouble(registers.SP, registers.PC);
    registers.PC = memory.readDouble(pc+1);
    return true;
}


bool Instr_RST_00::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.SP = registers.SP - 2;
    memory.writeDouble(registers.SP, registers.PC);
    registers.PC = 0x0000;
    return true;
}


bool Instr_RST_08::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.SP = registers.SP - 2;
    memory.writeDouble(registers.SP, registers.PC);
    registers.PC = 0x0008;
    return true;
}


bool Instr_RST_10::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.SP = registers.SP - 2;
    memory.writeDouble(registers.SP, registers.PC);
    registers.PC = 0x0010;
    return true;
}


bool Instr_RST_18::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.SP = registers.SP - 2;
    memory.writeDouble(registers.SP, registers.PC);
    registers.PC = 0x0018;
    return true;
}


bool Instr_RST_20::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.SP = registers.SP - 2;
    memory.writeDouble(registers.SP, registers.PC);
    registers.PC = 0x0020;
    return true;
}


bool Instr_RST_28::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.SP = registers.SP - 2;
    memory.writeDouble(registers.SP, registers.PC);
    registers.PC = 0x0028;
    return true;
}


bool Instr_RST_30::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.SP = registers.SP - 2;
    memory.writeDouble(registers.SP, registers.PC);
    registers.PC = 0x0030;
    return true;
}


bool Instr_RST_38::execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
{
    registers.SP = registers.SP - 2;
    memory.writeDouble(registers.SP, registers.PC);
    registers.PC = 0x0038;
    return true;
}




} /* namespace gbcoloremu */
