//
//  PixelMain_Game_p2.cpp
//  PixelGameLocal
//
//  Created by Kris Temmerman on 28/10/13.
//
//

#include "PixelMain.h"
#include "GameOverText.h"
void PixelMain::setupGame2p()
{
    stage.addChild(&hero2pF);
    hero2pF.setup(1);
    live.push_back(&hero2pF);

    stage.addChild(&hero2pM);
    hero2pM.setup(0);
    live.push_back(&hero2pM);


    //life stuff

    stage.addChild(&lifeBoyHolder2p);
    lifeBoyHolder2p.currentData = &boyInterData;
    stage.addChild(&lifeGirlHolder2p);
    lifeGirlHolder2p.currentData = &girlInterData;
    lifeBoy.setup();
    lifeGirl.setup();
    lifeGirl.fx =1;
    lifeGirl.fy=-2;
    lifeBoy.fx =0;
    lifeBoy.fy=-2;
    lifeBoyHolder2p.addChild(&lifeBoy);
    lifeGirlHolder2p.addChild(&lifeGirl);

    stage.addChild(&waterSplash2p);

    
    for (int i=0;i<MAX_BLOOD;i++)
    {
        Blood *blood = &_bloods[i];
        blood->setup();
        stage.addChild(blood);
    }

    //gameOver
    _gameOverText.fy = 0;
    _gameOverText.fx = 0;
    stage.addChild(&_gameOverText);
}
void PixelMain::resetGame2p()
{
    hero2pM.fxReal = 20;
    hero2pM.fx =20;
    hero2pM.fy = -16;
    hero2pM.reset();

    hero2pF.fxReal = 27;
    hero2pF.fx =27;
    hero2pF.fy = -16;
    hero2pF.reset();
    hero2pF.groundY =14;
    
    lifeBoyHolder2p.fx =-15;
    lifeBoyHolder2p.fy =16;
    lifeGirlHolder2p.fx =104;
    lifeGirlHolder2p.fy =16;
    lifeGirl.reset();
    lifeBoy.reset();

    hero2pF.setLevelPos(stagefx);
    
    hero2pM.setLevelPos(stagefx);
    
    for(size_t i=0;i< aliens.size();i++)
    {
        aliens[i]->setLevelPos(stagefx);
    }
}

void PixelMain::updateGame2p (float timeElapsed)
{
    switch (gameState)
    {
    case STATE_GAME_START:
        lifeBoyHolder2p.fx = Sprite::linearEase(1-switchTime,-15,19,1);
        lifeGirlHolder2p.fx = Sprite::linearEase(1-switchTime,104,-19,1);

        switchTime -=timeElapsed;
        if(switchTime<0){
            setGameState(STATE_GAME);
            lifeBoyHolder2p.fx = 4;
            lifeGirlHolder2p.fx = 85;
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
        if(alienBoss->isDead)
        {
            _gameOverText.show(3);

            setGameState(STATE_GAME_OVER);
            return;
        }
        if(hero2pM.life<=0 && hero2pF.life<=0)
        {
            _gameOverText.show();

            setGameState(STATE_GAME_OVER); ;
        }
        break;
    }

    for(size_t i=0;i< aliens.size();i++)
        aliens[i]->update(timeElapsed);
    
    hero2pM.update(timeElapsed);
    hero2pF.update(timeElapsed);
    
    resolveShoot(live);
    checkShoot(live);

    for (size_t i=0;i<MAX_ATTACKS;i++)
        _specialAttacks[i].update(timeElapsed,stagefx);

    if(hero2pM.fxReal < -10 )
    {
        hero2pM.fxReal  =-10;
        hero2pM.setKey(0);
    }
    
    if(hero2pF.fxReal < -10 )
    {
        hero2pF.fxReal  =-10;
        hero2pF.setKey(0);
    }
    Hero * first;
    Hero *last;
    if(hero2pM.fxReal >hero2pF.fxReal )
    {
        first = &hero2pM;
        last= &hero2pF;
    }
    else
    {
        first = &hero2pF;
        last= &hero2pM;
    }

    if(first->fxReal > stagefx+60 )
        stagefx +=first->fxReal -( stagefx+60 );
    else if(first->fxReal < stagefx+30)
        stagefx -= ( stagefx+30 )-first->fxReal;

    if(last->fxReal < stagefx+5  )
        last->fxReal =stagefx+5;

    alienHitTest(&hero2pM);
    alienHitTest(&hero2pF);
    resolveAttack(live);

    hero2pF.setLevelPos(stagefx);
    
    hero2pM.setLevelPos(stagefx);
    
    for(size_t i=0;i< aliens.size();i++)
        aliens[i]->setLevelPos(stagefx);
    
    lifeBoy.setLife(hero2pM.life);
    lifeGirl.setLife(hero2pF.life);
    
    lifeBoy.update(timeElapsed);
    lifeGirl.update(timeElapsed);

    waterSplash2p.update(timeElapsed,stagefx);

}
