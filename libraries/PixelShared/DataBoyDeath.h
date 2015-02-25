//generated pixeldata
#ifndef _DataBoyDeath_h
#define _DataBoyDeath_h
#include "PixelData.h"
namespace _BoyDeath_ {
    const uint8_t indices[60] = {
        255
        ,0
        ,0
        ,0
        ,0
        ,255
        ,255
        ,0
        ,0
        ,0
        ,0
        ,255
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,255
        ,4
        ,4
        ,4
        ,4
        ,255
        ,255
        ,4
        ,0
        ,4
        ,0
        ,255
        ,255
        ,4
        ,4
        ,4
        ,4
        ,255
        ,4
        ,8
        ,8
        ,8
        ,8
        ,4
        ,255
        ,8
        ,8
        ,8
        ,8
        ,255
        ,255
        ,0
        ,0
        ,0
        ,0
        ,255
        ,255
        ,0
        ,255
        ,255
        ,0
        ,255
    };
    const uint8_t color[12] = {
        150
        ,168
        ,181
        ,230
        ,255
        ,235
        ,220
        ,230
        ,164
        ,188
        ,230
        ,230
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataBoyDeath : public PixelDataImpl<DataBoyDeath<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 6; }
       static constexpr uint8_t height() { return 10; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _BoyDeath_::indices; }
       static constexpr const uint8_t* color() { return _BoyDeath_::color; }
       constexpr DataBoyDeath(){}
};
#endif
