//generated pixeldata
#ifndef _DataMenuSelect3_h
#define _DataMenuSelect3_h
#include "PixelData.h"
namespace _MenuSelect3_ {
    const uint8_t indices[192] = {
        255
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
        ,255
        ,0
        ,0
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
        ,0
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
        ,0
        ,4
        ,4
        ,4
        ,4
        ,0
        ,255
        ,255
        ,0
        ,0
        ,8
        ,8
        ,8
        ,8
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,4
        ,4
        ,4
        ,4
        ,0
        ,0
        ,255
        ,0
        ,8
        ,12
        ,16
        ,16
        ,16
        ,0
        ,0
        ,20
        ,0
        ,20
        ,0
        ,0
        ,20
        ,20
        ,0
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,0
        ,0
        ,0
        ,8
        ,16
        ,4
        ,16
        ,4
        ,0
        ,0
        ,20
        ,0
        ,20
        ,0
        ,0
        ,20
        ,0
        ,0
        ,0
        ,16
        ,16
        ,16
        ,16
        ,0
        ,0
        ,0
        ,8
        ,8
        ,16
        ,16
        ,16
        ,16
        ,8
        ,0
        ,0
        ,20
        ,0
        ,0
        ,20
        ,20
        ,0
        ,255
        ,0
        ,16
        ,4
        ,16
        ,4
        ,0
        ,255
        ,0
        ,0
        ,0
        ,0
        ,16
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,255
        ,0
        ,16
        ,16
        ,16
        ,16
        ,0
        ,255
        ,255
        ,255
        ,255
        ,0
        ,0
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
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,255
    };
    const uint8_t color[24] = {
        255
        ,0
        ,0
        ,255
        ,0
        ,0
        ,0
        ,255
        ,255
        ,234
        ,0
        ,255
        ,255
        ,201
        ,135
        ,255
        ,255
        ,198
        ,135
        ,255
        ,255
        ,255
        ,255
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataMenuSelect3 : public PixelDataImpl<DataMenuSelect3<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 24; }
       static constexpr uint8_t height() { return 8; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _MenuSelect3_::indices; }
       static constexpr const uint8_t* color() { return _MenuSelect3_::color; }
       constexpr DataMenuSelect3(){}
};
#endif
