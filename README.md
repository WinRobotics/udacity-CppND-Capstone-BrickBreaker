# CPPND: Capstone BrickBreaker

The game was created using a tutorial that i learnt from Udemy, it tries to simulate a classical 2D game known as brickbreaker. However, during the tutorial the code was written in a procedural manner without any OOP or using modern C++ techniques that was taught in Udacity. I really wanted to practice and push myself beyond my comfort level and practice as much as what i have learnt. My attempt was to create the game from scratch in a OOP manner. The game is not perfect and has a few bugs but i will strive to work on improving it.



## Gameplay 

The goal of the game is to break all the bricks by bouncing the ball off the bat without touching the floor of the window. If you managed to break all 12 bricks, you win the game. If the ball hits the floor of the window, the game ends.
<img src="game_play.png"/>


## Game Winning Screenshot
<img src="game_win.png"/>


## Game Losing Screenshot
<img src="game_lose.png"/>


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros


## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./NewGame`.



