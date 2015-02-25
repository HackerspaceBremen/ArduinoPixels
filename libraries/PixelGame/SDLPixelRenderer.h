/*
 * SDLPixelRenderer.h
 *
 *  Created on: 21.03.2014
 *      Author: michael
 */

#ifndef SDLPIXELRENDERER_H_
#define SDLPIXELRENDERER_H_

#include "PixelRenderer.h"

#include "SDL2/SDL.h"

class SDLPixelRenderer: public PixelRenderer {
public:
	SDLPixelRenderer(unsigned int width, unsigned int height, unsigned int scale = 10);
	virtual ~SDLPixelRenderer();

    virtual void setup() override;

    virtual void draw() override;

    virtual void setPixel(int x, int y, uint8_t r, uint8_t g , uint8_t b, uint8_t) override;

    virtual void setBrightness(uint8_t) override;
    virtual void fade() override;

private:
    unsigned int width, height, scale;
    SDL_Window *window;
    SDL_Surface *surface;

    void setPixel(int x, int y, uint32_t c);
};

#endif /* SDLPIXELRENDERER_H_ */
