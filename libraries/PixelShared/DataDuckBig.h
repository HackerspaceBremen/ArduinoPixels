//generated pixeldata
#ifndef _DataDuckBig_h
#define _DataDuckBig_h
#include "PixelData.h"
namespace _DuckBig_ {
    const uint8_t indices[16] = {
        0
        ,4
        ,255
        ,255
        ,255
        ,4
        ,255
        ,255
        ,255
        ,4
        ,4
        ,4
        ,255
        ,4
        ,4
        ,4
    };
    const uint8_t color[8] = {
        255
        ,147
        ,8
        ,255
        ,255
        ,194
        ,8
        ,255
    };
}
class DataDuckBig : public PixelDataImpl<DataDuckBig> { 
public:
       static constexpr int width() { return 4; }
       static constexpr int height() { return 4; }
       static constexpr const uint8_t* indices() { return _DuckBig_::indices; }
       static constexpr const uint8_t* color() { return _DuckBig_::color; }
};
#endif
