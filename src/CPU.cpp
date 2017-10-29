#include "CPU.hpp"


namespace gbcoloremu
{


GbaEmuCpu::GbaEmuCpu()
{
    // Create instruction array and load all the processor instruction

}


GbaEmuCpu::~GbaEmuCpu()
{


}


bool GbaEmuCpu::run()
{

    // each cycle
        // read the byte pointed by regPC
        // compare it with the opcodes of the instructions until a match is found
        // wait the number of delay cycles
        // read the instruction params
        // update PC
        // execute the instruction

    return true;
}





} /* namespace gbcoloremu */
