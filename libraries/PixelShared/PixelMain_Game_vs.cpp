//
//  PixelMain_Game_vs.cpp
//  PixelGameLocal
//
//  Created by Kris Temmerman on 28/10/13.
//
//

#include "PixelMain.h"

void PixelMain::setupGameVS()
{
   
        DecorSprite * city = &_cities[0];
        city ->currentData = &_cityData;
        
        city->fx = city->fxReal = 30;
        
        city->fy =7;
        city->depth =0.2;
        
        decorVS.push_back(city);
   
    int posTreeFar [3] = { 16,25, 77 };
    for(int i=0;i<3;i++)
    {
        DecorSprite * treeFar = &_farTrees[i];
        treeFar ->currentData = &_treeFarData;
        treeFar ->fx  =treeFar ->fxReal =  posTreeFar[i] ;
        int rPos = -rand()%2;
        treeFar ->fy = -rand()%2+_treeFarData.height();
        treeFar ->depth=0.3;
        if( rPos ==-1) treeFar ->depth=0.4;
        
        
        decorVS.push_back(treeFar );
    }
    
   
        DecorSprite * treeClose = &_closeTrees[0];
        
        treeClose->currentData = &_treeCloseData;
        treeClose->fx = treeClose->fxReal = 50;
 
        treeClose->fy =13;
        treeClose->depth =1;
       
       
        
        decorVS.push_back(treeClose );
    
    
    
    DecorSprite * bush = &_bushes[0];
    
    bush->currentData = &_bushData;
    bush->fx = bush->fxReal = 35;
   
    bush->fy = 13;
    bush->depth =1;
  

    
    decorVS.push_back(bush);
    int posFlower[6] = { 12,28, 77,55,23,45};
    
   
    for(int i=0;i<6;i++)
    {
        DecorSprite * flower = &_flowers[i];
        flower ->currentData = &_flowerData;
        
        flower->fx = posFlower[i];
        flower->fxReal = posFlower[i];
        int rPos = -rand()%4;
        flower->fy = rPos+15;
        flower->depth =1;
        if( rPos ==-2)  flower->depth=0.98;
        if( rPos ==-3)  flower->depth=0.95;
        
        
        decorVS.push_back( flower);
    }
    bool sorted =false;
    while(!sorted){
        sorted  =true;
        for (size_t i=0;i<   decorVS.size()-1;i++)
        {
            if(decorVS[i]->depth >decorVS[i+1]->depth)
            {
                DecorSprite *temp = decorVS[i];
                decorVS[i] = decorVS[i+1];
                decorVS[i+1] = temp;
                sorted  =false ;
            }
        }
    }
    for (size_t i=0;i<   decorVS.size();i++)
    {
        stageVS.addChild( decorVS[i]);
        
    }

    for (int i=0;i<6;i++)
    {
        SpecialAttack *attack = &_specialAttacks[i];

        attack->setup();
        stageVS.addChild(attack);
    }
    
    
    
    ///hero
    //setHeroData(heroVSM,0);
    stageVS.addChild(&heroVSM);
    heroVSM.setup(0);
    liveVS.push_back(&heroVSM);

    //setHeroData(heroVSF,1);
    stageVS.addChild(&heroVSF);
    heroVSF.setup(1);
    liveVS.push_back(&heroVSF);

    
    //life stuff

    stageVS.addChild(&lifeBoyHolderVS);
    lifeBoyHolderVS.currentData = &boyInterData;
    stageVS.addChild(&lifeGirlHolderVS);
    lifeGirlHolderVS.currentData = &girlInterData;
    lifeBoy.setup();
    lifeGirl.setup();
    lifeGirl.fx =1;
    lifeGirl.fy=-2;
    lifeBoy.fx =0;
    lifeBoy.fy=-2;
    lifeBoyHolderVS.addChild(&lifeBoy);
    lifeGirlHolderVS.addChild(&lifeGirl);

    _gameOverText.fy = 0;
    _gameOverText.fx = 0;
    stageVS.addChild(&_gameOverText);
}

void PixelMain::resetGameVS()
{
    lifeBoyHolderVS.fx =-15;
    lifeBoyHolderVS.fy =16;
    lifeGirlHolderVS.fx =104;
    lifeGirlHolderVS.fy =16;
    lifeGirl.reset();
    lifeBoy.reset();

    lifeBoyHolder1p.fx =-15;
    lifeBoyHolder1p.fy =16;

    heroVSM.fxReal = 20;
    heroVSM.fx =20;
    heroVSM.fy = -16;
    heroVSM.isAir =true;
    heroVSM.reset();

    heroVSF.fxReal = 70;
    heroVSF.fx =70;
    heroVSF.fy = -16;
    heroVSF.isAir =true;
    heroVSF.reset();
}
void PixelMain::updateGameVS(float timeElapsed)
{
    switch (gameState)
    {
    case STATE_GAME_START:
        lifeBoyHolderVS.fx = Sprite::linearEase(1-switchTime,-15,19,1);
        lifeGirlHolderVS.fx = Sprite::linearEase(1-switchTime,104,-19,1);

        switchTime -=timeElapsed;
        if(switchTime<0){
            setGameState(STATE_GAME);
            lifeBoyHolderVS.fx = 4;
            lifeGirlHolderVS.fx = 85;
        }

        return;

    case STATE_GAME_OVER:
        switchTime -=timeElapsed;
        _gameOverText.update(switchTime);

        if(switchTime<0)
        {
            _gameOverText.hide();
            setGameState(STATE_INTRO);
            return;
        }
        break;

    case STATE_GAME:
        if(heroVSF.life==0)
        {
            _gameOverText.show(1);

            setGameState(STATE_GAME_OVER);
        }
        if(heroVSM.life==0)
        {
            _gameOverText.show(2);

            setGameState(STATE_GAME_OVER);
        }
        break;
    }

    resolveShoot(liveVS);
    checkShoot(liveVS);

    heroVSM.update(timeElapsed);
    heroVSF.update(timeElapsed);

    resolveAttack(liveVS);

    for (size_t i=0;i<MAX_ATTACKS;i++)
        _specialAttacks[i].update(timeElapsed,stagefx);

    //
    //check hit etc
    //
    
    if(heroVSM.hitTestRect(&heroVSF))
    {
        heroVSM.speed =0;
        if(heroVSM.fxReal< heroVSF.fxReal)
        {
            heroVSM.fxReal-=0.5;
            heroVSF.fxReal+=0.5;
        }
        else
        {
            heroVSM.fxReal+=0.5;
            heroVSF.fxReal-=0.5;
        }
    }

    if(heroVSF.fxReal<5)
        heroVSF.fxReal =84;

    if(heroVSF.fxReal>85)
        heroVSF.fxReal =6;

    if(heroVSM.fxReal<5)
        heroVSM.fxReal =84;

    if(heroVSM.fxReal>85)
        heroVSM.fxReal =6;

    heroVSM.setLevelPos(stagefx);
    heroVSF.setLevelPos(stagefx);

    for (size_t i=0;i<   decorVS.size();i++)
        decorVS[i]->setLevelPos(stagefx);

    lifeGirl.setLife(heroVSF.life);
    lifeBoy.setLife(heroVSM.life);
    
    lifeBoy.update(timeElapsed);
    lifeGirl.update(timeElapsed);
}
