#include "GameObject.h"
#include "TextureManager.h"

enum class collisionType{walls,bottom_wall,bat,brick};


//Change to using Get/Set 
GameObject::GameObject(std::string texturesheet, int x, int y, int width, int height)
{
   
    _objTexture = TextureManager::LoadTexture(texturesheet);
    destRect.x =x;
    destRect.y =y;
    destRect.w =width;
    destRect.h =height;


};

GameObject::~GameObject()
{
   
};



void GameObject::Render()
{
    
    SDL_RenderCopy(Game::renderer,_objTexture,NULL,&destRect); //Render the playertex onto the screen
    SDL_RenderPresent(Game::renderer);
}

bool GameObject::Collision_Detection(GameObject*& obj)
{

    //passing by enum class type
    collisionType material;
    switch(material)
    {
        case collisionType::walls:
        break;
    }
    //using enum class and switch statement 
    if(obj->destRect.x == (this->destRect.x-50) || obj->destRect.y == (this->destRect.y+50))
    {
        std::cout<<"hit"<<std::endl;
    }
    //bally + ballscaling >= baty && bally+ballscaling <= baty+30
}

void GameObject::Object_Dynamics()
{

    destRect.x +=_setVelx;
    destRect.y +=_setVely;
    
}

void GameObject::setVelocity(int x, int y)
{
    _setVelx = x;
    _setVely =y;
}


