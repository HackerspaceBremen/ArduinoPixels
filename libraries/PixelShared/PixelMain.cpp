//
//  PixelMain.cpp
//  PixelGame
//
//  Created by Kris Temmerman on 15/09/13.
//  Copyright (c) 2013 Kris Temmerman. All rights reserved.
//

#include "PixelMain.h"


PixelMain::PixelMain(PixelRenderer *renderer)
{
	this->renderer = renderer;
    brightness = 180;
    initGame();
}
void PixelMain::setGameState(int state)
{
    switch (state)
    {
    case STATE_INTRO:
        allocIntro();
        resetIntro();
        stageIntro.fy =0;
        break;

    case STATE_INTRO_TO_MENU:
        switchTime =1;
        break;

    case STATE_MENU:
        stageMenu.fy =0;
        break;

    case STATE_MENU_TO_GAME:
        switchTime =1;
        break;

    case STATE_GAME:
        break;

    case STATE_GAME_START:
        switchTime =1;
        break;

    case STATE_GAME_OVER:
        switchTime =10;
        break;

    default:
        break;
    }

  gameState =state;
}
void PixelMain::setup()
{
    renderer->setup();
   
    stage.renderer =renderer;
    stage.renderer =renderer;
    stageVS.renderer =renderer;
    stageIntro.renderer =renderer;
    stageMenu.renderer =renderer;
   
    
    setupIntro();
    setupMenu();
    
    setGameState(STATE_INTRO);
}
void PixelMain::setInput(int key)
{
    switch (gameState)
    {
    case STATE_INTRO:
        switchTime =1;
        setGameState(STATE_INTRO_TO_MENU);
        break;

    case STATE_MENU:

        if((key>=0 && key<6) || (key>=20 && key<26))
        {
            resetGame();
            setupGame();

            //select
            switch (menuPos)
            {
            case 0:
                gameType = GAME_TYPE_1P;
                setupAliensGame();
                setupGame1p();
                break;
            case 1:
                gameType = GAME_TYPE_2P;
                setupAliensGame();
                setupGame2p();
                break;
            default:
                gameType = GAME_TYPE_VS;
                setupGameVS();
                break;
            }
            setGameState(STATE_MENU_TO_GAME);
        }
        if(key==13|| key==33) menuRight();
        if(key==17|| key==37) menuLeft();
        break;

    case STATE_GAME:
    case STATE_GAME_OVER:

        switch (gameType)
        {
        case GAME_TYPE_1P:
            boyHero = &hero1pm;
            break;

        case GAME_TYPE_2P:
            boyHero = &hero2pM;
            girlHero = &hero2pF;
            break;

        case GAME_TYPE_VS:
            boyHero = &heroVSM;
            girlHero = &heroVSF;
            break;
        }

        switch (key)
        {
        case 0:
            boyHero->setKey(10);
            break;
        case 1:
            boyHero->setKey(11);
            break;
        case 2:
            boyHero->setKey(10);
            break;
        case 3:
            boyHero->setKey(12);
            break;
        case 4:
            boyHero->setKey(10);
            break;
        case 5:
            boyHero->setKey(13);
            break;

        case 10:
            boyHero->setKey(0);
            break;
        case 11:
            boyHero->setKey(1);
            break;
        case 12:
            boyHero->setKey(2);
            break;
        case 13:
            boyHero->setKey(3);
            break;
        case 14:
            boyHero->setKey(4);
            break;
        case 15:
            boyHero->setKey(5);
            break;
        case 16:
            boyHero->setKey(6);
            break;
        case 17:
            boyHero->setKey(7);
            break;
        case 18:
            boyHero->setKey(8);
            break;
        }

        if(gameType !=GAME_TYPE_1P)
        {
            switch (key)
            {
            case 20:
                girlHero->setKey(10);
                break;
            case 21:
                girlHero->setKey(11);
                break;
            case 22:
                girlHero->setKey(10);
                break;
            case 23:
                girlHero->setKey(12);
                break;
            case 24:
                girlHero->setKey(10);
                break;
            case 25:
                girlHero->setKey(13);
                break;

            case 30:
                girlHero->setKey(0);
                break;
            case 31:
                girlHero->setKey(1);
                break;
            case 32:
                girlHero->setKey(2);
                break;
            case 33:
                girlHero->setKey(3);
                break;
            case 34:
                girlHero->setKey(4);
                break;
            case 35:
                girlHero->setKey(5);
                break;
            case 36:
                girlHero->setKey(6);
                break;
            case 37:
                girlHero->setKey(7);
                break;
            case 38:
                girlHero->setKey(8);
                break;
            }
        }
        break;

    default:
        //do nothing
        break;
    }
}
void PixelMain::update(float timeElapsed)
{
    renderer->setBrightness(brightness);

    switch (gameState)
    {
    case STATE_INTRO:
        updateIntro( timeElapsed);
        stageIntro.int_update();
        stageIntro.draw(&stageIntro);
        break;

    case STATE_INTRO_TO_MENU:
        updateIntro( timeElapsed);
        stageIntro.fy = Sprite::linearEase(1-switchTime,0,-16,1);;
        stageIntro.int_update();
        stageIntro.draw(&stageIntro);

        updateMenu( timeElapsed);
        stageMenu.fy = stageIntro.fy +16;
        stageMenu.int_update();
        stageMenu.draw(&stageMenu);

        switchTime -=timeElapsed;
        if(switchTime<0)setGameState(STATE_MENU);
        break;

    case STATE_MENU:
        updateMenu( timeElapsed);
        stageMenu.int_update();
        stageMenu.draw(&stageMenu);
        break;

    case STATE_MENU_TO_GAME:
        updateMenu( timeElapsed);
        stageMenu.fy = Sprite::linearEase(1-switchTime,0,-16,1);;
        stageMenu.int_update();
        stageMenu.draw();

        updateGame( timeElapsed);

        switch (gameType)
        {
        case GAME_TYPE_1P:
            stage.fy = stageMenu.fy +16;
            stage.int_update();
            stage.draw();
            break;

        case GAME_TYPE_2P:
            stage.fy = stageMenu.fy +16;
            stage.int_update();
            stage.draw();
            break;

        case GAME_TYPE_VS:
            stageVS.fy = stageMenu.fy +16;
            stageVS.int_update();
            stageVS.draw();
            break;
        }

        switchTime -=timeElapsed;
        if(switchTime<0){
            setGameState(STATE_GAME_START);
            stageVS.fy =0;
            stage.fy =0;
            stage.fy =0;
        }
        break;

    case STATE_GAME:
    case STATE_GAME_START:
    case STATE_GAME_OVER:

        updateGame(timeElapsed);

        switch(gameType)
        {
        case GAME_TYPE_1P:
            updateGame1p(timeElapsed);
            updateAliensGame(timeElapsed);
            stage.int_update();
            stage.draw();
            break;

        case GAME_TYPE_2P:
            updateGame2p(timeElapsed);
            updateAliensGame(timeElapsed);
            stage.int_update();
            stage.draw();
            break;

        case GAME_TYPE_VS:
            updateGameVS(timeElapsed);
            stageVS.int_update();
            stageVS.draw();
            break;
        }
        break;
    }
}

void PixelMain::setWin(int /*heroType*/)
{
}

void PixelMain::draw()
{
    renderer->draw();
}
