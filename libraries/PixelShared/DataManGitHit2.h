//generated pixeldata
#ifndef _DataManGitHit2_h
#define _DataManGitHit2_h
#include "PixelData.h"
namespace _ManGitHit2_ {
    const uint8_t indices[64] = {
        255
        ,0
        ,0
        ,0
        ,0
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
        ,0
        ,0
        ,0
        ,0
        ,0
        ,0
        ,255
        ,255
        ,255
        ,4
        ,4
        ,4
        ,8
        ,12
        ,4
        ,0
        ,255
        ,4
        ,8
        ,4
        ,4
        ,12
        ,0
        ,255
        ,255
        ,4
        ,4
        ,4
        ,4
        ,12
        ,0
        ,255
        ,255
        ,255
        ,255
        ,12
        ,12
        ,12
        ,0
        ,0
        ,255
        ,255
        ,4
        ,255
        ,255
        ,255
        ,255
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
struct DataManGitHit2 : public PixelDataImpl<DataManGitHit2<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 8; }
       static constexpr uint8_t height() { return 8; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _ManGitHit2_::indices; }
       static constexpr const uint8_t* color() { return _ManGitHit2_::color; }
       constexpr DataManGitHit2(){}
};
#endif
