//generated pixeldata
#ifndef _DataLife7_h
#define _DataLife7_h
#include "PixelData.h"
namespace _Life7_ {
    const uint8_t indices[25] = {
        255
        ,0
        ,255
        ,0
        ,255
        ,0
        ,0
        ,0
        ,0
        ,4
        ,0
        ,0
        ,0
        ,0
        ,4
        ,255
        ,0
        ,0
        ,4
        ,255
        ,255
        ,255
        ,4
        ,255
        ,255
    };
    const uint8_t color[8] = {
        249
        ,0
        ,0
        ,255
        ,180
        ,0
        ,0
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataLife7 : public PixelDataImpl<DataLife7<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 5; }
       static constexpr uint8_t height() { return 5; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _Life7_::indices; }
       static constexpr const uint8_t* color() { return _Life7_::color; }
       constexpr DataLife7(){}
};
#endif
