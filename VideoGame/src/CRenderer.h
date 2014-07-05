/*
file:			CRenderer.h
description:	The CRenderer class is just a wrapper. Method calls are passed to through to PixelRenderer.
author:			matthias
*/

#ifndef CRENDERER_H
#define CRENDERER_H

#include "..\..\libraries\PixelGame\PixelRenderer.h"

#ifdef _WINDOWS
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;
#endif

class CRenderer
{

private:

	PixelRenderer* renderer;

public:

	CRenderer();
	~CRenderer();

	// function is used be invasion game to get point to renderer
	PixelRenderer* getRenderer();

	// methods from PixelRenderer
	void setBrightness(int val);
	void setup();
	void clear();
	void setPixel(int x, int y, int  r,int  g, int  b,int a);
	void setPixel(int x, int y, uint32_t c);			// only for arduino code
	void draw();
	void fade();										// only for arduino code
};

#endif