/*
file:			CGame.pp
description:	-
author:			matthias
*/

#include "CGame.h"

CGame::CGame(CGameEngine* pengine)
{
	engine = pengine;
	is_active = false;
}

CGame::~CGame()
{
	//
}

void CGame::setSplash(string path_splash)
{
	splash = new CPrimitiveSprite(path_splash);

	// center horizomtal and vertical
	splash->setPosX((90 - splash->getw()) / 2);
	splash->setPosY((16 - splash->geth()) / 2);
}

void CGame::setSplashPos(int posx)
{
	splash->setPosX(posx);
}

void CGame::renderSplash(CGameEngine* engine)
{
	splash->render(engine);
}