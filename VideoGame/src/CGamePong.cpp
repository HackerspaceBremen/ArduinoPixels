/*
file:			CGamePong.cpp
description:	-
author:			matthias
*/

#include "CGamePong.h"

CGamePong::CGamePong(CGameEngine* pengine) : CGame(pengine)
{
	posx = 45.0;
	posy = 7.0;
	l_paddle = 4;			// length of paddle
	score_winning = 3;		// winning score
	t_show_score = 10;		// time to show winning score

	state = WAITING;		

	setBallSpeeds();
}

CGamePong::~CGamePong()
{
	delete paddle1;
	delete paddle2;
	delete ball;
	delete net1;
	delete net2;
	delete net3;
	delete net4;
	delete score1;
	delete score2;
}

void CGamePong::setBallSpeeds(void)
{
	vx = 1.0 + (rand() % 2000) / 1000;			// 1.0 - 3.0
	vy = 0.5 + (rand() % 500) / 1000;			// 0.5 - 1.0

	// swap speeds
	if(rand() % 2 + 1 == 1)
	{
		vx = -vx;
	}
	if(rand() % 2 + 1 == 1)
	{
		vy = -vy;
	}
}

bool CGamePong::isActive(PixelMain** ppPixelMain)
{
	*ppPixelMain = NULL;
	return false;
}

void CGamePong::setup(void)
{
	is_active = true;

	// create game all primitives

	paddle1 = new CPrimitiveRectangle(1, l_paddle, 255, 255, 255, 255);
	paddle1->setPos(1, 3);

	paddle2 = new CPrimitiveRectangle(1, l_paddle, 255, 255, 255, 255);
	paddle2->setPos(88, 3);

	ball = new CPrimitiveRectangle(1, 1, 255, 255, 255, 255);
	ball->setPos((int)posx, (int)posy);


	net1 = new CPrimitiveRectangle(1, 3, 255, 255, 255, 255);
	net1->setPos(45, 0);
	net2 = new CPrimitiveRectangle(1, 3, 255, 255, 255, 255);
	net2->setPos(45, 4);
	net3 = new CPrimitiveRectangle(1, 3, 255, 255, 255, 255);
	net3->setPos(45, 9);
	net4 = new CPrimitiveRectangle(1, 3, 255, 255, 255, 255);
	net4->setPos(45, 13);

	score1 = new CPrimitiveNumber();
	score1->setPos(10, 3);
	score1->hide();

	score2 = new CPrimitiveNumber();
	score2->setPos(70, 3);
	score2->hide();

	// load the sounds
	/*
	engine->sound->addTrack("../assests/pong1.wav", 1);
	engine->sound->addTrack("../assests/pong2.wav", 2);
	engine->sound->addTrack("../assests/pong3.wav", 3);
	*/
}

void CGamePong::loop(float delta_time)
{
	if(state == WAITING)
	{
		// wait for button3
		if(engine->input->keyDownEvent(KEY_P1_BTN2))
		{
			state = PLAYING;
		}
		if(engine->input->keyDownEvent(KEY_P2_BTN2))
		{
			state = PLAYING;
		}

		score_p1 = 0;
		score_p2 = 0;
	}
	else if(state == PLAYING)
	{
		// player 1
		if(engine->input->keyDownEvent(KEY_P1_UP))
		{
			if(paddle1->getPosy() > 0)
			{
				paddle1->setPosY(paddle1->getPosy() - 1);
			}
		}
		if(engine->input->keyDownEvent(KEY_P1_DOWN))
		{
			if(paddle1->getPosy() + l_paddle < 16)
			{
				paddle1->setPosY(paddle1->getPosy() + 1);
			}
		}

		// player2
		if(engine->input->keyDownEvent(KEY_P2_UP))
		{
			if(paddle2->getPosy() > 0)
			{
				paddle2->setPosY(paddle2->getPosy() - 1);
			}
		}
		if(engine->input->keyDownEvent(KEY_P2_DOWN))
		{
			if(paddle2->getPosy() + l_paddle < 16)
			{
				paddle2->setPosY(paddle2->getPosy() + 1);
			}
		}

		// ball speed in pixel / seconds
		float dx = vx * delta_time;
		float dy = vy * delta_time;

		// new positions 
		posx += dx;
		posy += dy;

		// check for collision on the sides
		if((int)posy == 0 || (int)posy == 16)
		{
			vy = - vy;
		}

		bool show_score = false;

		// player1
		if((int)posx == 1)
		{
			if((int)posy < paddle1->getPosy() || (int)posy > (paddle1->getPosy() + l_paddle))
			{
				// ball lost
				posx = 45;
				posy = 7;
				show_score = true;
				score_p2++;
			}
		}

		// player2
		if((int)posx == 88)
		{
			if((int)posy < paddle2->getPosy() || (int)posy > (paddle2->getPosy() + l_paddle))
			{
				// ball lost
				posx = 45;
				posy = 7;
				show_score = true;
				score_p1++;
			}
		}

		// check for collision with side walls
		if((int)posx == 1 || (int)posx == 88)
		{
			vx = - vx;
			// add velocity
			vx *= 1.2;
		}

		// cast to int
		ball->setPos((int)posx, (int)posy);
	
		// check for score
		if(score_p1 == score_winning || score_p2 == score_winning)
		{
			state = FINISHED;
		}		

		if(show_score)
		{
			state = SHOWSCORE;

			setBallSpeeds();
		}
	}
	else if(state == SHOWSCORE)
	{
		// show score
		score1->show();
		score1->render(engine, score_p1);
		score2->show();
		score2->render(engine, score_p2);

		// get back to game
		t_show_score -= delta_time;

		if(t_show_score < 0)
		{
			score1->hide();
			score2->hide();
			t_show_score = 10;
			state = PLAYING;
		}
	}
	else if(state == FINISHED)
	{
		// show score
		score1->show();
		score1->render(engine, score_p1);
		score2->show();
		score2->render(engine, score_p2);

		// wait button 2 to start game again
		if(engine->input->keyDownEvent(KEY_P1_BTN2))
		{
			state = WAITING;
		}
	}
	else
	{
		// unknown state
	}

	// clear key events
	engine->input->clearEvents();

	// render to frame buffer
	paddle1->render(engine);
	paddle2->render(engine);
	ball->render(engine);
	net1->render(engine);
	net2->render(engine);
	net3->render(engine);
	net4->render(engine);
}

void CGamePong::setInput(int key)
{
	// nothing to do, because never called
}

void CGamePong::shutdown(void)
{
	// clean up everything
	delete paddle1;
	delete paddle2;
	delete ball;
	delete net1;
	delete net2;
	delete net3;
	delete net4;
	delete score1;
	delete score2;

	is_active = false;
}

