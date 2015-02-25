//generated pixeldata
#ifndef _DataGirlGotHit2_h
#define _DataGirlGotHit2_h
#include "PixelData.h"
namespace _GirlGotHit2_ {
    const uint8_t indices[54] = {
        255
        ,255
        ,0
        ,0
        ,0
        ,0
        ,255
        ,4
        ,255
        ,255
        ,0
        ,8
        ,12
        ,12
        ,16
        ,4
        ,12
        ,20
        ,255
        ,0
        ,12
        ,16
        ,12
        ,12
        ,0
        ,4
        ,255
        ,0
        ,0
        ,12
        ,12
        ,12
        ,12
        ,4
        ,4
        ,255
        ,255
        ,255
        ,255
        ,255
        ,4
        ,4
        ,4
        ,4
        ,20
        ,255
        ,255
        ,255
        ,12
        ,255
        ,255
        ,255
        ,4
        ,255
    };
    const uint8_t color[24] = {
        255
        ,234
        ,0
        ,255
        ,255
        ,0
        ,10
        ,255
        ,255
        ,201
        ,135
        ,255
        ,255
        ,198
        ,135
        ,255
        ,179
        ,134
        ,85
        ,255
        ,39
        ,15
        ,2
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataGirlGotHit2 : public PixelDataImpl<DataGirlGotHit2<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 9; }
       static constexpr uint8_t height() { return 6; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _GirlGotHit2_::indices; }
       static constexpr const uint8_t* color() { return _GirlGotHit2_::color; }
       constexpr DataGirlGotHit2(){}
};
#endif
