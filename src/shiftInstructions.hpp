#ifndef __SHIFTINSTRUCTION_H
#define __SHIFTINSTRUCTION_H

#include "memoryController.hpp"
#include "instruction.hpp"
#include "registerBank.hpp"


namespace gbcoloremu
{

class Instr_RLCA: public Instruction {
public:
    Instr_RLCA(): Instruction("RLCA", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RLA: public Instruction {
public:
    Instr_RLA(): Instruction("RLA", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RRCA: public Instruction {
public:
    Instr_RRCA(): Instruction("RRCA", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RRA: public Instruction {
public:
    Instr_RRA(): Instruction("RRA", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


} /* namespace gbcoloremu */

#endif /* __SHIFTINSTRUCTION_H */
