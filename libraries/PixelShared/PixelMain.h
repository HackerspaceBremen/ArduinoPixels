//
//  PixelMain.h
//  PixelGame
//
//  Created by Kris Temmerman on 15/09/13.
//  Copyright (c) 2013 Kris Temmerman. All rights reserved.
//

#ifndef PixelGame_PixelMain_h
#define PixelGame_PixelMain_h


#include "PixelRenderer.h"
#include "Stage.h"
#include "PixelGameInclude.h"

#include "DataInterface.h"
#include "DataInterface2.h"

#include "Hero.h"
#include "DataThreeClose.h"
#include "DataThreeFar.h"
#include "DataCloud1.h"
#include "DataBush.h"
#include "Dataflower.h"
#include "DataCity.h"
#include "DataPaddo.h"
#include "Cloud.h"
#include "Blood.h"
#include "Life.h"
#include "SpecialAttack.h"
#include "Vector.h"
#include "Array.h"

#include "SpaceShip.h"
#include "Star.h"
#include "DecorSprite.h"
#include "Live.h"

#include "Alien.h"
#include "Alien1.h"
#include "Alien2.h"
#include "Alien3.h"
#include "AlienPond.h"

#include "WaterSplash.h"
#include "GameOverText.h"
#include "SoundPlayer.h"
#include "Alien3.h"
#define STATE_INTRO 10
#define STATE_INTRO_TO_MENU 11
#define STATE_MENU 12
#define STATE_MENU_TO_GAME 13
#define STATE_GAME_START 14
#define STATE_GAME 15
#define STATE_GAME_OVER 16

#define GAME_TYPE_1P 100
#define GAME_TYPE_2P 101
#define GAME_TYPE_VS 102
class PixelMain
{
public:
    SoundPlayer soundPlayer;
    Alien3 *alienBoss;
    
    PixelRenderer * renderer;
    
    PixelMain(PixelRenderer *renderer);
    void setup();
    
    
    void setGameState(int state);
    
    int gameState;
    int gameType;
    
    
    void update(float timeElapsed);
    
    void draw();
    
    void setInput(int key);
    void setWin(int);

    Stage stage;
    Stage stageVS;
    
    float switchTime;
    /*
     INTRO STUFF
     */
    ///////////////////////////////////////
    
    void setupIntro();
    void updateIntro(float timeElapsed);
    void resetIntro();
    void allocIntro();
    float introTime;
    
    Stage stageIntro;
    Sprite invasionText;
    SpaceShip spaceShip;
    Sprite pressKeyText;

    #define MAX_STARS 20
    Array<Star, MAX_STARS> _stars;
    
    Sprite backgroundIntro;
    
    ////////////////////////////////////////
    /*
   MENU STUFF
     */
    ///////////////////////////////////////
    
    void setupMenu();
    void updateMenu(float);
    void menuRight();
    void menuLeft();
    void allocMenu();
    void deallocMenu();
    
    Stage stageMenu;
    Sprite backgroundMenu;
    Sprite menuItem1;
    Sprite menuItem2;
    Sprite menuItem3;
    Sprite menuBack;
    float menuSpeed;
    int menuPos;
    
    
    ////////////////////////////////////////
    //GAME STUFF SHARED
    void initGame();

    void setupGame();
    void setupAliensGame();
    void updateGame(float timeElapsed);
    void updateAliensGame(float);
    void setHeroData(Hero * hero,int type);
    void setLifeData(Life * life);
    
    Blood * getBlood();
    SpecialAttack * getSpecialAttack();
    
    GameOverText _gameOverText;

    #define MAX_ATTACKS 16
    Array<SpecialAttack, MAX_ATTACKS> _specialAttacks;
    #define MAX_BLOOD 8
    Array<Blood, MAX_BLOOD> _bloods;

    void resolveShoot(const StackVector<Live *> &lives);
    void checkShoot(const StackVector<Live *> &lives);
    void resolveAttack(const StackVector<Live *> &lives);
    
    void alienHitTest(Hero * hero);
    
    //shared
    #define MAX_CITIES 2
    Array<DecorSprite, MAX_CITIES> _cities;
    #define MAX_FARTREES 15
    Array<DecorSprite, MAX_FARTREES> _farTrees;
    #define MAX_CLOSETREES 8
    Array<DecorSprite, MAX_CLOSETREES> _closeTrees;
    #define MAX_FLOWERS 20
    Array<DecorSprite, MAX_FLOWERS> _flowers;
    #define MAX_BUSHES 4
    Array<DecorSprite, MAX_BUSHES> _bushes;
    #define MAX_PADDOS 3
    Array<DecorSprite, MAX_PADDOS> _paddos;
    #define MAX_ALIEN 4
    Array<Alien1, MAX_ALIEN> _aliens1;
    Array<Alien2, MAX_ALIEN> _aliens2;
    #define MAX_ALIENPOND 2
    Array<AlienPond, MAX_ALIENPOND> _alienPonds;
    Alien3 _alienBoss;

    const DataCity<> _cityData;
    const DataThreeFar<> _treeFarData;
    const DataThreeClose<> _treeCloseData;
    const Dataflower<> _flowerData;
    const DataBush<> _bushData;
    const DataPaddo<> _paddoData;

    //////////////////////lifedata
    Life lifeGirl;
    Life lifeBoy;
    const DataInterface<> boyInterData;
    const DataInterface2<> girlInterData;

    //////////////////
    float stagefx;
    Hero * boyHero;
    Hero * girlHero;

    StackVector<Alien*> aliens;
    StackVector<Live *> live;

    //GAME 1PLAYER
    void setupGame1p();
    void updateGame1p(float timeElapsed);
    void resetGame1p();
    
    Hero hero1pm;

    Sprite lifeBoyHolder1p;
    WaterSplash waterSplash1p;

    //GAME 2 PLAYER
    void setupGame2p();
    void updateGame2p(float timeElapsed);
    void resetGame2p();
    Hero hero2pM;
    Hero hero2pF;
    Sprite lifeBoyHolder2p;
    Sprite lifeGirlHolder2p;
    WaterSplash waterSplash2p;

    //GAME VS
    void setupGameVS();
    void updateGameVS(float timeElapsed);
    void resetGameVS();
    Hero heroVSM;
    Hero heroVSF;
    
    Sprite lifeBoyHolderVS;
    Sprite lifeGirlHolderVS;
    StackVector<Live *> liveVS;
    StackVector<DecorSprite *>decorVS;
    
    void resetGame();
    bool readyToStart;

    bool endGame ;

    int brightness;
};



#endif
