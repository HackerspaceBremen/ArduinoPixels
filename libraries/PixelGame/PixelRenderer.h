//
//  PixelRenderer.h
//  PixelGame
//
//  Created by Kris Temmerman on 15/09/13.
//  Copyright (c) 2013 Kris Temmerman. All rights reserved.
//

#ifndef PixelGame_PixelRenderer_h
#define PixelGame_PixelRenderer_h
#ifdef _WINDOWS
#include "cinder/Color.h"
#include "cinder/gl/gl.h"
#else
#include "Adafruit_NeoPixel.h"
#endif

#include "PixelGameInclude.h"

class PixelRenderer
{
public:

#ifdef _WINDOWS
	 PixelRenderer()
    {
        height =16;
        width =90;
    
    };
    void setBrightness(int val){};
    void setup()
    {
        height =16;
        width =90;
         size = height*width*3 ;
        buffer =new float[size];
        for(int i=0;i<size;i++)
        {
            buffer[i]=0;
        
        }

    };
    void clear()
    {
        size = height*width*3;
     
        for(int i=0;i<size;i++)
        {
            buffer[i]=0.5;
            
        }

    
    }
    void setPixel(int x, int y, int  r,int  g, int  b,int a)
    {
   
        int pos = (x+(y*width))*3;
        if(pos>size-3)return;
        if (pos<0)return;
        if(a==255)
        {
            buffer[pos]=(float)r/255.f;
            pos++;
            buffer[pos]=(float)g/255.f;
            pos++;
            buffer[pos]=(float)b/255.f;
        
        }
        else
        {
        
            float alpha = (float)a/255;
            float alpha1 =1-alpha;
            float rOld = buffer[pos];
            buffer[pos] =rOld*alpha1 +(float)r/255*alpha;
            pos++;
        
            
            float gOld = buffer[pos];
            buffer[pos] =gOld*alpha1 +(float)g/255*alpha;
            pos++;

            
            
            float bOld = buffer[pos];
            buffer[pos] =bOld*alpha1 +(float)b/255*alpha;
            

        
        }
    
    };
    void draw()
    {
      
        int size=13;
        int pos=0;
        
        for(int y=0;y<height;y++)
        {
            for(int x=0;x<width;x++)
            {
                float  r =buffer[pos++];
              float  g =buffer[pos++];
                 float  b =buffer[pos++];
                 glColor3f(r,g,b);
                    cinder::gl::drawSolidRect( cinder::Rectf(x*(size)+10,y*(size)+10,x*(size)+size+10,y*(size)+size+10));
            }
        }    
    
    };
    float * buffer;
    int height;
    int width;
    int size;
#else
    
    Adafruit_NeoPixel *strip1;
    Adafruit_NeoPixel *strip2;
    Adafruit_NeoPixel *strip3;
    Adafruit_NeoPixel *strip4;
    Adafruit_NeoPixel *strip5;
    Adafruit_NeoPixel *strip6;
    
    
    PixelRenderer();
   
    void setup();
   
    void draw();
        
    void setPixel(int x,int y,uint8_t r, uint8_t g , uint8_t b, uint8_t a);
       
    void setPixel(int x, int y, uint32_t c);
    void setBrightness(int val);
    void fade();
#endif    
};

#endif
