/*
file:			CGameInvasion.cpp
description:	-
author:			matthias
*/

#include "CGameInvasion.h"

CGameInvasion::CGameInvasion(CGameEngine* pengine) : CGame(pengine)
{
	// create a new invasion
	invasion = new PixelMain();
	renderer = pengine->renderer->getRenderer();
}

CGameInvasion::~CGameInvasion()
{
	delete invasion;
}

bool CGameInvasion::isActive(PixelMain** ppPixelMain)
{
	*ppPixelMain = invasion;
	return is_active;
}

void CGameInvasion::setup(void)
{
	// set the renderer
	invasion->setup(renderer);
	is_active = true;
}

void CGameInvasion::loop(float delta_time)
{
	// update
	invasion->update(delta_time);

	// draw it all
	invasion->draw();

	// clear key events
	engine->input->clearEvents();
}

void CGameInvasion::shutdown(void)
{
	// unset active flag
	is_active = false;
}

void CGameInvasion::setInput(int key)
{
	invasion->setInput(key);
}

