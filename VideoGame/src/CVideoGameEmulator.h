/*
file:			CVideoGameEmulator.h
description:	Emulator stimulating VideoGame instance
author:			matthias
*/

#ifndef CVIDEOGAMEEMULATOR_H
#define CVIDEOGAMEEMULATOR_H

#ifdef _WINDOWS
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "CVideoGame.h"
#include "CGameEngine.h"
#include "CGameMenu.h"
#include "CGamePong.h"
#include "CInputInvasion.h"
#include "../../libraries/PixelShared/PixelMain.h"
#include <string>

using namespace ci;
using namespace ci::app;
using namespace std;

class CVideoGameEmulator : public AppBasic 
{

private:

	// main video game instance stimulated by emulator
	CVideoGame* videogame;

	// timing and locking variables
	double previousTime;
	bool lock;

	int offset;

	vector<CKeycode> keys;

	// pointer to invasion game
	PixelMain* ppixelMain;
	CInputInvasion* input_invasion;

public:

	CVideoGameEmulator();
	~CVideoGameEmulator();

	void setup();
	void setInput(int key);
	void update(float timeElapsed);
	void draw();

	void mouseDown( MouseEvent event );
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);

	void setPixelMain(PixelMain* pgame);
};

#endif
#endif