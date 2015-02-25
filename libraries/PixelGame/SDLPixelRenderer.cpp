/*
 * SDLPixelRenderer.cpp
 *
 *  Created on: 21.03.2014
 *      Author: michael
 */

#ifndef ARDUINO
#include "SDLPixelRenderer.h"

SDLPixelRenderer::SDLPixelRenderer(unsigned int width, unsigned int height, unsigned int scale)
	: width(width), height(height), scale(scale), window(NULL), surface(NULL) {

}

SDLPixelRenderer::~SDLPixelRenderer() {
	if (surface != NULL) SDL_FreeSurface(surface);
	if (window != NULL) SDL_DestroyWindow(window);
}

void SDLPixelRenderer::setup() {
	window = SDL_CreateWindow("SDLPixels",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			width * scale, height * scale, SDL_WINDOW_SHOWN);

	surface = SDL_CreateRGBSurface(0,width,height,32,0,0,0,0);
}

void SDLPixelRenderer::draw() {
	SDL_Surface *screen = SDL_GetWindowSurface(window);
	SDL_BlitScaled(surface, NULL, screen, NULL);
	SDL_UpdateWindowSurface(window);
}

void SDLPixelRenderer::setPixel(int x,int y,uint8_t r, uint8_t g , uint8_t b, uint8_t /*a*/) {
	uint32_t c = SDL_MapRGB(surface->format,r,g,b);
	setPixel(x, y, c);
}

void SDLPixelRenderer::setPixel(int x, int y, uint32_t c) {
	if (x < 0 || x >= surface->w || y < 0 || y >= surface->h)
		return; // off screen

	SDL_LockSurface(surface);

	Uint8 * pixel = (Uint8*)surface->pixels;
	pixel += (y * surface->pitch) + (x * sizeof(Uint32));
	*((Uint32*)pixel) = c;

	SDL_UnlockSurface(surface);
}

void SDLPixelRenderer::setBrightness(uint8_t /*val*/) {
	// not implemented
}

void SDLPixelRenderer::fade() {
	// not implemented
}

#endif // ARDUINO
