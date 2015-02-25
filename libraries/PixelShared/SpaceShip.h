//
//  SpaceShip.h
//  PixelGameLocal
//
//  Created by Kris Temmerman on 26/10/13.
//
//

#ifndef PixelGameLocal_SpaceShip_h
#define PixelGameLocal_SpaceShip_h
#include "Sprite.h"
#include "Alien3.h"

class SpaceShip:public Sprite
{
    float headTime;
    Sprite head;
    Sprite ship;
    Sprite armL;
    Sprite armR;

public:
    SpaceShip(){}
    void setup()
    {
        armL.currentData = &dataArmL;
        addChild(&armL);

        armR.currentData = &dataArmR;
        addChild(&armR);

        head.currentData = &dataHead;
        //head.fy =-4;
        head.fy =-2;
        addChild(&head);

        ship.currentData = &dataBottom;
        addChild(&ship);
        //ship.fy =3;
        ship.fy =1;
        headTime =6;
    }
    void reset()
    {
        headTime =6;
        ship.fy =0;
        head.fy =-2;
        armR.fx=0;
          armL.fx=0;
        armR.fy =head.fy-2;
        armL.fy =head.fy-2;
    }
    void showHead()
    {
    
        headTime =0;
    
    }
    void update(float timeElapsed)
    {
        
        if(headTime>4.5)return;
        if(headTime<0.3)
        {
            head.fy  =Sprite::backEaseOut(headTime,-2 , -2, 0.3);
           ship.fy  =Sprite::backEaseOut(headTime,0 , 1, 0.3);
            
        
        }if(headTime>0.3)
        {
            head.fy  =-4;//backEaseOut(headTime,-2 , -2, 0.5);
            ship.fy  =2;//backEaseOut(headTime,1 , 2, 0.5);
    
        }
        armR.fy =head.fy-1;
        armL.fy =head.fy-2;
        
        if(headTime>0.5 && headTime <1)
        {
            float armTime = headTime-0.5;
          armR.fx   =cubicEaseOut( armTime,0 ,5, 0.5);
             armL.fx   =cubicEaseOut( armTime,1 ,-5, 0.5);
        
            
        }
        
       else  if(headTime>1.5 && headTime<3 )
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
                
                armR.fx   = 5;
                armL.fx = -4;
                armR.drawType =0;
                armL.drawType =0;
             
                armR.fy =head.fy-1;
                armL.fy =head.fy-2;

            
            }

            
        } else  if(headTime>4 && headTime<4.5 )
        {
            float armTime = headTime-4;

            armR.fx   =cubicEaseOut( armTime,5 ,-5,0.5);
            armL.fx   =cubicEaseOut( armTime,-4 ,5, 0.5);
            head.fy  =cubicEaseOut(armTime,-4 , 2.1, 0.5);
            ship.fy  =cubicEaseOut(armTime ,2, -2,0.5);

            
        }
        
        headTime+=timeElapsed;
        
       
    }
};


#endif
