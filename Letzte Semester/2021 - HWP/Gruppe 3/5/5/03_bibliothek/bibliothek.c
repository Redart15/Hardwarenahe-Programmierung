#include "bibliothek.h"

#include <string.h>
#include <stdlib.h>

int buecher_einlesen(struct buch *buecher, FILE *eingabe){
    /* Implementieren Sie diese Funktion. */





}

void buecher_ausgeben(
    FILE *ausgabe_faellig,
    FILE *ausgabe_noch_nicht_faellig,
    struct buch *buecher,
    int anzahl,
    struct datum *testdatum
){
    /* Implementieren Sie diese Funktion. */







}

int main(int argc, char **argv){
    /* Die main-Funktion darf nicht verändert werden. */
    FILE *eingabe = fopen(argv[1], "r");

    struct buch buecher[100];

    int anzahl = buecher_einlesen(buecher, eingabe);

    fclose(eingabe);

    FILE *ausgabe_faellig = fopen(argv[2], "w");
    FILE *ausgabe_noch_nicht_faellig = fopen(argv[3], "w");

    /* Das Datum wird von der Kommandozeile eingelesen */
    struct datum testdatum;
    int jahr = atoi(argv[4]);
    int monat = atoi(argv[5]);
    int tag = atoi(argv[6]);
    datum_setzen(&testdatum, jahr, monat, tag);

    buecher_ausgeben(
        ausgabe_faellig,
        ausgabe_noch_nicht_faellig,
        buecher,
        anzahl,
        &testdatum);

    fclose(ausgabe_faellig);
    fclose(ausgabe_noch_nicht_faellig);

    return 0;
}
