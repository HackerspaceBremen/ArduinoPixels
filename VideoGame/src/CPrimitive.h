/*
file:			CPrimitive.cpp
description:	base class for game primitives.
author:			matthias
*/

#ifndef CPRIMITVE_H
#define CPRIMITVE_H

#include "common.h"
#include "CGameEngine.h"
#include "..\..\VideoGameLibs\lodepng\lodepng.h"
#include "..\..\VideoGamePngConverter\src\png_converted.h"

typedef enum PRIMITIVE_TYPE {RECTANGLE, CIRCLE, SPRITE} PRIMITIVE;

/* types of primitives */
class CPrimitive
{
    private:

	protected:
		
		// postion and dimension
		int posx;
		int posy;
		unsigned w;
		unsigned h;

		bool bshow;

		int index_sprite;

		// TODO: add layer?

    public:

		CPrimitive();
		~CPrimitive();

		int getPosx();
		int getPosy();
		int getw();
		int geth();

		void setPos(int x, int y);
		void setPosX(int x);
		void setPosY(int y);

		void show();
		void hide();

		void render(CGameEngine* engine);
};

#endif
