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
    memValue8_t opcode;
    Instruction currentInstruction;
    uint8_t numParamBytes;
    memValue16_t param;
    bool executeSuccess;

    // each cycle
    while(true)
    {
        // wait until next cycle
        // Configure cycle period

        // read the byte pointed by regPC
        opcode = memoryController.read(registers.PC);

        // compare it with the opcodes of the instructions until a match is found
        currentInstruction = decode(opcode);

        // wait the number of delay cycles
        delayCycles = currentInstruction.numDelayCycles();
        // wait(delayCycles)

        // read the instruction params and update PC
        numParamBytes = currentInstruction.numParamBytes();
        switch (numParamBytes)
        {
        case 2:
            param = memoryController.read(registers.PC+1);
            param |= (memoryController.read(registers.PC+2) << 8);
            registers.PC += 3;
            break;
        case 1:
            param = memoryController.read(registers.PC+1);
            registers.PC += 2;
            break;
        case 0:
            param = 0;
            registers.PC += 1;
            break;
        }

        // execute the instruction
        executeSuccess = currentInstruction.execute(registers, memoryController, param);
        if (!executeSuccess)
        {
            return false;
        }
    }

    return true;
}





} /* namespace gbcoloremu */
