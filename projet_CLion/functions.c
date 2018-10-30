/*
 * Created by Maxime on 07/10/2018.
 */

#include "header.h"

int generate_rand(int max) {
    int randomNumber = 0;
    randomNumber = rand() % max;

    return randomNumber;
}

int* allocate_vector(int dimension, int value) {
    int *vector, i;
    vector = (int *)malloc((dimension) * sizeof(int));

    for(i=0; i<dimension; i++) {
        vector[i] = value;
    }

    return vector;
}

void free_vector(int* vector) {
    free(vector);
}

void free_vector_coordinates(Coordinates* vector) {
    free(vector);
}

Coordinates* allocate_vector_coordinates(int dimension, int value) {
    int i;
    Coordinates *vector;

    vector = (Coordinates *)malloc((dimension) * sizeof(Coordinates));

    for(i=0; i<dimension; i++) {
        vector[i].x = value;
        vector[i].y = value;
    }

    return vector;
}

void fill_coordinates_vector(int row, int col, Coordinates* vector) { /*fill coordinates vector with [0][0], [0][1], [0][2]...*/
    int cpt = 0, i, j;

    for(i=1; i<row-1; i++) {
        for(j=1; j<col-1; j++) {
            vector[cpt].x = i;
            vector[cpt].y = j;
            cpt++;
        }
    }
}

void randomize_coordinates_vector(int row, int col, Coordinates* vector) {
    int random, tmpX, tmpY, i;

    for(i=0; i<(row-2)*(col-2); i++) { /*foreach cell which is not an outside wall, we swap coords with another*/
        random = generate_rand((row-2)*(col-2));
        tmpX = vector[i].x;
        tmpY = vector[i].y;

        vector[i].x = vector[random].x;
        vector[i].y = vector[random].y;

        vector[random].x = tmpX;
        vector[random].y = tmpY;
    }
}

int** allocate_matrix(int row, int col, int value) {
    int **matrix, i;

    matrix = (int**)malloc(row * sizeof(int*));
    for (i=0; i<row; i++) {
        matrix[i] = allocate_vector(col, value);
    }

    return matrix;
}

void free_matrix(int** matrix, int row) {
    int i;

    for (i=0; i<row; i++) {
        free_vector(matrix[i]);
    }
    free(matrix);
}

void init_matrix(Labyrinth* labyrinth) { /*init matrix with values 1,2,3...*/
    int value = 1, i, j;
    for (i=1; i<labyrinth->row; i+=2) {
        for (j=1; j<labyrinth->col; j+=2) {
            labyrinth->matrix[i][j] = value;
            value++;
        }
    }

    labyrinth->matrix[1][0] = 2;                                        /*Set player to entry*/
    labyrinth->matrix[(labyrinth->row)-2][(labyrinth->col)-1] = 1;      /*Set exit*/
}

int compare_scores_points (const void *pa, const void *pb) {
    const Score *a = pa;
    const Score *b = pb;
    return a->points - b->points;
}




