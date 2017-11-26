#ifndef __LDINSTRUCTION_H
#define __LDINSTRUCTION_H

#include "memoryController.hpp"
#include "registerBank.hpp"
#include "instruction.hpp"


namespace gbcoloremu
{


class Instr_LD_r_n: public Instruction
{
public:
    Instr_LD_r_n(): Instruction("LD r,n", 2, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_r_r: public Instruction
{
public:
    Instr_LD_r_r(): Instruction("LD r,r", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_r_HL: public Instruction
{
public:
    Instr_LD_r_HL(): Instruction("LD r,(HL)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_HL_r: public Instruction
{
public:
    Instr_LD_HL_r(): Instruction("LD (HL),r", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_HL_n: public Instruction
{
public:
    Instr_LD_HL_n(): Instruction("LD (HL),n", 2, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_A_BC: public Instruction
{
public:
    Instr_LD_A_BC(): Instruction("LD A,(BC)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_A_DE: public Instruction
{
public:
    Instr_LD_A_DE(): Instruction("LD A,(DE)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_A_nn: public Instruction
{
public:
    Instr_LD_A_nn(): Instruction("LD A,(nn)", 3, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_BC_A: public Instruction
{
public:
    Instr_LD_BC_A(): Instruction("LD (BC),A", 1, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_DE_A: public Instruction
{
public:
    Instr_LD_DE_A(): Instruction("LD (DE),A", 1, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_nn_A: public Instruction
{
public:
    Instr_LD_nn_A(): Instruction("LD (nn),A", 3, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_A_io: public Instruction
{
public:
    Instr_LD_A_io(): Instruction("LD A,(0xFF00+n)", 2, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};

class Instr_LD_io_A: public Instruction
{
public:
    Instr_LD_io_A(): Instruction("LD (0xFF00+n),A", 2, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_A_C: public Instruction
{
public:
    Instr_LD_A_C(): Instruction("LD A, (0xFF00+C)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_C_A: public Instruction
{
public:
    Instr_LD_C_A(): Instruction("LD (0xFF00+C),A", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LDI_HL_A: public Instruction
{
public:
    Instr_LDI_HL_A(): Instruction("LDI (HL+),A", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LDD_HL_A: public Instruction
{
public:
    Instr_LDD_HL_A(): Instruction("LDD (HL-),A", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);

};


class Instr_LDI_A_HL: public Instruction
{
public:
    Instr_LDI_A_HL(): Instruction("LDI A,(HL+)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LDD_A_HL: public Instruction
{
public:
    Instr_LDD_A_HL(): Instruction("LDD A,(HL-)", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_rr_nn: public Instruction
{
public:
    Instr_LD_rr_nn(): Instruction("LD rr,nn", 3, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_nn_SP: public Instruction
{
public:
    Instr_LD_nn_SP(): Instruction("LD (nn),SP", 3, 20){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_SP_HL: public Instruction
{
public:
    Instr_LD_SP_HL(): Instruction("LD SP,HL", 1, 8){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_LD_HL_SP: public Instruction
{
public:
    Instr_LD_HL_SP(): Instruction("LD HL,SP", 2, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_PUSH: public Instruction
{
public:
    Instr_PUSH(): Instruction("PUSH rr", 1, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_POP: public Instruction
{
public:
    Instr_POP(): Instruction("POP rr", 1, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};

} /* namespace gbcoloremu */

#endif /* __LDINSTRUCTION_H */
