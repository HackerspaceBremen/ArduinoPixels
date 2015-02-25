//
//  PixelMain_Game_p1.cpp
//  PixelGameLocal
//
//  Created by Kris Temmerman on 28/10/13.
//
//

#include "PixelMain.h"

#include "GameOverText.h"
void PixelMain::setupGame1p()
{
     ///hero
    // setHeroData(&hero1pm,0);
    stage.addChild(&hero1pm);
    hero1pm.setup(0);
   
    live.push_back(&hero1pm);
    
    
    //life
    lifeBoyHolder1p.currentData = &boyInterData ;
    lifeBoy.setup();
    lifeBoy.fx =0;
    lifeBoy.fy=-2;
    
    lifeBoyHolder1p.addChild(&lifeBoy);
    stage.addChild(&lifeBoyHolder1p);

    stage.addChild(&waterSplash1p);
    
    
    for (int i=0;i<MAX_BLOOD;i++)
    {
        Blood *blood = &_bloods[i];
        blood->setup();
        stage.addChild(blood);
    }
    _gameOverText.fy = 0;
    _gameOverText.fx =0;
    stage.addChild(&_gameOverText);
    
    
}
void PixelMain::resetGame1p()
{
    lifeBoy.reset();
    lifeBoyHolder1p.fx =-15;
    lifeBoyHolder1p.fy =16;
    hero1pm.fxReal = 20;
    hero1pm.fx =20;
    hero1pm.fy = -16;
    hero1pm.reset();
    _gameOverText.fy = 0;

    hero1pm.setLevelPos(stagefx);

    for(size_t i=0;i< aliens.size();i++)
    {
        aliens[i]->setLevelPos(stagefx);
    }
}

void PixelMain::updateGame1p (float timeElapsed)
{
    switch (gameState)
    {
    case STATE_GAME_START:
        lifeBoyHolder1p.fx = Sprite::linearEase(1-switchTime,-15,19,1);

        switchTime -=timeElapsed;
        if(switchTime<0){
            setGameState(STATE_GAME);
            lifeBoyHolder1p.fx = 4;
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
        if( alienBoss->isDead)
        {
            _gameOverText.show(3);

            setGameState(STATE_GAME_OVER);
        }

        if(hero1pm.life==0)
        {
            _gameOverText.show();

             setGameState(STATE_GAME_OVER);
        }
        break;
    }

    for(size_t i=0;i< aliens.size();i++)
        aliens[i]->update(timeElapsed);

    hero1pm.update(timeElapsed);

    resolveShoot(live);
    checkShoot(live);

    if(hero1pm.fxReal < -10 )
    {
        hero1pm.fxReal  =-10;
        hero1pm.setKey(0);
    }
    if(hero1pm.fxReal >550 )
    {
        endGame =true;
    }
    if( endGame )
    {
        if(hero1pm.fxReal <550 )
        {
            hero1pm.fxReal  =550;
            hero1pm.setKey(0);
        }
        if(hero1pm.fxReal >640 )
        {
            hero1pm.fxReal  =640;
            hero1pm.setKey(0);
        }
    }
    if(hero1pm.fxReal > stagefx+60 )
    {
        stagefx += hero1pm.fxReal -( stagefx+60 );
    }
    else  if(hero1pm.fxReal < stagefx+15)
    {
        stagefx -= ( stagefx+15 )-hero1pm.fxReal;
    }

    for (size_t i=0;i<MAX_ATTACKS;i++)
    {
        _specialAttacks[i].update(timeElapsed, stagefx);
    }
    alienHitTest(&hero1pm);

    resolveAttack(live);


    hero1pm.setLevelPos(stagefx);

    for(size_t i=0;i< aliens.size();i++)
        aliens[i]->setLevelPos(stagefx);

    lifeBoy.setLife(hero1pm.life);
    lifeBoy.update(timeElapsed);

    waterSplash1p.update(timeElapsed,stagefx);
}
