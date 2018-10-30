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

#ifndef UNTITLED_HEADER_USEFUL_FUNCTIONS_H
#define UNTITLED_HEADER_USEFUL_FUNCTIONS_H


/**
 * @file header_useful_functions.h
 *
 * File that contains useful functions.
 */

/*#include "header.h"*/

/**
 * Function which returns a random number.
 *
 * @param max - maximum value that can be returned
 * @return a random number
 */
int generate_rand(int max);

/**
 *  Function which compares scores.
 *
 * @param pa - first value to compare
 * @param pb - second value to compare
 * @return the difference between first and second value
 */
int compare_scores_points (const void *pa, const void *pb);

#endif /*UNTITLED_HEADER_USEFUL_FUNCTIONS_H*/
