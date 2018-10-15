cmake_minimum_required(VERSION 3.12)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c header.h functions_sauves.c functions_init_labyrinth.c functions.c functions_play.c)