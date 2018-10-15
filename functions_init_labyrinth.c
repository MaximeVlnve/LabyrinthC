//
// Created by Maxime on 09/10/2018.
//
#include "header.h"

void generateLabyrinth(Labyrinth* labyrinth, Coordinates* vector) {
    int** tabSurroundings;
    int newValue;

    for (int i = 0; i < (labyrinth->row - 2) * (labyrinth->col - 2); i++) { //scan surroundings vector

        if (!(vector[i].x == 0 || vector[i].x == labyrinth->row - 1 || vector[i].y == 0 || vector[i].y == labyrinth->col - 1)) {//verify coord is not an external wall

            if (labyrinth->matrix[vector[i].x][vector[i].y] == 0) { //verify if coord is a wall

                tabSurroundings = fillSurroundings(labyrinth->matrix, vector, i);
                checkSurroundings(tabSurroundings);
                newValue = valueToReplaceSurroundings(tabSurroundings);
                updateMatrix(labyrinth, newValue, vector[i].x, vector[i].y, tabSurroundings);
            }
        }
    }

    freeMatrix(tabSurroundings, 2);
}

int** fillSurroundings(int** matrix, Coordinates* vector, int index){
    int** matrixSurroundings;
    matrixSurroundings = allocateMatrix(2, 4, 0);

    matrixSurroundings[0][0] = matrix[(vector[index].x) - 1][vector[index].y];
    matrixSurroundings[0][1] = matrix[(vector[index].x) + 1][vector[index].y];
    matrixSurroundings[0][2] = matrix[vector[index].x][(vector[index].y) - 1];
    matrixSurroundings[0][3] = matrix[vector[index].x][(vector[index].y) + 1];

    return matrixSurroundings;
}

void checkSurroundings(int** matrixSurroundings){
    int cpt;

    for(int i=0; i<4; i++){
        cpt = 0;

        for(int j=0; j<4; j++){
            if ( matrixSurroundings[0][i] != 0 && (matrixSurroundings[0][i] == matrixSurroundings[0][j]) ){
                cpt++;
            }
        }
        matrixSurroundings[1][i] = cpt;
    }
}

int valueToReplaceSurroundings(int** matrixSurroundings){
    for(int i=0; i<4; i++){
        if (matrixSurroundings[1][i] == 1 && i%2 == 0 && matrixSurroundings[1][i+1] == 1){
            return matrixSurroundings[0][i];
        } else if ( matrixSurroundings[1][i] == 2 ){
            return -1;
        }
    }

    return -1;
}

void updateMatrix(Labyrinth* labyrinth, int newValue, int x, int y, int** matrixSurroundings){ //dispatch the newValue when breking a wall
    if (newValue != -1){
        labyrinth->matrix[x][y] = newValue;
        for(int i=0; i<4; i++){
            for(int j=1; j<labyrinth->row; j++){
                for(int k=1; k<labyrinth->col; k++){
                    if (matrixSurroundings[0][i] == labyrinth->matrix[j][k] && matrixSurroundings[1][i] != 0){
                        labyrinth->matrix[j][k] = newValue;
                    }
                }
            }
        }
    }
}

void clearLabyrinth(Labyrinth* labyrinth){
    for(int i=1; i<labyrinth->row; i++){
        for(int j=1; j<labyrinth->col; j++){
            if (labyrinth->matrix[i][j] != 0) labyrinth->matrix[i][j] = 1;
        }
    }
}

void displayMatrixClean(Labyrinth* labyrinth){
    for(int i=0; i<labyrinth->row; i++){
        for(int j=0; j<labyrinth->col; j++){
            /*switch (labyrinth->matrix[i][j]){
                case 0 :
                    printf("# ");
                case 1 :
                    printf("  ");
                case 2 :
                    printf("P ");
                default :
                    printf("B ");
            }*/

            if (labyrinth->matrix[i][j] == 0){
                printf("# ");
            } else if (labyrinth->matrix[i][j] == 1){
                printf("  ");
            } else if (labyrinth->matrix[i][j] == 2){
                printf("P ");
            } else {
               printf("%d ", labyrinth->matrix[i][j]);
            }
            //labyrinth->matrix[i][j] == 0 ? printf("# ") : printf("%d ", labyrinth->matrix[i][j]);
            //labyrinth->matrix[i][j] == 0 ? ( (i == 1 && j == 0) || (i == labyrinth->row-2 && j == labyrinth->col-1) ? printf("  ") : printf("# ")) : printf("  ") ;
        }
        printf("\n");
    }
}

void initLabyrinth(Labyrinth* labyrinth){

    int** matrix;
    int value = 0;

    matrix = allocateMatrix(labyrinth->row, labyrinth->col , value);

    labyrinth->matrix = matrix;

    initMatrix(labyrinth);

    Coordinates *listTmpCoordinates;
    int dimension = (labyrinth->row-2)*(labyrinth->col-2); //external walls do not count

    listTmpCoordinates = allocateVectorCoordinates(dimension, value);

    fillCoordinatesVector(labyrinth->row, labyrinth->col , listTmpCoordinates);

    randomizeCoordinatesVector(labyrinth->row, labyrinth->col, listTmpCoordinates);
    generateLabyrinth(labyrinth, listTmpCoordinates);

    freeVectorCoordinates(listTmpCoordinates);

    clearLabyrinth(labyrinth);
    displayMatrixClean(labyrinth);
}

void createLabyrinth(Labyrinth* labyrinth){
    int row, col;
    char fileName[256], *positionEntree, buffer[256];

    viderBuffer();

    printf("Nom du fichier?\n");

    if (fgets(fileName, sizeof(fileName), stdin)) {

        positionEntree = strchr(fileName, '\n'); // Looking for the \n of the user's input
        if (positionEntree != NULL) // if \n found
        {
            *positionEntree = '\0'; // then replace it by \0
        }
    }

    strcpy(labyrinth->name, fileName);


    do {
        printf("How many rows ? (odd)\n");
        fgets (buffer, 256, stdin);
        row = atoi (buffer);
    } while (row % 2 == 0);

    do {
        printf("How many columns ? (odd)\n");
        fgets (buffer, 256, stdin);
        col = atoi (buffer);
    } while (col % 2 == 0);

    labyrinth->row = row;
    labyrinth->col = col;
    labyrinth->boolEmpty = 1;
    labyrinth->player->x = 1;
    labyrinth->player->y = 0;

    initLabyrinth(labyrinth);
    sauveLaby(labyrinth, fileName);
}

void settingBonusMalus(Labyrinth* labyrinth){
    
}