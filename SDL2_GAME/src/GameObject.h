#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "game.h"
#include <memory>



class GameObject {
 public:

   
    GameObject(std::string texturesheet,int x, int y,int width,int height);
    ~GameObject();
    void Render();
    bool Collision_Detection(GameObject*& obj);
    void Object_Dynamics();
    SDL_Rect destRect;
    void setVelocity(int x, int y);

 
 private:
   SDL_Texture* _objTexture; 
   int _setVelx {0};
   int _setVely {0};


};

#endif
