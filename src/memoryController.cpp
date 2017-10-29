
#include "memoryController.hpp"
#include <iostream>

namespace gbcoloremu
{


#define IN_ADDR_SPACE(addr, memory)  ((addr >= memory ## _start) && (addr <= memory ## _end))
#define ADDR_SPACE_DISPL(memory)    (memory ## _start)

#define ROM16
#define switchableROM16k
#define videoRAM8k
#define switchableRAM8k
#define internalRAM8k
#define internalRAM8kEcho
#define spriteAttrMemory
#define internalRAM
#define unusable



MemoryController::MemoryController()
{


}


MemoryController::~MemoryController()
{


}


memValue8_t MemoryController::read(memAddr_t address)
{

    if (IN_ADDR_SPACE(address, ROM16))
    {
        address -= ADDR_SPACE_DISPL(ROM16);
        return _cartridge._ROM16[address];
    }
    else if (IN_ADDR_SPACE(address, switchableROM16k))
    {
        address -= ADDR_SPACE_DISPL(switchableROM16k);
        return _cartridge._switchableROM16k[address];
    }
    else if (IN_ADDR_SPACE(address, videoRAM8k))
    {
        address -= ADDR_SPACE_DISPL(videoRAM8k);
        return _videoRAM8k[address];
    }
    else if (IN_ADDR_SPACE(address, switchableRAM8k))
    {
        address -= ADDR_SPACE_DISPL(switchableRAM8k);
        return _switchableRAM8k[address];
    }
    else if (IN_ADDR_SPACE(address, internalRAM8k))
    {
        address -= ADDR_SPACE_DISPL(internalRAM8k);
        return _internalRAM8k[address];
    }
    else if (IN_ADDR_SPACE(address, internalRAM8kEcho))
    {
        address -= ADDR_SPACE_DISPL(internalRAM8kEcho);
        return _internalRAM8k[address];
    }
    else if (IN_ADDR_SPACE(address, spriteAttrMemory))
    {
        address -= ADDR_SPACE_DISPL(spriteAttrMemory);
        return _spriteAttrMemory[address];
    }
    else if (IN_ADDR_SPACE(address, internalRAM))
    {
        address -= ADDR_SPACE_DISPL(internalRAM);
        return _internalRAM[address];
    }
    else
    {
        // BAD address
        std::cout << "BAB read address" << std::endl;
    }


    return 0;
}


bool MemoryController::write(memAddr_t address, memValue8_t value)
{
    if (IN_ADDR_SPACE(address, ROM16))
    {
        address -= ADDR_SPACE_DISPL(ROM16);
        _cartridge._ROM16[address] = value;
    }
    else if (IN_ADDR_SPACE(address, switchableROM16k))
    {
        address -= ADDR_SPACE_DISPL(switchableROM16k);
        _cartridge._switchableROM16k[address] = value;
    }
    else if (IN_ADDR_SPACE(address, videoRAM8k))
    {
        address -= ADDR_SPACE_DISPL(videoRAM8k);
        _videoRAM8k[address] = value;
    }
    else if (IN_ADDR_SPACE(address, switchableRAM8k))
    {
        address -= ADDR_SPACE_DISPL(switchableRAM8k);
        _switchableRAM8k[address] = value;
    }
    else if (IN_ADDR_SPACE(address, internalRAM8k))
    {
        address -= ADDR_SPACE_DISPL(internalRAM8k);
        _internalRAM8k[address] = value;
    }
    else if (IN_ADDR_SPACE(address, internalRAM8kEcho))
    {
        address -= ADDR_SPACE_DISPL(internalRAM8kEcho);
        _internalRAM8k[address] = value;
    }
    else if (IN_ADDR_SPACE(address, spriteAttrMemory))
    {
        address -= ADDR_SPACE_DISPL(spriteAttrMemory);
        _spriteAttrMemory[address] = value;
    }
    else if (IN_ADDR_SPACE(address, internalRAM))
    {
        address -= ADDR_SPACE_DISPL(internalRAM);
        _internalRAM[address] = value;
    }
    else
    {
        // BAD address
        return false;
    }

    return true;
}

bool MemoryController::configCartridge(Cartridge& cartridge)
{
    _cartridge = cartridge;
    return true;
}

} /* namespace gbcoloremu */
