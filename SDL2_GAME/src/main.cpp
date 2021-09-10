#include "SDL.h" 
#include "game.h"
#include <iostream>


int main(int argc, char *argv[])
{
  const int FPS = 60; //frame rate
  const int frameDelay = 1000/60; //framedelay

  Uint32 frameStart;
  int frameDuration;

  Game game;
  game.init("BrickBreaker",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,false);
  

  while(game.running())
  {

    frameStart = SDL_GetTicks();
    
    game.clear();
    game.handlerEvents();
    game.update();
    game.render();

    frameDuration = SDL_GetTicks() - frameStart;

    if(frameDelay > frameDuration)
    {
      SDL_Delay(frameDelay-frameDuration);
    }
    
  }

  return 0;
}