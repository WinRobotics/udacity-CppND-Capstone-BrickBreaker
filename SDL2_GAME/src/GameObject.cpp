#include "GameObject.h"
#include "TextureManager.h"



//Change to using Get/Set 
GameObject::GameObject(std::string texturesheet, int x, int y, int width, int height)
{
   //TODO: Change to init list
    _objTexture = TextureManager::LoadTexture(texturesheet);
    destRect.x =x;
    destRect.y =y;
    destRect.w =width;
    destRect.h =height;


};

GameObject::~GameObject()
{
   SDL_DestroyTexture(_objTexture);
};



void GameObject::Render()
{
    
    SDL_RenderCopy(Game::renderer,_objTexture,NULL,&destRect); //Render obj onto the screen
    SDL_RenderPresent(Game::renderer);
}

int GameObject::Collision_Detection(GameObject*& obj,collisionType item)
{

    //passing by enum class type
    
    collisionType material;
    material = item;
    int _ballScaling =10;
    switch(material)
    {
        //obj is ball, this-> refers to item that will be collided with
        case collisionType::walls:
        if(obj->destRect.x > (this->destRect.x+620) || obj->destRect.x < (this->destRect.x))
        {
            obj->_setVelx = - obj->_setVelx;
        }
        if(obj->destRect.y < (this->destRect.y))
        {
            obj->_setVely = - obj->_setVely;
        }
        return false;
        

        case collisionType::bat:
        if(obj->destRect.y + _ballScaling >= this->destRect.y && obj->destRect.y + _ballScaling <= this->destRect.y+30 &&  
           obj->destRect.x + _ballScaling >= this->destRect.x && obj->destRect.x + _ballScaling <= this->destRect.x+60 )
           {
               obj->_setVely = - obj->_setVely; 
               
           }

        return false;

        case collisionType::bottom_wall:
        if(obj->destRect.y > (this->destRect.y+460))
        {
            return true;
        }
        return false;

        case collisionType::brick:


        if(this->destRect.x>(obj->destRect.x+obj->destRect.w))
        {
            return false;
            
        }
        if(this->destRect.x+this->destRect.w<obj->destRect.x)
        {
            return false;
           
        }
        if(this->destRect.y>(obj->destRect.y+obj->destRect.h))
        {
            return false;
            
        }
        if(this->destRect.y+this->destRect.h<obj->destRect.y)
        {
            return false;
            
        }
    
        //collided
        //std::cout<<collided<<std::endl;
        this->destRect.x = 1000; //move brick off screen;
        obj->_setVely = - obj->_setVely; //bounce off
        return true;
        
    }



}

void GameObject::Object_Dynamics()
{

    destRect.x +=_setVelx;
    destRect.y +=_setVely;
    
}

void GameObject::setVelocity(int x, int y)
{
    _setVelx =x;
    _setVely =y;
}





