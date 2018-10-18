//
// Created by Maxime on 16/10/2018.
//

#include "header.h"

void emptyBuffer(void){
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int secureInput(char *text, int length){
    char *entryPosition = NULL;

    if (fgets(text, length, stdin) != NULL){
        entryPosition = strchr(text, '\n');
        if (entryPosition != NULL){
            *entryPosition = '\0';
        } else {
            emptyBuffer();
        }
        return 1;
    }
    else {
        emptyBuffer();
        return 0;
    }
}

int menu(int choixMin, int choixMax){
    int val;
    char * ptr;
    char * text;
    text = (char*)malloc(256 * sizeof(char));
    ptr = (char*)malloc(256 * sizeof(char));
    do{
        printf("------------ LABYRINTH ------------\n\n");
        printf("\t 1 - Creer un labyrinthe\n");
        printf("\t 2 - Charger un labyrinthe\n");
        printf("\t 3 - Jouer\n");
        printf("\t 4 - Quitter\n\n");
        printf("-----------------------------------\n\n");
        secureInput(text,10);
        val = strtol(text, &ptr, 10);
    } while(val < choixMin || val > choixMax);
    return val;
}