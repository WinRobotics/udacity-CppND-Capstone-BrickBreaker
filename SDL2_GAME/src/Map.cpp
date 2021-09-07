#include "Map.h"


Map::Map(std::string texturesheet, int x, int y, int width, int height) 
{
    _mapPath = texturesheet;
    _mapTexture = TextureManager::LoadTexture(_mapPath);
    _mapRect.w = width;
    _mapRect.h = height;
    _mapRect.x = x;
    _mapRect.y = y;

}

Map::~Map()
{
    
}

void Map::Render()
{
    SDL_RenderCopy(Game::renderer,_mapTexture,NULL,&_mapRect); //Render the playertex onto the screen
    SDL_RenderPresent(Game::renderer);
}
