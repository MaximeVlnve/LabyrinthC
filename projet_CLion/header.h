/*
 * Created by Maxime on 21/10/2018.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <unistd.h>

#ifndef UNTITLED_HEADER_H
#define UNTITLED_HEADER_H

#define CHAR_MAX 256
#define POINTS 3
#define NB_SCORE 11
#define WALL 0
#define PLAYER 2
#define BONUS 3
#define MALUS 4
#define ZOMBIE 5
#define GHOST 6
#define PATH "/Users/maxime/Documents/Ensi/Prog/Recovery_bis/LabyrinthC/projet_CLion/sauves/"
#define EXTENSION_CFG ".cfg"
#define EXTENSION_SCORE ".score"

typedef struct
{
    int x;
    int y;
} Coordinates;

typedef struct
{
    int** matrix;
    int row;
    int col;
    char name[CHAR_MAX];
    int boolEmpty;
    Coordinates* player;
    Coordinates* bonus;
    Coordinates* malus;
    Coordinates* zombie;
    Coordinates* ghost;
} Labyrinth;

typedef struct
{
    int points;
    char name[CHAR_MAX];
} Score;

#endif /*UNTITLED_HEADER_H*/
