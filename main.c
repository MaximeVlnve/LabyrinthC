#include "header.h"

int main() {
    srand( time(NULL) ); //init rand

    int choice, exit = 1;
    Labyrinth labyrinth;

    while (exit){
        printf("------------ LABYRINTH ------------\n\n");
        printf("\t 1 - Creer un labyrinthe\n");
        printf("\t 2 - Charger un labyrinthe\n");
        printf("\t 3 - Jouer\n");
        printf("\t 4 - Quitter\n\n");
        printf("-----------------------------------\n\n");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                createLabyrinth(&labyrinth);

                printf("\n------------------------------\n");
                printf("Current Laby :\n");
                printf("\tName : %s\n", labyrinth.name);
                printf("\tRow : %d\n", labyrinth.row);
                printf("\tCol : %d\n", labyrinth.col);
                printf("\tPlayer : %d %d\n", labyrinth.player->x, labyrinth.player->y);
                printf("------------------------------\n");
                play(&labyrinth);
                break;
            case 2:
                loadLaby(&labyrinth);
                play(&labyrinth);
                break;
            case 3:
                printf("Jouer\n");

                if (labyrinth.boolEmpty == 1){
                    printf("Laby chargé %s\n", labyrinth.name);
                    displayMatrixClean(&labyrinth);
                    play(&labyrinth);
                } else {
                    printf("Pas de laby chargé\n");
                    loadLaby(&labyrinth);
                    play(&labyrinth);
                }
                break;
            default:
                printf("Quitter\n");
                exit = 0;
                break;
        }

    }




    /*

    initLabyrinth(&labyrinth);

    sauveLaby(&labyrinth);*/

    /*Labyrinth labyrinth;

    createLabyrinth(&labyrinth);
    play(&labyrinth);*/

    //loadLaby(&labyrinth);

    //displayMatrixClean(&labyrinth);



    return(0);


    //freeMatrix(labyrinth.matrix, labyrinth.row);

    return 0;
}