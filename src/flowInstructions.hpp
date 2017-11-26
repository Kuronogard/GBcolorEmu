#ifndef __FLOWINSTRUCTION_H
#define __FLOWINSTRUCTION_H

#include "memoryController.hpp"
#include "instruction.hpp"
#include "registerBank.hpp"


namespace gbcoloremu
{

class Instr_JR_NZ_n: public Instruction {
public:
    Instr_JR_NZ_n(): Instruction("JR NZ,n", 2, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_JR_NC_n: public Instruction {
public:
    Instr_JR_NC_n(): Instruction("JR NC,n", 2, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_JR_n: public Instruction {
public:
    Instr_JR_n(): Instruction("JR n", 2, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_JR_Z_n: public Instruction {
public:
    Instr_JR_Z_n(): Instruction("JR Z,n", 2, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_JR_C_n: public Instruction {
public:
    Instr_JR_C_n(): Instruction("JR C,n", 2, 12){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RET_NZ: public Instruction {
public:
    Instr_RET_NZ(): Instruction("RET NZ", 1, 20){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RET_NC: public Instruction {
public:
    Instr_RET_NC(): Instruction("RET NC", 1, 20){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RET_Z: public Instruction {
public:
    Instr_RET_Z(): Instruction("RET Z", 1, 20){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RET_C: public Instruction {
public:
    Instr_RET_C(): Instruction("RET C", 1, 20){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RET: public Instruction {
public:
    Instr_RET(): Instruction("RET", 1, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RETI: public Instruction {
public:
    Instr_RETI(): Instruction("RETI", 1, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_JP_NZ_nn: public Instruction {
public:
    Instr_JP_NZ_nn(): Instruction("JP NZ,nn", 3, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_JP_NC_nn: public Instruction {
public:
    Instr_JP_NC_nn(): Instruction("JP NC,nn", 3, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_JP_nn: public Instruction {
public:
    Instr_JP_nn(): Instruction("JP nn", 3, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_JP_Z_nn: public Instruction {
public:
    Instr_JP_Z_nn(): Instruction("JP Z,nn", 3, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_JP_C_nn: public Instruction {
public:
    Instr_JP_C_nn(): Instruction("JP C,nn", 3, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_JP_HL: public Instruction {
public:
    Instr_JP_HL(): Instruction("JP (HL)", 1, 4){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_CALL_NZ_nn: public Instruction {
public:
    Instr_CALL_NZ_nn(): Instruction("CALL NZ,nn", 3, 24){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_CALL_NC_nn: public Instruction {
public:
    Instr_CALL_NC_nn(): Instruction("CALL NC,nn", 3, 24){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_CALL_Z_nn: public Instruction {
public:
    Instr_CALL_Z_nn(): Instruction("CALL Z,nn", 3, 24){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_CALL_C_nn: public Instruction {
public:
    Instr_CALL_C_nn(): Instruction("CALL C,nn", 3, 24){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_CALL_nn: public Instruction {
public:
    Instr_CALL_nn(): Instruction("CALL nn", 3, 24){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RST_00: public Instruction {
public:
    Instr_RST_00(): Instruction("RST 00H", 1, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RST_08: public Instruction {
public:
    Instr_RST_08(): Instruction("RST 08H", 1, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RST_10: public Instruction {
public:
    Instr_RST_10(): Instruction("RST 10H", 1, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RST_18: public Instruction {
public:
    Instr_RST_18(): Instruction("RST 18H", 1, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RST_20: public Instruction {
public:
    Instr_RST_20(): Instruction("RST 20H", 1, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RST_28: public Instruction {
public:
    Instr_RST_28(): Instruction("RST 28H", 1, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RST_30: public Instruction {
public:
    Instr_RST_30(): Instruction("RST 30H", 1, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


class Instr_RST_38: public Instruction {
public:
    Instr_RST_38(): Instruction("RST 38H", 1, 16){}
    virtual bool execute(RegisterBank &registers, MemoryController &memory, doubleRegValue_t pc, memValue8_t opcode);
};


} /* namespace gbcoloremu */

#endif /* __FLOWINSTRUCTION_H */
