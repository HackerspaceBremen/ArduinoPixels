//
//  AlienPond.h
//  PixelGameLocal
//
//  Created by Kris Temmerman on 04/11/13.
//
//

#ifndef PixelGameLocal_AlienPond_h
#define PixelGameLocal_AlienPond_h
#include "Alien.h"

#include "DataPond.h"
#include "DataDuckBig.h"
#include "DataDuckSmall.h"

class AlienPond : public Alien
{
    float currentTime ;
    Sprite duckSmallSprite;
    Sprite duckBigSprite;

    const DataPond<> alienPond;
    const DataDuckBig<> alienDuckBig;
    const DataDuckSmall<> alienDuckSmall;
    
public:
    AlienPond(){ }
    void setup(){
        
        heroType=5;
        addChild(&duckBigSprite);
        addChild(&duckSmallSprite);

        currentData = &alienPond;
        duckBigSprite.currentData = &alienDuckBig;
        duckSmallSprite.currentData = &alienDuckSmall;
      
        currentTime =0;
       
        hitRect.x  =-4;
        hitRect.y =-3;
        
        hitRect.width  =7;
        hitRect.height =2;
        
    }
    virtual void update(float timeElapsed) override
    {
        currentTime+=timeElapsed;
        float dir =sin(currentTime);
        float dir2 =sin(currentTime-1);
        
        float bigOld = duckBigSprite.fx;
        float smallOld =  duckSmallSprite.fx;
        duckBigSprite.fx  =  dir*5 +1;
        duckSmallSprite.fx =  dir2*5 +1;
        duckBigSprite.drawType =0;
        duckBigSprite.fy = -2;
        duckSmallSprite.drawType =0;
        duckSmallSprite.fy = -2;

        if(bigOld<duckBigSprite.fx)
        {
            duckBigSprite.fy = -1;
            duckBigSprite.drawType =1;
        }

        if(smallOld< duckSmallSprite.fx)
        {
            duckSmallSprite.fy = -1;
            duckSmallSprite.drawType =1;
        }
    }
};



#endif
