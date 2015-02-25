//generated pixeldata
#ifndef _DataGirlShoot2_h
#define _DataGirlShoot2_h
#include "PixelData.h"
namespace _GirlShoot2_ {
    const uint8_t indices[32] = {
        255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,0
        ,255
        ,4
        ,255
        ,4
        ,255
        ,0
        ,8
        ,8
        ,0
        ,255
        ,4
        ,255
        ,4
        ,0
        ,12
        ,8
        ,0
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,0
        ,255
    };
    const uint8_t color[16] = {
        79
        ,224
        ,255
        ,255
        ,255
        ,255
        ,255
        ,122
        ,255
        ,255
        ,255
        ,254
        ,255
        ,255
        ,255
        ,250
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataGirlShoot2 : public PixelDataImpl<DataGirlShoot2<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 8; }
       static constexpr uint8_t height() { return 4; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _GirlShoot2_::indices; }
       static constexpr const uint8_t* color() { return _GirlShoot2_::color; }
       constexpr DataGirlShoot2(){}
};
#endif
