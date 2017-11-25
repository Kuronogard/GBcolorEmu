#include "CPU.hpp"
#include <iomanip>

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
    doubleRegValue_t pc;

    // each cycle
    while(true)
    {
        // Start counting the current cycle period
        auto time_start = Clock_t::now();

        // read the byte pointed by regPC
        cout << "Read instruction at: [" << std::showbase << std::hex << registers.PC << "]" << endl;
        cout << std::noshowbase << std::dec;
        opcode = memoryController.read(registers.PC);
        pc = registers.PC;

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
        executeSuccess = currentInstruction->execute(registers, memoryController, pc , opcode);
        if (!executeSuccess)
        {
            return false;
            cout << "ERROR executing instruction" << endl;
        }
        cout << "Instruction: " << currentInstruction->mnemonic(opcode) << endl;

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


void GbaEmuCpu::printInstructions()
{
    for (int c = 0; c <= 0xF; c++) {
        for (int r = 0; r <= 0xF; r++) {
            int i = (c << 4) | r;
            if (instructions[i] == NULL)
                printf("[%02x]: %-20s", i, "(EMPTY)");
            else
                printf("[%02x]: %-20s", i, instructions[i]->mnemonic(i).data());
            printf("\n");
        }
        //printf("\n");
    }
}

bool GbaEmuCpu::initInstructions()
{
    // clean instructions array
    for (int i  = 0; i < 256; i++) {
        instructions[i] = NULL;
    }


    instructions[0x02] = new Instr_LD_BC_A();
    instructions[0x06] = new Instr_LD_r_n();
    instructions[0x0A] = new Instr_LD_A_BC();
    instructions[0x0E] = instructions[0x06];

    instructions[0x12] = new Instr_LD_DE_A();
    instructions[0x16] = instructions[0x06];
    instructions[0x1A] = new Instr_LD_A_DE();
    instructions[0x1E] = instructions[0x06];

    instructions[0x22] = new Instr_LDI_HL_A();  // LD (HL+), A
    instructions[0x26] = instructions[0x06];
    instructions[0x2A] = new Instr_LDI_A_HL;  // LD A, (HL+)
    instructions[0x2E] = instructions[0x06];

    instructions[0x32] = new Instr_LDD_HL_A();  // LD (HL-), A
    instructions[0x36] = new Instr_LD_HL_n();
    instructions[0x3A] = new Instr_LDD_A_HL();  // LD A, (HL-)
    instructions[0x3E] = instructions[0x06];

    instructions[0x40] = new Instr_LD_r_r();
    instructions[0x41] = instructions[0x40];
    instructions[0x42] = instructions[0x40];
    instructions[0x43] = instructions[0x40];
    instructions[0x44] = instructions[0x40];
    instructions[0x45] = instructions[0x40];
    instructions[0x46] = new Instr_LD_r_HL();
    instructions[0x47] = instructions[0x40];
    instructions[0x48] = instructions[0x40];
    instructions[0x49] = instructions[0x40];
    instructions[0x4A] = instructions[0x40];
    instructions[0x4B] = instructions[0x40];
    instructions[0x4C] = instructions[0x40];
    instructions[0x4D] = instructions[0x40];
    instructions[0x4E] = instructions[0x46];
    instructions[0x4F] = instructions[0x40];
    instructions[0x50] = instructions[0x40];
    instructions[0x51] = instructions[0x40];
    instructions[0x52] = instructions[0x40];
    instructions[0x53] = instructions[0x40];
    instructions[0x54] = instructions[0x40];
    instructions[0x55] = instructions[0x40];
    instructions[0x56] = instructions[0x46];
    instructions[0x57] = instructions[0x40];
    instructions[0x58] = instructions[0x40];
    instructions[0x59] = instructions[0x40];
    instructions[0x5A] = instructions[0x40];
    instructions[0x5B] = instructions[0x40];
    instructions[0x5C] = instructions[0x40];
    instructions[0x5D] = instructions[0x40];
    instructions[0x5E] = instructions[0x46];
    instructions[0x5F] = instructions[0x40];
    instructions[0x60] = instructions[0x40];
    instructions[0x61] = instructions[0x40];
    instructions[0x62] = instructions[0x40];
    instructions[0x63] = instructions[0x40];
    instructions[0x64] = instructions[0x40];
    instructions[0x65] = instructions[0x40];
    instructions[0x66] = instructions[0x46];
    instructions[0x67] = instructions[0x40];
    instructions[0x68] = instructions[0x40];
    instructions[0x69] = instructions[0x40];
    instructions[0x6A] = instructions[0x40];
    instructions[0x6B] = instructions[0x40];
    instructions[0x6C] = instructions[0x40];
    instructions[0x6D] = instructions[0x40];
    instructions[0x6E] = instructions[0x46];
    instructions[0x6F] = instructions[0x40];
    instructions[0x70] = new Instr_LD_HL_r();
    instructions[0x71] = instructions[0x70];
    instructions[0x72] = instructions[0x70];
    instructions[0x73] = instructions[0x70];
    instructions[0x74] = instructions[0x70];
    instructions[0x75] = instructions[0x70];
    instructions[0x76] = NULL; // HALT
    instructions[0x77] = instructions[0x70];
    instructions[0x78] = instructions[0x40];
    instructions[0x79] = instructions[0x40];
    instructions[0x7A] = instructions[0x40];
    instructions[0x7B] = instructions[0x40];
    instructions[0x7C] = instructions[0x40];
    instructions[0x7D] = instructions[0x40];
    instructions[0x7E] = instructions[0x46];
    instructions[0x7F] = instructions[0x40];

    instructions[0xC1] = new Instr_POP();
    instructions[0xC5] = new Instr_PUSH();

    instructions[0xD1] = instructions[0xC1];
    instructions[0xD5] = instructions[0xC5];

    instructions[0xE0] = new Instr_LD_io_A();
    instructions[0xE1] = instructions[0xC1];
    instructions[0xE2] = new Instr_LD_C_A(); // LD  (C), A
    instructions[0xE5] = instructions[0xC5];
    instructions[0xEA] = new Instr_LD_nn_A();
    instructions[0xF0] = new Instr_LD_A_io();
    instructions[0xF1] = instructions[0xC1];
    instructions[0xF2] = new Instr_LD_A_C();
    instructions[0xF5] = instructions[0xC5];
    instructions[0xF8] = new Instr_LD_HL_SP();
    instructions[0xF9] = new Instr_LD_SP_HL();
    instructions[0xFA] = new Instr_LD_A_nn();
}


std::ostream &operator<<(std::ostream &os, const GbaEmuCpu& obj)
{
    os << "Registers:" << endl;
    os << obj.registers;
    return os;
}

} /* namespace gbcoloremu */
