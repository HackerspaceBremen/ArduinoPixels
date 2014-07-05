/*
file:			CGame.h
description:	abstract base class for games.
author:			matthias
*/

#ifndef CGAME_H
#define CGAME_H

#include "common.h"
#include "CPrimitive.h"
#include "CPrimitiveSprite.h"
#include "CGameEngine.h"
#include "PixelRenderer.h"
#include "..\PixelShared\PixelMain.h"
#include "..\..\VideoGameLibs\lodepng\lodepng.h"

class CGame
{
private:

    vector<CPrimitive> primitives;

	std::string path_splash; 
	CPrimitiveSprite* splash;

protected:

		CGameEngine* engine;
		bool is_active;

public:

		CGame(CGameEngine* pengine);
		~CGame();

		virtual void setup() = 0;
		virtual void loop(float delta_time) = 0;
		virtual void shutdown() = 0;

		// only necassary for Invasion, does nothing in other games
		virtual void setInput(int key) = 0;

		virtual bool isActive(PixelMain** ppPixelMain) = 0;

		void setSplash(string path_splash);
		void renderSplash(CGameEngine* engine);
		void setSplashPos(int posx);

		bool checkForExit(float delta_time);
		void setupRenderer(PixelRenderer* prenderer);
};

#endif