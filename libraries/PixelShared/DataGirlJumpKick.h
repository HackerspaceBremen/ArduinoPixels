//generated pixeldata
#ifndef _DataGirlJumpKick_h
#define _DataGirlJumpKick_h
#include "PixelData.h"
namespace _GirlJumpKick_ {
    const uint8_t indices[72] = {
        255
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
        ,0
        ,0
        ,4
        ,4
        ,255
        ,255
        ,255
        ,255
        ,0
        ,4
        ,4
        ,4
        ,8
        ,0
        ,255
        ,255
        ,255
        ,0
        ,4
        ,8
        ,4
        ,4
        ,255
        ,255
        ,255
        ,0
        ,0
        ,4
        ,4
        ,4
        ,12
        ,4
        ,255
        ,255
        ,255
        ,255
        ,12
        ,12
        ,12
        ,12
        ,4
        ,4
        ,16
        ,255
        ,4
        ,12
        ,12
        ,12
        ,12
        ,255
        ,255
        ,255
        ,255
        ,255
        ,16
        ,255
        ,255
        ,255
        ,255
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
struct DataGirlJumpKick : public PixelDataImpl<DataGirlJumpKick<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 9; }
       static constexpr uint8_t height() { return 8; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _GirlJumpKick_::indices; }
       static constexpr const uint8_t* color() { return _GirlJumpKick_::color; }
       constexpr DataGirlJumpKick(){}
};
#endif
