/*
file:			CPrimitiveNumber.cpp
description:	-
author:			matthias
*/

#include "CPrimitiveNumber.h"

CPrimitiveNumber::CPrimitiveNumber()
{
	unsigned error = 0;

	// load all digits
#ifdef _WINDOWS
		#ifndef PNG_HACK			
			error += lodepng::decode(image[0], w, h, "../assets/num0.png");
			error += lodepng::decode(image[1], w, h, "../assets/num1.png");
			error += lodepng::decode(image[2], w, h, "../assets/num2.png");
			error += lodepng::decode(image[3], w, h, "../assets/num3.png");
			error += lodepng::decode(image[4], w, h, "../assets/num4.png");
			error += lodepng::decode(image[5], w, h, "../assets/num5.png");
			error += lodepng::decode(image[6], w, h, "../assets/num6.png");
			error += lodepng::decode(image[7], w, h, "../assets/num7.png");
			error += lodepng::decode(image[8], w, h, "../assets/num8.png");
			error += lodepng::decode(image[9], w, h, "../assets/num9.png");
		#else
			error += get_png(&image[0], &w, &h, "../assets/num0.png");
			error += get_png(&image[1], &w, &h, "../assets/num1.png");
			error += get_png(&image[2], &w, &h, "../assets/num1.png");
			error += get_png(&image[3], &w, &h, "../assets/num1.png");
			error += get_png(&image[4], &w, &h, "../assets/num1.png");
			error += get_png(&image[5], &w, &h, "../assets/num1.png");
			error += get_png(&image[6], &w, &h, "../assets/num1.png");
			error += get_png(&image[7], &w, &h, "../assets/num1.png");
			error += get_png(&image[8], &w, &h, "../assets/num1.png");
			error += get_png(&image[9], &w, &h, "../assets/num1.png");
		#endif
#else
		#ifndef PNG_HACK
			// TODO: place here code for SD lib call
		#else
			error += get_png(&image[0], &w, &h, "../assets/num0.png");
			error += get_png(&image[1], &w, &h, "../assets/num1.png");
			error += get_png(&image[2], &w, &h, "../assets/num1.png");
			error += get_png(&image[3], &w, &h, "../assets/num1.png");
			error += get_png(&image[4], &w, &h, "../assets/num1.png");
			error += get_png(&image[5], &w, &h, "../assets/num1.png");
			error += get_png(&image[6], &w, &h, "../assets/num1.png");
			error += get_png(&image[7], &w, &h, "../assets/num1.png");
			error += get_png(&image[8], &w, &h, "../assets/num1.png");
			error += get_png(&image[9], &w, &h, "../assets/num1.png");
		#endif
#endif

	if(error > 0)
	{
		// somthing went wrong
	}
}

CPrimitiveNumber::~CPrimitiveNumber()
{
	//
}

void CPrimitiveNumber::render(CGameEngine* engine, int number)
{	
	if(bshow)
	{
		for(int i = 0; i < w; i++)
		{
			for(int k = 0; k < h; k++)
			{
				int index = (k * w + i) * 4;
				// format RGBA
				engine->setPixel(posx + i, posy + k, 
									image[number][index], 
									image[number][index + 1 ], 
									image[number][index + 2], 
									image[number][index + 3]);
			}
		}
	}
}
