//generated pixeldata
#ifndef _DataGirlCrouch_h
#define _DataGirlCrouch_h
#include "PixelData.h"
namespace _GirlCrouch_ {
    const uint8_t indices[42] = {
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
        ,255
        ,255
        ,8
        ,20
        ,255
        ,24
        ,20
        ,8
    };
    const uint8_t color[28] = {
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
        ,0
        ,0
        ,0
        ,2
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataGirlCrouch : public PixelDataImpl<DataGirlCrouch<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 7; }
       static constexpr uint8_t height() { return 6; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _GirlCrouch_::indices; }
       static constexpr const uint8_t* color() { return _GirlCrouch_::color; }
       constexpr DataGirlCrouch(){}
};
#endif
