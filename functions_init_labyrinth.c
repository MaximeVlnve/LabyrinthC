//
// Created by Maxime on 09/10/2018.
//
#include "header_sauves.h"

/*
 * Permet de générer un labyrinthe parfait en parcourant un tableau de coordonnées
 * préalablement mélangé. Puis on vérifie les cases environnantes afin de savoir
 * si l'on doit modifier la case que l'on traite ou pas.
 */
void generate_labyrinth(Labyrinth* labyrinth, Coordinates* vector) {
    int** tabSurroundings;
    int newValue;
    int i;

    for (i=0; i < (labyrinth->row - 2) * (labyrinth->col - 2); i++) { //scan surroundings vector

        if (!(vector[i].x == 0 || vector[i].x == labyrinth->row - 1 || vector[i].y == 0 || vector[i].y == labyrinth->col - 1)) {//verify coord is not an external wall

            if (labyrinth->matrix[vector[i].x][vector[i].y] == 0) { //verify if coord is a wall
                tabSurroundings = fill_surroundings(labyrinth->matrix, vector, i);
                check_surroundings(tabSurroundings);
                newValue = value_to_replace_surroundings(tabSurroundings);
                update_matrix(labyrinth, newValue, vector[i].x, vector[i].y, tabSurroundings);
            }
        }
    }

    free_matrix(tabSurroundings, 2);
}

/*
 * Rempli un tableau des coordonnées environnantes de la case que l'on analyse.
 */
int** fill_surroundings(int** matrix, Coordinates* vector, int index) {
    int** matrixSurroundings;
    matrixSurroundings = allocate_matrix(2, 4, 0);

    matrixSurroundings[0][0] = matrix[(vector[index].x) - 1][vector[index].y];
    matrixSurroundings[0][1] = matrix[(vector[index].x) + 1][vector[index].y];
    matrixSurroundings[0][2] = matrix[vector[index].x][(vector[index].y) - 1];
    matrixSurroundings[0][3] = matrix[vector[index].x][(vector[index].y) + 1];

    return matrixSurroundings;
}

/*
 * Compte le nombre de valeurs présentes parmis les cases environnantes
 */
void check_surroundings(int** matrixSurroundings) {
    int cpt;
    int i;
    int j;

    for (i=0; i<4; i++) {
        cpt = 0;

        for (j=0; j<4; j++) {
            if ( matrixSurroundings[0][i] != 0 && (matrixSurroundings[0][i] == matrixSurroundings[0][j]) ) {
                cpt++;
            }
        }
        matrixSurroundings[1][i] = cpt;
    }
}

/*
 * retourne la valeur par laquelle on doit remplacer la case que l'on analyse
 */
int value_to_replace_surroundings(int** matrixSurroundings) {
    int i;

    for (i=0; i<4; i++) {
        if (matrixSurroundings[1][i] == 1 && i%2 == 0 && matrixSurroundings[1][i+1] == 1) {
            return matrixSurroundings[0][i];
        } else if ( matrixSurroundings[1][i] == 2 ) {
            return -1;
        }
    }

    return -1;
}

/*
 * propage la nouvelle valeur dans le labyrinthe
 */
void update_matrix(Labyrinth* labyrinth, int newValue, int x, int y, int** matrixSurroundings) { //dispatch the newValue when breking a wall
    int i;
    int j;
    int k;

    if (newValue != -1) {
        labyrinth->matrix[x][y] = newValue;
        for (i=0; i<4; i++) {
            for (j=1; j<labyrinth->row; j++) {
                for (k=1; k<labyrinth->col; k++) {
                    if (matrixSurroundings[0][i] == labyrinth->matrix[j][k] && matrixSurroundings[1][i] != 0) {
                        labyrinth->matrix[j][k] = newValue;
                    }
                }
            }
        }
    }
}

/*
 * unifie toute les valeurs si elles ne valent pas 0 (= un mur) afin d'avoir un seul chemin possible
 */
void clear_labyrinth(Labyrinth* labyrinth) {
    int i;
    int j;
    for (i=1; i<labyrinth->row; i++) {
        for (j=1; j<labyrinth->col; j++) {
            if (labyrinth->matrix[i][j] != 0) labyrinth->matrix[i][j] = 1;
        }
    }
}

/*
 * affiche le labyrinthe proprement
 */
void display_matrix_clean(Labyrinth* labyrinth) {
    int i;
    int j;

    for (i=0; i<labyrinth->row; i++) {
        for (j=0; j<labyrinth->col; j++) {
            if (labyrinth->matrix[i][j] == 0) {
                printf("# ");
            } else if (labyrinth->matrix[i][j] == 1) {
                printf("  ");
            } else if (labyrinth->matrix[i][j] == 2) {
                printf("P ");
            } else if (labyrinth->matrix[i][j] == 3) {
                printf("+ ");
            } else if (labyrinth->matrix[i][j] == 4) {
                printf("- ");
            } else {
               printf("%d ", labyrinth->matrix[i][j]);
            }
        }
        printf("\n");
    }
}

/*
 * initialise un labyrinthe parfait
 */
void init_labyrinth(Labyrinth* labyrinth) {
    int** matrix;
    int value;
    int dimension;
    Coordinates *listTmpCoordinates;

    value = 0;
    dimension = (labyrinth->row-2)*(labyrinth->col-2); //external walls do not count

    matrix = allocate_matrix(labyrinth->row, labyrinth->col , value);

    labyrinth->matrix = matrix;

    init_matrix(labyrinth);


    listTmpCoordinates = allocate_vector_coordinates(dimension, value);
    fill_coordinates_vector(labyrinth->row, labyrinth->col , listTmpCoordinates);

    randomize_coordinates_vector(labyrinth->row, labyrinth->col, listTmpCoordinates);
    generate_labyrinth(labyrinth, listTmpCoordinates);

    free_vector_coordinates(listTmpCoordinates);

    clear_labyrinth(labyrinth);
    setting_bonus_malus(labyrinth);
}

/*
 * Créer un labyrinthe parfait et son fichier de sauvegarde correspondant
 */
void create_labyrinth(Labyrinth* labyrinth) {
    int row, col;
    char fileName[256], buffer[256];

    labyrinth->player = allocate_vector_coordinates(1, 0);
    labyrinth->bonus = allocate_vector_coordinates(1, 0);
    labyrinth->malus = allocate_vector_coordinates(1, 0);

    printf("Nom du fichier?\n");

    secure_input(fileName, 256);

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

    init_labyrinth(labyrinth);
    save_laby(labyrinth, fileName);
}

void setting_bonus_malus(Labyrinth* labyrinth) {
    int bonusX, bonusY, malusX, malusY;

    do {
        bonusX = generate_rand(labyrinth->row -1);
        bonusY = generate_rand(labyrinth->col -1);
    } while ( labyrinth->matrix[bonusX][bonusY] != 1 );

    labyrinth->matrix[bonusX][bonusY] = 3;
    labyrinth->bonus->x = bonusX;
    labyrinth->bonus->y = bonusY;

    do {
        malusX = generate_rand(labyrinth->row - 1);
        malusY = generate_rand(labyrinth->col - 1);
    } while ( labyrinth->matrix[malusX][malusY] != 1);

    labyrinth->matrix[malusX][malusY] = 4;
    labyrinth->malus->x = malusX;
    labyrinth->malus->y = malusY;
}