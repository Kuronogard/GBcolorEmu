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
                printf("[%02x]: %-5s", i, "O");
            else
                printf("[%02x]: %-5s", i, instructions[i]->mnemonic(i).data());
            //printf("\n");
        }
        printf("\n");
    }
}

void GbaEmuCpu::initInstructions()
{
    // clean instructions array
    for (int i  = 0; i < 256; i++) {
        instructions[i] = NULL;
    }

    instructions[0x00] = new Instr_NOP();
    instructions[0x01] = new Instr_LD_rr_nn();
    instructions[0x02] = new Instr_LD_BC_A();
    instructions[0x03] = new Instr_INC_rr();
    instructions[0x04] = new Instr_INC_r();
    instructions[0x05] = new Instr_DEC_r();
    instructions[0x06] = new Instr_LD_r_n();
    instructions[0x07] = new Instr_RLCA();
    instructions[0x08] = new Instr_LD_nn_SP();
    instructions[0x09] = new Instr_ADD_HL_rr();
    instructions[0x0A] = new Instr_LD_A_BC();
    instructions[0x0B] = new Instr_DEC_rr();
    instructions[0x0C] = instructions[0x04];
    instructions[0x0D] = instructions[0x05];
    instructions[0x0E] = instructions[0x06];
    instructions[0x0F] = new Instr_RRCA();

    instructions[0x10] = new Instr_STOP();
    instructions[0x11] = instructions[0x01];
    instructions[0x12] = new Instr_LD_DE_A();
    instructions[0x13] = instructions[0x03];
    instructions[0x14] = instructions[0x04];
    instructions[0x15] = instructions[0x05];
    instructions[0x16] = instructions[0x06];
    instructions[0x17] = new Instr_RLA();
    instructions[0x18] = new Instr_JR_n();
    instructions[0x19] = instructions[0x09];
    instructions[0x1A] = new Instr_LD_A_DE();
    instructions[0x1B] = instructions[0x0B];
    instructions[0x1C] = instructions[0x04];
    instructions[0x1D] = instructions[0x05];
    instructions[0x1E] = instructions[0x06];
    instructions[0x1F] = new Instr_RRA();

    instructions[0x20] = new Instr_JR_NZ_n();
    instructions[0x21] = instructions[0x01];
    instructions[0x22] = new Instr_LDI_HL_A();  // LD (HL+), A
    instructions[0x23] = instructions[0x03];
    instructions[0x24] = instructions[0x04];
    instructions[0x25] = instructions[0x05];
    instructions[0x26] = instructions[0x06];
    instructions[0x27] = new Instr_DAA();
    instructions[0x28] = new Instr_JR_Z_n();
    instructions[0x29] = instructions[0x09];
    instructions[0x2A] = new Instr_LDI_A_HL;  // LD A, (HL+)
    instructions[0x2B] = instructions[0x0B];
    instructions[0x2C] = instructions[0x04];
    instructions[0x2D] = instructions[0x05];
    instructions[0x2E] = instructions[0x06];
    instructions[0x2F] = new Instr_CPL();

    instructions[0x30] = new Instr_JR_NC_n();
    instructions[0x31] = instructions[0x01];
    instructions[0x32] = new Instr_LDD_HL_A();  // LD (HL-), A
    instructions[0x33] = instructions[0x03];
    instructions[0x34] = new Instr_INC_HL();
    instructions[0x35] = new Instr_DEC_HL();
    instructions[0x36] = new Instr_LD_HL_n();
    instructions[0x37] = new Instr_SCF();
    instructions[0x38] = new Instr_JR_C_n();
    instructions[0x39] = instructions[0x09];
    instructions[0x3A] = new Instr_LDD_A_HL();  // LD A, (HL-)
    instructions[0x3B] = instructions[0x0B];
    instructions[0x3C] = instructions[0x04];
    instructions[0x3D] = instructions[0x05];
    instructions[0x3E] = instructions[0x06];
    instructions[0x3F] = new Instr_CCF();

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
    instructions[0x76] = new Instr_HALT(); // HALT
    instructions[0x77] = instructions[0x70];
    instructions[0x78] = instructions[0x40];
    instructions[0x79] = instructions[0x40];
    instructions[0x7A] = instructions[0x40];
    instructions[0x7B] = instructions[0x40];
    instructions[0x7C] = instructions[0x40];
    instructions[0x7D] = instructions[0x40];
    instructions[0x7E] = instructions[0x46];
    instructions[0x7F] = instructions[0x40];

    instructions[0x80] = new Instr_ADD_A_r();
    instructions[0x81] = instructions[0x80];
    instructions[0x82] = instructions[0x80];
    instructions[0x83] = instructions[0x80];
    instructions[0x84] = instructions[0x80];
    instructions[0x85] = instructions[0x80];
    instructions[0x86] = new Instr_ADD_A_HL();
    instructions[0x87] = instructions[0x80];
    instructions[0x88] = new Instr_ADC_A_r();
    instructions[0x89] = instructions[0x88];
    instructions[0x8A] = instructions[0x88];
    instructions[0x8B] = instructions[0x88];
    instructions[0x8C] = instructions[0x88];
    instructions[0x8D] = instructions[0x88];
    instructions[0x8E] = new Instr_ADC_A_HL();
    instructions[0x8F] = instructions[0x88];

    instructions[0x90] = new Instr_SUB_A_r();
    instructions[0x91] = instructions[0x90];
    instructions[0x92] = instructions[0x90];
    instructions[0x93] = instructions[0x90];
    instructions[0x94] = instructions[0x90];
    instructions[0x95] = instructions[0x90];
    instructions[0x96] = new Instr_SUB_A_HL();
    instructions[0x97] = instructions[0x90];
    instructions[0x98] = new Instr_SBC_A_r();
    instructions[0x99] = instructions[0x98];
    instructions[0x9A] = instructions[0x98];
    instructions[0x9B] = instructions[0x98];
    instructions[0x9C] = instructions[0x98];
    instructions[0x9D] = instructions[0x98];
    instructions[0x9E] = new Instr_SBC_A_HL();
    instructions[0x9F] = instructions[0x98];

    instructions[0xA0] = new Instr_AND_A_r();
    instructions[0xA1] = instructions[0xA0];
    instructions[0xA2] = instructions[0xA0];
    instructions[0xA3] = instructions[0xA0];
    instructions[0xA4] = instructions[0xA0];
    instructions[0xA5] = instructions[0xA0];
    instructions[0xA6] = new Instr_AND_A_HL();
    instructions[0xA7] = instructions[0xA0];
    instructions[0xA8] = new Instr_XOR_A_r();
    instructions[0xA9] = instructions[0xA8];
    instructions[0xAA] = instructions[0xA8];
    instructions[0xAB] = instructions[0xA8];
    instructions[0xAC] = instructions[0xA8];
    instructions[0xAD] = instructions[0xA8];
    instructions[0xAE] = new Instr_XOR_A_HL();
    instructions[0xAF] = instructions[0xA8];

    instructions[0xB0] = new Instr_OR_A_r();
    instructions[0xB1] = instructions[0xB0];
    instructions[0xB2] = instructions[0xB0];
    instructions[0xB3] = instructions[0xB0];
    instructions[0xB4] = instructions[0xB0];
    instructions[0xB5] = instructions[0xB0];
    instructions[0xB6] = new Instr_OR_A_HL();
    instructions[0xB7] = instructions[0xB0];
    instructions[0xB8] = new Instr_CP_A_r();
    instructions[0xB9] = instructions[0xB8];
    instructions[0xBA] = instructions[0xB8];
    instructions[0xBB] = instructions[0xB8];
    instructions[0xBC] = instructions[0xB8];
    instructions[0xBD] = instructions[0xB8];
    instructions[0xBE] = new Instr_CP_A_HL();
    instructions[0xBF] = instructions[0xB8];

    instructions[0xC0] = new Instr_RET_NZ();
    instructions[0xC1] = new Instr_POP();
    instructions[0xC2] = new Instr_JP_NZ_nn();
    instructions[0xC3] = new Instr_JP_nn();
    instructions[0xC4] = new Instr_CALL_NZ_nn();
    instructions[0xC5] = new Instr_PUSH();
    instructions[0xC6] = new Instr_ADD_A_n();
    instructions[0xC7] = new Instr_RST_00();
    instructions[0xC8] = new Instr_RET_Z();
    instructions[0xC9] = new Instr_RET();
    instructions[0xCA] = new Instr_JP_Z_nn();
    //instructions[0xCB] = new Instr_PREFIX_CB();
    instructions[0xCC] = new Instr_CALL_Z_nn();
    instructions[0xCD] = new Instr_CALL_nn();
    instructions[0xCE] = new Instr_ADC_A_n();
    instructions[0xCF] = new Instr_RST_08();

    instructions[0xD0] = new Instr_RET_NC();
    instructions[0xD1] = instructions[0xC1];
    instructions[0xD2] = new Instr_JP_NC_nn();
    instructions[0xD4] = new Instr_CALL_NC_nn();
    instructions[0xD5] = instructions[0xC5];
    instructions[0xD6] = new Instr_SUB_A_n();
    instructions[0xD7] = new Instr_RST_10();
    instructions[0xD8] = new Instr_RET_C();
    instructions[0xD9] = new Instr_RETI();
    instructions[0xDA] = new Instr_JP_C_nn();
    instructions[0xDC] = new Instr_CALL_C_nn();
    instructions[0xDE] = new Instr_SBC_A_n();
    instructions[0xDF] = new Instr_RST_18();

    instructions[0xE0] = new Instr_LD_io_A();
    instructions[0xE1] = instructions[0xC1];
    instructions[0xE2] = new Instr_LD_C_A(); // LD  (C), A
    instructions[0xE5] = instructions[0xC5];
    instructions[0xE6] = new Instr_AND_A_n();
    instructions[0xE7] = new Instr_RST_20();
    instructions[0xE8] = new Instr_ADD_SP_n();
    instructions[0xE9] = new Instr_JP_HL();
    instructions[0xEA] = new Instr_LD_nn_A();
    instructions[0xEE] = new Instr_XOR_A_n();
    instructions[0xEF] = new Instr_RST_28();

    instructions[0xF0] = new Instr_LD_A_io();
    instructions[0xF1] = instructions[0xC1];
    instructions[0xF2] = new Instr_LD_A_C();
    instructions[0xF4] = new Instr_DI();
    instructions[0xF5] = instructions[0xC5];
    instructions[0xF6] = new Instr_OR_A_n();
    instructions[0xF7] = new Instr_RST_30();
    instructions[0xF8] = new Instr_LD_HL_SP();
    instructions[0xF9] = new Instr_LD_SP_HL();
    instructions[0xFA] = new Instr_LD_A_nn();
    instructions[0xFB] = new Instr_EI();
    instructions[0xFE] = new Instr_CP_A_n();
    instructions[0xFF] = new Instr_RST_38();
}


std::ostream &operator<<(std::ostream &os, const GbaEmuCpu& obj)
{
    os << "Registers:" << endl;
    os << obj.registers;
    return os;
}

} /* namespace gbcoloremu */
