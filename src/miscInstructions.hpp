#ifndef __MISCINSTRUCTION_H
#define __MISCINSTRUCTION_H

#include "memoryController.hpp"
#include "instruction.hpp"
#include "registerBank.hpp"


namespace gbcoloremu
{

class Instr_NOP: public Instruction {
public:
    Instr_NOP(): Instruction("NOP", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_STOP: public Instruction {
public:
    Instr_STOP(): Instruction("STOP 0", 2, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_HALT: public Instruction {
public:
    Instr_HALT(): Instruction("HALT", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_PREFIX_CB: public Instruction {
public:
    Instr_PREFIX_CB(): Instruction("PREFIX CB", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_DI: public Instruction {
public:
    Instr_DI(): Instruction("DI", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_EI: public Instruction {
public:
    Instr_EI(): Instruction("EI", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


} /* namespace gbcoloremu */

#endif /* __MISCINSTRUCTION_H */
