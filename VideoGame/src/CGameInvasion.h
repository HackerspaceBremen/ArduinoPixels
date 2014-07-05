/*
file:			CGameInvasion.h
description:	Original invasion game wrapped in a CGame class.
author:			matthias
*/

#ifndef CGAMEINVASION_H
#define CGAMEINVASION_H

#include "CGame.h"
#include "CPrimitive.h"
#include "CPrimitiveRectangle.h"
#include "CPrimitiveSprite.h"
#include "CPrimitiveNumber.h"
#include "CInput.h"
#include "CGameEngine.h"
#include "../../libraries/PixelShared/PixelMain.h"

class CGameInvasion: public CGame
{
private:

		PixelMain* invasion;
		PixelRenderer* renderer;

public:

		virtual bool isActive(PixelMain** ppPixelMain);

		CGameInvasion(CGameEngine* pengine);
		~CGameInvasion();

		void setup(void);
		void loop(float delta_time);
		void shutdown(void);
		void setInput(int key);
};

#endif