/*
file:			CInput.cpp
description:	-
author:			matthias
*/

#include "CInput.h"

CInput::CInput()
{
	keys.clear();

	// player1 controls
	keys.push_back(CKeycode("W", KEY_P1_UP));
	keys.push_back(CKeycode("S", KEY_P1_DOWN));
	keys.push_back(CKeycode("A", KEY_P1_LEFT));
	keys.push_back(CKeycode("D", KEY_P1_RIGHT));

	keys.push_back(CKeycode("H", KEY_P1_BTN1));
	keys.push_back(CKeycode("J", KEY_P1_BTN2));
	keys.push_back(CKeycode("K", KEY_P1_BTN3));

	// player2 controls
	keys.push_back(CKeycode("UP", KEY_P2_UP));
	keys.push_back(CKeycode("DOWN", KEY_P2_DOWN));
	keys.push_back(CKeycode("LEFT", KEY_P2_LEFT));
	keys.push_back(CKeycode("RIGHT", KEY_P2_RIGHT));

	keys.push_back(CKeycode("KP1", KEY_P2_BTN1));
	keys.push_back(CKeycode("KP2", KEY_P2_BTN2));
	keys.push_back(CKeycode("KP3", KEY_P2_BTN3));

	clearEvents();
}

CInput::~CInput()
{
	//
}

void CInput::setInput(int key)
{
	// iterate over list with key codes
	// much nicer code than long if statements
	for(int i = 0; i < keys.size(); i++)
	{
		if(keys[i].code == key /*&& keys[i].event != KEY_DOWN_EVENT*/)
		{
			// set key down event
			keys[i].event = KEY_DOWN_EVENT;
		}
		/*
		if(keys[i].code == key && keys[i].event != KEY_UP_EVENT)
		{
			// set key up event
			keys[i].event = KEY_UP_EVENT;
		}
		*/
	}

}

void CInput::clearEvents()
{
	// clear all events
	for(int i = 0; i < keys.size(); i++)
	{
		keys[i].event = KEY_NO_EVENT;
	}
}

bool CInput::keyDownEvent(int key_code)
{
	for(int i = 0; i < keys.size(); i++)
	{
		if(keys[i].code == key_code && keys[i].event == KEY_DOWN_EVENT)
		{
			return true;
		}
	}

	// fallback if key code is unknown
	return false;

}

bool CInput::keyUpEvent(int key_code)
{
	for(int i = 0; i < keys.size(); i++)
	{
		if(keys[i].code == key_code && keys[i].event == KEY_UP_EVENT)
		{
			return true;
		}
	}

	// fallback if key code is unknown
	return false;
}