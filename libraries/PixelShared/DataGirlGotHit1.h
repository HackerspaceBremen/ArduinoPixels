//generated pixeldata
#ifndef _DataGirlGotHit1_h
#define _DataGirlGotHit1_h
#include "PixelData.h"
namespace _GirlGotHit1_ {
    const uint8_t indices[56] = {
        255
        ,255
        ,0
        ,0
        ,255
        ,255
        ,255
        ,255
        ,0
        ,4
        ,4
        ,0
        ,0
        ,255
        ,255
        ,0
        ,4
        ,8
        ,4
        ,4
        ,255
        ,0
        ,0
        ,4
        ,4
        ,4
        ,8
        ,0
        ,255
        ,12
        ,12
        ,12
        ,12
        ,255
        ,255
        ,255
        ,12
        ,4
        ,12
        ,12
        ,4
        ,255
        ,255
        ,12
        ,12
        ,12
        ,12
        ,12
        ,255
        ,255
        ,255
        ,16
        ,255
        ,255
        ,16
        ,255
    };
    const uint8_t color[20] = {
        255
        ,234
        ,0
        ,255
        ,255
        ,198
        ,135
        ,255
        ,179
        ,134
        ,85
        ,255
        ,255
        ,0
        ,10
        ,255
        ,39
        ,15
        ,2
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataGirlGotHit1 : public PixelDataImpl<DataGirlGotHit1<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 7; }
       static constexpr uint8_t height() { return 8; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _GirlGotHit1_::indices; }
       static constexpr const uint8_t* color() { return _GirlGotHit1_::color; }
       constexpr DataGirlGotHit1(){}
};
#endif
