/*
file:			CGameEngine.cpp
description:	The game engine with renderer, input handler and sound engine
author:			matthias
*/

#ifndef CGAMEENGINE_H
#define CGAMEENGINE_H

#include <vector>        // c++ vector type is used
#include "common.h"

#include "CRenderer.h"
#include "CInput.h"
#include "CSound.h"

#ifdef _WINDOWS
#include "cinder/Color.h"
#include "cinder/gl/gl.h"
#endif

/*
TODO

arduino uno specs
* 84 MHz
* RAM?
* ROM?

* frame buffers
* get_delta_time
* CRenderer, CGameEninge ... review
* load static png
* load animated png
* draw_primitive
* draw_sprite
*/

class CGameEngine
{
    private:


	public:

		CRenderer* renderer;
		CInput* input;
		CSound* sound;

		CGameEngine();
		~CGameEngine();

		// functions called from games
		void setup();
		void draw();
		void update();
		void setInput();
 
		/* 
		state of joysticks and buttons
		*/
		uint16 stick1;
		uint16 stick2;
		uint16 buttons1;
		uint16 buttons2;
          
    
		void get_stick_state();
		void get_button_state();
    
		void register_game();
		void register_renderer();

		void setPixel(int x, int y, int  r, int g, int  b, int a);

		// draw calls PixelRenderer
		//void draw();

		/*
		list of primitives, this can be pngs, or boxes
		*/
    
		/*
		fixed frame rate 30 or 60 fps
		will always return
		*/
		void get_delta_time();
};

#endif