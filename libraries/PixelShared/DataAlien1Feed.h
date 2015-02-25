//generated pixeldata
#ifndef _DataAlien1Feed_h
#define _DataAlien1Feed_h
#include "PixelData.h"
namespace _Alien1Feed_ {
    const uint8_t indices[35] = {
        0
        ,255
        ,255
        ,255
        ,0
        ,0
        ,255
        ,255
        ,255
        ,0
        ,0
        ,255
        ,255
        ,255
        ,0
        ,0
        ,255
        ,255
        ,255
        ,0
        ,0
        ,255
        ,255
        ,255
        ,0
        ,0
        ,255
        ,255
        ,255
        ,0
        ,0
        ,0
        ,255
        ,0
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
struct DataAlien1Feed : public PixelDataImpl<DataAlien1Feed<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 5; }
       static constexpr uint8_t height() { return 7; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _Alien1Feed_::indices; }
       static constexpr const uint8_t* color() { return _Alien1Feed_::color; }
       constexpr DataAlien1Feed(){}
};
#endif
