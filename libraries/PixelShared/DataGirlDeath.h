//generated pixeldata
#ifndef _DataGirlDeath_h
#define _DataGirlDeath_h
#include "PixelData.h"
namespace _GirlDeath_ {
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
        ,8
        ,8
        ,8
        ,255
        ,255
        ,0
        ,8
        ,12
        ,8
        ,12
        ,255
        ,0
        ,0
        ,8
        ,8
        ,8
        ,8
        ,0
        ,255
        ,8
        ,16
        ,16
        ,16
        ,16
        ,8
        ,255
        ,255
        ,16
        ,16
        ,16
        ,16
        ,255
        ,255
        ,16
        ,16
        ,16
        ,16
        ,16
        ,16
        ,255
        ,255
        ,20
        ,255
        ,255
        ,20
        ,255
    };
    const uint8_t color[24] = {
        255
        ,245
        ,163
        ,230
        ,255
        ,227
        ,211
        ,230
        ,255
        ,226
        ,211
        ,230
        ,187
        ,217
        ,233
        ,230
        ,235
        ,202
        ,222
        ,230
        ,184
        ,213
        ,229
        ,230
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataGirlDeath : public PixelDataImpl<DataGirlDeath<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 7; }
       static constexpr uint8_t height() { return 8; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _GirlDeath_::indices; }
       static constexpr const uint8_t* color() { return _GirlDeath_::color; }
       constexpr DataGirlDeath(){}
};
#endif
