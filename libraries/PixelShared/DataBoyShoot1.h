//generated pixeldata
#ifndef _DataBoyShoot1_h
#define _DataBoyShoot1_h
#include "PixelData.h"
namespace _BoyShoot1_ {
    const uint8_t indices[20] = {
        0
        ,255
        ,4
        ,255
        ,4
        ,255
        ,8
        ,255
        ,12
        ,12
        ,255
        ,0
        ,255
        ,4
        ,255
        ,4
        ,255
        ,8
        ,12
        ,12
    };
    const uint8_t color[16] = {
        147
        ,255
        ,0
        ,150
        ,147
        ,255
        ,0
        ,219
        ,147
        ,255
        ,0
        ,245
        ,147
        ,255
        ,0
        ,236
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataBoyShoot1 : public PixelDataImpl<DataBoyShoot1<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 10; }
       static constexpr uint8_t height() { return 2; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _BoyShoot1_::indices; }
       static constexpr const uint8_t* color() { return _BoyShoot1_::color; }
       constexpr DataBoyShoot1(){}
};
#endif
