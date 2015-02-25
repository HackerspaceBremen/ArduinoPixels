//generated pixeldata
#ifndef _DataManStandKick_h
#define _DataManStandKick_h
#include "PixelData.h"
namespace _ManStandKick_ {
    const uint8_t indices[70] = {
        255
        ,0
        ,0
        ,0
        ,0
        ,255
        ,255
        ,255
        ,0
        ,0
        ,0
        ,0
        ,255
        ,255
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,255
        ,255
        ,4
        ,4
        ,4
        ,4
        ,255
        ,255
        ,255
        ,4
        ,0
        ,4
        ,0
        ,255
        ,255
        ,255
        ,4
        ,4
        ,4
        ,4
        ,255
        ,255
        ,255
        ,8
        ,8
        ,8
        ,8
        ,255
        ,255
        ,4
        ,8
        ,8
        ,4
        ,8
        ,255
        ,255
        ,255
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,255
        ,0
        ,255
        ,255
        ,255
        ,255
        ,255
    };
    const uint8_t color[12] = {
        0
        ,0
        ,0
        ,255
        ,255
        ,198
        ,135
        ,255
        ,34
        ,59
        ,169
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataManStandKick : public PixelDataImpl<DataManStandKick<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 7; }
       static constexpr uint8_t height() { return 10; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _ManStandKick_::indices; }
       static constexpr const uint8_t* color() { return _ManStandKick_::color; }
       constexpr DataManStandKick(){}
};
#endif
