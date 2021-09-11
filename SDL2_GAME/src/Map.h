#ifndef MAP_H
#define MAP_H

#include "SDL.h"
#include "TextureManager.h"
#include <iostream>




class Map {
 public:

    Map(std::string texturesheet, int x, int y, int width, int height);
    ~Map();
    void Render();


 private:

   int _mapX {0};
   int _mapY {0};
   int _mapW {0};
   int _mapH {0};
   SDL_Rect _mapRect;

   SDL_Texture* _mapTexture;
   SDL_Rect srcRect;
   SDL_Rect destRect;
   std::string _mapPath;


};

#endif
