
#ifndef __CPU_HPP
#define __CPU_HPP

#include "MemoryController.hpp"

namespace gbcoloremu
{

class GbaEmuCpu {
private:

    MemoryController memoryController;

public:

    GbaEmuCpu();
    ~GbaEmuCpu();

    bool run();

};

} /* namespace gbcoloremu */


#endif /* __CPU_HPP */
