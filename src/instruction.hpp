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

    Instruction(string mnemonic, uint8_t numParamBytes, uint8_t numDelayCycles):
        _mnemonic(mnemonic), _numParamBytes(numParamBytes), _numDelayCycles(numDelayCycles)
    {}

    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t PC, memValue8_t opcode) = 0;

    string mnemonic(uint8_t opcode)
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

};


/*=========================================================================================
 *                          INSTRUCTIONS
 *=========================================================================================
 */



class Instr_CB: public Instruction
{
public:

    Instr_CB(): Instruction("PREFIX CB", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode )
    {
        // read the next byte
        // execute the corresponding 'PREFIX CB' instruction
        return true;
    }
};


class Instr_RLC: public Instruction
{
public:

    Instr_RLC(): Instruction("RLC", 1, 8){}


    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode )
    {
        regValue_t reg = opcode & 0x7;
        regValue_t value = registers.getValue(reg);
        registers.setValue(reg, value);
        return true;
    }
};

// TODO: Implement all the instructions


} /* namespace gbcoloremu */

#endif /* __INSTRUCTION_H */
