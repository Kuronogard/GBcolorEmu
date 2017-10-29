#include "CPU.hpp"


namespace gbcoloremu
{

using Clock_t = std::chrono::high_resolution_clock;

GbaEmuCpu::GbaEmuCpu()
{
    //cyclePeriod_ns = std::chrono::nanoseconds(DEFAULT_PERIOD_NS);
    // Create instruction array and load all the processor instruction

    registers.PC = 0x0100;

}


GbaEmuCpu::~GbaEmuCpu()
{


}


bool GbaEmuCpu::run()
{
    memValue8_t opcode;
    Instruction* currentInstruction;
    uint8_t numParamBytes;
    memValue16_t param;
    bool executeSuccess;

    // each cycle
    while(true)
    {
        // Start counting the current cycle period
        auto time_start = Clock_t::now();

        // read the byte pointed by regPC
        cout << "Read instruction at: [" << std::showbase << std::hex << registers.PC << "]" << endl;
        cout << std::noshowbase << std::dec;
        opcode = memoryController.read(registers.PC);

        // compare it with the opcodes of the instructions until a match is found
        currentInstruction = decode(opcode);
        if (currentInstruction == NULL)
        {
            cout << "NULL instruction" << endl;
            return false;
        }

        // wait the number of delay cycles
        delayCycles = currentInstruction->numDelayCycles();
        // wait(delayCycles)

        // read the instruction params and update PC
        numParamBytes = currentInstruction->numParamBytes();
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
        executeSuccess = currentInstruction->execute(registers, memoryController, param);
        if (!executeSuccess)
        {
            return false;
            cout << "ERROR executing instruction" << endl;
        }
        cout << "Instruction: " << currentInstruction->mnemonic() << endl;

        // Wait until the current cycle period is expired
        auto time_end = Clock_t::now();
        auto time_curr = std::chrono::duration_cast<std::chrono::nanoseconds>(time_end - time_start).count();

        while(time_curr < cyclePeriod_ns)
        {
            time_end = Clock_t::now();
            time_curr = std::chrono::duration_cast<std::chrono::nanoseconds>(time_end - time_start).count();
        }
    }

    return true;
}


Instruction * GbaEmuCpu::decode(memValue8_t opcode)
{
    cout << "Decoding: [" << std::showbase << std::hex << unsigned(opcode) << "]" << endl;
    cout << std::noshowbase << std::dec;
    return instructions[opcode];
}


bool GbaEmuCpu::loadCartridge(Cartridge& cartridge)
{
    memoryController.configCartridge(cartridge);
    return true;
}

std::ostream &operator<<(std::ostream &os, const GbaEmuCpu& obj)
{
    os << "Registers:" << endl;
    os << obj.registers;
    return os;
}

} /* namespace gbcoloremu */
