/*
file:			CPrimitiveSprite.cpp
description:	-
author:			matthias
*/

#include "CPrimitiveSprite.h"

// set define PNG_HACK to use compiled pngs
#define PNG_HACK

CPrimitiveSprite::CPrimitiveSprite(string sprite_path)
{
		state = 0;
		dx = 0;

		// make decisions for windows / arduino code
#ifdef _WINDOWS
		#ifndef PNG_HACK
			unsigned error = lodepng::decode(image[0], w, h, sprite_path);
		#else
			int error = get_png(&image[0], &w, &h, sprite_path);
		#endif
#else
		#ifndef PNG_HACK
			// TODO: place here code for SD lib call
		#else
			get_png(&image[0], &w, &h, sprite_path);
		#endif
#endif

		index_sprite = 0;
}

void CPrimitiveSprite::addSprite(string sprite_path)
{
	#ifndef PNG_HACK
		unsigned error = lodepng::decode(image[1], w, h, sprite_path);
	#else
		get_png(&image[1], &w, &h, sprite_path);
	#endif
}

void CPrimitiveSprite::setSprite(int i)
{
	index_sprite = i;
}

CPrimitiveSprite::~CPrimitiveSprite()
{
	//
}

void CPrimitiveSprite::setAnimation(int delta_x)
{
	dx = delta_x;
}

void CPrimitiveSprite::animate()
{
	if(state == 0)
	{
		posx += dx;
		state++;
	}
	else if(state == 1)
	{
		posx -= dx;
		state++;
	}

	if(state >= 2)
	{
		state = 0;
	}
}

void CPrimitiveSprite::render(CGameEngine* engine)
{
	if(bshow)
	{
		for(int i = 0; i < w; i++)
		{
			for(int k = 0; k < h; k++)
			{
				int index = (k * w + i) * 4;
				engine->setPixel(posx + i, posy + k, 
					image[index_sprite][index], 
					image[index_sprite][index + 1 ], 
					image[index_sprite][index + 2], 
					image[index_sprite][index + 3]);
			}
		}
	}
}
