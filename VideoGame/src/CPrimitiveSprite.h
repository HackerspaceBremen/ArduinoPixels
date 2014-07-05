/*
file:			CPrimitiveSprite.h
description:	Sprite
author:			matthias
*/

#ifndef CPRIMITIVESPRITE_H
#define CPRIMITIVESPRITE_H

#include "CPrimitive.h"
#include "CGameEngine.h"
#include "common.h"

using namespace std;

class CPrimitiveSprite : public CPrimitive
{
	private:

		// raw pixels
		vector<unsigned char> image[3];	

		// current animation state
		int state;
		int dx;

	public:

		CPrimitiveSprite(string sprite_path);
		~CPrimitiveSprite();

		void addSprite(string sprite_path);
		void setSprite(int i);

		void setAnimation(int delta_x);
		void animate();

		void render(CGameEngine* engine);
};

#endif