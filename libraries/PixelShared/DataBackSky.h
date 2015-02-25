//generated pixeldata
#ifndef _DataBackSky_h
#define _DataBackSky_h
#include "PixelData.h"
namespace _BackSky_ {
    const uint8_t indices[16] = {
        0
        ,4
        ,8
        ,12
        ,16
        ,20
        ,24
        ,28
        ,32
        ,36
        ,40
        ,44
        ,48
        ,52
        ,56
        ,60
    };
    const uint8_t color[64] = {
        0
        ,0
        ,0
        ,255
        ,6
        ,0
        ,6
        ,255
        ,14
        ,0
        ,13
        ,255
        ,23
        ,0
        ,21
        ,255
        ,33
        ,0
        ,30
        ,255
        ,43
        ,0
        ,41
        ,255
        ,54
        ,0
        ,52
        ,255
        ,63
        ,1
        ,65
        ,255
        ,72
        ,12
        ,79
        ,255
        ,80
        ,26
        ,93
        ,255
        ,87
        ,45
        ,109
        ,255
        ,95
        ,67
        ,127
        ,255
        ,103
        ,91
        ,146
        ,255
        ,112
        ,120
        ,168
        ,255
        ,122
        ,153
        ,193
        ,255
        ,130
        ,180
        ,213
        ,255
    };
}
template<int8_t WidthOffset=0, int8_t HeightOffset=0>
struct DataBackSky : public PixelDataImpl<DataBackSky<WidthOffset, HeightOffset> > {
       static constexpr uint8_t width() { return 1; }
       static constexpr uint8_t height() { return 16; }
       static constexpr int8_t widthOffset() { return WidthOffset; }
       static constexpr int8_t heightOffset() { return HeightOffset; }
       static constexpr const uint8_t* indices() { return _BackSky_::indices; }
       static constexpr const uint8_t* color() { return _BackSky_::color; }
       constexpr DataBackSky(){}
};
#endif
