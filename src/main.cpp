
#include <iostream>

#include "videoController.hpp"
#include "soundController.hpp"
#include "memoryController.hpp"
#include "registerBank.hpp"
#include "CPU.hpp"

using namespace gbcoloremu;
using namespace std;


void createProgram(Cartridge &cartridge) {

    cartridge._ROM16[0x0100] = Instr_LDBn().opcode();
    cartridge._ROM16[0x0101] = 0x88;
    cartridge._ROM16[0x0102] = Instr_LDCn().opcode();
    cartridge._ROM16[0x0103] = 0xAA;

}



int main(int argc, char *argv[])
{
    bool runSuccess;
    GbaEmuCpu cpu = GbaEmuCpu();
    Cartridge cartridge;

    createProgram(cartridge);

    cpu.loadCartridge(cartridge);
    runSuccess = cpu.run();

    if (runSuccess)
    {
        cout << "Finished execution" << endl;
    }
    else
    {
        cout << "Error in execution" << endl;
        cout << "Core DUMP:" << endl;
        cout << cpu << endl;
    }

    return 0;
}
