//
//  NeuroPixelRenderer.h
//  PixelGame
//
//  Renderer for a LED display wired as individual strips.
//
//  Created by Kris Temmerman.
//  Copyright (c) 2013 Kris Temmerman. All rights reserved.
//

#ifdef ARDUINO

#ifndef PixelGame_NeuroPixelRenderer_h
#define PixelGame_NeuroPixelRenderer_h
#include "PixelGameInclude.h"
#include "../Adafruit_NeoPixel/Adafruit_NeoPixel.h"

#include "PixelRenderer.h"

class NeuroPixelRenderer : public PixelRenderer
{
public:
    Adafruit_NeoPixel *strip1;
    Adafruit_NeoPixel *strip2;
    Adafruit_NeoPixel *strip3;
    Adafruit_NeoPixel *strip4;
    Adafruit_NeoPixel *strip5;
    Adafruit_NeoPixel *strip6;

    NeuroPixelRenderer() { }

    virtual void setup() override;

    virtual void draw() override;

    virtual void setPixel(int x,int y,uint8_t r, uint8_t g , uint8_t b, uint8_t a) override;

    virtual void setBrightness(uint8_t val) override;
    virtual void fade() override;
};

#endif
#endif
