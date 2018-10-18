//
// Created by Maxime on 15/10/2018.
//

#include "header.h"

/*
 * Premièrement, cette fonction verifie que les coordonnées qui résultent du choix
 * de direction de l'utilisateur (selon zqsd) sont autorisées. Ce qui veut dire que
 * ses coordonnées sont accessibles selon la taille du labyrinthe.
 * Ensuite, on vérifie que les coordonnées sont "possibles" d'accés, c'est à dire
 * que les coordonnées ne correspondent pas à un mur.
 */
int verifyMoveAllowed(Labyrinth* labyrinth, Coordinates nextPosition) {
    if (nextPosition.x < 0  || nextPosition.x >= labyrinth->row || nextPosition.y < 0 || nextPosition.y >= labyrinth->col) return 1;

    if (labyrinth->matrix[nextPosition.x][nextPosition.y] == 0) {
        return 1;
    } else {
        return 0;
    }

}

/*
 * Cette fonction utilise un booléen qui vérifie que la partie n'est pas terminée (ce qui est le cas
 * si le joueur est à la sortie du labyrinthe). Puis, on propose un mouvement au joueur,
 * on vérifie que son mouvement souhaité est possible. Si c'est le cas on change la position
 * du joueur et son ancienne position redevient une case accessible. Sinon, on demande une nouvelle
 * entrée.
 */
void play(Labyrinth* labyrinth) {
    Coordinates oldPosition, nextPosition;
    char nextMove[10];
    int boolIsMoveAllowed = 1;
    int boolIsGameOver = 1;
    Score* score;

    score = (Score *)malloc(sizeof(Score));

    score->points = 0;

    printf("Entrez votre nom\n");
    secureInput(score->name, 256);

    printf("%s", score->name);


    while (boolIsGameOver) { //Verifies if the player is not a the end of the labyrinth
        oldPosition.x = labyrinth->player->x;
        oldPosition.y = labyrinth->player->y;

        printf("Score : %d - Use ZQSD to move or press E to back menu\n", score->points);

        do {
            secureInput(nextMove, 10);

            if (nextMove[0] == 'Z' || nextMove[0] == 'z') { //if else to decide coordinates according zqsd system
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
            } else if (nextMove[0] == 'E' || nextMove[0] == 'e') { //press e allows user to back menu
                return;
            }

            boolIsMoveAllowed = verifyMoveAllowed(labyrinth, nextPosition);
        } while ((nextMove[0] != 'Z' && nextMove[0] != 'z' && nextMove[0] != 'Q' && nextMove[0] != 'q' && nextMove[0] != 'S' && nextMove[0] != 's' && nextMove[0] != 'D' && nextMove[0] != 'd') || boolIsMoveAllowed);



        labyrinth->player->x = nextPosition.x;
        labyrinth->player->y = nextPosition.y;

        score->points++;

        labyrinth->matrix[oldPosition.x][oldPosition.y] = 1; // replacing player's previous position with 1 (code chose to identify a coordinate where player can go
        labyrinth->matrix[labyrinth->player->x][labyrinth->player->y] = 2;
        displayMatrixClean(labyrinth);

        if (labyrinth->matrix[labyrinth->row - 2][labyrinth->col - 1] == 2) { //verifies that player is at labyrinth's exit or not
            boolIsGameOver = 0;
        }

        sauveScore(score, labyrinth);

    }
    sauveLaby(labyrinth, labyrinth->name); //saves the move in case player leaves and wants to play again with that labyrinth
}