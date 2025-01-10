cmake_minimum_required(VERSION 3.10)
project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

add_executable(TicTacToe
        main.cpp
        src/Game.cpp
        src/Board.cpp
        src/Player.cpp
        src/AI.cpp
        src/Network.cpp)

include_directories(include)