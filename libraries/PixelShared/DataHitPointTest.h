//generated pixeldata
#ifndef _DataHitPointTest_h
#define _DataHitPointTest_h
#include "PixelData.h"
namespace _HitPointTest_ {
    const uint8_t indices[2] = {
        0
        ,0
    };
    const uint8_t color[4] = {
        237
        ,28
        ,36
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataHitPointTest : public PixelDataImpl<DataHitPointTest<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 2; }
       static constexpr uint8_t height() { return 1; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _HitPointTest_::indices; }
       static constexpr const uint8_t* color() { return _HitPointTest_::color; }
       constexpr DataHitPointTest(){}
};
#endif
