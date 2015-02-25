//generated pixeldata
#ifndef _DataManRay2_h
#define _DataManRay2_h
#include "PixelData.h"
namespace _ManRay2_ {
    const uint8_t indices[26] = {
        255
        ,0
        ,255
        ,4
        ,0
        ,8
        ,0
        ,8
        ,4
        ,12
        ,8
        ,16
        ,16
        ,0
        ,255
        ,0
        ,255
        ,4
        ,0
        ,8
        ,4
        ,8
        ,4
        ,12
        ,16
        ,16
    };
    const uint8_t color[20] = {
        147
        ,255
        ,0
        ,122
        ,147
        ,255
        ,0
        ,186
        ,147
        ,255
        ,0
        ,219
        ,147
        ,255
        ,0
        ,245
        ,147
        ,255
        ,0
        ,236
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataManRay2 : public PixelDataImpl<DataManRay2<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 13; }
       static constexpr uint8_t height() { return 2; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _ManRay2_::indices; }
       static constexpr const uint8_t* color() { return _ManRay2_::color; }
       constexpr DataManRay2(){}
};
#endif
