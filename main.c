#include "header.h"

int main() {
    srand( time(NULL) ); //init rand

    /*int choice;

    printf("------------ LABYRINTH ------------\n\n");
    printf("\t 1 - Creer un labyrinthe\n");
    printf("\t 2 - Charger un labyrinthe\n");
    printf("\t 3 - Jouer\n");
    printf("\t 4 - Quitter\n\n");
    printf("-----------------------------------\n\n");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1: printf("");
            Labyrinth labyrinth;

            initLabyrinth(&labyrinth);
            break;
        case 2: printf("Charger un labyrinthe\n");
            break;
        case 3: printf("Jouer\n");
            break;
        default: printf("Quitter\n");
            break;
    }*/

    Labyrinth labyrinth;

    initLabyrinth(&labyrinth);

    //sauveLaby(&labyrinth);

    return(0);


    //freeMatrix(labyrinth.matrix, labyrinth.row);

    return 0;
}