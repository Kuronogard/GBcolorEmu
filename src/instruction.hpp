#ifndef __INSTRUCTION_H
#define __INSTRUCTION_H

#include "memoryController.hpp"
#include "CPU.hpp"
#include "registerBank.hpp"
#include <string>


namespace gbcoloremu
{


class Instruction
{
private:
    string _mnemonic;
    memValue8_t _opcode;
    uint8_t _numParamBytes;
    uint8_t _numDelayCycles;


public:

    Instruction(string mnemonic, memValue8_t opcode, uint8_t numParamBytes, uint8_t numDelayCycles):
        _mnemonic(mnemonic), _opcode(opcode), _numParamBytes(numParamBytes), _numDelayCycles(numDelayCycles)
    {}

    virtual bool execute(RegisterBank &registers, MemoryController &memory, memValue16_t param) = 0;

    string mnemonic()
    {
        return _mnemonic;
    }

    uint8_t numParamBytes()
    {
        return _numParamBytes;
    }

    uint8_t numDelayCycles()
    {
        return _numDelayCycles;
    }

    memValue8_t opcode()
    {
        return _opcode;
    }
};

class Instr_LDBn: public Instruction
{
public:

    Instr_LDBn(): Instruction("LD B,n", 0x06, 1, 8){}

    virtual bool execute(RegisterBank &registers, MemoryController &memory, memValue16_t param)
    {
        regValue_t value = param;
        registers.B = memory.read(value);
        return true;
    }
};

class Instr_LDCn: public Instruction
{
public:

    Instr_LDCn(): Instruction("LD C,n", 0x0E, 1, 8){}

    virtual bool execute(RegisterBank &registers, MemoryController &memory, memValue16_t param)
    {
        regValue_t value = param;
        registers.C = memory.read(value);
        return true;
    }
};

class Instr_LDDn: public Instruction
{
public:

    Instr_LDDn(): Instruction("LD D,n", 0x16, 1, 8){}

    virtual bool execute(RegisterBank &registers, MemoryController &memory, memValue16_t param)
    {
        regValue_t value = param;
        registers.D = memory.read(value);
        return true;
    }
};


class Instr_LDAA: public Instruction
{
public:

    Instr_LDAA(): Instruction("LD A,A", 0x78, 0, 4){}

    virtual bool execute(RegisterBank &registers, MemoryController &, memValue16_t)
    {
        registers.A = registers.A;
        return true;
    }
};


// TODO: Implement all the instructions


} /* namespace gbcoloremu */

#endif /* __INSTRUCTION_H */
