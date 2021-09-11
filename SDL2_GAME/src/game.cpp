#include "game.h"


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
    delete _bat;
    delete _win;
    delete _lose;
    delete _wall;
    delete _lowerWall;

    for(int i=0;i<12;i++)
    {
        delete _bricks[i]; // delete all bricks
    }

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
    else{

        std::cout<<"No such path to assets"<<std::endl;
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
            SDL_SetRenderDrawColor(renderer,255,255,255,255);
        }
        _isrunning= true; //defualt true 

    }
    _ball = new GameObject(_data_path+ball_png,100,250,30,20);
    _ball->setVelocity(1,1);
    _bat = new GameObject(_data_path+bat_png,300,450,50,20);
    _map = new Map(_data_path+map_png,0,0,640,480);
    _wall = new GameObject("",0,0,0,0); //all walls
    _lowerWall = new GameObject("",0,0,0,0); //lower walls
    _win = new GameObject(_data_path+win_png,170,150,300,150); //win
    _lose = new GameObject(_data_path+lose_png,170,150,300,150); //lose
    

    //create a vector of bricks pointer obj game object
    for(int numb_of_bricks =0; numb_of_bricks<12; numb_of_bricks++)
    {

        _brick = new GameObject(_data_path+brick_png,25,25,85,35); //x=25, y =50 first brick location
        if(numb_of_bricks<6)
        {
            _brick->destRect.x = spacing_x;
            spacing_x+= 100;  
            
        }
        if(numb_of_bricks<12 && numb_of_bricks>5)
        {
        
            _brick->destRect.y = 100;
            spacing_x-=100;
            _brick->destRect.x = spacing_x;

        }

        _bricks.push_back(_brick);

    }
    

}

bool Game::running()
{
    return _isrunning;
}

void Game::update()
{      
        if(number_of_bricks_dest <12)
        {
            brick_dest = false;
            _ball->Object_Dynamics(); //Ball movement 
            brick_dest=_wall->Collision_Detection(_ball, collisionType::walls);
            brick_dest=_bat->Collision_Detection(_ball, collisionType::bat);
            brick_dest=_lowerWall->Collision_Detection(_ball,collisionType::bottom_wall);
            if(brick_dest == true)
            {
                //std::cout<<"You Lose"<<std::endl;
                game_lost = true;
            }

            for(int i =0; i<12; i++)
            {
            
                brick_dest=_bricks[i]->Collision_Detection(_ball,collisionType::brick);
                if(brick_dest == true)
                {
                    number_of_bricks_dest++;
                    std::cout<<"Game Score:"<<number_of_bricks_dest<<std::endl;
                    brick_dest = false; //reset
                }
            }


        }
        else if(number_of_bricks_dest==12)
        {
            //Pause game
        }

       

}


void Game::render()
{    
    _map->Render();
    _bat->Render();
    _ball->Render();
    for(int i =0; i<12; i++)
    {
     _bricks[i]->Render();
    }
    if(number_of_bricks_dest ==12)
    {
         _win->Render();
    }
    if(game_lost == true)
    {
        _lose->Render();
    }
    SDL_RenderPresent(renderer);
}



void Game::clear()
{
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
    
