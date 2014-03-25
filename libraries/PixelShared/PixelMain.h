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


#include "Hero.h"
#include "DataThreeClose.h"
#include "DataThreeFar.h"
#include "DataCloud1.h"
#include "DataFlower.h"
#include "Cloud.h"
#include "Blood.h"
#include "Life.h"
#include "SpecialAttack.h"
#include "Vector.h"

#include "SpaceShip.h"
#include "Star.h"
#include "DecorSprite.h"
#include "Live.h"
#include "Alien.h"
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
    Alien3 *alienBoss2p;
    Alien3 *alienBoss1p;
    
    PixelRenderer * renderer;
    
    PixelMain(PixelRenderer *renderer);
    void setup();
    
    
    void setGameState(int state);
    
    int gameState;
    int gameType;
    
    
    void update(float timeElapsed);
 

    
    
    void draw();
    
    void setInput(int key);
    void setWin(int heroType);
    
    Stage stage2p;
    Stage stage1p;
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
    void deallocInto();
    float introTime;
    
    Stage stageIntro;
    Sprite * invasionText;
    SpaceShip *spaceShip;
    Sprite *pressKeyText;
    Vector <Star *> stars;
    
     Sprite * backgroundIntro;
    
    ////////////////////////////////////////
    /*
   MENU STUFF
     */
    ///////////////////////////////////////
    
    void setupMenu();
    void updateMenu(float timeElapsed);
    void menuRight();
    void menuLeft();
    void allocMenu();
    void deallocMenu();
    
    Stage stageMenu;
    Sprite * backgroundMenu;
    
    Sprite * menuItem1;
    Sprite * menuItem2;
    Sprite * menuItem3;
    Sprite *menuBack;
    float menuSpeed  ;   int menuPos;
    
    
    ////////////////////////////////////////
    //GAME STUFF SHARED
    void allocGame();
    void deallocGame();
    
    
    void setupGame();
    void updateGame(float timeElapsed);
    void setHeroData(Hero * hero,int type);
     void setLifeData(Life * life);
    
    void setAliens(const Vector<Alien *> &aliens);
    
    Blood * getBlood(const Vector<Blood *> & bloods);
    SpecialAttack * getSpecialAttack(const Vector<SpecialAttack *> &attacs);
    
    
    Vector<SpecialAttack *>specialAttackBuffer1p;
    Vector<Blood *>bloodBuffer1p;
    
    Vector<SpecialAttack *>specialAttackBuffer2p;
    Vector<Blood *>bloodBuffer2p;
    
    Vector<SpecialAttack *>specialAttackBufferVS;
    Vector<Blood *>bloodBufferVS;
    
    PixelData * frame1b;
    PixelData * frame2b;
    PixelData * frame3b;
   void  resolveShoot(const Vector<Live *> &lives,const Vector<SpecialAttack *> &attacs);
     void  checkShoot(const Vector<Live *> &lives,const Vector<SpecialAttack *> &attacs,const Vector<Blood *> &bloods);
   void  resolveAttack(const Vector<Live *> &lives,const Vector<Blood *> &bloods);
    
      void alienHitTest(Hero * hero,const Vector<Alien *> &aliens,const Vector<Blood *> &bloods);
    
    //shared
    
    PixelData *  girlShoot1 ;
    PixelData *  girlShoot2 ;
    
    PixelData * boyShoot1 ;
    PixelData * boyShoot2;
    
    PixelData * alienShoot1;
    PixelData * alienShoot2;

     PixelData * splashFrame1;
     PixelData * splashFrame2;
    
    
    
    
    DataThreeClose *treeCloseData;
        DataThreeFar *treeFarData;
        DataCloud1 *cloudData;
        Dataflower *flowerData;
PixelData *paddoData;
        PixelData * backGrass ;
     PixelData * cityData;
    PixelData * bushData;
    //heroData
    
        PixelData * jumpDataB;
        PixelData * jumpKickDataB;
        PixelData * jumpHitDataB;
        PixelData * jumpBlockDataB;
    
    
        PixelData * crouchDataB;
    PixelData * crouchDataWalk1B;
     PixelData * crouchDataWalk2B;
        PixelData * crouchKickDataB;
        PixelData * crouchHitDataB;
        PixelData * crouchBlockDataB;
    
        PixelData * standDataB;
    
        PixelData * standKickDataB;
        PixelData * standHitData1B;
        PixelData * standHitData2B;
        PixelData * standBlockDataB;
    
    
        PixelData * walk1DataB;
        PixelData * walk2DataB;
        PixelData * walk3DataB;
    
        PixelData * deathDataB;
    PixelData * gotHit1B;
    PixelData * gotHit2B;
    
        PixelData * jumpDataG;
        PixelData * jumpKickDataG;
        PixelData * jumpHitDataG;
        PixelData * jumpBlockDataG;
    
    
        PixelData * crouchDataG;
        PixelData * crouchDataWalk1G;
   
        PixelData * crouchDataWalk2G;
        PixelData * crouchKickDataG;
        PixelData * crouchHitDataG;
        PixelData * crouchBlockDataG;
    
        PixelData * standDataG;
    
        PixelData * standKickDataG;
        PixelData * standHitData1G;
        PixelData * standHitData2G;
        PixelData * standBlockDataG;
    
    
        PixelData * walk1DataG;
        PixelData * walk2DataG;
        PixelData * walk3DataG;
    
        PixelData * deathDataG;
    PixelData * gotHit1G;
    PixelData * gotHit2G;
    //////////////////////lifedata
        PixelData *  boyInterData;
        PixelData *  girlInterData;
    
        PixelData * life0;
        PixelData * life1;
        PixelData * life2;
        PixelData * life3;
    
        PixelData * life4;
        PixelData * life5;
        PixelData * life6;
        PixelData * life7;
    
        PixelData * lifeGlow;
    
     //////////
    PixelData *alien1Head;
     PixelData *alien1Feet;
    
    PixelData *alien2Head;
    PixelData *alien2Feet;
    
    PixelData *alienPond;
    PixelData *alienDuckBig;
       PixelData *alienDuckSmall;
    //////////////////
    float stagefx;
    Hero * boyHero;
    Hero * girlHero;

    //GAME 1PLAYER
    void setupGame1p();
    void updateGame1p(float timeElapsed);
    void resetGame1p();
    Vector<Cloud *>clouds1p;
    
     Vector<DecorSprite *>decor1p;
    
    Hero *hero1pm;
    
    Vector <Alien *> aliens1p;
    Sprite *lifeBoyHolder1p;
    Life *lifeBoy1p;
  
  Vector<Live *>live1p;
    GameOverText *  gameOverText1p;
    WaterSplash * waterSplash1p;
    //GAME 2 PLAYER
    
    void setupGame2p();
    void updateGame2p(float timeElapsed);
    void resetGame2p();
    Vector<Cloud *>clouds2p;
      Vector <Alien *> aliens2p;
    Hero *hero2pM;
    Hero *hero2pF;
    Sprite *lifeBoyHolder2p;
    Sprite *lifeGirlHolder2p;
    Life * lifeGirl2p;
    Life *lifeBoy2p;
     Vector<Live *>live2p;
        GameOverText *  gameOverText2p;
       Vector<DecorSprite *>decor2p;
    WaterSplash * waterSplash2p;
    //GAME VS
    
    void setupGameVS();
    void updateGameVS(float timeElapsed);
    void resetGameVS();
    Vector<Cloud *>cloudsVS;
    Hero *heroVSM;
    Hero *heroVSF;
    
    Sprite *lifeBoyHolderVS;
    Sprite *lifeGirlHolderVS;
    Life * lifeGirlVS;
    Life *lifeBoyVS;

     Vector<Live *>liveVS;
    
       Vector<DecorSprite *>decorVS;
     GameOverText *  gameOverTextVS;
    
    void resetGame();
    bool readyToStart;
 
    
    
   
   
    
    bool endGame ;
  
    
    int brightness;
};



#endif
