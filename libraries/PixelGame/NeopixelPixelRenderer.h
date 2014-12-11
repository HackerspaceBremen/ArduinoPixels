//
//  NeopixelPixelRenderer.h
//  PixelGame
//
//  Created by Kris Temmerman on 15/09/13.
//  Copyright (c) 2013 Kris Temmerman. All rights reserved.
//

#ifdef ARDUINO

#ifndef PixelGame_NeopixelPixelRenderer_h
#define PixelGame_NeopixelPixelRenderer_h
#include "Adafruit_NeoMatrix.h"

#include "PixelGameInclude.h"
#include "PixelRenderer.h"

#define PIXEL_WIDTH     90
#define PIXEL_HEIGHT    16
#define PIXEL_PIN       2

class NeopixelPixelRenderer : public PixelRenderer
{
public:
    Adafruit_NeoMatrix *pixels;
    
    NeopixelPixelRenderer();
   
    void setup();
   
    void draw();
        
    void setPixel(int x,int y,uint8_t r, uint8_t g , uint8_t b, uint8_t a);
       
    void setPixel(int x, int y, uint32_t c);
    void setBrightness(int val);
    void fade();
};

#endif // PixelGame_NeopixelPixelRenderer_h

#endif // ARDUINO
