//
//  PixelRenderer.cpp
//  PixelGame
//
//  Created by Kris Temmerman on 15/09/13.
//  Copyright (c) 2013 Kris Temmerman. All rights reserved.
//

#include "PixelRenderer.h"

/*
	PixelRenderer.cpp had to be rewritten because stripe arrangement is different.
	It is only one long stripe.

	Set define ONE_LONG_STRIPE to activate code.
*/

#define ONE_REALLY_LONG_STRIPE

#ifndef _WINDOWS

PixelRenderer::PixelRenderer()
{

}
void PixelRenderer::setBrightness(int br)
{
#ifndef ONE_REALLY_LONG_STRIPE
	strip1->setBrightness(br);
	strip2->setBrightness(br);
    strip3->setBrightness(br);
    strip4->setBrightness(br);
    strip5->setBrightness(br);
	strip6->setBrightness(br);
#else
	strip1->setBrightness(br);
#endif
}
void PixelRenderer::setup()
{
#ifndef ONE_REALLY_LONG_STRIPE
    int br =50;
    strip1 =new Adafruit_NeoPixel(270, 7, NEO_GRB + NEO_KHZ800);
    strip1->begin();
    strip1->setBrightness(br);
    strip1->show();
  
    strip2 =new Adafruit_NeoPixel(270, 6, NEO_GRB + NEO_KHZ800);
    strip2->begin();
	strip2->setBrightness(br);
    strip2->show();
    
  
    strip3 =new Adafruit_NeoPixel(270, 5, NEO_GRB + NEO_KHZ800);
    strip3->begin();
    strip3->setBrightness(br);
    strip3->show();
 
    strip4 =new Adafruit_NeoPixel(270, 4, NEO_GRB + NEO_KHZ800);
    strip4->begin();
    strip4->setBrightness(br);
    strip4->show();
  
    
    strip5 =new Adafruit_NeoPixel(270, 3, NEO_GRB + NEO_KHZ800);
    strip5->begin();
    strip5->setBrightness(br);
    strip5->show();
 
    strip6 =new Adafruit_NeoPixel(90, 2, NEO_GRB + NEO_KHZ800);
    strip6->begin();
    strip6->setBrightness(br);
    strip6->show();
#else
    int br =10;
    strip1 =new Adafruit_NeoPixel(1800, 2, NEO_GRB + NEO_KHZ800);
    strip1->begin();
    strip1->setBrightness(br);
    strip1->show();    
#endif
}
void PixelRenderer::fade()
{
#ifndef ONE_REALLY_LONG_STRIPE
    for(int i=0;i<270*3;i++)
    {
        strip1->pixels[i]*=0.9;
		strip2->pixels[i]*=0.9;
        strip3->pixels[i]*=0.9;
		strip4->pixels[i]*=0.9;
		strip5->pixels[i]*=0.9;
    
    } 
	for(int i=0;i<270;i++)
    {
        strip6->pixels[i]*=0.9; 
    }
#else
	// no fading implemented
#endif
    
}
void PixelRenderer::draw()
{
#ifndef ONE_REALLY_LONG_STRIPE
	strip1->show();
    strip2->show();
    strip3->show();
    strip4->show();
    strip5->show();
    strip6->show();
#else
	strip1->show(); 
#endif    
}

void PixelRenderer::setPixel(int x,int y,uint8_t r, uint8_t g , uint8_t b,uint8_t a)
{
#ifndef ONE_REALLY_LONG_STRIPE
    if(y<8)
    {
        if(y==0)
        {
            strip1->setPixelColor(89-x, r,g,b,a);
        }else if(y==1)
        {
            strip1->setPixelColor(90+x, r,g,b,a);
        
        }else if(y==2)
        {
            strip1->setPixelColor(269-x, r,g,b,a);
        
        }
    
 
       else if(y==3)
        {
            strip2->setPixelColor(89-x, r,g,b,a);
        }
        else if(y==4)
        {
            strip2->setPixelColor(90+x, r,g,b,a);
        
        }
        else if(y==5)
        {
            strip2->setPixelColor(269-x, r,g,b,a);
        
        }
    
    
    
        else if(y==6)
        {
            strip3->setPixelColor(89-x, r,g,b,a);
        }
        else if(y==7)
        {
            strip3->setPixelColor(90+x, r,g,b,a);
        
        }
    } else
    {
   
        if(y==8)
        {
            strip3->setPixelColor(269-x, r,g,b,a);
        
        }
    else if(y==9)
    {
        strip4->setPixelColor(89-x, r,g,b,a);
    }else if(y==10)
    {
        strip4->setPixelColor(90+x, r,g,b,a);
        
    }else if(y==11)
    {
        strip4->setPixelColor(269-x,r,g,b,a);
        
    }
    else if(y==12)
    {
        strip5->setPixelColor(89-x, r,g,b,a);
    }else if(y==13)
    {
            strip5->setPixelColor(90+x, r,g,b,a);
        
        }else if(y==14)
        {
            strip5->setPixelColor(269-x, r,g,b,a);
        
        }
    
        else if(y==15)
        {
            strip6->setPixelColor(89-x, r,g,b,a);
        }

    }
#else   
	/*
	TODO: 
	Explain this code a little bit more please.
	*/
	strip1->setPixelColor((y*90)+(((y%2)*89)-(y%2*x))+((1-y%2)*x), r,g,b,a);
#endif
}

#endif

