//generated pixeldata
#ifndef _DataManRay1_h
#define _DataManRay1_h
#include "PixelData.h"
namespace _ManRay1_ {
    const uint8_t indices[26] = {
        0
        ,255
        ,0
        ,0
        ,4
        ,0
        ,8
        ,4
        ,8
        ,4
        ,12
        ,16
        ,16
        ,255
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
        ,12
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
struct DataManRay1 : public PixelDataImpl<DataManRay1<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 13; }
       static constexpr uint8_t height() { return 2; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _ManRay1_::indices; }
       static constexpr const uint8_t* color() { return _ManRay1_::color; }
       constexpr DataManRay1(){}
};
#endif
