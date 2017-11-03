#include "videoController.hpp"

namespace gbcoloremu
{

    VideoController::drawLine()
    {
        // iterate throught _bgMapX
            // take the corresponding tile (16bytes) from _charRAM
            // iterate throught the tile pixels
                // compose the palette number
                // take the color from _OBJ0PAL or OBJ1PAL
                // write the color in _virtualScreen
    }

} /* namespace gbcoloremu */
