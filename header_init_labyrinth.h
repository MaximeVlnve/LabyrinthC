//
// Created by Maxime on 21/10/2018.
//

#include "header_functions.h"

#ifndef UNTITLED_HEADER_INIT_LABYRINTH_H
#define UNTITLED_HEADER_INIT_LABYRINTH_H

#endif //UNTITLED_HEADER_INIT_LABYRINTH_H

// Functions init laby

int** fill_surroundings(int** matrix, Coordinates* vector, int index);
void check_surroundings(int** matrixSurroundings);
int value_to_replace_surroundings(int** matrixSurroundings);
void update_matrix(Labyrinth* labyrinth, int newValue, int x, int y, int** matrixSurroundings);
void clear_labyrinth(Labyrinth* labyrinth);
void display_matrix_clean(Labyrinth* labyrinth);
void generate_labyrinth(Labyrinth* labyrinth, Coordinates* vector);
void init_labyrinth(Labyrinth* labyrinth);
void create_labyrinth(Labyrinth* labyrinth);
void setting_bonus_malus(Labyrinth* labyrinth);