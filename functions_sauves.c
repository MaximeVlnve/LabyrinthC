//
// Created by Maxime on 10/10/2018.
//

#include "header.h"

void sauveLaby(Labyrinth* labyrinth, char fileName[256]){

    char path[100], extension[5];

    strcpy(path,  "/Users/maxime/Documents/Ensi/Prog/LabyrinthC/sauves/");
    strcpy(extension, ".txt");

    strcat(path, fileName);
    strcat(path, extension); //copying path, fileName, and extension to save a labyrinth


    FILE *f = fopen(path, "w"); // open the file or create it if it already exists

    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

    //fprintf(f, "%d\n%d\n%d\n%d\n%d\n", labyrinth->player->x, labyrinth->player->y, labyrinth->col, labyrinth->row, labyrinth->boolEmpty);
    fprintf(f, "%d\n%d\n%d\n%d\n1\n", labyrinth->player->x, labyrinth->player->y, labyrinth->col, labyrinth->row); //writing infos we need if we want to re-open

    for(int i=0; i<labyrinth->row; i++){
        for(int j=0; j<labyrinth->col; j++){
            fprintf(f, "%d", labyrinth->matrix[i][j]); //writing every coordinates
        }
    }

    fclose(f);

}

void loadLaby(Labyrinth* labyrinth){
    char fileName[256], path[100], extension[5], *positionEntree;

    printf("Enter the laby's name you want to load\n");

    viderBuffer();

    strcpy(path,  "/Users/maxime/Documents/Ensi/Prog/LabyrinthC/sauves/");
    strcpy(extension, ".txt");

    if (fgets(fileName, sizeof(fileName), stdin)) {

        positionEntree = strchr(fileName, '\n'); // Looking for the \n of the user's input
        if (positionEntree != NULL) // if \n found
        {
            *positionEntree = '\0'; // then replace it by \0
        }

        strcat(path, fileName);
        strcat(path, extension); //copying path, fileName, and extension to load a labyrinth

        if( access( path, F_OK ) != -1 ) { //verifies file exists

            FILE *f = fopen(path, "r");

            if (f == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }

            char str[240];
            int index=0, row, col, playerX, playerY, isEmpty;


            while (1) {
                if (fgets(str, 240, f) == NULL) break;

                switch (index){
                    case 0:
                        playerX = atoi(&str[0]); // retrieve X player's position
                        break;
                    case 1:
                        playerY = atoi(&str[0]); // retrieve Y player's position
                        break;
                    case 2:
                        col = atoi(&str[0]); // retrieve labyrinth's column size
                        break;
                    case 3:
                        row = atoi(&str[0]); // retrieve labyrinth's row size
                        break;
                    case 4:
                        isEmpty = atoi(&str[0]);
                        break;
                }

                index++;
            }

            int vector[240];

            for(int i=0; i<strlen(str); i++){
                vector[i] = str[i] - '0'; // retrieve labyrinth's coordinates in an array
            }


            labyrinth->row = row;
            labyrinth->col = col;
            labyrinth->player->x = playerX;
            labyrinth->player->y = playerY;
            labyrinth->boolEmpty = isEmpty;
            strcpy(labyrinth->name, fileName);
            labyrinth->matrix = allocateMatrix(labyrinth->row, labyrinth->col, 0);

            int value=0;
            for(int i=0; i<labyrinth->row; i++){
                for(int j=0; j<labyrinth->col; j++){
                    labyrinth->matrix[i][j] = vector[value];
                    value++;
                }
            }

            fclose(f);

            displayMatrixClean(labyrinth);
        }
    }
}


