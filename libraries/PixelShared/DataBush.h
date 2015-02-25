//generated pixeldata
#ifndef _DataBush_h
#define _DataBush_h
#include "PixelData.h"
namespace _Bush_ {
    const uint8_t indices[77] = {
        255
        ,255
        ,255
        ,0
        ,0
        ,4
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,255
        ,0
        ,8
        ,12
        ,0
        ,4
        ,8
        ,255
        ,255
        ,255
        ,255
        ,0
        ,12
        ,0
        ,0
        ,8
        ,4
        ,0
        ,4
        ,255
        ,0
        ,0
        ,12
        ,8
        ,0
        ,12
        ,0
        ,0
        ,4
        ,8
        ,4
        ,255
        ,255
        ,0
        ,0
        ,0
        ,4
        ,8
        ,4
        ,4
        ,4
        ,4
        ,255
        ,255
        ,255
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,16
        ,255
        ,255
        ,16
        ,255
        ,255
        ,255
        ,255
    };
    const uint8_t color[20] = {
        141
        ,180
        ,118
        ,255
        ,111
        ,144
        ,93
        ,255
        ,183
        ,1
        ,1
        ,255
        ,169
        ,200
        ,150
        ,255
        ,54
        ,43
        ,38
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataBush : public PixelDataImpl<DataBush<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 11; }
       static constexpr uint8_t height() { return 7; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _Bush_::indices; }
       static constexpr const uint8_t* color() { return _Bush_::color; }
       constexpr DataBush(){}
};
#endif
