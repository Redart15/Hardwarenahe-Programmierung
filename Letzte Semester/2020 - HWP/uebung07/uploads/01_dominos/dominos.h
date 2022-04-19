#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int inner;
    int outer;
    int direction;
} domino;

int dominos_einlesen(FILE* in, domino** domino_arr);
void dominocpy(domino* dest, domino source);
int pruefe_um_stein(int i, int j, int vergleichs_wert, char **feld, int feld_hoehe);
void domino_einfuegen(char ***feld, int *hoehe, domino d);
int berechne_breite(char** feld, int h);

void printe_feld(int* returnwert, char* outfile, char **feld, int hoehe, int breite);
void printe_feld_std(FILE* out, char **feld, int hoehe);

int platzierbar(char** feld, int feld_hoehe, int i, int j, domino d);
void platziere(char ***feld, int i, int j, domino d);