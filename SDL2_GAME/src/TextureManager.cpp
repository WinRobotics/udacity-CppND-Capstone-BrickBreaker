#include "TextureManager.h"


TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
    
}

 SDL_Texture* TextureManager::LoadTexture(std::string texture)
{
    //create surface 
    SDL_Surface* tmpSurface =IMG_Load(texture.c_str());
    //create texture from surface
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer,tmpSurface);
    //free surface
    SDL_FreeSurface(tmpSurface);

    return tex;
}


void TextureManager::Draw(SDL_Texture* Tex,SDL_Rect Src,SDL_Rect Dest)
{
    SDL_RenderCopy(Game::renderer,Tex,NULL,&Dest);
}
