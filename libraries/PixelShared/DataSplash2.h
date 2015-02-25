//generated pixeldata
#ifndef _DataSplash2_h
#define _DataSplash2_h
#include "PixelData.h"
namespace _Splash2_ {
    const uint8_t indices[60] = {
        255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,255
        ,255
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
struct DataSplash2 : public PixelDataImpl<DataSplash2<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 10; }
       static constexpr uint8_t height() { return 6; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _Splash2_::indices; }
       static constexpr const uint8_t* color() { return _Splash2_::color; }
       constexpr DataSplash2(){}
};
#endif
