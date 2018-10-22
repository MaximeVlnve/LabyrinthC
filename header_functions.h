//
// Created by Maxime on 21/10/2018.
//

#include "header_functions_input.h"

#ifndef UNTITLED_HEADER_INIT_LABYRINTH_H
#define UNTITLED_HEADER_INIT_LABYRINTH_H

#endif //UNTITLED_HEADER_INIT_LABYRINTH_H




//      Vectors
//          Int
int* allocate_vector(int dimension, int value);
void free_vector(int* vector);
void free_vector_coordinates(Coordinates* vector);

//          Coordinates
Coordinates* allocate_vector_coordinates(int dimension, int value);
void fill_coordinates_vector(int row, int col, Coordinates* vector);
void randomize_coordinates_vector(int row, int col, Coordinates* vector);


//  Matrix

int** allocate_matrix(int row, int col, int value);
void free_matrix(int** matrix, int row);
void init_matrix(Labyrinth* labyrinth);
