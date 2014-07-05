/*
file:			CVideoGameEmulator.cpp
description:	-
author:			matthias
*/

#include "CVideoGameEmulator.h"

#ifdef _WINDOWS

CVideoGameEmulator::CVideoGameEmulator(void)
{
	videogame = new CVideoGame();

	offset = 0;
	//lock = false;

	ppixelMain = NULL;

	input_invasion = new CInputInvasion();
}

CVideoGameEmulator::~CVideoGameEmulator(void)
{
	delete videogame;
}

void CVideoGameEmulator::setup()
{
	setWindowSize(90 * 13 + 20, 16 * 13 + 20);
	videogame->setup();
	previousTime = ci::app::getElapsedSeconds();
    gl::disableVerticalSync();
	lock =true;     
}

void CVideoGameEmulator::update(float timeElapsed)
{
	videogame->update(timeElapsed);
}

void CVideoGameEmulator::draw()
{
	lock = true;

	double currentTime = ci::app::getElapsedSeconds();
	update(currentTime - previousTime);
    previousTime = currentTime;

	videogame->draw();

	lock = false;
}

void CVideoGameEmulator::mouseDown(MouseEvent event)
{
	// no mouse events
}

//
void CVideoGameEmulator::keyDown(KeyEvent event)
{
	if(lock)
	{
		return;
	}
	else
	{
		// check for invasion active and set pointer to pixelMain
		if(videogame->invasion_active(&ppixelMain))
		{
			// pass call along
			input_invasion->keyDown(event, ppixelMain, lock);

			videogame->setInput(event.getCode());
		}
		else
		{
			// send key code to input handler of  engine
			videogame->setInput(event.getCode());
		}
	}    
}

void CVideoGameEmulator::keyUp(KeyEvent event)
{
	// check for invasion active
	if(videogame->invasion_active(&ppixelMain))
	{
		// pass call along
		input_invasion->keyUp(event, ppixelMain, lock);
	}
}

void CVideoGameEmulator::setPixelMain(PixelMain* pgame)
{
	ppixelMain = pgame;
}

// create cinder application
CINDER_APP_BASIC(CVideoGameEmulator, RendererGl)

#endif

