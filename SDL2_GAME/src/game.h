#ifndef GAME_H
#define GAME_H


#include "SDL.h"
#include "SDL_image.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"


#include <iostream>
#include<unistd.h>
#include <string.h>
#include <fstream>
#include <vector>

class GameObject;  //forward declaration

enum class collisionType; //forward declaration

class Map; //forward declaration


//Runs the game 
class Game {
 public:

    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int height, int width, bool fullscreen);
    void update(); //update game status
    void render(); //drawing of game images
    void handlerEvents(); //handle key-mouse events
    bool running(); 
    void clear();

    static SDL_Renderer *renderer;

    bool brick_dest {false};
    bool game_lost{false};
    int number_of_bricks_dest {0};
    
   
 
 private:
    void InitializeDataPath();
    bool _isrunning;

    std::string _data_path;
    std::string ball_bmp {"ball.bmp"};
    std::string bat_bmp {"bat.bmp"};
    std::string map_bmp {"bk.bmp"};
    std::string brick_bmp {"brick.bmp"};
    std::string win_bmp {"win.bmp"};
    std::string lose_bmp {"lose.bmp"};

    int spacing_x {25};
    int spacing_y {0};

    SDL_Window *window; //creating a pointer of obj SDL_Window

    GameObject *_ball;
    GameObject *_bat;
    GameObject *_wall;
    GameObject *_lowerWall;
    GameObject *_brick;
    GameObject *_win;
    GameObject *_lose;
    std::vector<GameObject*> _bricks;
    Map *_map;
    
   

};

#endif