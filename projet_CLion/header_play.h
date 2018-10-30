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

#ifndef UNTITLED_HEADER_PLAY_H
#define UNTITLED_HEADER_PLAY_H

/**
 * @file header_play.h
 *
 * File that contains functions used to play.
 */

/*#include "header_init_labyrinth.h"*/


/**
 * This function is using a boolean in order to verify if the game is over (which is the case if
 * the player is at the exit. Then, we offers the player a new move and verify if his wish
 * is possible. If it is, we're changing player's position and his older position is a
 * reachable cell. Else, we are asking him to enter another move.
 *
 * @param labyrinth - labyrinth which contains matrix, dimensions, player's positions, etc..
 */
void play(Labyrinth* labyrinth);

/**
 * First this function verifies that coordinates made by the player's choice (zqsd) are reachable
 * (among the labyrinth's size). Then it verifies if coordinates are a wall or not. If it is
 * not, then the player is able choose that direction.
 *
 * @param labyrinth - labyrinth which contains matrix, dimensions, player's positions, etc..
 * @param nextPosition - Coordinates which is the nextPosition wanted according to user's input
 * @return 1 if the move is allowed, 0 else
 */
int verify_move_allowed(Labyrinth* labyrinth, Coordinates nextPosition);

#endif /*UNTITLED_HEADER_PLAY_H*/
