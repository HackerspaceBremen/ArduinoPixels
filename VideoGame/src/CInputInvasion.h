/*
file:			CInputInvasion.h
description:	Input code taken from original emulator and wrapped into a class.
author:			matthias
*/

#ifndef CINPUTINVASION_H
#define CINPUTINVASION_H

#include "cinder/app/AppBasic.h"
#include "../../libraries/PixelShared/PixelMain.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CInputInvasion
{

public:

    void keyDown(KeyEvent event, PixelMain* pPixelMain, bool lock);
    void keyUp(KeyEvent event, PixelMain* pPixelMain, bool lock);

	void setKeysL(PixelMain* pPixelMain);
	void setKeysR(PixelMain* pPixelMain);
   
    bool upL;
    bool downL;
    bool rightL;
    bool leftL;
    
    bool upR;
    bool downR;
    bool rightR;
    bool leftR;
};

#endif