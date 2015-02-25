//
//  Live.h
//  PixelGameLocal
//
//  Created by Kris Temmerman on 20/10/13.
//
//

#ifndef PixelGameLocal_Life_h
#define PixelGameLocal_Life_h

#include "Sprite.h"

#include "DataLife0.h"
#include "DataLife1.h"
#include "DataLife2.h"
#include "DataLife3.h"

#include "DataLife4.h"
#include "DataLife5.h"
#include "DataLife6.h"
#include "DataLife7.h"
#include "DataLifeLight.h"

class Life:public Sprite
{
public:
    Life() {currentTime=0;}
        
    const DataLife0<> life0;
    const DataLife1<> life1;
    const DataLife2<> life2;
    const DataLife3<> life3;
    const DataLife4<> life4;
    const DataLife5<> life5;
    const DataLife6<> life6;
    const DataLife7<> life7;
    const DataLifeLight<> lifeGlow;

    Sprite glow;
    float currentTime;
    int lifeCount;
    void setup()
    {
        glow.fx =0;
        glow.fy =1;
        glow.currentData = &lifeGlow;
        addChild(&glow);
        glow.visible =false;
    }
    void reset()
    {
        currentData = &life7;
        lifeCount =7;
    }
    void setLife(int i)
    {
        if(lifeCount==i)return;
        lifeCount = i;
        if(i==6)currentData = &life6;
        else if(i==5)currentData = &life5;
        else if(i==4)currentData = &life4;
        else if(i==3)currentData = &life3;
        else if(i==2)currentData = &life2;
        else if(i==1)currentData = &life1;
        else if(i==0)currentData = &life0;
       
          glow.visible =true;
            currentTime =1;
       
        
    }
    void update(float timeElapsed)
    {
      if(currentTime<=0)return;
        currentTime-=timeElapsed;
         if(currentTime<=0)glow.visible =false;
  
    
    }
};

#endif
