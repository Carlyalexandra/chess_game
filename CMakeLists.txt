cmake_minimum_required(VERSION 3.4)
project(chess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    chess.c
    chess.h
    chess_game.c)

add_executable(chess ${SOURCE_FILES})