//generated pixeldata
#ifndef _DataInterface2_h
#define _DataInterface2_h
#include "PixelData.h"
namespace _Interface2_ {
    const uint8_t indices[144] = {
        0
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,0
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,0
        ,4
        ,4
        ,8
        ,8
        ,8
        ,12
        ,4
        ,4
        ,0
        ,4
        ,4
        ,16
        ,16
        ,16
        ,20
        ,12
        ,4
        ,0
        ,4
        ,4
        ,24
        ,16
        ,24
        ,16
        ,12
        ,4
        ,0
        ,4
        ,8
        ,16
        ,16
        ,16
        ,16
        ,8
        ,4
        ,0
        ,4
        ,4
        ,4
        ,16
        ,16
        ,4
        ,4
        ,4
        ,0
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,0
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,0
        ,4
        ,4
        ,4
        ,28
        ,4
        ,28
        ,4
        ,4
        ,0
        ,4
        ,4
        ,28
        ,28
        ,28
        ,28
        ,32
        ,4
        ,0
        ,4
        ,4
        ,28
        ,28
        ,28
        ,28
        ,32
        ,4
        ,0
        ,4
        ,4
        ,4
        ,28
        ,28
        ,32
        ,4
        ,4
        ,0
        ,4
        ,4
        ,4
        ,4
        ,32
        ,4
        ,4
        ,4
        ,0
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,0
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
        ,4
    };
    const uint8_t color[36] = {
        34
        ,34
        ,34
        ,255
        ,61
        ,61
        ,61
        ,255
        ,255
        ,210
        ,0
        ,255
        ,255
        ,212
        ,6
        ,255
        ,255
        ,198
        ,135
        ,255
        ,255
        ,201
        ,135
        ,255
        ,0
        ,0
        ,0
        ,255
        ,249
        ,0
        ,0
        ,255
        ,180
        ,0
        ,0
        ,255
    };
}
struct DataInterface2 : public PixelDataImpl<DataInterface2> {
       static constexpr uint8_t width() { return 9; }
       static constexpr uint8_t height() { return 16; }
       static constexpr const uint8_t* indices() { return _Interface2_::indices; }
       static constexpr const uint8_t* color() { return _Interface2_::color; }
       constexpr DataInterface2(){}
};
#endif
