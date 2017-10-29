#ifndef __REGISTERBANK_HPP
#define __REGISTERBANK_HPP

#include <iostream>

namespace gbcoloremu
{

using regValue_t = uint8_t;
using doubleRegValue_t = uint16_t;

class RegisterBank
{
public:
    // Posible 16bit pairings  (15..8 | 7..0)
    //                              A - F
    //                              B - C
    //                              D - E
    //                              H - L

    // regF stores results of various math operations
    // PC points to the next instruction to be executed (initial value: 0x0100)
    // SP points to the current stack position (initial value: 0xFFFE)

    // SP grows downward in RAM memory.
    // It decrements automatically before something is put in it
    regValue_t A, B, C, D, E, F;
    regValue_t H, L;
    doubleRegValue_t SP, PC;

    friend std::ostream &operator<<(std::ostream &os, const RegisterBank &obj)
    {
        os << "A:" << unsigned(obj.A) << "  F:" << unsigned(obj.F) << endl;
        os << "B:" << unsigned(obj.B) << "  C:" << unsigned(obj.C) << endl;
        os << "D:" << unsigned(obj.D) << "  E:" << unsigned(obj.E) << endl;
        os << "H:" << unsigned(obj.H) << "  L:" << unsigned(obj.L) << endl;
        os << "SP:" << unsigned(obj.SP) << "  PC:" << unsigned(obj.PC) << endl;
        return os;
    }
};


} /* namespace gbcoloremu */


#endif /* __REGISTERBANK_HPP */

