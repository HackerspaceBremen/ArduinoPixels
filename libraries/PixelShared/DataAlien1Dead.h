//generated pixeldata
#ifndef _DataAlien1Dead_h
#define _DataAlien1Dead_h
#include "PixelData.h"
namespace _Alien1Dead_ {
    const uint8_t indices[54] = {
        0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,4
        ,4
        ,4
        ,4
        ,0
        ,0
        ,8
        ,4
        ,8
        ,4
        ,0
        ,0
        ,4
        ,4
        ,4
        ,4
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,255
        ,0
        ,255
        ,255
        ,255
        ,0
        ,255
        ,0
        ,255
        ,255
        ,255
        ,0
        ,255
        ,0
        ,255
        ,255
        ,255
        ,0
        ,255
        ,0
        ,0
        ,255
        ,0
        ,0
    };
    const uint8_t color[12] = {
        208
        ,235
        ,199
        ,230
        ,255
        ,255
        ,255
        ,230
        ,150
        ,168
        ,181
        ,230
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataAlien1Dead : public PixelDataImpl<DataAlien1Dead<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 6; }
       static constexpr uint8_t height() { return 9; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _Alien1Dead_::indices; }
       static constexpr const uint8_t* color() { return _Alien1Dead_::color; }
       constexpr DataAlien1Dead(){}
};
#endif
