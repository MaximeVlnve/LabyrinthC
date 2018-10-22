//
// Created by Maxime on 21/10/2018.
//

/* -*- c-basic-offset: 3 -*-
 *
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @author Maxime Villeneuve <mvilleneuve@ecole.ensicaen.fr>
 * @version     0.0.3 - 22-10-2018
 *
 * @todo step 4 - init a labyrinth which is not perfect (not a single way to arrives at the end).
 */

#ifndef UNTITLED_HEADER_FUNCTIONS_H
#define UNTITLED_HEADER_FUNCTIONS_H


/**
 * @file header_functions.h
 *
 * File that contains functions used when we an array (either 1D or 2D).
 */

#include "header_functions_input.h"

/**
 * Allows to allocate a 1D array
 *
 * @param dimension - array's size
 * @param value - value that will be in each array's cell
 * @return a 1D array
 */
int* allocate_vector(int dimension, int value);

/**
 * Free the memory used by a 1D array which contains int
 *
 * @param vector - a 1D array which contains int
 */
void free_vector(int* vector);

/**
 * Free the memory used by a 1D which contains Coordinates
 *
 * @param vector - a 1D array which contains Coordinates
 */
void free_vector_coordinates(Coordinates* vector);

/**
 * Allows to allocate a 1D array which contains Coordinates
 *
 * @param dimension - array's size
 * @param value - value that will be in each array's cell
 * @return a 1D array which contains Coordinates
 */
Coordinates* allocate_vector_coordinates(int dimension, int value);

/**
 * Allows to fill a 1D array of Coordinates
 *
 * @param row - array's row number
 * @param col - array's col number
 * @param vector - the array to fill
 */
void fill_coordinates_vector(int row, int col, Coordinates* vector);

/**
 * Allows to randomize Coordinates which are in the vector
 *
 * @param row - array's row number
 * @param col - array's col number
 * @param vector - the array with randomized Coordinates
 */
void randomize_coordinates_vector(int row, int col, Coordinates* vector);

/**
 * Allows to allocate a 2D array
 *
 * @param row - array's row number
 * @param col - array's col number
 * @param value - value that will be in each array's cell
 * @return a 2D array
 */
int** allocate_matrix(int row, int col, int value);

/**
 * Free a 2D array
 *
 * @param matrix - the 2D array to free
 * @param row - array's row number
 */
void free_matrix(int** matrix, int row);

/**
 * Initializes a 2D array
 *
 * @param labyrinth - to init the labyrinth's matrix
 */
void init_matrix(Labyrinth* labyrinth);

#endif //UNTITLED_HEADER_FUNCTIONS_H
