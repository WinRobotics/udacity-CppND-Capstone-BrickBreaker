#include "game.h"

//TODO remove this
SDL_Renderer *Game::renderer = nullptr;

Game::Game()
{

    InitializeDataPath();
};

Game::~Game()
{

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    delete _ball;
    delete _map;
    SDL_QUIT;
    std::cout<<"Game Quit"<<std::endl;
    
};



void Game::InitializeDataPath() {
char *base_path = SDL_GetBasePath();
if (base_path) {
      
      std::string sub_path(base_path);
      std::string delimiter;
      delimiter ="/SDL2_GAME";
      _data_path = sub_path.substr(0,sub_path.find(delimiter));
      _data_path += "/SDL2_GAME/src/assets/";
      
      
    } 
}



void Game::init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        int flags =0;
        if(fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN; //ENMU 1 = full screen
        }
        std::cout<< "All System is functioning"<<std::endl; 
        window =SDL_CreateWindow(title,xpos,ypos,height,width,flags);
        if(window)
        {
            std::cout<<"Window is created"<<std::endl; 
        }
        renderer = SDL_CreateRenderer(window,-1,0);
        if(renderer)
        {
            std::cout<<"Rendering"<<std::endl;
        }

        _isrunning= true; //defualt true 

    }
    _ball = new GameObject(_data_path+ball_bmp,100,250,30,20);
    _ball->setVelocity(1,1);
    _bat = new GameObject(_data_path+bat_bmp,300,450,50,20);
    _map = new Map(_data_path+map_bmp,0,0,640,480);

}

bool Game::running()
{
    return _isrunning;
}

void Game::update()
{   

    //Ball movement 
    _ball->Object_Dynamics();
    //Collision with bat
    bool state=_ball->Collision_Detection(_bat);
    // should be passing the obj to be collided 
    //if collided move brick outside the screen
    //if collided with wall bounce 
    //if collided with bottom lose
    //Collison with wall 
    //Collision with bricks


}


void Game::render()
{

    _map->Render();
    _ball->Render();
    _bat->Render();
    SDL_RenderPresent(renderer);
    SDL_RenderClear(renderer); //clear screen

}

void Game::handlerEvents()
{

  SDL_Event event;
  SDL_PollEvent(&event);
  if(event.type == SDL_QUIT)
  {
      _isrunning = false;
  }
  else if(event.type == SDL_KEYDOWN) //if key is pressed
  {
    if(event.key.keysym.sym == SDLK_LEFT && _bat->destRect.x>0)
    {
        _bat->destRect.x -=5;
    }

    if(event.key.keysym.sym == SDLK_RIGHT && _bat->destRect.x<580) //640 - 60
    {
        _bat->destRect.x +=5;
    }

  }

}
    
