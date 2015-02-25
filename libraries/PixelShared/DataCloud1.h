//generated pixeldata
#ifndef _DataCloud1_h
#define _DataCloud1_h
#include "PixelData.h"
namespace _Cloud1_ {
    const uint8_t indices[120] = {
        255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,0
        ,0
        ,0
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,8
        ,12
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,0
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,12
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,255
        ,0
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,8
        ,8
        ,8
        ,8
        ,8
        ,12
        ,255
        ,255
        ,255
        ,255
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,8
        ,8
        ,8
        ,8
        ,8
        ,8
        ,8
        ,12
        ,12
        ,12
        ,12
        ,12
        ,12
        ,12
        ,12
        ,12
    };
    const uint8_t color[16] = {
        255
        ,252
        ,245
        ,255
        ,252
        ,242
        ,242
        ,255
        ,238
        ,231
        ,241
        ,255
        ,225
        ,218
        ,229
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataCloud1 : public PixelDataImpl<DataCloud1<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 24; }
       static constexpr uint8_t height() { return 5; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _Cloud1_::indices; }
       static constexpr const uint8_t* color() { return _Cloud1_::color; }
       constexpr DataCloud1(){}
};
#endif
