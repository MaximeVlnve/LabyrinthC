//
// Created by Maxime on 15/10/2018.
//

#include "header.h"

/*void play(Labyrinth* labyrinth){
    Coordinates exit, nextPosition;
    char nextMove;
    int isMoveAllowed;

    isMoveAllowed = 1;

    exit.x = labyrinth->col - 1;
    exit.y = labyrinth->row - 1;

    printf("%d %d", labyrinth->player.x, labyrinth->player.y);

    //while (nextPosition.x < 0  || nextPosition.x >= labyrinth->row || nextPosition.y < 0 || nextPosition.y >= labyrinth->col ) {
         do {

            scanf("%c", &nextMove);

            isMoveAllowed = verifyMoveAllowed(labyrinth, nextPosition);

            printf("\nisMoveAllowed : %d \n", isMoveAllowed);
        } while ((nextMove != 'Z' && nextMove != 'z' && nextMove != 'Q' && nextMove != 'q' && nextMove != 'S' && nextMove != 's' && nextMove != 'D' && nextMove != 'd') || isMoveAllowed );



        /*if (nextMove == 'Z' || nextMove == 'z'){
            nextPosition.x = labyrinth->player.x-1;
            nextPosition.y = labyrinth->player.y;
        } else if (nextMove == 'Q' || nextMove == 'q') {
            nextPosition.x = labyrinth->player.x;
            nextPosition.y = labyrinth->player.y-1;
        } else if (nextMove == 'S' || nextMove == 's'){
            nextPosition.x = labyrinth->player.x+1;
            nextPosition.y = labyrinth->player.y;
        } else {
            nextPosition.x = labyrinth->player.x;
            nextPosition.y = labyrinth->player.y+1;
        }
    //}



}*/

int verifyMoveAllowed(Labyrinth* labyrinth, Coordinates nextPosition){
    //printf("%d %d", nextPosition.x, nextPosition.y);
    if (nextPosition.x < 0  || nextPosition.x >= labyrinth->row || nextPosition.y < 0 || nextPosition.y >= labyrinth->col) return 1;

    if (labyrinth->matrix[nextPosition.x][nextPosition.y] == 0) {
        return 1;
    } else {
        return 0;
    }

}

void play(Labyrinth* labyrinth){
    Coordinates oldPosition, nextPosition;
    char nextMove;
    int boolIsMoveAllowed = 1;
    int boolIsGameOver = 1;

    while (boolIsGameOver){
        oldPosition.x = labyrinth->player.x;
        oldPosition.y = labyrinth->player.y;

        do {
            printf("Prochain mouvement?\n");
            scanf(" %c", &nextMove);

            if (nextMove == 'Z' || nextMove == 'z'){
                nextPosition.x = labyrinth->player.x-1;
                nextPosition.y = labyrinth->player.y;
            } else if (nextMove == 'Q' || nextMove == 'q') {
                nextPosition.x = labyrinth->player.x;
                nextPosition.y = labyrinth->player.y-1;
            } else if (nextMove == 'S' || nextMove == 's'){
                nextPosition.x = labyrinth->player.x+1;
                nextPosition.y = labyrinth->player.y;
            } else {
                nextPosition.x = labyrinth->player.x;
                nextPosition.y = labyrinth->player.y+1;
            }

            boolIsMoveAllowed = verifyMoveAllowed(labyrinth, nextPosition);
        } while ((nextMove != 'Z' && nextMove != 'z' && nextMove != 'Q' && nextMove != 'q' && nextMove != 'S' && nextMove != 's' && nextMove != 'D' && nextMove != 'd') || boolIsMoveAllowed);



        labyrinth->player.x = nextPosition.x;
        labyrinth->player.y = nextPosition.y;

        labyrinth->matrix[oldPosition.x][oldPosition.y] = 1;
        labyrinth->matrix[labyrinth->player.x][labyrinth->player.y] = 2;
        displayMatrixClean(labyrinth);

        if (labyrinth->matrix[labyrinth->row - 2][labyrinth->col - 1] == 2) {
            boolIsGameOver = 0;
        }
    }



}