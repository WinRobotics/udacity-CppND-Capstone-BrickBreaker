#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SDL.h"
#include <iostream>
#include "game.h"
#include <memory>


enum class collisionType{walls,bat,brick,bottom_wall};


class GameObject {
 public:

   
    GameObject(std::string texturesheet,int x, int y,int width,int height);
    ~GameObject();
    void Render();
    int Collision_Detection(GameObject*& obj,collisionType item);
    void Object_Dynamics();
    SDL_Rect destRect;
    void setVelocity(int x, int y);
    int _setVelx {0};
    int _setVely {0};
    


 
 private:
   SDL_Texture* _objTexture; 


};

#endif
