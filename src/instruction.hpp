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

    virtual bool execute(registerBank &registers, MemoryController &memory, memValue16_t param) = 0;

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


class Instr_LDAA: public Instruction
{
public:

    Instr_LDAA(): Instruction("LD A,A", 0x78, 0, 4){}

    virtual bool execute(registerBank &registers, MemoryController &, memValue16_t)
    {
        registers.A = registers.A;
        return true;
    }

};


// TODO: Implement all the instructions


} /* namespace gbcoloremu */

#endif /* __INSTRUCTION_H */
