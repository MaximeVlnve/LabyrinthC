#include "header_sauves.h"

int main() {
    srand( time(NULL) ); //init rand

    int choice, exit = 1;
    Labyrinth labyrinth;

    while (exit){
        system("clear");
        choice = menu(1,4);

        switch(choice)
        {
            case 1:
                create_labyrinth(&labyrinth);

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
                load_laby(&labyrinth);
                play(&labyrinth);
                break;
            case 3:
                printf("Jouer\n");

                if (labyrinth.boolEmpty == 1){
                    printf("Laby chargé %s\n", labyrinth.name);
                    play(&labyrinth);
                } else {
                    printf("Pas de laby chargé\n");
                    load_laby(&labyrinth);
                    play(&labyrinth);
                }
                break;
            case 4:
                printf("Quitter\n");
                exit = 0;
                break;
        }

    }

    return(0);
}