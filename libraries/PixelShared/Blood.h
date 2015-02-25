//
//  Blood.h
//  PixelGameLocal
//
//  Created by Kris Temmerman on 17/10/13.
//
//

#ifndef PixelGameLocal_Blood_h
#define PixelGameLocal_Blood_h

#include "Sprite.h"
#include "PixelData.h"

#include "DataBlood1.h"
#include "DataBlood2.h"
#include "DataBlood3.h"

class Blood:public Sprite
{
    float currentTime = 0;
    const DataBlood1<> frame1;
    const DataBlood2<> frame2;
    const DataBlood3<> frame3;
public:
    float fxReal = 0;
    bool isUsed = false;

    Blood(){}
    void setup()
    {
        isUsed =false;
        currentTime =-1;
    }
    void show()
    {
        visible =true;
        isUsed =true;
        currentTime =0.35;
        currentData = &frame1;
    }
    
    void update(float timeElapsed,float stagefx)
    {
        if(visible==false)return;
        
        currentTime -=timeElapsed;
        if(currentTime>0.1 &&currentTime<0.2 )
        {
            currentData = &frame2;
        }
        else if(currentTime<0.1 )
        {
            currentData = &frame3;
        }
        if(currentTime<0.0 ){
            isUsed =false;
            visible =false;
        }
          setLevelPos(stagefx);
    }
    void setLevelPos(float stagefx)
    {
        fx = fxReal -stagefx;
    }
};




#endif
