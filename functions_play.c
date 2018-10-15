//
// Created by Maxime on 15/10/2018.
//

#include "header.h"

/*
 * First, this function verify if coordinates made by the choice of the direction (zqsd) is
 * "allowed". "Allowed" means coordinates is among those possible of the labyrinth's matrix.
 * Then, it verifies if coordinates is "possible" meaning its not a wall.
 */
int verifyMoveAllowed(Labyrinth* labyrinth, Coordinates nextPosition){
    if (nextPosition.x < 0  || nextPosition.x >= labyrinth->row || nextPosition.y < 0 || nextPosition.y >= labyrinth->col) return 1;

    if (labyrinth->matrix[nextPosition.x][nextPosition.y] == 0) {
        return 1;
    } else {
        return 0;
    }

}

void play(Labyrinth* labyrinth){
    Coordinates oldPosition, nextPosition;
    char nextMove[10], *positionEntree;
    int boolIsMoveAllowed = 1;
    int boolIsGameOver = 1;

    while (boolIsGameOver){ //Verifies if the player is not a the end of the labyrinth
        oldPosition.x = labyrinth->player->x;
        oldPosition.y = labyrinth->player->y;

        printf("Use ZQSD to move or press E to back menu\n");

        do {
            if (fgets(nextMove, sizeof(nextMove), stdin)) { //using fgets instead of scanf to secure input

                positionEntree = strchr(nextMove, '\n'); // Looking for the \n of the user's input
                if (positionEntree != NULL) // if \n found
                {
                    *positionEntree = '\0'; // then replace it by \0
                }
            }

            if (nextMove[0] == 'Z' || nextMove[0] == 'z'){ //if else to decide coordinates according zqsd system
                nextPosition.x = labyrinth->player->x-1;
                nextPosition.y = labyrinth->player->y;
            } else if (nextMove[0] == 'Q' || nextMove[0] == 'q') {
                nextPosition.x = labyrinth->player->x;
                nextPosition.y = labyrinth->player->y-1;
            } else if (nextMove[0] == 'S' || nextMove[0] == 's'){
                nextPosition.x = labyrinth->player->x+1;
                nextPosition.y = labyrinth->player->y;
            } else if (nextMove[0] == 'D' || nextMove[0] == 'd'){
                nextPosition.x = labyrinth->player->x;
                nextPosition.y = labyrinth->player->y+1;
            } else if(nextMove[0] == 'E' || nextMove[0] == 'e'){ //press e allows user to back menu
                return;
            }

            boolIsMoveAllowed = verifyMoveAllowed(labyrinth, nextPosition);
        } while ((nextMove[0] != 'Z' && nextMove[0] != 'z' && nextMove[0] != 'Q' && nextMove[0] != 'q' && nextMove[0] != 'S' && nextMove[0] != 's' && nextMove[0] != 'D' && nextMove[0] != 'd') || boolIsMoveAllowed);



        labyrinth->player->x = nextPosition.x;
        labyrinth->player->y = nextPosition.y;

        labyrinth->matrix[oldPosition.x][oldPosition.y] = 1; // replacing player's previous position with 1 (code chose to identify a coordinate where player can go
        labyrinth->matrix[labyrinth->player->x][labyrinth->player->y] = 2;
        displayMatrixClean(labyrinth);

        if (labyrinth->matrix[labyrinth->row - 2][labyrinth->col - 1] == 2) { //verifies that player is at labyrinth's exit or not
            boolIsGameOver = 0;
        }

        sauveLaby(labyrinth, labyrinth->name); //saves the move in case player leaves and wants to play again with that labyrinth
    }


}