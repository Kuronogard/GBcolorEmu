
#ifndef __VIDEO_CONTROLLER_HPP
#define __VIDEO_CONTROLLER_HPP


// Screen buffer (background) 256x256 pixels -> 32x32 tiles (8x8 pixel/tiles)
// only 160x144 pixels displayed on screen -> SCROLLX and SCROLLY are the left upper corner
// background wraps around the screen

// Background Tile Map:  32 rows of 32 bytes (each contains the number of a til to be displayed)

// Tile Data Table :($8000 - $8FFF) or ($8800 - 97FF)
        // $8000 - $8FFF: patterns numbered from 0 to 255
        // $8800 - $97FF: patterns numbered from -128 to 127

// Window overlayng the background (WINDPOSX and WINDPOSY are the left upper corner)

namespace gbcoloremu
{
class VideoController {
private:

public:

};

} /* namespace gbcoloremu */


#endif /* __VIDEO_CONTROLLER_HPP */
