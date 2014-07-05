/*
file:			CRenderer.cpp
description:	-
author:			matthias
*/

#include "CRenderer.h"

CRenderer::CRenderer()
{
	renderer = new PixelRenderer();
}

CRenderer::~CRenderer()
{
	delete renderer;
}

PixelRenderer* CRenderer::getRenderer()
{
	return renderer;
}

void CRenderer::setBrightness(int val)
{
	renderer->setBrightness(val);
}

void CRenderer::setup()
{
	renderer->setup();
}
void CRenderer::clear()
{
	// no member function clear
	//renderer->clear();
}

void CRenderer::setPixel(int x, int y, int  r,int  g, int  b,int a)
{
	renderer->setPixel(x, y, r, g, b, a);
}
void CRenderer::setPixel(int x, int y, uint32_t c)
{
	#ifndef _WINDOWS
	renderer->setPixel(x, y, c);
	#endif
}

void CRenderer::draw()
{
	
#ifdef _WINDOWS
	// clear only under windows
	// clear out frame around display
	gl::clear(Color(1, 1, 1));
#endif

	// pass call along
	renderer->draw();

}

void CRenderer::fade()
{
	#ifndef _WINDOWS
	renderer->fade();
	#endif
}
