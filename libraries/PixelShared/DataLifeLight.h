//generated pixeldata
#ifndef _DataLifeLight_h
#define _DataLifeLight_h
#include "PixelData.h"
namespace _LifeLight_ {
    const uint8_t indices[49] = {
        255
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
        ,0
        ,255
        ,0
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,0
        ,255
        ,255
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
        ,255
        ,255
        ,0
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
    };
    const uint8_t color[4] = {
        253
        ,207
        ,0
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataLifeLight : public PixelDataImpl<DataLifeLight<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 7; }
       static constexpr uint8_t height() { return 7; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _LifeLight_::indices; }
       static constexpr const uint8_t* color() { return _LifeLight_::color; }
       constexpr DataLifeLight(){}
};
#endif
