/*
 * Created by Maxime on 15/10/2018.
 */

#include "header.h"
#include "header_useful_functions.h"
#include "header_init_labyrinth.h"
#include "header_functions_input.h"
#include "header_sauves.h"

int verify_move_allowed(Labyrinth* labyrinth, Coordinates nextPosition) {
    if (nextPosition.x < 0  || nextPosition.x >= labyrinth->row || nextPosition.y < 0 || nextPosition.y >= labyrinth->col) return 1;

    if (labyrinth->matrix[nextPosition.x][nextPosition.y] == WALL) {
        return 1;
    } else {
        return 0;
    }

}

void play(Labyrinth* labyrinth) {
    Coordinates oldPosition;
    Coordinates nextPosition;
    Coordinates bonus;
    Coordinates malus;
    Coordinates zombie;
    Coordinates ghost;
    char nextMove[CHAR_MAX];
    int boolIsMoveAllowed;
    int boolIsGameOver;
    Score* score;

    boolIsMoveAllowed = 1;
    boolIsGameOver = 1;

    bonus = *labyrinth->bonus;
    malus = *labyrinth->malus;
    zombie = *labyrinth->zombie;
    ghost = *labyrinth->ghost;

    score = (Score *)malloc(sizeof(Score));
    score->points = 0;

    while (boolIsGameOver) { /*Verifies if the player is not a the end of the labyrinth*/
        display_matrix_clean(labyrinth);

        oldPosition.x = labyrinth->player->x;
        oldPosition.y = labyrinth->player->y;

        printf("Score : %d\n", score->points);

        do {
            printf("Utilisez ZQSD pour vous déplacer ou E pour retourner au menu\n");
            secure_input(nextMove, CHAR_MAX);

            if (nextMove[0] == 'Z' || nextMove[0] == 'z') { /*if else to decide coordinates according zqsd*/
                nextPosition.x = labyrinth->player->x-1;
                nextPosition.y = labyrinth->player->y;
            } else if (nextMove[0] == 'Q' || nextMove[0] == 'q') {
                nextPosition.x = labyrinth->player->x;
                nextPosition.y = labyrinth->player->y-1;
            } else if (nextMove[0] == 'S' || nextMove[0] == 's') {
                nextPosition.x = labyrinth->player->x+1;
                nextPosition.y = labyrinth->player->y;
            } else if (nextMove[0] == 'D' || nextMove[0] == 'd') {
                nextPosition.x = labyrinth->player->x;
                nextPosition.y = labyrinth->player->y+1;
            } else if (nextMove[0] == 'E' || nextMove[0] == 'e') { /*press e allows user to back menu*/
                labyrinth->matrix[labyrinth->player->x][labyrinth->player->y] = 1;
                labyrinth->matrix[1][0] = PLAYER;

                labyrinth->player->x = 1;
                labyrinth->player->y = 0;

                labyrinth->matrix[bonus.x][bonus.y] = BONUS;
                labyrinth->matrix[malus.x][malus.y] = MALUS;

                return;
            }

            boolIsMoveAllowed = verify_move_allowed(labyrinth, nextPosition);
        } while ((nextMove[0] != 'Z' && nextMove[0] != 'z' && nextMove[0] != 'Q' && nextMove[0] != 'q' && nextMove[0] != 'S' && nextMove[0] != 's' && nextMove[0] != 'D' && nextMove[0] != 'd') || boolIsMoveAllowed);


        if (labyrinth->matrix[nextPosition.x][nextPosition.y] == BONUS) {
            if (score->points - POINTS >= 0) {
                score->points -= POINTS;
            } else {
                score->points -= score->points;
            }
        } else if (labyrinth->matrix[nextPosition.x][nextPosition.y] == MALUS) {
            score->points += POINTS;
        } else {
            score->points++;
        }

        if (labyrinth->matrix[nextPosition.x][nextPosition.y] == ZOMBIE || labyrinth->matrix[nextPosition.x][nextPosition.y] == GHOST) {
            boolIsGameOver = 0;
            printf("Perdu !\n");
        }

        labyrinth->player->x = nextPosition.x;
        labyrinth->player->y = nextPosition.y;


        labyrinth->matrix[oldPosition.x][oldPosition.y] = 1; /* replacing player's previous position with 1 (code chose to identify a coordinate where player can go*/
        labyrinth->matrix[labyrinth->player->x][labyrinth->player->y] = PLAYER;

        if (labyrinth->matrix[labyrinth->row - 2][labyrinth->col - 1] == PLAYER) { /*verifies that player is at labyrinth's exit or not*/
            boolIsGameOver = 0;
            display_matrix_clean(labyrinth);
            printf("Félicitations !\n");

            printf("Entrez votre nom\n");
            secure_input(score->name, CHAR_MAX);

            save_score(score, labyrinth);
        }

    }

    labyrinth->matrix[labyrinth->player->x][labyrinth->player->y] = 1;
    labyrinth->matrix[1][0] = PLAYER;

    labyrinth->player->x = 1;
    labyrinth->player->y = 0;

    labyrinth->matrix[bonus.x][bonus.y] = BONUS;
    labyrinth->matrix[malus.x][malus.y] = MALUS;
    labyrinth->matrix[zombie.x][zombie.y] = ZOMBIE;
    labyrinth->matrix[ghost.x][ghost.y] = GHOST;

    save_laby(labyrinth, labyrinth->name);

}
