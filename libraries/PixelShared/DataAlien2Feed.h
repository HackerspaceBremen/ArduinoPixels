//generated pixeldata
#ifndef _DataAlien2Feed_h
#define _DataAlien2Feed_h
#include "PixelData.h"
namespace _Alien2Feed_ {
    const uint8_t indices[2] = {
        0
        ,0
    };
    const uint8_t color[4] = {
        141
        ,198
        ,63
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataAlien2Feed : public PixelDataImpl<DataAlien2Feed<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 2; }
       static constexpr uint8_t height() { return 1; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _Alien2Feed_::indices; }
       static constexpr const uint8_t* color() { return _Alien2Feed_::color; }
       constexpr DataAlien2Feed(){}
};
#endif
