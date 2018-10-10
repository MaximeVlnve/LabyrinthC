//
// Created by Maxime on 10/10/2018.
//

#include "header.h"

void sauveLaby(Labyrinth* labyrinth){

    FILE *f = fopen("/Users/maxime/Documents/Ensi/Prog/GitHubProjet/sauves/laby.txt", "w");

    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "Col : %d\nRow : %d\n", labyrinth->col, labyrinth->row);

    for(int i=0; i<labyrinth->row; i++){
        for(int j=0; j<labyrinth->col; j++){
            fprintf(f, "%d", labyrinth->matrix[i][j]);
        }
    }

    fclose(f);
}

