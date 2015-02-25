//generated pixeldata
#ifndef _DataGirlWalk3_h
#define _DataGirlWalk3_h
#include "PixelData.h"
namespace _GirlWalk3_ {
    const uint8_t indices[56] = {
        255
        ,255
        ,0
        ,0
        ,0
        ,0
        ,255
        ,255
        ,0
        ,4
        ,4
        ,4
        ,4
        ,255
        ,255
        ,0
        ,4
        ,8
        ,4
        ,8
        ,255
        ,0
        ,0
        ,4
        ,4
        ,4
        ,4
        ,0
        ,255
        ,255
        ,12
        ,12
        ,12
        ,12
        ,255
        ,255
        ,255
        ,12
        ,12
        ,12
        ,12
        ,4
        ,255
        ,12
        ,4
        ,12
        ,12
        ,12
        ,12
        ,255
        ,255
        ,16
        ,255
        ,16
        ,255
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
        ,0
        ,0
        ,0
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
struct DataGirlWalk3 : public PixelDataImpl<DataGirlWalk3<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 7; }
       static constexpr uint8_t height() { return 8; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _GirlWalk3_::indices; }
       static constexpr const uint8_t* color() { return _GirlWalk3_::color; }
       constexpr DataGirlWalk3(){}
};
#endif
