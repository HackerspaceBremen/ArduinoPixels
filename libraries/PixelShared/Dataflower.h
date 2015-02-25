//generated pixeldata
#ifndef _Dataflower_h
#define _Dataflower_h
#include "PixelData.h"
namespace _flower_ {
    const uint8_t indices[9] = {
        255
        ,0
        ,255
        ,0
        ,4
        ,0
        ,255
        ,0
        ,255
    };
    const uint8_t color[8] = {
        255
        ,255
        ,255
        ,255
        ,190
        ,175
        ,98
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct Dataflower : public PixelDataImpl<Dataflower<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 3; }
       static constexpr uint8_t height() { return 3; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _flower_::indices; }
       static constexpr const uint8_t* color() { return _flower_::color; }
       constexpr Dataflower(){}
};
#endif
