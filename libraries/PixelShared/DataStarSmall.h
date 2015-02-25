//generated pixeldata
#ifndef _DataStarSmall_h
#define _DataStarSmall_h
#include "PixelData.h"
namespace _StarSmall_ {
    const uint8_t indices[1] = {
        0
    };
    const uint8_t color[4] = {
        51
        ,51
        ,51
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataStarSmall : public PixelDataImpl<DataStarSmall<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 1; }
       static constexpr uint8_t height() { return 1; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _StarSmall_::indices; }
       static constexpr const uint8_t* color() { return _StarSmall_::color; }
       constexpr DataStarSmall(){}
};
#endif
