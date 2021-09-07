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

    static SDL_Renderer *renderer;
    
   
 
 private:
    void InitializeDataPath();
    bool _isrunning;
    std::string _data_path;
    std::string ball_bmp {"ball.bmp"};
    std::string bat_bmp {"bat.bmp"};
    std::string map_bmp {"bk.bmp"};
    SDL_Window *window; //creating a pointer of obj SDL_Window
    GameObject *_ball;
    GameObject *_bat;
    Map *_map;
    
   

};

#endif