//generated pixeldata
#ifndef _DataManJump_h
#define _DataManJump_h
#include "PixelData.h"
namespace _ManJump_ {
    const uint8_t indices[60] = {
        255
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
        ,4
        ,8
        ,8
        ,8
        ,8
        ,4
        ,255
        ,8
        ,8
        ,8
        ,8
        ,255
        ,255
        ,0
        ,0
        ,0
        ,0
        ,255
        ,0
        ,255
        ,255
        ,255
        ,255
        ,0
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
struct DataManJump : public PixelDataImpl<DataManJump> {
       static constexpr uint8_t width() { return 6; }
       static constexpr uint8_t height() { return 10; }
       static constexpr const uint8_t* indices() { return _ManJump_::indices; }
       static constexpr const uint8_t* color() { return _ManJump_::color; }
       constexpr DataManJump(){}
};
#endif
