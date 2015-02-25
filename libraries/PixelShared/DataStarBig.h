//generated pixeldata
#ifndef _DataStarBig_h
#define _DataStarBig_h
#include "PixelData.h"
namespace _StarBig_ {
    const uint8_t indices[9] = {
        255
        ,0
        ,255
        ,0
        ,255
        ,0
        ,255
        ,0
        ,255
    };
    const uint8_t color[4] = {
        51
        ,51
        ,51
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataStarBig : public PixelDataImpl<DataStarBig<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 3; }
       static constexpr uint8_t height() { return 3; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _StarBig_::indices; }
       static constexpr const uint8_t* color() { return _StarBig_::color; }
       constexpr DataStarBig(){}
};
#endif
