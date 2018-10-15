//
// Created by Maxime on 10/10/2018.
//

#include "header.h"

void sauveLaby(Labyrinth* labyrinth, char fileName[256]){

    char path[100], extension[5];

    strcpy(path,  "/Users/maxime/Documents/Ensi/Prog/LabyrinthC/sauves/");
    strcpy(extension, ".txt");

    strcat(path, fileName);
    strcat(path, extension);

    printf("Final path : %s", path);

    FILE *f = fopen(path, "w");

    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "%d\n%d\n", labyrinth->col, labyrinth->row);

    for(int i=0; i<labyrinth->row; i++){
        for(int j=0; j<labyrinth->col; j++){
            fprintf(f, "%d", labyrinth->matrix[i][j]);
        }
    }

    fclose(f);

}

void loadLaby(Labyrinth* labyrinth){
    char fileName[256], path[100], extension[5], *positionEntree;

    strcpy(path,  "/Users/maxime/Documents/Ensi/Prog/LabyrinthC/sauves/");
    strcpy(extension, ".txt");

    if (fgets(fileName, sizeof(fileName), stdin)) {

        positionEntree = strchr(fileName, '\n'); // On recherche l'"Entrée"
        if (positionEntree != NULL) // Si on a trouvé le retour à la ligne
        {
            *positionEntree = '\0'; // On remplace ce caractère par \0
        }

        strcat(path, fileName);
        strcat(path, extension);

        if( access( path, F_OK ) != -1 ) {
            printf("File exists\n");

            FILE *f = fopen(path, "r");

            if (f == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }

            char str[240];
            int index=0, row, col;


            while (1) {
                if (fgets(str, 240, f) == NULL) break;

                switch (index){
                    case 0:
                        col = atoi(&str[0]);
                        break;
                    case 1:
                        row = atoi(&str[0]);
                        break;
                }

                index++;
            }

            int vector[240];

            for(int i=0; i<strlen(str); i++){
                vector[i] = str[i] - '0';
            }

            printf("test\n");


            labyrinth->row = row;
            labyrinth->col = col;

            labyrinth->matrix = allocateMatrix(labyrinth->row, labyrinth->col, 0);

            int value=0;
            for(int i=0; i<labyrinth->row; i++){
                for(int j=0; j<labyrinth->col; j++){
                    labyrinth->matrix[i][j] = vector[value];
                    value++;
                }
            }

            fclose(f);
        }
    }
}


