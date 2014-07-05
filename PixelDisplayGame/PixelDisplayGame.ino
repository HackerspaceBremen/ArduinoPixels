
#ifndef PSTR
 #define PSTR // Make Arduino Due happy
#endif
#ifndef ARDUINOGAME
 #define ARDUINOGAME
#endif

//#include <Adafruit_NeoPixel.h>

/*
 * With the define VIDEOGAME the old code is bypassed 
 * and the videogame (CVideoGame) instance takes over control.
 * 
 * It makes the code ugly but allows quick access to the
 * original code base.
*/
#define VIDEOGAME

#include <Hero.h>
#include <PixelMain.h>
#include <PixelGameInclude.h>
#include <PixelRenderer.h>

#ifndef VIDEOGAME
  PixelMain pixelMain;
#else
  #include <CVideoGame.h>
  CVideoGame videogame;
#endif

int count = 0;
int brightness = 0;
unsigned long secTime = 0;
unsigned long lastTime = 0;
boolean checkBrightness = true;

void setup()
{
  // serial port for debugging output to dev machine
  Serial.begin(57600);
  // serial port to slave arduino
  Serial3.begin(57600);
  Serial.println("start2");
  
  #ifndef VIDEOGAME
    /*
    pixelmain setup can be told the renderer
    this is used only for videogame. so here a null pointer
    is passed and a local instance of a renderer will be
    created.
    */
    pixelMain.setup(NULL);
  #else
    /*
    TODO: pass serial port as function pointer (?) 
    to setup() to allow debugging output?
    */
    videogame.setup();
  #endif

  secTime = millis();
  lastTime = millis(); 
}

int incomingByte = 0;

void loop() {

  if(checkBrightness)
  {
      //brightness = analogRead(0)/4;
      brightness = 180;
      #ifndef VIDEOGAME
        pixelMain.brightness = brightness;
      #else
        videogame.setBrightness(brightness);
      #endif
  }
  
  // calculate time step
  unsigned long currentTime = millis();
  float timestep  = currentTime - lastTime;
  lastTime = currentTime;
  
   if (Serial3.available() > 0) 
   {
      // checkBrightness =false;
      // check for new input data
      incomingByte = Serial3.read();  
      
      // pass input data to game
      #ifndef VIDEOGAME
        pixelMain.setInput((int)incomingByte);     
      #else
        videogame.setInput((int)incomingByte);
      #endif      
    }

    // update game state and draw frame
    #ifndef VIDEOGAME
      pixelMain.update(timestep / 200);
      pixelMain.draw();
    #else
      videogame.update(timestep / 200);
      videogame.draw();
    #endif   
}

