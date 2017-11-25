
#include <iostream>

#include "videoController.hpp"
#include "soundController.hpp"
#include "memoryController.hpp"
#include "registerBank.hpp"
#include "CPU.hpp"

using namespace gbcoloremu;
using namespace std;


void createProgram(Cartridge &cartridge) {

    cartridge._ROM16[0x0100] = 0x0;
    cartridge._ROM16[0x0101] = 0x88;
    cartridge._ROM16[0x0102] = 0x0;
    cartridge._ROM16[0x0103] = 0xAA;

}



int main(int argc, char *argv[])
{
    bool runSuccess;
    GbaEmuCpu cpu = GbaEmuCpu();
    Cartridge cartridge;

    printf("Init Instructions ... ");
    cpu.initInstructions();
    printf("DONE\n");


    cpu.printInstructions();

    printf("Creating test cartridge ... ");
    createProgram(cartridge);
    printf("DONE\n");

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
