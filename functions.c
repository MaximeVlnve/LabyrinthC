//
// Created by Maxime on 07/10/2018.
//

#include "header.h"

int generateRand(int max){
    int randomNumber = 0;
    randomNumber = rand() % max;

    return randomNumber;
}

//  Vectors
//      Int

void displayVector(int *vector, int dimension){

    for(int i=0; i<dimension; i++){
        *(vector+i) = i;
        printf("%d ", *(vector+i));
    }
    printf("\n");
}

int* allocateVector(int dimension, int value){
    int *vector;
    vector = (int *)malloc((dimension) * sizeof(int));

    for(int i=0; i<dimension; i++){
        vector[i] = value;
    }

    return vector;
}

void freeVector(int* vector){
    free(vector);
}


//      Coordinates

void freeVectorCoordinates(Coordinates* vector){
    free(vector);
}

void displayVectorCoordinates(Coordinates *vector, int dimension){

    for(int i=0; i<dimension; i++){
        printf("[%d][%d]\n", vector[i].x, vector[i].y);
    }
    printf("\n");
}

Coordinates* allocateVectorCoordinates(int dimension, int value){

    Coordinates *vector;
    vector = (Coordinates *)malloc((dimension) * sizeof(Coordinates));

    for(int i=0; i<dimension; i++){
        vector[i].x = value;
        vector[i].y = value;
    }

    return vector;
}

void fillCoordinatesVector(int row, int col, Coordinates* vector){ //fill coordinates vector with [0][0], [0][1], [0][2]...
    int cpt = 0;

    for(int i=1; i<row-1; i++){
        for(int j=1; j<col-1; j++){
            vector[cpt].x = i;
            vector[cpt].y = j;
            cpt++;

        }
    }
}

void randomizeCoordinatesVector(int row, int col, Coordinates* vector){
    int random, tmpX, tmpY;

    for(int i=0; i<(row-2)*(col-2); i++){ //foreach cell which is not an outside wall, we swap coords with another
        random = generateRand((row-2)*(col-2));
        tmpX = vector[i].x;
        tmpY = vector[i].y;

        vector[i].x = vector[random].x;
        vector[i].y = vector[random].y;

        vector[random].x = tmpX;
        vector[random].y = tmpY;
    }
}


//  Matrix

void displayMatrix(Labyrinth* labyrinth){
    for(int i=0; i<labyrinth->row; i++){
        for(int j=0; j<labyrinth->col; j++){
            labyrinth->matrix[i][j] == 0 ? ( (i == 1 && j == 0) || (i == labyrinth->row-2 && j == labyrinth->col-1) ? printf("  ") : printf("# ")) : printf("%d ", labyrinth->matrix[i][j]) ;
        }
        printf("\n");
    }
}

int** allocateMatrix(int row, int col, int value){
    int **matrix;

    matrix = (int**)malloc(row * sizeof(int*));
    for(int i=0; i<row;i++){
        matrix[i] = allocateVector(col, value);
    }

    return matrix;
}

void freeMatrix(int** matrix, int row){
    for(int i=0; i<row; i++){
        freeVector(matrix[i]);
    }
    free(matrix);
}

void initMatrix(Labyrinth* labyrinth){ //init matrix with values 1,2,3...
    int value = 1;
    for(int i=1; i<labyrinth->row; i+=2){
        for(int j=1; j<labyrinth->col; j+=2){
            labyrinth->matrix[i][j] = value;
            value++;
        }
    }

    labyrinth->matrix[1][0] = 1;                                        //Set entry
    labyrinth->matrix[(labyrinth->row)-2][(labyrinth->col)-1] = 1;      //Set exit

}



