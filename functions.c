//
// Created by Maxime on 07/10/2018.
//

#include "header.h"
/*
 *Permet de générer un nombre aléatoire.
 */
int generateRand(int max) {
    int randomNumber = 0;
    randomNumber = rand() % max;

    return randomNumber;
}

//  Vectors
//      Int

/*
 * Permet d'afficher un tableau à une dimension
 */
void displayVector(int *vector, int dimension) {
    int i;

    for(i=0; i<dimension; i++) {
        *(vector+i) = i;
        printf("%d ", *(vector+i));
    }

    printf("\n");
}

/*
 * Permet d'allouer un tableau à une dimension
 */
int* allocateVector(int dimension, int value) {
    int *vector, i;
    vector = (int *)malloc((dimension) * sizeof(int));

    for(i=0; i<dimension; i++) {
        vector[i] = value;
    }

    return vector;
}
/*
 * Permet de libérer la mémoire occupée par un tableau à une dimension
 */
void freeVector(int* vector) {
    free(vector);
}


//      Coordinates

/*
 * Permet de libérer la mémoire occupée par un tableau de coordonnées à une dimension
 */
void freeVectorCoordinates(Coordinates* vector) {
    free(vector);
}

/*
 * Permet d'afficher un tableau de coordonnées à une dimension
 */
void displayVectorCoordinates(Coordinates *vector, int dimension) {
    int i;

    for(i=0; i<dimension; i++) {
        printf("[%d][%d]\n", vector[i].x, vector[i].y);
    }

    printf("\n");
}

/*
 * Permet d'allouer un tableau de coordonnées à une dimension
 */
Coordinates* allocateVectorCoordinates(int dimension, int value) {
    int i;
    Coordinates *vector;

    vector = (Coordinates *)malloc((dimension) * sizeof(Coordinates));

    for(i=0; i<dimension; i++) {
        vector[i].x = value;
        vector[i].y = value;
    }

    return vector;
}

/*
 * Permet de remplir un tableau de coordonnées
 */
void fillCoordinatesVector(int row, int col, Coordinates* vector) { //fill coordinates vector with [0][0], [0][1], [0][2]...
    int cpt = 0, i, j;

    for(i=1; i<row-1; i++) {
        for(j=1; j<col-1; j++) {
            vector[cpt].x = i;
            vector[cpt].y = j;
            cpt++;
        }
    }
}

/*
 * Permet de mélanger un tableau de coordonnées
 */
void randomizeCoordinatesVector(int row, int col, Coordinates* vector) {
    int random, tmpX, tmpY, i;

    for(i=0; i<(row-2)*(col-2); i++) { //foreach cell which is not an outside wall, we swap coords with another
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

/*
 * Permet d'afficher un tableau à deux dimensions
 */
void displayMatrix(Labyrinth* labyrinth) {
    int i, j;

    for(i=0; i<labyrinth->row; i++) {
        for(j=0; j<labyrinth->col; j++) {
            labyrinth->matrix[i][j] == 0 ? ( (i == 1 && j == 0) || (i == labyrinth->row-2 && j == labyrinth->col-1) ? printf("  ") : printf("# ")) : printf("%d ", labyrinth->matrix[i][j]) ;
        }
        printf("\n");
    }
}

/*
 * Permet d'allouer un tableau à deux dimensions
 */
int** allocateMatrix(int row, int col, int value) {
    int **matrix, i;

    matrix = (int**)malloc(row * sizeof(int*));
    for (i=0; i<row; i++) {
        matrix[i] = allocateVector(col, value);
    }

    return matrix;
}

/*
 * Permet de libérer la mémoire occupée un tableau à deux dimensions
 */
void freeMatrix(int** matrix, int row) {
    int i;

    for (i=0; i<row; i++) {
        freeVector(matrix[i]);
    }
    free(matrix);
}

/*
 * Permet d'initialiser le labyrinthe de base (avant d'effectuer l'algorithme)
 * qui créer un labyrinthe parfait
 */
void initMatrix(Labyrinth* labyrinth) { //init matrix with values 1,2,3...
    int value = 1, i, j;
    for (i=1; i<labyrinth->row; i+=2) {
        for (j=1; j<labyrinth->col; j+=2) {
            labyrinth->matrix[i][j] = value;
            value++;
        }
    }

    labyrinth->matrix[1][0] = 2;                                        //Set player to entry
    labyrinth->matrix[(labyrinth->row)-2][(labyrinth->col)-1] = 1;      //Set exit
}

/*
 *  Permet de vider le buffer suite à une entrée utilisateur
 */
void emptyBuffer() {
    int c = 0;

    while (c != '\n' && c != EOF) {
        c = getchar();
    }
}



