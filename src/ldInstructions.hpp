#ifndef __LDINSTRUCTION_H
#define __LDINSTRUCTION_H

#include "memoryController.hpp"
#include "CPU.hpp"
#include "registerBank.hpp"
#include <string>


namespace gbcoloremu
{

/*=========================================================================================
 *                          INSTRUCTIONS
 *=========================================================================================
 */


/******************************************************************************************
 * LD r, n    r = (register)  n = (memory)
 *****************************************************************************************/
class Instr_LD_r_n: public Instruction
{
public:

    Instr_LD_r_n(): Instruction("LD r,n", 2, 8){}

    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode )
    {
        regValue_t reg = (opcode >> 3) & 0x7;   // 000r rr110
        regValue_t value = memory.read(pc+1);
        registers.setValue(reg, value);
        return true;
    }
};


class Instr_LD_r_r: public Instruction
{
public:

    Instr_LD_r_r(): Instruction("LD r,r", 1, 4){}


    virtual bool execute(RegisterBank &registers, MemoryController &, doubleRegValue_t , memValue8_t opcode )
    {
        regValue_t regSrc = opcode & 0x7;   // 01dd dsss
        regValue_t regDst = (opcode >> 3) & 0x7;
        regValue_t value = registers.getValue(regSrc);
        registers.setValue(regDst, value);
        return true;
    }
};


class Instr_LD_r_HL: public Instruction
{
public:

    Instr_LD_r_HL(): Instruction("LD r,(HL)", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t opcode )
    {
        regValue_t regDst = (opcode >> 3) & 0x7;
        memValue8_t value = memory.read(registers.getHL());
        registers.setValue(regDst, value);
        return true;
    }
};


class Instr_LD_HL_r: public Instruction
{
public:

    Instr_LD_HL_r(): Instruction("LD (HL),r", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t opcode )
    {
        regValue_t regSrc = opcode & 0x7;
        memory.write(registers.getHL(), registers.getValue(regSrc));
        return true;
    }
};


class Instr_LD_HL_n: public Instruction
{
public:

    Instr_LD_HL_n(): Instruction("LD (HL),n", 2, 12){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        memory.write(registers.getHL(), memory.read(pc+1));
        return true;
    }
};


class Instr_LD_A_BC: public Instruction
{
public:

    Instr_LD_A_BC(): Instruction("LD A,(BC)", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
    {
        registers.A = memory.read(registers.getBC());
        return true;
    }
};


class Instr_LD_A_DE: public Instruction
{
public:

    Instr_LD_A_DE(): Instruction("LD A,(DE)", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
    {
        registers.A = memory.read(registers.getDE());
        return true;
    }
};

class Instr_LD_A_nn: public Instruction
{
public:

    Instr_LD_A_nn(): Instruction("LD A,(nn)", 3, 16){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        registers.A = memory.read(memory.readDouble(pc+1));
        return true;
    }
};

class Instr_LD_BC_A: public Instruction
{
public:

    Instr_LD_BC_A(): Instruction("LD (BC),A", 3, 12){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
    {
        memory.write(registers.getBC(), registers.A);
        return true;
    }
};

class Instr_LD_DE_A: public Instruction
{
public:

    Instr_LD_DE_A(): Instruction("LD (DE),A", 3, 12){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
    {
        memory.write(registers.getDE(), registers.A);
        return true;
    }
};

class Instr_LD_nn_A: public Instruction
{
public:

    Instr_LD_nn_A(): Instruction("LD (nn),A", 1, 16){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t , memValue8_t )
    {
        memory.write(registers.getDE(), registers.A);
        return true;
    }
};


class Instr_LD_A_io: public Instruction
{
public:

    Instr_LD_A_io(): Instruction("LD A,(0xFF00+n)", 2, 12){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        registers.A = memory.read(0xFF00 + memory.read(pc+1));
        return true;
    }
};

class Instr_LD_io_A: public Instruction
{
public:

    Instr_LD_io_A(): Instruction("LD (0xFF00+n),A", 2, 12){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        registers.A = memory.read(0xFF00 + memory.read(pc+1));
        return true;
    }
};


class Instr_LD_A_C: public Instruction
{
public:

    Instr_LD_A_C(): Instruction("LD A, (0xFF00+C)", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        registers.A = memory.read(0xFF00 + registers.C);
        return true;
    }
};


class Instr_LD_C_A: public Instruction
{
public:

    Instr_LD_C_A(): Instruction("LD (0xFF00+C),A", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        memory.write(0xFF00 + registers.C, registers.A);
        return true;
    }
};

class Instr_LDI_HL_A: public Instruction
{
public:

    Instr_LDI_HL_A(): Instruction("LDI (HL+),A", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        memory.write(registers.getHL(), registers.A);
        registers.setHL(registers.getHL()+1);
        return true;
    }
};

class Instr_LDD_HL_A: public Instruction
{
public:

    Instr_LDD_HL_A(): Instruction("LD (HL-),A", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        memory.write(registers.getHL(), registers.A);
        registers.setHL(registers.getHL()-1);
        return true;
    }
};

class Instr_LDI_A_HL: public Instruction
{
public:

    Instr_LDI_A_HL(): Instruction("LDI (HL+),A", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        registers.A = memory.read(registers.getHL());
        registers.setHL(registers.getHL()+1);
        return true;
    }
};

class Instr_LDD_A_HL: public Instruction
{
public:

    Instr_LDD_A_HL(): Instruction("LD (HL-),A", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        registers.A = memory.read(registers.getHL());
        registers.setHL(registers.getHL()-1);
        return true;
    }
};




class Instr_LD_rr_nn: public Instruction
{
public:

    Instr_LD_rr_nn(): Instruction("LD rr,nn", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode)
    {
        regValue_t reg = (opcode >> 4) & 0x3;
        registers.setDoubleValue(reg, memory.readDouble(pc+1));
        return true;
    }
};


class Instr_LD_nn_SP: public Instruction
{
public:

    Instr_LD_nn_SP(): Instruction("LD (nn),SP", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        memAddr_t addr = memory.readDouble(pc+1);
        memory.writeDouble(addr, registers.SP);
        return true;
    }
};

class Instr_LD_SP_HL: public Instruction
{
public:

    Instr_LD_SP_HL(): Instruction("LD SP,HL", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        registers.SP = registers.getHL();
        return true;
    }
};


class Instr_LD_HL_SP: public Instruction
{
public:

    Instr_LD_HL_SP(): Instruction("LD HL,SP", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t )
    {
        registers.setHL(registers.SP + memory.read(pc+1));
        return true;
    }
};

class Instr_PUSH: public Instruction
{
public:

    Instr_PUSH(): Instruction("LD PUSH", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode)
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
};

class Instr_POP: public Instruction
{
public:

    Instr_POP(): Instruction("LD POP", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode)
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
};

} /* namespace gbcoloremu */

#endif /* __LDINSTRUCTION_H */
