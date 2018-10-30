#include "header.h"
#include "header_init_labyrinth.h"
#include "header_functions_input.h"
#include "header_play.h"
#include "header_sauves.h"

int main() {
    int choice;
    int exit;
    Labyrinth labyrinth;

    srand( time(NULL) ); /*init rand*/

    exit = 1;

    while (exit){
        choice = menu(1,4);

        switch(choice)
        {
            case 1:
                create_labyrinth(&labyrinth);

                printf("\n------------------------------\n");
                printf("Labyrinthe actuel :\n");
                printf("\tNom : %s\n", labyrinth.name);
                printf("\tNombre de lignes : %d\n", labyrinth.row);
                printf("\tNombre de colonnes : %d\n", labyrinth.col);
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
                    printf("Labyrinthe chargé : %s\n", labyrinth.name);
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
