//
//  WaterSplash.h
//  PixelGameLocal
//
//  Created by Kris Temmerman on 18/11/13.
//
//

#ifndef PixelGameLocal_WaterSplash_h
#define PixelGameLocal_WaterSplash_h

#include "Sprite.h"
#include "PixelData.h"

#include "DataSplash1.h"
#include "DataSplash2.h"

class WaterSplash :public Sprite
{
    const DataSplash1<> splash1;
    const DataSplash2<> splash2;

    float time;
    const PixelData * frame1;
    const PixelData * frame2;
    
public:
    WaterSplash() : frame1(&splash1), frame2(&splash2)
    {
        visible =false;
    }
    void show(float _fxReal)
    {
        fy = 16;
        currentData =frame1;
        visible  =true;
        time =0;
        fxReal =_fxReal;
    }
    void update (float timeEllapsed, float levelfx)
    {
        if(!visible)return;
        fx =  fxReal-levelfx;
        time+=timeEllapsed;
        if(time>0.3)currentData =frame2;
        
        if(time>0.6)visible=false;
    
    }
};


#endif
