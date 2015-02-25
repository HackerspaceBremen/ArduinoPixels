//generated pixeldata
#ifndef _DataPaddo_h
#define _DataPaddo_h
#include "PixelData.h"
namespace _Paddo_ {
    const uint8_t indices[36] = {
        255
        ,255
        ,0
        ,4
        ,255
        ,255
        ,255
        ,8
        ,8
        ,4
        ,12
        ,255
        ,8
        ,8
        ,0
        ,8
        ,4
        ,16
        ,8
        ,0
        ,4
        ,20
        ,24
        ,16
        ,255
        ,255
        ,28
        ,32
        ,255
        ,255
        ,255
        ,255
        ,36
        ,40
        ,255
        ,255
    };
    const uint8_t color[44] = {
        214
        ,212
        ,212
        ,255
        ,192
        ,0
        ,0
        ,255
        ,214
        ,0
        ,0
        ,255
        ,214
        ,214
        ,214
        ,122
        ,155
        ,0
        ,0
        ,255
        ,173
        ,0
        ,0
        ,255
        ,173
        ,171
        ,171
        ,255
        ,203
        ,144
        ,79
        ,255
        ,147
        ,104
        ,56
        ,255
        ,182
        ,129
        ,70
        ,255
        ,164
        ,116
        ,63
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataPaddo : public PixelDataImpl<DataPaddo<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 6; }
       static constexpr uint8_t height() { return 6; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _Paddo_::indices; }
       static constexpr const uint8_t* color() { return _Paddo_::color; }
       constexpr DataPaddo(){}
};
#endif
