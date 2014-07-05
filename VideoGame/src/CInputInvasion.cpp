/*
file:			CInputInvasion.cpp
description:	-
author:			matthias
*/

#include "CInputInvasion.h"

void CInputInvasion::keyDown(KeyEvent event, PixelMain* pPixelMain, bool lock)
{
    //console()<< KeyEvent::KEY_RIGHT << " "<< event.getCode()<<endl;
    if(lock)return;
    if(event.getCode()==KeyEvent::KEY_ESCAPE)
    {
        //v
        pPixelMain->setGameState(STATE_INTRO);
        return;
    }
    if(event.getCode()==102)
    {
        //v
        pPixelMain->setInput(25);
        
    }
    if(event.getCode()==103)
    {
        //b
        pPixelMain->setInput(21);
        
    }
    if(event.getCode()==104)
    {
        //n
        pPixelMain->setInput(23);
        
    }
    if(event.getCode()==44)
    {
        //v
        pPixelMain->setInput(5);
        
    }
    if(event.getCode()==46)
    {
        //b
        pPixelMain->setInput(1);
        
    }
    if(event.getCode()==47)
    {
        //n
        pPixelMain->setInput(3);
      
    }
    if(event.getCode()==KeyEvent::KEY_RIGHT && !rightR)
    {
        rightR =true;
        leftR =false;
        setKeysR(pPixelMain);
    }
    if(event.getCode()==KeyEvent::KEY_LEFT && !leftR)
    {
        rightR =false ;
        leftR =true;
        setKeysR(pPixelMain);
  
    }
    if(event.getCode()==KeyEvent::KEY_UP && !upR )
    {
        upR =true;
        downR =false;
       setKeysR(pPixelMain);
    }
    if(event.getCode()==KeyEvent::KEY_DOWN && !downR)
    {
        upR =false;
        downR =true;
        setKeysR(pPixelMain);
    }
    
    
    if(event.getCode()==KeyEvent::KEY_d && !rightL)
    {
        rightL =true;
        leftL =false;
        setKeysL(pPixelMain);
    }
    if(event.getCode()==KeyEvent::KEY_a && !leftL)
    {
        rightL =false ;
        leftL =true;
        setKeysL(pPixelMain);
        
    }
    if(event.getCode()==KeyEvent::KEY_z && !upL )
    {
        upL =true;
        downL =false;
        setKeysL(pPixelMain);
    }
    if(event.getCode()==KeyEvent::KEY_s && !downL)
    {
        upL =false;
        downL =true;
        setKeysL(pPixelMain);
    }

    
}
void CInputInvasion::keyUp(KeyEvent event, PixelMain* pPixelMain, bool lock)
{
      if( lock)return;
    if(event.getCode()==KeyEvent::KEY_ESCAPE)
    {
    
        return;
    }
    if(event.getCode()==102)
    {
        //v
        pPixelMain->setInput(24);
        
    }
    if(event.getCode()==103)
    {
        //b
        pPixelMain->setInput(20);
        
    }
    if(event.getCode()==104)
    {
        //n
        pPixelMain->setInput(22);
        
    }
    if(event.getCode()==44)
    {
        //v
         pPixelMain->setInput(4);
        
    }
    if(event.getCode()==46)
    {
        //b
         pPixelMain->setInput(0);
         
    }
    if(event.getCode()==47)
    {
        //n
         pPixelMain->setInput(2);
        
    }
    
    if(event.getCode()==KeyEvent::KEY_RIGHT)
    {
        rightR =false;
        setKeysR(pPixelMain);
    }
    if(event.getCode()==KeyEvent::KEY_LEFT)
    {
        leftR =false;
       setKeysR(pPixelMain);
    }
    if(event.getCode()==KeyEvent::KEY_UP)
    {
        upR=false;
         setKeysR(pPixelMain);
    }
    if(event.getCode()==KeyEvent::KEY_DOWN)
    {
        downR  =false;
    setKeysR(pPixelMain);
    }
    
    
    
    if(event.getCode()==KeyEvent::KEY_d)
    {
        rightL =false;
        setKeysL(pPixelMain);
    }
    if(event.getCode()==KeyEvent::KEY_a)
    {
        leftL =false;
        setKeysL(pPixelMain);
    }
    if(event.getCode()==KeyEvent::KEY_z)
    {
        upL=false;
        setKeysL(pPixelMain);
    }
    if(event.getCode()==KeyEvent::KEY_s)
    {
        downL  =false;
        setKeysL(pPixelMain);
    }
   
}
void CInputInvasion::setKeysL(PixelMain* pPixelMain)
{
    if(upL)
    {
        if(leftL)
        {
            pPixelMain->setInput(38);
        }
        else if(rightL)
        {
            pPixelMain->setInput(32);
            
        }else
        {
            pPixelMain->setInput(31);
            
        }
        
    }
    else if(downL)
    {
        if(leftL)
        {
            pPixelMain->setInput(36);
            
        }
        else if(rightL)
        {
            pPixelMain->setInput(34);
            
        }else
        {
            pPixelMain->setInput(35);
            
        }
        
        
    }
    else if(leftL)
    {
        pPixelMain->setInput(37);
    }
    else if(rightL)
    {
        pPixelMain->setInput(33);
        
    }
    else
    {
        
        pPixelMain->setInput(30);
        
        
    }   
}

void CInputInvasion::setKeysR(PixelMain* pPixelMain)
{
    if(upR)
    {
        if(leftR)
        {
            pPixelMain->setInput(18);
        }
        else if(rightR)
        {
         pPixelMain->setInput(12);
        
        }else
        {
         pPixelMain->setInput(11);
        
        }
    
    }
    else if(downR)
    {
        if(leftR)
        {
            pPixelMain->setInput(16);
            
        }
        else if(rightR)
        {
            pPixelMain->setInput(14);
            
        }else
        {
            pPixelMain->setInput(15);
            
        }
    
    
    }
    else if(leftR)
    {
        pPixelMain->setInput(17);
    }
    else if(rightR)
    {
        pPixelMain->setInput(13);
        
    }
    else
    {
    
    pPixelMain->setInput(10);

    }
}