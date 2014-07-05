/*
file:			CInput.h
description:	Input handler
author:			matthias
*/

#ifndef CINPUT_H
#define CINPUT_H

#include <string>
#include <vector>

// cinder key codes
using namespace std;

// defines for keycodes (from cinder)
#define KEY_P1_UP			119			// W
#define KEY_P1_DOWN			115			// S
#define KEY_P1_LEFT			97			// A
#define KEY_P1_RIGHT		100			// D

#define KEY_P1_BTN1			104			// H
#define KEY_P1_BTN2			106			// J
#define KEY_P1_BTN3			107			// K

#define KEY_P2_UP			273			// UP
#define KEY_P2_DOWN			274			// DOWN
#define KEY_P2_LEFT			276			// LEFT
#define KEY_P2_RIGHT		275			// RIGHT

#define KEY_P2_BTN1			279			// KP 1
#define KEY_P2_BTN2			274			// KP 2
#define KEY_P2_BTN3			281			// KP 3

typedef enum TYPE_BUTTON_EVENT
{
	KEY_NO_EVENT,
	KEY_DOWN_EVENT,
	KEY_UP_EVENT
} BUTTON_EVENT;

typedef struct TYPE_BUTTON_SET
{
	BUTTON_EVENT LEFT;
	BUTTON_EVENT RIGHT;
	BUTTON_EVENT UP;
	BUTTON_EVENT DOWN;

	BUTTON_EVENT BTN1;
	BUTTON_EVENT BTN2;
	BUTTON_EVENT BTN3;
} BUTTON_SET;

class CKeycode 
{
	public:
		
		string name;
		int	code;
		BUTTON_EVENT event;

		CKeycode(string str, int key)
		{
			name = str;
			code = key;
		}

		~CKeycode()
		{

		}
};

class CInput
{
	private:

		BUTTON_SET player1;
		BUTTON_SET player2;

	protected:

		vector<CKeycode> keys;

	public:

		CInput();
		~CInput();

		vector<CKeycode>* getKeyCodes(void);

		void setInput(int key);

		void clearEvents();

		bool keyDownEvent(int key_code);
		bool keyUpEvent(int key_code);
};

/*

key codes:

KEY_UNKNOWN 	
KEY_FIRST 	
KEY_BACKSPACE 	
KEY_TAB 	
KEY_CLEAR 	
KEY_RETURN 	
KEY_PAUSE 	
KEY_ESCAPE 	
KEY_SPACE 	
KEY_EXCLAIM 	
KEY_QUOTEDBL 	
KEY_HASH 	
KEY_DOLLAR 	
KEY_AMPERSAND 	
KEY_QUOTE 	
KEY_LEFTPAREN 	
KEY_RIGHTPAREN 	
KEY_ASTERISK 	
KEY_PLUS 	
KEY_COMMA 	
KEY_MINUS 	
KEY_PERIOD 	
KEY_SLASH 	
KEY_0 	
KEY_1 	
KEY_2 	
KEY_3 	
KEY_4 	
KEY_5 	
KEY_6 	
KEY_7 	
KEY_8 	
KEY_9 	
KEY_COLON 	
KEY_SEMICOLON 	
KEY_LESS 	
KEY_EQUALS 	
KEY_GREATER 	
KEY_QUESTION 	
KEY_AT 	
KEY_LEFTBRACKET 	
KEY_BACKSLASH 	
KEY_RIGHTBRACKET 	
KEY_CARET 	
KEY_UNDERSCORE 	
KEY_BACKQUOTE 	
KEY_a 	
KEY_b 	
KEY_c 	
KEY_d 	
KEY_e 	
KEY_f 	
KEY_g 	
KEY_h 	
KEY_i 	
KEY_j 	
KEY_k 	
KEY_l 	
KEY_m 	
KEY_n 	
KEY_o 	
KEY_p 	
KEY_q 	
KEY_r 	
KEY_s 	
KEY_t 	
KEY_u 	
KEY_v 	
KEY_w 	
KEY_x 	
KEY_y 	
KEY_z 	
KEY_DELETE 	
KEY_KP0 	
KEY_KP1 	
KEY_KP2 	
KEY_KP3 	
KEY_KP4 	
KEY_KP5 	
KEY_KP6 	
KEY_KP7 	
KEY_KP8 	
KEY_KP9 	
KEY_KP_PERIOD 	
KEY_KP_DIVIDE 	
KEY_KP_MULTIPLY 	
KEY_KP_MINUS 	
KEY_KP_PLUS 	
KEY_KP_ENTER 	
KEY_KP_EQUALS 	
KEY_UP 	
KEY_DOWN 	
KEY_RIGHT 	
KEY_LEFT 	
KEY_INSERT 	
KEY_HOME 	
KEY_END 	
KEY_PAGEUP 	
KEY_PAGEDOWN 	
KEY_F1 	
KEY_F2 	
KEY_F3 	
KEY_F4 	
KEY_F5 	
KEY_F6 	
KEY_F7 	
KEY_F8 	
KEY_F9 	
KEY_F10 	
KEY_F11 	
KEY_F12 	
KEY_F13 	
KEY_F14 	
KEY_F15 	
KEY_NUMLOCK 	
KEY_CAPSLOCK 	
KEY_SCROLLOCK 	
KEY_RSHIFT 	
KEY_LSHIFT 	
KEY_RCTRL 	
KEY_LCTRL 	
KEY_RALT 	
KEY_LALT 	
KEY_RMETA 	
KEY_LMETA 	
KEY_LSUPER 	
KEY_RSUPER 	
KEY_MODE 	
KEY_COMPOSE 	
KEY_HELP 	
KEY_PRINT 	
KEY_SYSREQ 	
KEY_BREAK 	
KEY_MENU 	
KEY_POWER 	
KEY_EURO 	
KEY_UNDO 	
KEY_LAST 
*/

#endif