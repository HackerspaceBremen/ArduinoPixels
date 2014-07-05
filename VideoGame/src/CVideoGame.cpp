/*
file:			CVideoGame.cpp
description:	-
author:			matthias
*/

#include "CVideoGame.h"

// set define PNG_HACK to use compiled pngs
#define PNG_HACK

CVideoGame::CVideoGame(void)
{

#ifdef PNG_HACK
	// first call goes to png initialization
	init_png_array();
#endif

	// create  engine
	engine = new CGameEngine();
	// create menu and set the engine
	menu = new CGameMenu(engine);

	lock = false;
}

CVideoGame::~CVideoGame(void)
{
	//
}

bool CVideoGame::invasion_active(PixelMain** pPixelMain)
{
	return invasion->isActive(pPixelMain);
}

void CVideoGame::setup()
{
	// create games
	invasion = new CGameInvasion(engine);
	pong = new CGamePong(engine);
	
	// register games
	menu->registerGame(invasion);
	invasion->setSplash("../../assets/TextInvasion.png");
	menu->registerGame(pong);
	pong->setSplash("../assets/splash_pong.png");
}

void CVideoGame::update(float timeElapsed)
{
	// delagte call to game menu
	menu->update(timeElapsed);
}

void CVideoGame::draw()
{
	lock = true;

#ifdef _WINDOWS
	gl::clear(Color( 255, 255, 255));
#endif

	// call draw function from game engine
	engine->draw();

	lock = false;
}

void CVideoGame::setInput(int key)
{
	PixelMain* ppixelMain;
	// check if Invasion is active
	if(invasion->isActive(&ppixelMain))
	{
		// for invasion game key events have to be send directly
		invasion->setInput(key);

		// also set in engine to get out of game
		engine->input->setInput(key);
	}
	else
	{
		// getting key codes and send to engine
		engine->input->setInput(key);
	}
}


