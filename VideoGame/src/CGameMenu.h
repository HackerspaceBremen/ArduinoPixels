/*
file:			CGameMenu.h
description:	
author:			matthias
*/
#ifndef CGAMEMENU_H
#define CGAMEMENU_H


#include "common.h"
#include "CGameEngine.h"
#include "CGame.h"
#include "CSprite.h"
#include "CPrimitive.h"
#include "CPrimitiveSprite.h"
#include "CPrimitiveRectangle.h"
#include "CGamePong.h"
#include "CInput.h"

#ifdef _WINDOWS
#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;
#endif

typedef enum TYPE_STATE_EXIT {WAIT, COUNT, FINISH} STATE_EXIT;

typedef enum TYPE_STATE_GAMEMENU 
{
	BOOT_SCREEN,
	SHOW_MENU,
	IN_GAME
} STATE_GAMEMENU;

class CGameMenu
{
private:

		float delta_time;
		float t_button_leave;
		float t_leave;
		float t_boot_time;

		int state;

		int selected_game;

		bool exit_game;

		bool step;

		CGameEngine* engine;

		STATE_EXIT state_exit;

		vector<CGame*> games;

		CPrimitiveSprite* arrow_left;
		CPrimitiveSprite* arrow_right;

		CPrimitiveSprite* bootscreen;

		CPrimitiveRectangle* background;

public:

		CGameMenu(CGameEngine* engine);
		~CGameMenu();

		void registerGame(CGame* game);
		void startGame();
		void stopGame();

		void update(float timeElapsed);
		void draw();

		void checkForExit(float delta_time);
};

#endif