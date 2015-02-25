//generated pixeldata
#ifndef _DataDuckSmall_h
#define _DataDuckSmall_h
#include "PixelData.h"
namespace _DuckSmall_ {
    const uint8_t indices[6] = {
        0
        ,4
        ,255
        ,255
        ,4
        ,4
    };
    const uint8_t color[8] = {
        255
        ,147
        ,8
        ,255
        ,255
        ,194
        ,8
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataDuckSmall : public PixelDataImpl<DataDuckSmall<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 3; }
       static constexpr uint8_t height() { return 2; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _DuckSmall_::indices; }
       static constexpr const uint8_t* color() { return _DuckSmall_::color; }
       constexpr DataDuckSmall(){}
};
#endif
