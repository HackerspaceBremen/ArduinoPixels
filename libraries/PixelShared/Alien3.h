//
//  Alien3.h
//  PixelGameLocal
//
//  Created by Kris Temmerman on 04/11/13.
//
//

#ifndef PixelGameLocal_Alien3_h
#define PixelGameLocal_Alien3_h

#include "Alien.h"
#include "DataSpaceArmL.h"
#include "DataSpaceArmR.h"
#include "DataSpaceHead.h"
#include "DataSpaceBottem.h"

const DataSpaceArmL<> dataArmL;
const DataSpaceArmR<> dataArmR;
const DataSpaceBottem<> dataBottom;
const DataSpaceHead<> dataHead;

class Alien3: public Alien
{
    float waitshoot;
    float posTime;
    Sprite head;
    Sprite ship;
    Sprite armL;
    Sprite armR;

public:
    Alien3() : waitshoot(0), posTime(0) {}
    void setup(){
        
        heroType=4;

        armL.currentData = &dataArmL;
        addChild(&armL);

        armR.currentData = &dataArmR;
        addChild(&armR);

        head.currentData = &dataHead;
        //head.fy =-4;
        head.fy =-1;
        addChild(&head);

        ship.currentData = &dataBottom;
        addChild(&ship);
        //ship.fy =3;
        ship.fy =1;

        fxStart =fx;

        hitRect.x  =-8;
        hitRect.y =-7;
        
        hitRect.width  =16;
        hitRect.height =7;
        life=3;
        
        }
    
    virtual void resetImpl() override
    {
        fxReal =fxStart;
        isDead =false;
        life =3;
        fy =15;
        saveTime =-1;
    }
       
    float fxStart;
    virtual void update(float timeElapsed) override
    {
        
     
         if(intHidden)return;
       // if(fx >120)return;
        saveTime -=timeElapsed;
        if(isDead)
        {
            fy-=1;
            if(fy<20)intHidden =true;
            fxReal+=hitSpeed* timeElapsed;
            hitSpeed*=0.4;
            return;
        }
        
        posTime+=timeElapsed;
        if(posTime>16  )posTime =0;
        if(posTime>0 && posTime<=2)
        {
            //  ship.fy  =cubicEaseOut(posTime,1 , 2, 2);
            fxReal = cubicEaseInOut(posTime,20 , -40, 2)+fxStart;
            if(posTime<=1)
            {
                fy = cubicEaseInOut(posTime,15 , -14, 1);
            }
            
            if(posTime<=2 && posTime>=1)
            {
                fy = cubicEaseInOut(posTime-1,1 , 14, 1);
            }
        }
        if(posTime>8 && posTime<=10)
        {
            
            float tPos =posTime-8;
            fxReal = cubicEaseInOut(tPos,-20 , 40, 2)+fxStart;
            
            if(tPos<=1)
            {
                fy = cubicEaseInOut(tPos,15 , -14, 1);
            }
            
            if(tPos<2 && tPos>=1)
            {
                fy = cubicEaseInOut(tPos-1,1 , 14, 1);
            }

           
            
        }
        if(fy>14)fy=14;
        
        if(posTime>2&& posTime<=8)showHead(posTime-2);
        if(posTime>10&& posTime<=16)showHead(posTime-10);
        waitshoot-=timeElapsed;
    }
    void showHead(float headTime)
    {
        if(headTime<=0.3 )
        {
            head.fy  =cubicEaseOut(headTime,-2 , -2, 0.3);
                     
        }else if(headTime>5.7 && headTime <=6)
        {
            head.fy  =cubicEaseOut(headTime-5.7,-4 ,3, 0.3);
        }else
        {
            head.fy=-5;
        }
        if(headTime>1.5 && headTime<5 )
        {
            int armTimeInt = (headTime-1.5)*5;
            
            if( armTimeInt%2==0)
            {
                armR.drawType =1;
                armL.drawType =1;
                armR.fx   = -4;
                armL.fx =5;
                armR.fy =head.fy-1;
                armL.fy =head.fy-2;
                
            }else
            {
                if(waitshoot<0){
                    waitshoot=0.4;
                    if (drawType==1)drawType =0;
                    else drawType =1;
               startShoot =true;
                }
                armR.fx   = 5;
                armL.fx = -4;
                armR.drawType =0;
                armL.drawType =0;
                
                armR.fy =head.fy-1;
                armL.fy =head.fy-2;
                
                
            }
            armR.visible  =true;
            armL.visible  =true;

            
        }else
        {
            armR.visible  =false;
            armL.visible  =false;
        }

    
    
    }
};



#endif
