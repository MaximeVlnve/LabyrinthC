//
// Created by Maxime on 16/10/2018.
//

#include "header_sauves.h"

void empty_buffer(void) {
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int secure_input(char *text, int length) {
    char *entryPosition = NULL;

    if (fgets(text, length, stdin) != NULL){
        entryPosition = strchr(text, '\n');
        if (entryPosition != NULL){
            *entryPosition = '\0';
        } else {
            empty_buffer();
        }
        return 1;
    }
    else {
        empty_buffer();
        return 0;
    }
}

int menu(int choixMin, int choixMax) {
    int val;
    char * ptr;
    char * text;
    text = (char*)malloc(CHAR_MAX * sizeof(char));
    ptr = (char*)malloc(CHAR_MAX * sizeof(char));
    do{
        printf("------------ LABYRINTH ------------\n\n");
        printf("\t 1 - Creer un labyrinthe\n");
        printf("\t 2 - Charger un labyrinthe\n");
        printf("\t 3 - Jouer\n");
        printf("\t 4 - Quitter\n\n");
        printf("-----------------------------------\n\n");
        secure_input(text,10);
        val = strtol(text, &ptr, 10);
    } while(val < choixMin || val > choixMax);
    return val;
}

int get_difficulty() {
    int val;
    char * ptr;
    char * text;
    text = (char*)malloc(CHAR_MAX * sizeof(char));
    ptr = (char*)malloc(CHAR_MAX * sizeof(char));
    do{
        printf("Veuillez choisir une difficulté (1 - Facile, 2 - Difficile)\n");
        secure_input(text,10);
        val = strtol(text, &ptr, 10);
    } while(val < 1 || val > 2);
    return val;
}