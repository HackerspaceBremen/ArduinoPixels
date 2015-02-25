//generated pixeldata
#ifndef _DataAlien2Dead_h
#define _DataAlien2Dead_h
#include "PixelData.h"
namespace _Alien2Dead_ {
    const uint8_t indices[56] = {
        255
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,255
        ,255
        ,0
        ,4
        ,4
        ,4
        ,4
        ,0
        ,255
        ,255
        ,0
        ,4
        ,8
        ,4
        ,8
        ,0
        ,255
        ,255
        ,0
        ,4
        ,4
        ,4
        ,4
        ,0
        ,255
        ,255
        ,0
        ,4
        ,4
        ,4
        ,4
        ,0
        ,255
        ,0
        ,255
        ,0
        ,255
        ,0
        ,255
        ,0
        ,255
        ,255
        ,0
        ,255
        ,0
        ,255
        ,0
        ,255
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
struct DataAlien2Dead : public PixelDataImpl<DataAlien2Dead<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 8; }
       static constexpr uint8_t height() { return 7; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _Alien2Dead_::indices; }
       static constexpr const uint8_t* color() { return _Alien2Dead_::color; }
       constexpr DataAlien2Dead(){}
};
#endif
