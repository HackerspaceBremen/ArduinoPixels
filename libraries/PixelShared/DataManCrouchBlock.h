//generated pixeldata
#ifndef _DataManCrouchBlock_h
#define _DataManCrouchBlock_h
#include "PixelData.h"
namespace _ManCrouchBlock_ {
    const uint8_t indices[48] = {
        255
        ,0
        ,0
        ,0
        ,0
        ,255
        ,255
        ,0
        ,0
        ,0
        ,0
        ,255
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,255
        ,4
        ,4
        ,4
        ,4
        ,255
        ,255
        ,4
        ,0
        ,4
        ,0
        ,255
        ,255
        ,4
        ,4
        ,4
        ,4
        ,4
        ,255
        ,8
        ,8
        ,8
        ,8
        ,4
        ,0
        ,255
        ,255
        ,255
        ,0
        ,255
    };
    const uint8_t color[12] = {
        0
        ,0
        ,0
        ,255
        ,255
        ,198
        ,135
        ,255
        ,34
        ,59
        ,169
        ,255
    };
}
class DataManCrouchBlock : public PixelDataImpl<DataManCrouchBlock> { 
public:
       static constexpr int width() { return 6; }
       static constexpr int height() { return 8; }
       static constexpr const uint8_t* indices() { return _ManCrouchBlock_::indices; }
       static constexpr const uint8_t* color() { return _ManCrouchBlock_::color; }
};
#endif
