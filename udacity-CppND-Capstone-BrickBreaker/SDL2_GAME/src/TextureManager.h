#ifndef TextureManager_H
#define TextureManager_H

#include "SDL.h"
#include "SDL_image.h"
#include "game.h"
#include <iostream>
#include <unistd.h>


class TextureManager
{
private:
    
public:
   static SDL_Texture* LoadTexture(std::string fileName);
   static void Draw(SDL_Texture* Tex,SDL_Rect Src,SDL_Rect Dest);
   TextureManager();
   ~TextureManager();
};



#endif