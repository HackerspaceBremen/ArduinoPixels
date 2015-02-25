//
//  Sprite.h
//  pixelgame
//
//  Created by Kris Temmerman on 09/09/13.
//
//

#ifndef pixelgame_Sprite_h
#define pixelgame_Sprite_h
#include "PixelGameInclude.h"
#include "PixelData.h"
#include "Vector.h"
#include "npRect.h"
class Sprite
{
public:
    bool intHidden = false;
    int x = 0;
    int y = 0;
    float fxReal = 0;
    float fx = 0;
    float fy = 0;
    float drawfY = 0;
    float drawfX = 0;
    bool visible = true;
    float depth = 1;
    bool hasHitRect = false;
    npRect hitRect;
    const PixelData * currentData = nullptr;
    int drawType = 0;

    virtual void resetImpl() {}
    void reset()
    {
        resetImpl();

        intHidden = false;
        x = 0;
        y = 0;
        fxReal = 0;
        fx = 0;
        fy = 0;
        drawfY = 0;
        drawfX = 0;
        visible = true;
        depth = 1;
        hasHitRect = false;
        hitRect = npRect();
        currentData = nullptr;
        drawType = 0;

        // Recursively reset & clear
        children.resetAll();
        children.clear();
    }

    void addChild(Sprite *child)
    {
        child->parent =this;
        children.push_back(child);
    }

    Vector<Sprite *> children;
    Sprite * parent = nullptr;
    
    void int_update()
    {
        if(parent==0)
        {
            drawfY = fy;
            drawfX= fx;
            x = drawfX;
            y = drawfY;
        
        }else
        {
            drawfY = fy + parent->drawfY;
            drawfX= fx + parent->drawfX;
            x = drawfX;
            y = drawfY;
            intHidden = false;
            if(x>100 || x<-10)intHidden = true;
        }
        for(size_t i=0;i<children.size();i++)
        {
            children[i]->int_update();
        }
    }

    bool hitTestRect(Sprite *s)
    {
        float x_1 =fxReal+hitRect.x ;
        float x_2 =s->fxReal +s->hitRect.x ;
        float y_1 =fy +hitRect.y ;
        float y_2 =s->fy +s->hitRect.y ;
        float width_1 =hitRect.width;
        float width_2 = s->hitRect.width;
        float height_1 =hitRect.height;
        float height_2 =s->hitRect.height;
        
       bool hit = !(x_1 > x_2+width_2 || x_1+width_1 < x_2 || y_1 > y_2+height_2 || y_1+height_1 < y_2);
        
        hitRect.isHit =hit;
        s->hitRect.isHit =hit;
        
        
        return hit;
    
    
    }
    bool hitTest(int hitPosX,int hitPosY)
    {
        float x_l =fxReal+hitRect.x ;
        float y_t =fy+hitRect.y ;
        float x_r =x_l +hitRect.width ;
        float y_b =y_t+hitRect.height ;
        if(hitPosX>= x_l && hitPosX<= x_r && hitPosY>= y_t && hitPosY<= y_b)
            return true;
        return false;
    }

    //t is the current time (or position) of the tween. This can be seconds or frames, steps, seconds, ms, whatever – as long as the unit is the same as is used for the total time [3].
    //b is the beginning value of the property.
    //c is the change between the beginning and destination value of the property.
    //d is the total time of the tween.
    
    static float backEaseOut(float t,float b , float c, float d) {
        float s = 1.70158f;
	t = t/d-1;
        return c*(t*t*((s+1)*t + s) + 1) + b;
    }
    static float cubicEaseOut(float t,float b , float c, float d) {
        t = t/d-1;
        return c*(t*t*t + 1) + b;
    }

    static float cubicEaseInOut(float t,float b , float c, float d) {
	t/=d/2;
        if (t < 1) return c/2*t*t*t + b;
	t-=2;
        return c/2*(t*t*t + 2) + b;
    }

    static float expoEaseIn (float t,float b , float c, float d) {
        return (t==0) ? b : c * pow(2, 10 * (t/d - 1)) + b;
    }

    static float expoEaseOut(float t,float b , float c, float d) {
        return (t==d) ? b+c : c * (-pow(2, -10 * t/d) + 1) + b;
    }
    
    static float linearEase(float t,float b , float c, float d) {
        return c*t/d + b;;
    }
};

#endif
