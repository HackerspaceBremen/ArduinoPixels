//generated pixeldata
#ifndef _DataManGitHit1_h
#define _DataManGitHit1_h
#include "PixelData.h"
namespace _ManGitHit1_ {
    const uint8_t indices[60] = {
        255
        ,0
        ,0
        ,0
        ,255
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
        ,255
        ,255
        ,4
        ,4
        ,0
        ,0
        ,0
        ,255
        ,4
        ,8
        ,4
        ,4
        ,255
        ,4
        ,4
        ,4
        ,4
        ,8
        ,255
        ,12
        ,12
        ,12
        ,12
        ,255
        ,255
        ,12
        ,12
        ,12
        ,12
        ,255
        ,255
        ,0
        ,4
        ,0
        ,0
        ,4
        ,255
        ,255
        ,0
        ,255
        ,255
        ,0
        ,255
    };
    const uint8_t color[16] = {
        0
        ,0
        ,0
        ,255
        ,255
        ,198
        ,135
        ,255
        ,179
        ,134
        ,85
        ,255
        ,34
        ,59
        ,169
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataManGitHit1 : public PixelDataImpl<DataManGitHit1<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 6; }
       static constexpr uint8_t height() { return 10; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _ManGitHit1_::indices; }
       static constexpr const uint8_t* color() { return _ManGitHit1_::color; }
       constexpr DataManGitHit1(){}
};
#endif
