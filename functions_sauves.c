//
// Created by Maxime on 10/10/2018.
//

#include "header_sauves.h"

/*
 * La fonction save_laby utilise un nom de fichier en parametre et
 * enregistre le labirynthe. On sauvegarde des parametres utiles pour la suite
 * comme les dimensions (row et col), la position du joueur
 * (afin de replacer le joueur correctement quand on chargera le labyrinthe).
 */
void save_laby(Labyrinth* labyrinth, char fileName[CHAR_MAX]) {
    int i, j;
    char path[CHAR_MAX];
    char extension[CHAR_MAX];
    FILE *f;

    strcpy(path,  "/Users/maxime/Documents/Ensi/Prog/Recovery_bis/LabyrinthC/sauves/");
    strcpy(extension, ".cfg");

    strcat(path, fileName);
    strcat(path, extension); //copying path, fileName, and extension to save a labyrinth


    f = fopen(path, "w"); // open the file or create it if it already exists

    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fprintf(f, "%d\n%d\n1\n", labyrinth->col, labyrinth->row); //writing infos we need if we want to re-open

    for (i=0; i<labyrinth->row; i++) {
        for(j=0; j<labyrinth->col; j++) {
            fprintf(f, "%d", labyrinth->matrix[i][j]); //writing every coordinates
        }
    }

    fclose(f);
}
/*
 * On utilise une entrée utilisateur pour savoir quel labyrinthe charger.
 * Si le nom d'un fichier correspond à l'entrée utilisateur,
 * alors on accède au fichier et on récupère les informations
 * présentes dans le fichier.
 */
void load_laby(Labyrinth* labyrinth) {
    char fileName[CHAR_MAX];
    char path[CHAR_MAX];
    char extension[CHAR_MAX];
    char str[CHAR_MAX];
    int index;
    int row;
    int col;
    int isEmpty;
    int vector[CHAR_MAX];
    int i;
    int j;
    int value;
    FILE *f;

    index = 0;
    value = 0;

    labyrinth->player = allocate_vector_coordinates(1,0);
    labyrinth->bonus = allocate_vector_coordinates(1, 0);
    labyrinth->malus = allocate_vector_coordinates(1, 0);


    printf("Enter the laby's name you want to load\n");

    strcpy(path,  "/Users/maxime/Documents/Ensi/Prog/Recovery_Bis/LabyrinthC/sauves/");
    strcpy(extension, ".cfg");

    if (secure_input(fileName, CHAR_MAX)) {
        strcat(path, fileName);
        strcat(path, extension); //copying path, fileName, and extension to load a labyrinth

        if (access( path, F_OK ) != -1) { //verifies file exists
            f = fopen(path, "r");

            if (f == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }

            while (1) {
                if (fgets(str, CHAR_MAX, f) == NULL) break;

                switch (index) {
                    case 0:
                        col = atoi(&str[0]); // retrieve labyrinth's column size
                        break;
                    case 1:
                        row = atoi(&str[0]); // retrieve labyrinth's row size
                        break;
                    case 2:
                        isEmpty = atoi(&str[0]); // retourne un booléen qui détermine si le labyrinthe est vide ou pas
                        break;
                }

                index++;
            }

            for (i=0; i<(int)strlen(str); i++) {
                vector[i] = str[i] - '0'; // retrieve labyrinth's coordinates in an array
            }

            labyrinth->player->x = 1;
            labyrinth->player->y = 0;

            labyrinth->row = row;
            labyrinth->col = col;

            labyrinth->boolEmpty = isEmpty;

            strcpy(labyrinth->name, fileName);

            labyrinth->matrix = allocate_matrix(labyrinth->row, labyrinth->col, 0);

            for (i=0; i<labyrinth->row; i++) {
                for (j=0; j<labyrinth->col; j++) {
                    labyrinth->matrix[i][j] = vector[value];

                    if (labyrinth->matrix[i][j] == 3) {
                            labyrinth->bonus->x = i;
                            labyrinth->bonus->y = j;
                    } else if (labyrinth->matrix[i][j] == 4) {
                        labyrinth->malus->x = i;
                        labyrinth->malus->y = j;
                    }

                    value++;
                }
            }

            fclose(f);
        } else {
            create_labyrinth(labyrinth);
        }
    }
}

void save_score(Score* score, Labyrinth* labyrinth) {
    char path[CHAR_MAX];
    char extension[CHAR_MAX];
    Score results[NB_SCORE];
    Score tmp;
    int nbScores;
    int i;
    FILE *f;

    strcpy(path,  "/Users/maxime/Documents/Ensi/Prog/Recovery_bis/LabyrinthC/sauves/");
    strcpy(extension, ".score");

    strcat(path, labyrinth->name);
    strcat(path, extension);

    f = fopen(path,"r");

    if (f != NULL) {
        for (nbScores = 0 ; fscanf(f,"%s %d",tmp.name,&tmp.points) != EOF ; nbScores++) {
            if (nbScores < NB_SCORE-1) {
                results[nbScores] = tmp;
            }
        }

        fclose(f);
        f = fopen(path,"w");

        strcpy(results[nbScores].name, score->name);
        results[nbScores].points = score->points;

        qsort(results,nbScores+1,sizeof(Score),compare_scores_points);

        for(i = 0; i < 10; i++) {
            if (i<=nbScores) {
                fprintf(f, "%s %d\n",results[i].name, results[i].points);
            }

        }
        fclose(f);
    } else {
        fclose(f);

        f = fopen(path, "w");
        fprintf(f, "%s %d\n", score->name, score->points);
        fclose(f);
    }
}


