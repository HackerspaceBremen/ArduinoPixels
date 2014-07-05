/*
file:			CGameEngine.cpp
description:	-
author:			matthias
*/

#include "CGameEngine.h"

CGameEngine::CGameEngine()
{
	renderer = new CRenderer();
	input = new CInput();
	sound = new CSound();

	renderer->setup();
}

CGameEngine::~CGameEngine()
{
	delete renderer;
	delete input;
	delete sound;
}

void CGameEngine::setPixel(int x, int y, int  r, int g, int  b, int a)
{
	renderer->setPixel(x, y, r, g, b, a);
}

void CGameEngine::draw()
{
	// call pixel renderer
	renderer->draw();	
}
