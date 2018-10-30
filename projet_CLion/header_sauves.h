/*
 * Created by Maxime on 09/10/2018.
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

#ifndef UNTITLED_HEADER_SAUVES_H
#define UNTITLED_HEADER_SAUVES_H

/**
 * @file header_sauves.h
 *
 * File that contains functions used to save a score or a labyrinth.
 */

/*#include "header_play.h"*/


/**
 * This function use a fileName (user's input) and save the labyrinth. We
 * save useful parameters such as the labyrinth's dimension
 *
 * @param labyrinth - labyrinth which contains matrix, dimensions, player's positions, etc..
 * @param fileName - name that the user wants to give to his labyrinth
 */
void save_laby(Labyrinth* labyrinth, char fileName[CHAR_MAX]);

/**
 * This function uses the user's input to know which labyrinth to load.
 * If the user's input matches with a file then we load it and retrieve
 * useful informations the file contains.
 *
 * @param labyrinth - labyrinth which contains matrix, dimensions, player's positions, etc..
 */
void load_laby(Labyrinth* labyrinth);

/**
 * This function tries to open the score's file of the labyrinth. If it does not exist
 * we create it. Else we retrieve every past scores and sort them including the current score.
 * Then we write the 10 best scores sorted in the file.
 *
 * @param score - contains the current score and the player's name
 * @param labyrinth - contains the labyrinth's name
 */
void save_score(Score* score, Labyrinth* labyrinth);

#endif /*PROJET_HEADER_H*/
