#ifndef __ARITHINSTRUCTION_H
#define __ARITHINSTRUCTION_H

#include "memoryController.hpp"
#include "instruction.hpp"
#include "registerBank.hpp"


namespace gbcoloremu
{

class Instr_ADD_A_r: public Instruction {
public:
    Instr_ADD_A_r(): Instruction("ADD A,r", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_ADD_A_n: public Instruction {
public:
    Instr_ADD_A_n(): Instruction("ADD A,n", 2, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_ADD_A_HL: public Instruction {
public:
    Instr_ADD_A_HL(): Instruction("ADD A,(HL)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_ADC_A_r: public Instruction
{
public:
    Instr_ADC_A_r(): Instruction("ADC A,r", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_ADC_A_n: public Instruction
{
public:
    Instr_ADC_A_n(): Instruction("ADC A,n", 2, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_ADC_A_HL: public Instruction
{
public:
    Instr_ADC_A_HL(): Instruction("ADC A,(HL)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_SUB_A_r: public Instruction
{
public:
    Instr_SUB_A_r(): Instruction("SUB A,r", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_SUB_A_n: public Instruction
{
public:
    Instr_SUB_A_n(): Instruction("SUB A,n", 2, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_SUB_A_HL: public Instruction
{
public:
    Instr_SUB_A_HL(): Instruction("SUB A,(HL)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_SBC_A_r: public Instruction
{
public:
    Instr_SBC_A_r(): Instruction("SBC A,r", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_SBC_A_n: public Instruction
{
public:
    Instr_SBC_A_n(): Instruction("SBC A,n", 2, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_SBC_A_HL: public Instruction
{
public:
    Instr_SBC_A_HL(): Instruction("SBC A,(HL)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_AND_A_r: public Instruction
{
public:
    Instr_AND_A_r(): Instruction("AND A,r", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_AND_A_n: public Instruction
{
public:
    Instr_AND_A_n(): Instruction("AND A,n", 2, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_AND_A_HL: public Instruction
{
public:
    Instr_AND_A_HL(): Instruction("AND A,(HL)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_XOR_A_r: public Instruction
{
public:
    Instr_XOR_A_r(): Instruction("XOR A,r", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_XOR_A_n: public Instruction
{
public:
    Instr_XOR_A_n(): Instruction("XOR A,n", 2, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_XOR_A_HL: public Instruction
{
public:
    Instr_XOR_A_HL(): Instruction("XOR A,(HL)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_OR_A_r: public Instruction
{
public:
    Instr_OR_A_r(): Instruction("OR A,r", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_OR_A_n: public Instruction
{
public:
    Instr_OR_A_n(): Instruction("OR A,n", 2, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_OR_A_HL: public Instruction
{
public:
    Instr_OR_A_HL(): Instruction("OR A,(HL)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};

class Instr_CP_A_r: public Instruction
{
public:
    Instr_CP_A_r(): Instruction("CP A,r", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_CP_A_n: public Instruction
{
public:
    Instr_CP_A_n(): Instruction("CP A,n", 2, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_CP_A_HL: public Instruction
{
public:
    Instr_CP_A_HL(): Instruction("CP A,(HL)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_INC_r: public Instruction
{
public:
    Instr_INC_r(): Instruction("INC r", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_INC_HL: public Instruction
{
public:
    Instr_INC_HL(): Instruction("INC (HL)", 1, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_DEC_r: public Instruction
{
public:
    Instr_DEC_r(): Instruction("DEC r", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_DEC_HL: public Instruction
{
public:
    Instr_DEC_HL(): Instruction("DEC (HL)", 1, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_DAA: public Instruction
{
public:
    Instr_DAA(): Instruction("DAA", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_SCF: public Instruction
{
public:
    Instr_SCF(): Instruction("SCF", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_CPL: public Instruction
{
public:
    Instr_CPL(): Instruction("CPL", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_CCF: public Instruction
{
public:
    Instr_CCF(): Instruction("CCF", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_ADD_HL_rr: public Instruction
{
public:
    Instr_ADD_HL_rr(): Instruction("ADD HL,rr", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_INC_rr: public Instruction
{
public:
    Instr_INC_rr(): Instruction("INC rr", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_DEC_rr: public Instruction
{
public:
    Instr_DEC_rr(): Instruction("DEC rr", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_ADD_SP_n: public Instruction
{
public:
    Instr_ADD_SP_n(): Instruction("ADD SP,n", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t pc, memValue8_t opcode);
};

} /* namespace gbcoloremu */

#endif /* __ARITHINSTRUCTION_H */
