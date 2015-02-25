//
//  Live.h
//  PixelGameLocal
//
//  Created by Kris Temmerman on 29/10/13.
//
//

#ifndef PixelGameLocal_Live_h
#define PixelGameLocal_Live_h
#include "Sprite.h"
class Live :public Sprite
{

public:
    virtual void setDead(){isDead =true;}
    
    float speed = 0;
    bool startShoot = false;
    int heroType = 0;
    int attackType = 0;
    int hitX = 0;
    int hitY = 0;
    bool isDead = false;
    int life = 0;
    float saveTime = 0;
    float hitSpeed = 0;
    int hitFall = 0;
};

#endif
