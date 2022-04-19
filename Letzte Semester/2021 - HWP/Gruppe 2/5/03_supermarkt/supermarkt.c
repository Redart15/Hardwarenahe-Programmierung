#include "supermarkt.h"

#include <stdio.h>
#include <stdlib.h>

int produkte_einlesen(
    struct produkt *produkte,
    FILE *eingabe_datum,
    FILE *eingabe_kategorie,
    FILE *eingabe_bezeichnung
){
    /* Implementieren Sie diese Funktion. */





}

void produkte_ausgeben(
    FILE *ausgabe,
    struct produkt *produkte,
    int anzahl,
    struct datum *verfallsdatum
){
    /* Implementieren Sie diese Funktion. */





}

int main(int argc, char **argv){
    /* Diese Funktion darf nicht verändert werden! */

    // Eingabedateien öffnen
    FILE *eingabe_datum = fopen(argv[1], "r");
    FILE *eingabe_kategorie = fopen(argv[2], "r");
    FILE *eingabe_bezeichnung = fopen(argv[3], "r");

    struct produkt produkte[100];

    int anzahl = produkte_einlesen(
        produkte,
        eingabe_datum,
        eingabe_kategorie,
        eingabe_bezeichnung);

    // Eingabedateien schließen
    fclose(eingabe_datum);
    fclose(eingabe_kategorie);
    fclose(eingabe_bezeichnung);

    FILE *ausgabe = fopen(argv[4], "w");

    // Verfallsdatum von Kommandozeile einlesen
    struct datum verfallsdatum;
    int jahr = atoi(argv[5]);
    int monat = atoi(argv[6]);
    int tag = atoi(argv[7]);
    datum_setzen(&verfallsdatum, jahr, monat, tag);

    produkte_ausgeben(ausgabe, produkte, anzahl, &verfallsdatum);

    fclose(ausgabe);

    return 0;
}
