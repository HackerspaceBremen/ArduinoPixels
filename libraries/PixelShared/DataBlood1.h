//generated pixeldata
#ifndef _DataBlood1_h
#define _DataBlood1_h
#include "PixelData.h"
namespace _Blood1_ {
    const uint8_t indices[9] = {
        255
        ,0
        ,255
        ,0
        ,0
        ,0
        ,255
        ,0
        ,255
    };
    const uint8_t color[4] = {
        151
        ,0
        ,0
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataBlood1 : public PixelDataImpl<DataBlood1<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 3; }
       static constexpr uint8_t height() { return 3; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _Blood1_::indices; }
       static constexpr const uint8_t* color() { return _Blood1_::color; }
       constexpr DataBlood1(){}
};
#endif
