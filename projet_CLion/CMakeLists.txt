cmake_minimum_required(VERSION 3.12)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(executable main.c header_sauves.h functions_sauves.c functions_init_labyrinth.c functions.c functions_play.c functions_input.c header_functions.h header_init_labyrinth.h header_play.h header_useful_functions.h header_functions_input.h header.h)