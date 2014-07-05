/*
file:			CPrimitiveRectangle.cpp
description:	-
author:			matthias
*/

#include "CPrimitiveRectangle.h"

CPrimitiveRectangle::CPrimitiveRectangle(int width, int height, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	w = width;
	h = height;

	r = red;
	b = blue;
	g = green;
	a = alpha;
}

CPrimitiveRectangle::~CPrimitiveRectangle()
{
	//
}

void CPrimitiveRectangle::render(CGameEngine* engine)
{
	if(bshow)
	{
		for(int i = 0; i < w; i++)
		{
			for(int k = 0; k < h; k++)
			{
				engine->renderer->setPixel(posx + i, posy + k, r, g, b, a);
			}
		}
	}
}