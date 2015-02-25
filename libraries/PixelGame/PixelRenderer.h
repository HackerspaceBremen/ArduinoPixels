//
//  PixelRenderer.h
//  PixelGame
//
//  Created by Kris Temmerman on 15/09/13.
//  Copyright (c) 2013 Kris Temmerman. All rights reserved.
//

#ifndef PixelGame_PixelRenderer_h
#define PixelGame_PixelRenderer_h

#ifndef ARDUINO
#include <cstdint>
#else
#include <Arduino.h>
#endif

class PixelRenderer
{
public:

    virtual ~PixelRenderer() {}

    virtual void setup() = 0;

    virtual void draw() = 0;

    virtual void setPixel(int x,int y,uint8_t r, uint8_t g , uint8_t b, uint8_t a) = 0;
    virtual void setBrightness(uint8_t val) = 0;
    virtual void fade() = 0;
};

#endif
