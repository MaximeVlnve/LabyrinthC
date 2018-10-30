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

#ifndef UNTITLED_HEADER_FUNCTIONS_INPUT_H
#define UNTITLED_HEADER_FUNCTIONS_INPUT_H


/**
 * @file header_functions_input.h
 *
 * File that contains functions used when we need a user input.
 */


/*#include "header_useful_functions.h"*/

/**
 * Function that empties buffer.
 */
void empty_buffer();

/**
 * Secured function that waits a user input.
 *
 * @param text - user's input
 * @param length - user's input's length
 * @return 1 in case of error, 0 else
 */
int secure_input(char *text, int length);

/**
 * Secured function that waits the user's choice in the menu
 *
 * @param choixMin - minimum value possible in the menu
 * @param choixMax - maximum value possible in the menu
 * @return user's choice
 */
int menu(int choixMin, int choixMax);

/**
 * Secured function that waits the difficulty the user wants
 *
 * @return user's choice
 */
int get_difficulty();


#endif /*UNTITLED_FUNCTIONS_INPUT_H*/


