//
//  PixelMain_Menu.cpp
//  PixelGameLocal
//
//  Created by Kris Temmerman on 25/10/13.
//
//

#include "PixelMain.h"

#include "DataBackSky.h"
#include "DataMenuMain.h"
#include "DataMenuSelect1.h"
#include "DataMenuSelect2.h"
#include "DataMenuSelect3.h"
#include "DataBackSky.h"

const DataBackSky<> dataBackSky;
const DataMenuMain<> dataMenuMain;
const DataMenuSelect1<> dataMenuSelect1;
const DataMenuSelect2<> dataMenuSelect2;
const DataMenuSelect3<> dataMenuSelect3;

void PixelMain::setupMenu()
{
    backgroundMenu.drawType =3;
    backgroundMenu.currentData = &dataBackSky;
    stageMenu.addChild(&backgroundMenu);

    menuBack.currentData = &dataMenuMain;
    menuBack.fx =45;
    menuBack.fy =11;
    stageMenu.addChild(&menuBack);

    menuItem1.currentData = &dataMenuSelect1;
    menuItem1.fx =12;
    menuItem1.fy =12;
    
    stageMenu.addChild(&menuItem1);

    menuItem2.visible =false;
    menuItem2.currentData = &dataMenuSelect2;
    menuItem2.fx =44;
    menuItem2.fy = 12;
    stageMenu.addChild(&menuItem2);

    menuItem3.visible =false;
    menuItem3.currentData = &dataMenuSelect3;
    menuItem3.fx =77;
    menuItem3.fy = 12;
    stageMenu.addChild(&menuItem3);

    menuPos=0;
}

void PixelMain::menuRight()
{
    menuPos++;
    menuItem1.visible =false;
    menuItem2.visible =false;
    menuItem3.visible =false;
  
    
    if(  menuPos>2){
        menuPos =0;
        
    }
    
    if(menuPos==0 )
    {
        menuItem1.visible =true ;
    }
    else  if(menuPos==1  )
    {
        menuItem2.visible =true ;
    }
    else if(menuPos==2 )
    {
        menuItem3.visible =true ;
    }

    

}void PixelMain::menuLeft()
{
  
    menuItem1.visible =false;
    menuItem2.visible =false;
    menuItem3.visible =false;
    menuPos--;

    switch (menuPos)
    {
    case 0:
        menuItem1.visible = true;
        break;

    case 1:
        menuItem2.visible = true;
        break;

    default:
        menuPos = 2;
    case 2:
        menuItem3.visible = true;
        break;
    }
}
void PixelMain::updateMenu(float /*timeElapsed*/)
{
}
