/*
 * Created by Maxime on 09/10/2018.
 */
#include "header.h"
#include "header_functions_input.h"
#include "header_functions.h"
#include "header_useful_functions.h"
#include "header_init_labyrinth.h"
#include "header_sauves.h"

void generate_labyrinth(Labyrinth* labyrinth, Coordinates* vector) {
    int** tabSurroundings;
    int newValue;
    int i;

    for (i=0; i < (labyrinth->row - 2) * (labyrinth->col - 2); i++) { /*scan surroundings vector*/

        if (!(vector[i].x == 0 || vector[i].x == labyrinth->row - 1 || vector[i].y == 0 || vector[i].y == labyrinth->col - 1)) {/*verify coord is not an external wall*/

            if (labyrinth->matrix[vector[i].x][vector[i].y] == WALL) { /*verify if coord is a wall*/
                tabSurroundings = fill_surroundings(labyrinth->matrix, vector, i);
                check_surroundings(tabSurroundings);
                newValue = value_to_replace_surroundings(tabSurroundings);
                update_matrix(labyrinth, newValue, vector[i].x, vector[i].y, tabSurroundings);
            }
        }
    }

    free_matrix(tabSurroundings, 2);
}

int** fill_surroundings(int** matrix, Coordinates* vector, int index) {
    int** matrixSurroundings;
    matrixSurroundings = allocate_matrix(2, 4, 0);

    matrixSurroundings[0][0] = matrix[(vector[index].x) - 1][vector[index].y];
    matrixSurroundings[0][1] = matrix[(vector[index].x) + 1][vector[index].y];
    matrixSurroundings[0][2] = matrix[vector[index].x][(vector[index].y) - 1];
    matrixSurroundings[0][3] = matrix[vector[index].x][(vector[index].y) + 1];

    return matrixSurroundings;
}

void check_surroundings(int** matrixSurroundings) {
    int cpt;
    int i;
    int j;

    for (i=0; i<4; i++) {
        cpt = 0;

        for (j=0; j<4; j++) {
            if ( matrixSurroundings[0][i] != WALL && (matrixSurroundings[0][i] == matrixSurroundings[0][j]) ) {
                cpt++;
            }
        }
        matrixSurroundings[1][i] = cpt;
    }
}

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

void update_matrix(Labyrinth* labyrinth, int newValue, int x, int y, int** matrixSurroundings) { /*dispatch the newValue when breking a wall*/
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

void clear_labyrinth(Labyrinth* labyrinth) {
    int i;
    int j;
    for (i=1; i<labyrinth->row; i++) {
        for (j=1; j<labyrinth->col; j++) {
            if (labyrinth->matrix[i][j] != WALL) labyrinth->matrix[i][j] = 1;
        }
    }
}

void display_matrix_clean(Labyrinth* labyrinth) {
    int i;
    int j;

    for (i=0; i<labyrinth->row; i++) {
        for (j=0; j<labyrinth->col; j++) {
            if (labyrinth->matrix[i][j] == WALL) {
                printf("# ");
            } else if (labyrinth->matrix[i][j] == 1) {
                printf("  ");
            } else if (labyrinth->matrix[i][j] == PLAYER) {
                printf("P ");
            } else if (labyrinth->matrix[i][j] == BONUS) {
                printf("+ ");
            } else if (labyrinth->matrix[i][j] == MALUS) {
                printf("- ");
            } else if (labyrinth->matrix[i][j] == ZOMBIE) {
                printf("Z ");
            } else if (labyrinth->matrix[i][j] == GHOST) {
                printf("G ");
            } else {
               printf("%d ", labyrinth->matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void init_labyrinth(Labyrinth* labyrinth) {
    int** matrix;
    int value;
    int dimension;
    int difficulty;
    Coordinates *listTmpCoordinates;

    difficulty = get_difficulty();

    value = WALL;
    dimension = (labyrinth->row-2)*(labyrinth->col-2); /*external walls do not count*/

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

    if (difficulty == 2) {
        setting_ghost(labyrinth);
        setting_zombie(labyrinth);
    }

}

void create_labyrinth(Labyrinth* labyrinth) {
    int row;
    int col;
    char fileName[CHAR_MAX];
    char buffer[CHAR_MAX];

    labyrinth->player = allocate_vector_coordinates(1, 0);
    labyrinth->bonus = allocate_vector_coordinates(1, 0);
    labyrinth->malus = allocate_vector_coordinates(1, 0);
    labyrinth->zombie = allocate_vector_coordinates(1, 0);
    labyrinth->ghost = allocate_vector_coordinates(1, 0);

    printf("Nom du fichier?\n");

    secure_input(fileName, CHAR_MAX);

    strcpy(labyrinth->name, fileName);

    do {
        printf("Combien de lignes ? (impaire)\n");
        fgets (buffer, CHAR_MAX, stdin);
        row = atoi (buffer);
    } while (row % 2 == 0 || row < 5); /* having a row < 5 is not useful */

    do {
        printf("Combien de colonnes ? (impaire)\n");
        fgets (buffer, CHAR_MAX, stdin);
        col = atoi (buffer);
    } while (col % 2 == 0 || col < 5); /* having a col < 5 is not useful */

    labyrinth->row = row;
    labyrinth->col = col;
    labyrinth->boolEmpty = 1;
    labyrinth->player->x = 1;
    labyrinth->player->y = 0;

    init_labyrinth(labyrinth);
    save_laby(labyrinth, fileName);
}

void setting_bonus_malus(Labyrinth* labyrinth) {
    int bonusX;
    int bonusY;
    int malusX;
    int malusY;

    do {
        bonusX = generate_rand(labyrinth->row -1);
        bonusY = generate_rand(labyrinth->col -1);
    } while ( labyrinth->matrix[bonusX][bonusY] != 1 );

    labyrinth->matrix[bonusX][bonusY] = BONUS;
    labyrinth->bonus->x = bonusX;
    labyrinth->bonus->y = bonusY;

    do {
        malusX = generate_rand(labyrinth->row - 1);
        malusY = generate_rand(labyrinth->col - 1);
    } while ( labyrinth->matrix[malusX][malusY] != 1);

    labyrinth->matrix[malusX][malusY] = MALUS;
    labyrinth->malus->x = malusX;
    labyrinth->malus->y = malusY;
}

void setting_zombie(Labyrinth* labyrinth) {
    int zombieX;
    int zombieY;

    do {
        zombieX = generate_rand(labyrinth->row -1);
        zombieY = generate_rand(labyrinth->col -1);
    } while ( labyrinth->matrix[zombieX][zombieY] != 1 );

    labyrinth->matrix[zombieX][zombieY] = ZOMBIE;
    labyrinth->zombie->x = zombieX;
    labyrinth->zombie->y = zombieY;
}

void setting_ghost(Labyrinth* labyrinth) {
    int ghostX;
    int ghostY;

    do {
        ghostX = generate_rand(labyrinth->row -1);
        ghostY = generate_rand(labyrinth->col -1);
    } while ( labyrinth->matrix[ghostX][ghostY] != 1 );

    labyrinth->matrix[ghostX][ghostY] = GHOST;
    labyrinth->ghost->x = ghostX;
    labyrinth->ghost->y = ghostY;
}
