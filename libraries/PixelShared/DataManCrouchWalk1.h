//generated pixeldata
#ifndef _DataManCrouchWalk1_h
#define _DataManCrouchWalk1_h
#include "PixelData.h"
namespace _ManCrouchWalk1_ {
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
        ,255
        ,255
        ,8
        ,8
        ,8
        ,8
        ,255
        ,255
        ,4
        ,255
        ,12
        ,0
        ,4
    };
    const uint8_t color[16] = {
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
        ,0
        ,0
        ,0
        ,2
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataManCrouchWalk1 : public PixelDataImpl<DataManCrouchWalk1<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 6; }
       static constexpr uint8_t height() { return 8; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _ManCrouchWalk1_::indices; }
       static constexpr const uint8_t* color() { return _ManCrouchWalk1_::color; }
       constexpr DataManCrouchWalk1(){}
};
#endif
