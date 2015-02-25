//generated pixeldata
#ifndef _DataManWalk4_h
#define _DataManWalk4_h
#include "PixelData.h"
namespace _ManWalk4_ {
    const uint8_t indices[60] = {
        255
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
        ,255
        ,8
        ,8
        ,8
        ,8
        ,255
        ,255
        ,0
        ,4
        ,0
        ,0
        ,4
        ,255
        ,0
        ,255
        ,255
        ,0
        ,255
    };
    const uint8_t color[12] = {
        0
        ,0
        ,0
        ,255
        ,255
        ,198
        ,135
        ,255
        ,34
        ,59
        ,169
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataManWalk4 : public PixelDataImpl<DataManWalk4<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 6; }
       static constexpr uint8_t height() { return 10; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _ManWalk4_::indices; }
       static constexpr const uint8_t* color() { return _ManWalk4_::color; }
       constexpr DataManWalk4(){}
};
#endif
