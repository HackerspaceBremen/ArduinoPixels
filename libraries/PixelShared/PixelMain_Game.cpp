//
//  PixelMain_Game.cpp
//  PixelGameLocal
//
//  Created by Kris Temmerman on 24/10/13.
//
//

#include "PixelMain.h"

#include "DataPond.h"

#include "DataHitPointTest.h"

#include "DataBackGrass.h"

#include "DataManJump.h"
#include "DataManStand.h"
#include "DataManWalk1.h"
#include "DataManWalk2.h"
#include "DataManWalk3.h"

#include "DataManCrouch.h"

#include "DataManJumpKick.h"
#include "DataManCrouchKick.h"
#include "DataManStandKick.h"

#include "DataManJumpHit.h"
#include "DataManCrouchHit.h"
#include "DataManStandHit1.h"
#include "DataManStandHit2.h"

#include "DataManJumpKick.h"
#include "DataManCrouchKick.h"
#include "DataManStandKick.h"

#include "DataManJumpBlock.h"
#include "DataManCrouchBlock.h"
#include "DataManStandBlock.h"
#include "DataBoyDeath.h"

#include "DataManGitHit1.h"
#include "DataManGitHit2.h"

#include "DataGirlJump.h"
#include "DataGirlStand.h"
#include "DataGirlWalk1.h"
#include "DataGirlWalk2.h"
#include "DataGirlWalk3.h"

#include "DataGirlCrouch.h"

#include "DataGirlJumpKick.h"
#include "DataGirlCrouchKick.h"
#include "DataGirlStandKick.h"

#include "DataGirlJumpHit.h"
#include "DataGirlCrouchHit.h"
#include "DataGirlStandHit1.h"
#include "DataGirlStandHit2.h"

#include "DataGirlJumpKick.h"
#include "DataGirlCrouchKick.h"
#include "DataGirlStandKick.h"

#include "DataGirlJumpBlock.h"
#include "DataGirlCrouchBlock.h"
#include "DataGirlStandBlock.h"
#include "DataGirlDeath.h"

#include "DataGirlGotHit1.h"
#include "DataGirlGotHit2.h"

#include "Alien1.h"
#include "Alien2.h"
#include "AlienPond.h"

#include "DataManCrouchWalk1.h"
#include "DataManCrouchWalk2.h"

#include "DataGirlCrouchWalk1.h"
#include "DataGirlCrouchWalk2.h"


//
// Decor Data
//

Array<Cloud,6> _clouds;
Array<Sprite,2> _backgroundGame;
const DataCloud1<> _cloudData;
const DataBackGrass<> _backGrass;

StackVector<DecorSprite *, 64> aliensDecor;


//
// Boy Data
//

const DataManJump<> jumpDataB;
const DataManJumpKick<-1> jumpKickDataB;
const DataManJumpHit<> jumpHitDataB;
const DataManJumpBlock<> jumpBlockDataB;

const DataManCrouch<> crouchDataB;
const DataManCrouchWalk1<> crouchDataWalk1B;
const DataManCrouchWalk2<> crouchDataWalk2B;
const DataManCrouchKick<-1> crouchKickDataB;
const DataManCrouchHit<-1> crouchHitDataB;
const DataManCrouchBlock<> crouchBlockDataB;

const DataManStand<> standDataB;
const DataManStandKick<> standKickDataB;
const DataManStandHit1<-1> standHitData1B;
const DataManStandHit2<-1> standHitData2B;
const DataManStandBlock<> standBlockDataB;
const DataManGitHit1<> gotHit1B;
const DataManGitHit2<0,-1> gotHit2B;

const DataManWalk1<> walk1DataB;
const DataManWalk2<> walk2DataB;
const DataManWalk3<> walk3DataB;
const DataBoyDeath<> deathDataB;


//
// Girl Data
//

const DataGirlJump<0,1> jumpDataG;
const DataGirlJumpKick<-1,1> jumpKickDataG;
const DataGirlJumpHit<-1,1> jumpHitDataG;
const DataGirlJumpBlock<0,1> jumpBlockDataG;

const DataGirlCrouch<0,1> crouchDataG;
const DataGirlCrouchWalk1<0,1> crouchDataWalk1G;
const DataGirlCrouchWalk2<0,1> crouchDataWalk2G;
const DataGirlCrouchKick<-1,1> crouchKickDataG;
const DataGirlCrouchHit<-1,1> crouchHitDataG;
const DataGirlCrouchBlock<0,1> crouchBlockDataG;

const DataGirlStand<0,1> standDataG;
const DataGirlStandKick<-1,1> standKickDataG;
const DataGirlStandHit1<-1,1> standHitData1G;
const DataGirlStandHit2<-1,1> standHitData2G;
const DataGirlStandBlock<0,1> standBlockDataG;
const DataGirlGotHit2<0,1> gotHit1G;
const DataGirlGotHit2<> gotHit2G;

const DataGirlWalk1<0,1> walk1DataG;
const DataGirlWalk2<0,1> walk2DataG;
const DataGirlWalk3<0,1> walk3DataG;
const DataGirlDeath<0,1> deathDataG;

//
// GirlVS data
//

const DataGirlJump<> jumpDataG_VS;
const DataGirlJumpKick<-1> jumpKickDataG_VS;
const DataGirlJumpHit<-1> jumpHitDataG_VS;
const DataGirlJumpBlock<> jumpBlockDataG_VS;

const DataGirlCrouch<> crouchDataG_VS;
const DataGirlCrouchWalk1<> crouchDataWalk1G_VS;
const DataGirlCrouchWalk2<> crouchDataWalk2G_VS;
const DataGirlCrouchKick<-1> crouchKickDataG_VS;
const DataGirlCrouchHit<-1> crouchHitDataG_VS;
const DataGirlCrouchBlock<> crouchBlockDataG_VS;

const DataGirlStand<> standDataG_VS;
const DataGirlStandKick<-1> standKickDataG_VS;
const DataGirlStandHit1<-1> standHitData1G_VS;
const DataGirlStandHit2<-1> standHitData2G_VS;
const DataGirlStandBlock<> standBlockDataG_VS;
const DataGirlGotHit2<> gotHit1G_VS;
const DataGirlGotHit2<0,-1> gotHit2G_VS;

const DataGirlWalk1<> walk1DataG_VS;
const DataGirlWalk2<> walk2DataG_VS;
const DataGirlWalk3<> walk3DataG_VS;
const DataGirlDeath<> deathDataG_VS;

void PixelMain::initGame()
{
    //set the data
    setHeroData(&hero1pm,0);

    setHeroData(&hero2pF,1);
    setHeroData(&hero2pM,0);

    setHeroData(&heroVSF,2);
    setHeroData(&heroVSM,0);

    lifeBoyHolder1p.currentData = &boyInterData;

    lifeBoyHolder2p.currentData = &boyInterData;
    lifeGirlHolder2p.currentData = &girlInterData;
    lifeBoyHolderVS.currentData = &boyInterData;
    lifeGirlHolderVS.currentData = &girlInterData;
}
void PixelMain::alienHitTest(Hero * hero)
{
    if(hero->saveTime >0)return;
    for(size_t i=0;i<aliens.size();i++)
    {
        if(aliens[i]->intHidden)continue;
    
        if(  hero->hitTestRect(aliens[i]))
        {
            Alien * alien = aliens[i];
            //water
            if(alien->heroType==5)
            {
                
                hero->life --;
             

                
                if(hero->life==0){
                    hero->setDead();
                    
                }else
                {
                    hero->hitWater();
                    hero-> saveTime =0.3;
                }
                if(gameType == GAME_TYPE_1P)
                {
                    waterSplash1p.show(hero->fxReal);
                }
                if(gameType == GAME_TYPE_2P)
                {
                    waterSplash2p.show(hero->fxReal);
                }
            
            }else{
            
                if(alien->fxReal > hero->fxReal)
                {
                    hero->hitSpeed =-35;
               
                }
                else
                {
                    hero->hitSpeed =35;
                }
           
                hero->speed =0;
                hero->life --;
            
            
                if(hero->life==0){
                    hero->setDead();
               
                }
           
            
                hero->hitFall =rand()%2;
                hero->saveTime =0.8;
            
                Blood * blood =getBlood();
                if(blood!=0)
                {
                    blood->fxReal = hero->fxReal ;
                    blood->fy= hero->fy -4;
                    blood->show();

                }
            }
        }
    
    }

    


}


void  PixelMain::resolveAttack(const StackVector<Live *> &lives)
{

    for(size_t j=0;j<lives.size();j++)
    {
         if(lives[j]->intHidden)continue;
        Live *attacker=lives[j];
        if(attacker->attackType == HIT ||attacker->attackType == KICK )
        {
            int hitPosX=attacker->fxReal+attacker->hitX;
            int hitPosY = attacker->y+attacker->hitY;
           
            for(size_t i=0;i<lives.size();i++)
            {
                    if( lives[i]->heroType==5)continue;
                   if(lives[i]->intHidden)continue;
                if(i==j)continue;
                if(gameType == GAME_TYPE_2P)
                {
                  
                    if(attacker->heroType==1 && lives[i]->heroType==0)
                    {
                       continue;
                
                    } if(attacker->heroType==0 && lives[i]->heroType==1)
                    {
                        continue;
                        
                    }
                
                
                }
                
                if(lives[i]->saveTime>0  )return;
                
                bool hasHit = lives[i]->hitTest(hitPosX,hitPosY);
               
                if(hasHit   )
                {
              //      Serial.println("hit");
                      Live *attackee=lives[i];
                    if(attackee->attackType==BLOCK && attackee->drawType !=attacker->drawType )
                    {
                       if(attackee->x>attacker->x)
                        {
                            attacker->hitSpeed =-20;
                        }else 
                        {
                               attacker->hitSpeed =20;
                        }
                        
                        
                    }
                    else
                    {
                        if(attackee->x>attacker->x)
                        {
                           attackee->hitSpeed =35;
                        }else 
                        {
                            attackee->hitSpeed =-35;
                        }
                    
                        attackee->life --;
                        
                       if(attackee->life==0)
                       {
                           attackee->setDead();
                       }
                        if(attacker->drawType==1)
                            attackee->drawType =0;
                        else if (attacker->drawType==0)
                            attackee->drawType =1;
                        
                        attackee->hitFall =rand()%2;
                       attackee->saveTime =0.8;
                        
                        Blood * blood =getBlood();
                        if(blood!=0)
                        {
                            blood->fxReal = hitPosX;
                            blood->fy= hitPosY;
                            blood->show();
                        }
                    }
                }

            
            }
        }
    }
    
    
  

}
void  PixelMain::checkShoot(const StackVector<Live *> &lives)
{
    for(size_t j=0;j<MAX_ATTACKS;j++)
    {
        if(_specialAttacks[j].isUsed)
        {
            SpecialAttack * attack = &_specialAttacks[j];
            for(size_t i=0;i<lives.size();i++)
            {
                if(gameType == GAME_TYPE_2P)
                {
                    if(attack->heroType==1 && lives[i]->heroType==0)
                    {
                        continue;
                        
                    } if(attack->heroType==0 && lives[i]->heroType==1)
                    {
                        continue;
                        
                    }
                }

                if( attack->heroType>1 && lives[i]->heroType>1)continue;
            if( attack->heroType != lives[i]->heroType)
            {
              
                if(lives[i]->hitTest(attack->fxReal, attack->fy) &&   lives[i]->saveTime<=0)
                {
                    Live *attackee=lives[i];
                                    
                    if(attackee->attackType==BLOCK && attack->drawType !=attackee->drawType )
                    {
                        if(attackee->x >  attack->x)
                        {
                            attackee->hitSpeed =20;
                           
                        }else
                        {
                           attackee->hitSpeed =-20;
                        }
                         attackee->speed =0;
                        attack-> hit();
                    }
                    else
                    {
                        if(attackee->x>attack->x)
                        {
                            attackee->hitSpeed =35;
                        }else
                        {
                            attackee->hitSpeed =-35;
                        }
                        //playSound(SOUND_HIT);
                        attackee->life --;
                        
                        if(attackee->life==0)
                        {
                            attackee->setDead();
                        }
                        if(attack->drawType==1)
                            attackee->drawType =0;
                        else if (attack->drawType==0)
                            attackee->drawType =1;
                        
                        attackee->hitFall =rand()%2;
                        attackee->saveTime =0.8;
                        
                        Blood * blood =getBlood();
                        if(blood!=0)
                        {
                            blood->fxReal = attack->fxReal;
                            blood->fy= attack->fy;
                            blood->show();
                        }
                         attack-> hit();
                    }

                
                
                
                }
            
            
            }
        
        }
    
        }
    
    }

}
void  PixelMain::resolveShoot(const StackVector<Live *> &lives)
{
    for(size_t i=0;i< lives.size();i++)
    
    if(lives[i]->startShoot)
    {
        lives[i]->startShoot =false;
        SpecialAttack * attack=getSpecialAttack();
        if(attack){
            attack->fxReal =lives[i]->fxReal +4;
            if(lives[i]->drawType==1)attack->fxReal -=7;
            
            attack->fy =lives[i]->y-2;
            attack->start(lives[i]->drawType, lives[i]->heroType);
        }
    }



}

Blood * PixelMain::getBlood()
{
    // TODO more random blood selection.
    for (size_t i=0;i<MAX_BLOOD;i++)
        if(!_bloods[i].isUsed) return &_bloods[i];

    return 0;
}
SpecialAttack * PixelMain::getSpecialAttack()
{
    for (size_t i=0;i<MAX_ATTACKS;i++)
        if(!_specialAttacks[i].isUsed) return &_specialAttacks[i];

    return 0;
}

void  PixelMain::resetGame()
{
    // Clear the vectors
    aliens.clear();
    live.clear();
    aliensDecor.clear();
    liveVS.clear();
    decorVS.clear();

    _gameOverText.reset();

    stage.reset();
    stageVS.reset();

    endGame = false;
    stagefx = 0;
    resetGame1p();
    resetGame2p();
    resetGameVS();

    for (size_t i=0;i<aliensDecor.size();i++)
        aliensDecor[i]->setLevelPos(stagefx);
}

void PixelMain::setupGame()
{
    for (int i=0; i<2; i++)
    {
        _backgroundGame[i].drawType =3;
        _backgroundGame[i].currentData = &_backGrass;
    }

    stage.addChild(&_backgroundGame[0]);
    stageVS.addChild(&_backgroundGame[1]);

    for (int j=0;j<6;j++)
    {
        Cloud *c = &_clouds[j];
        c->currentData  = &_cloudData;
        c->fx = rand()%90;
        c->fy = rand()%5  -4+_cloudData.height();
        c->setup();

        if (j<3) stage.addChild(c);
        else stageVS.addChild(c);
    }
}

void PixelMain::setupAliensGame()
{
    // Setup the 1p and 2p common game assets
    int posCity [2] = {30,150};
    for(int i=0;i<MAX_CITIES;i++)
    {
        DecorSprite * city = &_cities[i];
        city ->currentData = &_cityData;

        city->fx = city->fxReal = posCity [i];

        city->fy =7;
        city->depth =0.2;

        aliensDecor.push_back(city);
    }
    srand (5);
    int treePosS [15] = { 35,296,120,157,272,221,253,90,112,55,97,35,190,158,224};
    int treePosSH [15] = {-1,0,-1,-1,0,0,0,-1,-1,0,-1,-1,0,0,-1};

    for(int i=0;i<MAX_FARTREES;i++)
    {
        DecorSprite * treeFar = &_farTrees[i];
        treeFar ->currentData = &_treeFarData;
        treeFar ->fx  =treeFar ->fxReal = treePosS[i];
       // cout << treeFar->fx<<",";
        int rPos = treePosSH[i];

        treeFar ->fy = -rand()%2+_treeFarData.height();
        treeFar ->depth=0.3;
        if( rPos ==-1) treeFar ->depth=0.25;


        aliensDecor.push_back(treeFar );
    }

     //srand (1);
    int treePos [8] = {50,233,270,400,430,250,252,147};
    int treePosH [8] = {-2,0,-1,-2,0,-2,-1,-1};
    for(int i=0;i<MAX_CLOSETREES;i++)
    {
        DecorSprite * treeClose = &_closeTrees[i];

        treeClose->currentData = &_treeCloseData;
        treeClose->fx = treeClose->fxReal = treePos [i];
       // cout << treeClose->fx<<",";
        int rPos = treePosH[i]  ;

        treeClose->fy = rPos+_treeCloseData.height()-5;
        treeClose->depth =0.8;
        if( rPos ==-1)treeClose->depth=0.5;
        if( rPos ==-2)treeClose->depth=0.4;

        aliensDecor.push_back(treeClose );
    }
    srand (1);
    for(int i=0;i<MAX_FLOWERS;i++)
    {
        DecorSprite * flower = &_flowers[i];
        flower ->currentData = &_flowerData;

        flower->fx = flower->fxReal = rand()%600;
        int rPos = -rand()%3;
        flower->fy = rPos+16;
        flower->depth =1;

        switch (rPos) {
        case -2:
            flower->depth=0.98;
            break;
        case -3:
            flower->depth=0.95;
            break;
        }

        aliensDecor.push_back( flower);
    }
    int posBush [] = {60,150, 400,470};
    for(int i=0;i<MAX_BUSHES;i++)
    {
        DecorSprite * bush = &_bushes[i];

        bush->currentData = &_bushData;
        bush->fx = bush->fxReal = posBush[i];

        bush->fy = 13;
        bush->depth =1;
        aliensDecor.push_back( bush );
    }

    int posPaddo[] = {250,320,550};
    for(int i=0;i<MAX_PADDOS;i++)
    {
        DecorSprite * paddo = &_paddos[i];

        paddo->currentData = &_paddoData;
        paddo->fx = paddo->fxReal = posPaddo[i];

        paddo->fy = 13;
        paddo->depth =1;
        aliensDecor.push_back( paddo);
    }

    // slow sort ;)
    bool sorted =false;
    while(!sorted){
        sorted  =true;
        for (size_t i=0;i<   aliensDecor.size()-1;i++)
        {
            if(aliensDecor[i]->depth >aliensDecor[i+1]->depth)
            {
                DecorSprite *temp = aliensDecor[i];
                aliensDecor[i] = aliensDecor[i+1];
                aliensDecor[i+1] = temp;
                sorted  =false;
            }
        }
    }

    for (size_t i=0;i<   aliensDecor.size();i++)
    {
        stage.addChild(aliensDecor[i]);
    }

    int posAlienPond [2] = {193,350};
    for (int i=0;i<MAX_ALIENPOND;i++)
    {
        AlienPond *alien = &_alienPonds[i];
        alien->setup();
        alien->fx  = alien->fxReal = posAlienPond [i];
        alien->fy =16;
        aliens.push_back(alien);
        stage.addChild(alien);
        live.push_back(alien);
    }

    int posAlien1 [4] = {290,380, 451 , 500};
    for (int i=0;i<MAX_ALIEN;i++)
    {
        Alien1 *alien  = &_aliens1[i];

        alien->fx  = alien->fxReal = posAlien1 [i]; // rand()%200;
        alien->fy =15;
        alien->setup();
        aliens.push_back(alien);
        stage.addChild(alien);
        live.push_back(alien);
    }

    int posAlien2 [4] = {95,150, 250 , 420};
    for (int i=0;i<MAX_ALIEN;i++)
    {
        Alien2 *alien = &_aliens2[i];

        alien->fx  = alien->fxReal =posAlien2[i];
        alien->fy =15;
        alien->setup();//setup after fx
        aliens.push_back(alien);
        stage.addChild(alien);
        live.push_back(alien);
    }

    for (int i=0;i<MAX_ATTACKS;i++)
    {
        SpecialAttack *attack = &_specialAttacks[i];

        attack->setup();
        stage.addChild(attack);
    }

    alienBoss = &_alienBoss;

    alienBoss->fx = alienBoss->fxReal =600;
    alienBoss->fy =15;
    alienBoss->setup();
    aliens.push_back(alienBoss);
    stage.addChild(alienBoss);
    live.push_back(alienBoss);
}

void  PixelMain::setHeroData(Hero * hero,int type)
{
    switch (type)
    {
    case 0:
        hero->jumpData = &jumpDataB ;
        hero->jumpKickData = &jumpKickDataB;
        hero->jumpHitData= &jumpHitDataB;
        hero->jumpBlockData = &jumpBlockDataB;
        
        hero->crouchData = &crouchDataB;
        hero->crouchKickData = &crouchKickDataB;
        hero->crouchHitData = &crouchHitDataB;
        hero->crouchBlockData = &crouchBlockDataB ;
        
        hero->standData = &standDataB ;
        hero->standKickData = &standKickDataB ;
        hero->standHitData1 = &standHitData1B;
        hero->standHitData2 = &standHitData2B;
        hero->standBlockData = &standBlockDataB;
        
        hero->gotHitData1 = &gotHit1B;
        hero->gotHitData2 = &gotHit2B;
        
        hero->walk1Data = &walk1DataB ;
        hero->walk2Data = &walk2DataB;
        hero->walk3Data = &walk3DataB;
        hero->deathData = &deathDataB;
    
        hero->crouchWalk1Data = &crouchDataWalk1B;
        hero->crouchWalk2Data = &crouchDataWalk2B;
        break;

    case 1:
        hero->jumpData = &jumpDataG;
        hero->jumpKickData = &jumpKickDataG;
        hero->jumpHitData = &jumpHitDataG;
        hero->jumpBlockData = &jumpBlockDataG;
        
        hero->crouchData = &crouchDataG;
        hero->crouchKickData = &crouchKickDataG;
        hero->crouchHitData = &crouchHitDataG;
        hero->crouchBlockData = &crouchBlockDataG;
        
        hero->standData = &standDataG;
        hero->standKickData = &standKickDataG;
        hero->standHitData1 = &standHitData1G;
        hero->standHitData2 = &standHitData2G;
        hero->standBlockData = &standBlockDataG;
        
        hero->crouchWalk1Data = &crouchDataWalk1G;
        hero->crouchWalk2Data = &crouchDataWalk2G;
        
        hero->walk1Data = &walk1DataG;
        hero->walk2Data = &walk2DataG;
        hero->walk3Data = &walk3DataG;
        hero->deathData = &deathDataG;
    
        hero->gotHitData1 = &gotHit1G;
        hero->gotHitData2 = &gotHit2G;
        break;

    case 2:
        hero->jumpData = &jumpDataG_VS;
        hero->jumpKickData = &jumpKickDataG_VS;
        hero->jumpHitData = &jumpHitDataG_VS;
        hero->jumpBlockData = &jumpBlockDataG_VS;

        hero->crouchData = &crouchDataG_VS;
        hero->crouchKickData = &crouchKickDataG_VS;
        hero->crouchHitData = &crouchHitDataG_VS;
        hero->crouchBlockData = &crouchBlockDataG_VS;

        hero->standData = &standDataG_VS;
        hero->standKickData = &standKickDataG_VS;
        hero->standHitData1 = &standHitData1G_VS;
        hero->standHitData2 = &standHitData2G_VS;
        hero->standBlockData = &standBlockDataG_VS;

        hero->crouchWalk1Data = &crouchDataWalk1G_VS;
        hero->crouchWalk2Data = &crouchDataWalk2G_VS;

        hero->walk1Data = &walk1DataG_VS;
        hero->walk2Data = &walk2DataG_VS;
        hero->walk3Data = &walk3DataG_VS;
        hero->deathData = &deathDataG_VS;

        hero->gotHitData1 = &gotHit1G_VS;
        hero->gotHitData2 = &gotHit2G_VS;
        break;
    }

    hero->currentData = hero->jumpData;
}

void PixelMain::updateGame(float timeElapsed)
{
    // Update the common game assets
    for (int i=0;i<6;i++)
        _clouds[i].update(timeElapsed);

    for (size_t i=0;i<MAX_BLOOD;i++)
        _bloods[i].update(timeElapsed,stagefx);
}

void PixelMain::updateAliensGame(float /*timeElapsed*/)
{
    // Update the 1p and 2p common game assets

    if (gameState != STATE_GAME_START)
    {
        for (size_t i=0;i<aliensDecor.size();i++)
            aliensDecor[i]->setLevelPos(stagefx);
    }
}
