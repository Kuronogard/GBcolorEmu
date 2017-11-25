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


    void setValue(uint8_t regNum, doubleRegValue_t value)
    {
        switch(regNum)
        {
        case 0x0:
            B = value;
            break;
        case 0x1:
            C = value;
            break;
        case 0x2:
            D = value;
            break;
        case 0x3:
            E = value;
            break;
        case 0x4:
            H = value;
            break;
        case 0x5:
            L = value;
            break;
        case 0x6:
            cout << "Invalid write to register HL" << endl;
            break;
        case 0x7:
            A = value;
        }
    }


    doubleRegValue_t getValue(uint8_t regNum)
    {
        doubleRegValue_t value;
        switch(regNum)
        {
        case 0x0:
            value = B;
            break;
        case 0x1:
            value = C;
            break;
        case 0x2:
            value = D;
            break;
        case 0x3:
            value = E;
            break;
        case 0x4:
            value = H;
            break;
        case 0x5:
            value = L;
            break;
        case 0x6:
            cout << "Invalid read from register HL" << endl;
            break;
        case 0x7:
            value = A;
        }

        return value;
    }

    doubleRegValue_t getDoubleValue(uint8_t regNum)
    {
        doubleRegValue_t value;
        switch(regNum)
        {
        case 0x0:
            value = getBC();
            break;
        case 0x1:
            value = getDE();
            break;
        case 0x2:
            value = getHL();
            break;
        case 0x3:
            value = SP;
            break;
        }

        return value;
    }

    void setDoubleValue(uint8_t regNum, doubleRegValue_t value)
    {
        switch(regNum)
        {
        case 0x0:
            setBC(value);
            break;
        case 0x1:
            setDE(value);
            break;
        case 0x2:
            setHL(value);
            break;
        case 0x3:
            SP = value;
            break;
        }
    }


    doubleRegValue_t getHL() {
        return ((doubleRegValue_t)H << 8) | L;
    }

    void setHL(doubleRegValue_t value) {
        H = (value >> 8) & 0x7;
        L = value & 0x7;
    }

    doubleRegValue_t getBC() {
        return ((doubleRegValue_t)B << 8) | C;
    }

    void setBC(doubleRegValue_t value) {
        B = (value >> 8) & 0x7;
        C = value & 0x7;
    }

    doubleRegValue_t getDE() {
        return ((doubleRegValue_t)D << 8) | E;
    }

    void setDE(doubleRegValue_t value) {
        D = (value >> 8) & 0x7;
        E = value & 0x7;
    }

    doubleRegValue_t getAF() {
        return ((doubleRegValue_t)A << 8) | F;
    }

    void setAF(doubleRegValue_t value) {
        A = (value >> 8) & 0x7;
        F = value & 0x7;
    }

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

