set(CMAKE_CXX_FLAGS "-std=c++17")
cmake_minimum_required(VERSION 3.10.2)
add_executable(chess card.cpp square.cpp board.cpp player.cpp warChess.cpp main.cpp)