/*
file:			CVideoGame.h
description:	Top level class containing engine, menu and game instances.
author:			matthias
*/

#ifndef CVIDEOGAME_H
#define CVIDEOGAME_H

// only include for windows compilation
#ifdef _WINDOWS
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;
#endif

#include "CGameEngine.h"
#include "CGameMenu.h"
#include "CGamePong.h"
#include "CGamePacman.h"
#include "CGameInvasion.h"
#include "CInputInvasion.h"

class CVideoGame
{

private:
	
	CGameEngine* engine;
	CGameMenu* menu;
	
	// games
	CGame* invasion;
	CGame* pong;

	bool lock;

public:

	CVideoGame();
	~CVideoGame();

	bool invasion_active(PixelMain** pPixelMain);

	void setBrightness(int brightness);

	// functions called directly from arduino sketch
	void setup();
	void setInput(int key);
	void update(float timeElapsed);
	void draw();

	// debug, necessary?
	void setSerialArduinoConsole();
	void print_debug();
};

#endif
