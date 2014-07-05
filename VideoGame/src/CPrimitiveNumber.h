/*
file:			CPrimitiveNumber.h
description:	-
author:			matthias
*/

#ifndef CPRIMITIVENUMBER_H
#define CPRIMITIVENUMBER_H

#include "CPrimitive.h"

class CPrimitiveNumber : public CPrimitive
{
	private:

		// current animation state
		int state;
		int dx;

		unsigned char r;
		unsigned char g;
		unsigned char b;
		unsigned char a;

		vector<unsigned char> image[10];	

	public:

		CPrimitiveNumber();
		~CPrimitiveNumber();

		void render(CGameEngine* engine, int number);
};

#endif