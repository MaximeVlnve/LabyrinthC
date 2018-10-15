//
// Created by Maxime on 09/10/2018.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <unistd.h>

#ifndef PROJET_HEADER_H
#define PROJET_HEADER_H

#endif //PROJET_HEADER_H


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
    char name[256];
    Coordinates player;
} Labyrinth;

//  Functions useful
int generateRand(int max);
void viderBuffer();

//      Vectors
//          Int
void displayVector(int *vector, int dimension);
int* allocateVector(int dimension, int value);
void freeVector(int* vector);
void freeVectorCoordinates(Coordinates* vector);

//          Coordinates
void displayVectorCoordinates(Coordinates *vector, int dimension);
Coordinates* allocateVectorCoordinates(int dimension, int value);
void fillCoordinatesVector(int row, int col, Coordinates* vector);
void randomizeCoordinatesVector(int row, int col, Coordinates* vector);

//  Matrix

void displayMatrix(Labyrinth* labyrinth);
int** allocateMatrix(int row, int col, int value);
void freeMatrix(int** matrix, int row);
void initMatrix(Labyrinth* labyrinth);



// Functions init laby

int** fillSurroundings(int** matrix, Coordinates* vector, int index);
void checkSurroundings(int** matrixSurroundings);
int valueToReplaceSurroundings(int** matrixSurroundings);
void updateMatrix(Labyrinth* labyrinth, int newValue, int x, int y, int** matrixSurroundings);
void clearLabyrinth(Labyrinth* labyrinth);
void displayMatrixClean(Labyrinth* labyrinth);
void generateLabyrinth(Labyrinth* labyrinth, Coordinates* vector);
void initLabyrinth(Labyrinth* labyrinth);

void createLabyrinth(Labyrinth* labyrinth);


// Functions sauves

void sauveLaby(Labyrinth* labyrinth, char fileName[256]);
void loadLaby(Labyrinth* labyrinth);

// Functions play

void play(Labyrinth* labyrinth);
int verifyMoveAllowed(Labyrinth* labyrinth, Coordinates nextPosition);

