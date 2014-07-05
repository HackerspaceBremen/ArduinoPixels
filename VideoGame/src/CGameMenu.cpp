/*
file:			CGameMenu.cpp
description:	-
author:			matthias
*/

#include "CGameMenu.h"

CGameMenu::CGameMenu(CGameEngine* pengine)
{
	state = BOOT_SCREEN;

	state_exit = WAIT;

	selected_game = 0;

	delta_time = 0;

	exit_game = false;

	t_button_leave = 2.0;
	t_leave = t_button_leave;

	t_boot_time = 10.0;

	games.clear();

	engine = pengine;

	step = false;

	// load arrows
	arrow_left = new CPrimitiveSprite("../assets/arrow_left.png");
	arrow_right = new CPrimitiveSprite("../assets/arrow_right.png");

	arrow_left->setPos(2, 3);
	arrow_right->setPos(76, 3);

	arrow_left->setAnimation(-1);
	arrow_right->setAnimation(1);
	
	arrow_left->addSprite("../assets/arrow_left_active.png");
	arrow_right->addSprite("../assets/arrow_right_active.png");

	arrow_right->setSprite(1);
	arrow_left->hide();
	
	background = new CPrimitiveRectangle(90, 16, 0, 0, 0, 255);

	bootscreen = new CPrimitiveSprite("../assets/bootscreen.png");
}

CGameMenu::~CGameMenu()
{
	//
	delete arrow_left;
	delete arrow_right;
}

void CGameMenu::registerGame(CGame* game)
{
	// add to list of games
	games.push_back(game);
}

void CGameMenu::update(float timeElapsed)
{
	// update state of gamemenu or game
	delta_time += timeElapsed;

	// for 20 fps are 50 ms
	if(delta_time > 0.250)
	{
		step = true;
		delta_time = 0;
	}
	else
	{
		step = false;
	}

	if(step)
	{
		arrow_left->animate();
		arrow_right->animate();
	}

	arrow_left->setSprite(0);
	arrow_right->setSprite(0);

	// check for key press
	if(state == BOOT_SCREEN)
	{
		t_boot_time -= delta_time;

		if(t_boot_time < 0)
		{
			// change into menu
			t_boot_time = 2.0;
			state = SHOW_MENU;
		}
	}
	if(state == SHOW_MENU)
	{
		if(engine->input->keyDownEvent(KEY_P1_RIGHT) && (selected_game < games.size() - 1))
		{
			selected_game++;
		}
		if(engine->input->keyDownEvent(KEY_P1_LEFT) && (selected_game > 0))
		{
			selected_game--;
		}

		if(engine->input->keyDownEvent(KEY_P1_BTN1))
		{
			// go into into game state
			state = IN_GAME;
			startGame();
		}

		// set arrow state
		if(selected_game == 0)
		{
			arrow_left->hide();
			arrow_right->show();
		}

		if(selected_game == games.size() - 1)
		{
			arrow_left->show();
			arrow_right->hide();
		}

		if((selected_game > 0)  && (selected_game < games.size() - 1))
		{
			arrow_left->show();
			arrow_right->show();
		}

		// clear all key events
		engine->input->clearEvents();
	}
	else
	{
		// check for shutdown
		checkForExit(timeElapsed);
		if(exit_game)
		{
			stopGame();

			// reset state
			state = SHOW_MENU;
		}
	}

	// draw, actually more writeToFrameBuffers()
	draw();
}

void CGameMenu::draw()
{
	background->render(engine);

	// TODO: integrate boot screen
	if(state == BOOT_SCREEN)
	{
		bootscreen->render(engine);
	}
	else if(state == SHOW_MENU)
	{
		// draw game menu
		games[selected_game]->renderSplash(engine);

		arrow_left->render(engine);
		arrow_right->render(engine);
		
		// animation
	}
	else if(state == IN_GAME)
	{
		// call game loop from current game
		games[selected_game]->loop(delta_time);
	}
	else
	{
		// unknown state, better never get here
	}
}

void CGameMenu::checkForExit(float delta_time)
{
	if(state_exit == WAIT)
	{
		exit_game = false;
		t_leave = t_button_leave;

		// check for key down
		if(engine->input->keyDownEvent(KEY_P1_BTN3))
		{
			state_exit = COUNT;
		}
	}
	else if(state_exit == COUNT)
	{
		// if key up change back to wait
		if(engine->input->keyUpEvent(KEY_P1_BTN3))
		{
			state_exit = WAIT;
		}

		// count down
		t_leave -= delta_time;

		// check for time < 0s
		if(t_leave < 0)
		{
			state_exit = FINISH;
		}
	}
	else if(state_exit == FINISH)
	{
		// set game exit
		exit_game = true;

		state_exit = WAIT;
	}
	else
	{
		// unknown state
	}
}

void CGameMenu::startGame()
{
	// setup game instance
	games[selected_game]->setup();	
}

void CGameMenu::stopGame()
{
	// shutdown game instance
	games[selected_game]->shutdown();
}
