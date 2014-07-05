/*
file:			CGamePong.h
description:	Pong game
author:			matthias
*/

#ifndef CGAMEPONG_H
#define CGAMEPONG_H

#include "CGame.h"
#include "CPrimitive.h"
#include "CPrimitiveRectangle.h"
#include "CPrimitiveSprite.h"
#include "CPrimitiveNumber.h"
#include "CInput.h"
#include <stdlib.h>

typedef enum TYPE_PONG_STATE 
{
	WAITING,
	PLAYING,
	SHOWSCORE,
	FINISHED
} PONG_STATE;

class CGamePong: public CGame
{

private:
	// paddles
	CPrimitiveRectangle* paddle1;
	CPrimitiveRectangle* paddle2;

	// ball
	CPrimitiveRectangle* ball;

	// net
	CPrimitiveRectangle* net1;
	CPrimitiveRectangle* net2;
	CPrimitiveRectangle* net3;
	CPrimitiveRectangle* net4;
	CPrimitiveRectangle* net5;

	CPrimitiveNumber* score1;
	CPrimitiveNumber* score2;

	float posx;
	float posy;

	float vx;
	float vy;

	int l_paddle;

	int score_p1;
	int score_p2;

	int score_winning;

	float t_show_score;

	PONG_STATE state;

public:

	CGamePong(CGameEngine* pengine);
	~CGamePong();

	virtual bool isActive(PixelMain** ppPixelMain);

	void setBallSpeeds(void);

	void setup(void);
	void loop(float delta_time);
	void shutdown(void);


	void setInput(int key);
};

#endif