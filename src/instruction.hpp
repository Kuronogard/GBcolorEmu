#ifndef __INSTRUCTION_H
#define __INSTRUCTION_H

#include "memoryController.hpp"


namespace gbcoloremu
{

class Instruction
{
public:
    Instruction();
    ~Instruction();


    virtual bool execute() = 0;

    virtual memValue8_t opcode() = 0;

    virtual string mnemonic() = 0;

    virtual uint8_t numParams() = 0;
};


} /* namespace gbcoloremu */

#endif /* __INSTRUCTION_H */
