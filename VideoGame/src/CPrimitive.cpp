/*
file:			CPrimitive.h
description:	-
author:			matthias
*/

#include "CPrimitive.h"

CPrimitive::CPrimitive()
{
	posx = 0;
	posy = 0;

	bshow = true;

	index_sprite = 0;
}

CPrimitive::~CPrimitive()
{
	//
}

int CPrimitive::getPosx()
{
	return posx;
}

int CPrimitive::getPosy()
{
	return posy;
}

int CPrimitive::getw()
{
	return w;
}

int CPrimitive::geth()
{
	return h;
}

void CPrimitive::setPos(int x, int y)
{
	posx = x;
	posy = y;
}

void CPrimitive::setPosX(int x)
{
	posx = x;
}

void CPrimitive::setPosY(int y)
{
	posy = y;
}

void CPrimitive::show()
{
	bshow = true;
}

void CPrimitive::hide()
{
	bshow = false;
}

