cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SDL2Test)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

add_executable(Newgame src/main.cpp src/game.h src/game.cpp src/TextureManager.cpp src/TextureManager.h src/GameObject.cpp src/GameObject.h src/Map.cpp src/Map.h )
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(Newgame ${SDL2_LIBRARIES})


find_package(SDL2_image REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})
target_link_libraries(Newgame ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})