//generated pixeldata
#ifndef _DataSplash1_h
#define _DataSplash1_h
#include "PixelData.h"
namespace _Splash1_ {
    const uint8_t indices[24] = {
        255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,0
        ,255
        ,255
        ,0
        ,255
        ,255
        ,255
        ,255
        ,0
        ,255
        ,255
        ,255
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
    };
    const uint8_t color[8] = {
        84
        ,141
        ,162
        ,255
        ,103
        ,202
        ,234
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataSplash1 : public PixelDataImpl<DataSplash1<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 6; }
       static constexpr uint8_t height() { return 4; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _Splash1_::indices; }
       static constexpr const uint8_t* color() { return _Splash1_::color; }
       constexpr DataSplash1(){}
};
#endif
