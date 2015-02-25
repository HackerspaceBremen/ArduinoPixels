//
//  Hero.h
//  PixelGame
//
//  Created by Kris Temmerman on 05/10/13.
//  Copyright (c) 2013 Kris Temmerman. All rights reserved.
//

#ifndef PixelGame_Hero_h
#define PixelGame_Hero_h
#include "PixelGameInclude.h"
#include "Sprite.h"
#include "Vector.h"
#include "Live.h"
#define NO_ATTACK 0
#define HIT 1
#define KICK 2
#define BLOCK 3
#define SPECIAL_ATTACK 4
class Hero:public Live
{
public:
    Hero(){
        nonMove =true;
        isRight =true;
        isWalking =false;
        isAir = false;
        isCrouching =false;
        isDead =false;
        hitType=0;
        isWaterHit =false;
        isCrouchingWalking =false;
    };
    bool hitType;
   
   
    void setKey(uint8_t key);
    void setup(uint8_t type);
    void update(float timeElapsed);
    void startWalking();
    void startCrouching();
    void setLevelPos(float levelfx);
    void reset();
    void setDead();
        void hitWater();
    bool isWaterHit;
    float walkingTime;
    bool isCrouchingWalking;
    float screenfx;
    bool isDead;
    bool nonMove;
    bool isRight;
    bool isWalking;
    bool isAir;
    bool isCrouching;
   
    float attackTime;
 
  
    
    float jumpSpeed;//start jump speed
    float airFall;//fall speed
    float airSpeed;//current jump speed
    float speedStepX;
    float groundY;

    const PixelData * jumpData;
    const PixelData * jumpKickData;
    const PixelData * jumpHitData;
    const PixelData * jumpBlockData;
    
    
    const PixelData * crouchData;
    const PixelData * crouchWalk1Data;
    const PixelData * crouchWalk2Data;
    const PixelData * crouchKickData;
    const PixelData * crouchHitData;
    const PixelData * crouchBlockData;
    
    const PixelData * standData;
    
    const PixelData * standKickData;
    const PixelData * standHitData1;
    const PixelData * standHitData2;
    const PixelData * standBlockData;
    
    
    const PixelData * walk1Data;
    const PixelData * walk2Data;
    const PixelData * walk3Data;
    
    const PixelData * gotHitData1;
    const PixelData * gotHitData2;
    
    const PixelData * deathData;
    StackVector<int> lastKeys;
};


#endif
