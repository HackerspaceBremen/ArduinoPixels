//generated pixeldata
#ifndef _DataSpaceHead_h
#define _DataSpaceHead_h
#include "PixelData.h"
namespace _SpaceHead_ {
    const uint8_t indices[56] = {
        255
        ,255
        ,0
        ,4
        ,0
        ,255
        ,255
        ,255
        ,0
        ,8
        ,4
        ,0
        ,0
        ,255
        ,0
        ,12
        ,0
        ,0
        ,0
        ,0
        ,0
        ,16
        ,16
        ,16
        ,16
        ,16
        ,16
        ,16
        ,16
        ,20
        ,20
        ,20
        ,20
        ,20
        ,16
        ,16
        ,24
        ,20
        ,24
        ,20
        ,24
        ,16
        ,16
        ,20
        ,20
        ,20
        ,20
        ,20
        ,16
        ,16
        ,16
        ,16
        ,16
        ,16
        ,16
        ,16
    };
    const uint8_t color[28] = {
        255
        ,0
        ,0
        ,255
        ,255
        ,62
        ,32
        ,255
        ,255
        ,96
        ,50
        ,255
        ,255
        ,82
        ,40
        ,255
        ,141
        ,198
        ,63
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,0
        ,0
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataSpaceHead : public PixelDataImpl<DataSpaceHead<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 7; }
       static constexpr uint8_t height() { return 8; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _SpaceHead_::indices; }
       static constexpr const uint8_t* color() { return _SpaceHead_::color; }
       constexpr DataSpaceHead(){}
};
#endif
