/*
 * Created by Maxime on 21/10/2018.
 */

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
 * @todo step 4 - init a labyrinth which is not perfect (not a single way to arrive at the end).
 */

#ifndef UNTITLED_HEADER_INIT_LABYRINTH_H
#define UNTITLED_HEADER_INIT_LABYRINTH_H

/**
 * @file header_init_labyrinth.h
 *
 * File that contains functions used to initialize a labyrinth.
 */

/*#include "header_functions.h"*/


/**
 * Fills a matrix which surrounding of a cell that we are currently analyzing
 *
 * @param matrix - the labyrinth's matrix
 * @param vector - Coordinates of a cell
 * @param index - the index of the cell that we are analyzing in the vector that contains every Coordinates
 * @return a matrix which contains surrondings
 */
int** fill_surroundings(int** matrix, Coordinates* vector, int index);

/**
 * Counts every time a value is among surroundings
 *
 * @param matrixSurroundings - the surrondings' matrix
 */
void check_surroundings(int** matrixSurroundings);

/**
 * Sets a value that will replace the cell's value that we are analyzing
 *
 * @param matrixSurroundings - the surrondings' matrix
 * @return a value
 */
int value_to_replace_surroundings(int** matrixSurroundings);

/**
 * Function that updates the labyrinth by spreading the new value
 *
 * @param labyrinth - labyrinth which contains matrix and dimensions
 * @param newValue - the value that will be spread
 * @param x - the x value of the cell that we are currently analyzing
 * @param y - the y value of the cell that we are currently analyzing
 * @param matrixSurroundings - the surrondings' matrix
 */
void update_matrix(Labyrinth* labyrinth, int newValue, int x, int y, int** matrixSurroundings);

/**
 * Sets the same value to every Coordinates which is not a wall
 *
 * @param labyrinth - labyrinth which contains matrix and dimensions
 */
void clear_labyrinth(Labyrinth* labyrinth);

/**
 * Displays the final matrix
 *
 * @param labyrinth - labyrinth which contains matrix and dimensions
 */
void display_matrix_clean(Labyrinth* labyrinth);

/**
 * Generates a labyrinth by verifying every cell of a coordinates' array that is already randomized.
 * Then we verify surrondings in order to know if we have to edit the current cell's value or not.
 *
 * @param labyrinth - labyrinth which contains matrix and dimensions
 * @param vector - Coordinates of a cell
 */
void generate_labyrinth(Labyrinth* labyrinth, Coordinates* vector);

/**
 * Initalizes a labyrinth
 *
 * @param labyrinth - labyrinth which contains matrix and dimensions
 */
void init_labyrinth(Labyrinth* labyrinth);

/**
 * Creates a labyrinth
 *
 * @param labyrinth - labyrinth which contains matrix and dimensions
 */
void create_labyrinth(Labyrinth* labyrinth);

/**
 * Sets bonus and malus in the labyrinth
 *
 * @param labyrinth - labyrinth which contains matrix and dimensions
 */
void setting_bonus_malus(Labyrinth* labyrinth);

/**
 * Sets a zombie in the labyrinth
 *
 * @param labyrinth - labyrinth which contains matrix and dimensions
 */
void setting_zombie(Labyrinth* labyrinth);

/**
 * Sets a ghost in the labyrinth
 *
 * @param labyrinth - labyrinth which contains matrix and dimensions
 */
void setting_ghost(Labyrinth* labyrinth);

#endif /*UNTITLED_HEADER_INIT_LABYRINTH_H*/
