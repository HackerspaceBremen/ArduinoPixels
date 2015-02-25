//generated pixeldata
#ifndef _DataGirlStandBlock_h
#define _DataGirlStandBlock_h
#include "PixelData.h"
namespace _GirlStandBlock_ {
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
        ,255
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
        ,8
        ,255
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
        ,255
        ,20
        ,255
    };
    const uint8_t color[24] = {
        255
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
        ,0
        ,0
        ,0
        ,255
        ,237
        ,28
        ,36
        ,255
        ,39
        ,15
        ,2
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataGirlStandBlock : public PixelDataImpl<DataGirlStandBlock<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 7; }
       static constexpr uint8_t height() { return 8; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _GirlStandBlock_::indices; }
       static constexpr const uint8_t* color() { return _GirlStandBlock_::color; }
       constexpr DataGirlStandBlock(){}
};
#endif
