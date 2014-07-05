/*
file:			CPrimitiveRectangle.h
description:	Rectangle
author:			matthias
*/

#ifndef CPRIMITIVERECTANGLE_H
#define CPRIMITIVERECTANGLE_H

#include "CPrimitive.h"

class CPrimitiveRectangle : public CPrimitive
{

private:

	// current animation state
	int state;

	int dx;

	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

public:

	CPrimitiveRectangle(int width, int height, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
	~CPrimitiveRectangle();

	void render(CGameEngine* engine);
};

#endif