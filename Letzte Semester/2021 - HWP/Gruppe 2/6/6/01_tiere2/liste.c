#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* Die Verwendung von globalen Variablen ist wie gewohnt verboten. */

typedef struct Tier Tier;

struct Tier {
    /* Implementieren Sie hier einen Knoten der verketteten Liste. */
};

Tier* tiere_einlesen(FILE *eingabe){
    /* Diese Funktion muss von Ihnen implementiert werden. */
}

void tiere_ausgeben(FILE *ausgabe, Tier *anfang){
    /* Diese Funktion muss von Ihnen implementiert werden. */
}

void tiere_freigeben(Tier *anfang){
    /* Diese Funktion muss von Ihnen implementiert werden. */
}

int main(int argc, char **argv){
    /* Diese Funktion darf nicht verändert werden. */
    if (argc < 3){
        fprintf(stderr, "Zu wenige Parameter übergeben.\n");
        return EXIT_FAILURE;
    }

    // Tiere aus Eingabedatei einlesen.
    FILE *eingabe = fopen(argv[1], "r");
    Tier *anfang = tiere_einlesen(eingabe);
    fclose(eingabe);

    // Tiere in Ausgabedatei ausgeben.
    FILE *ausgabe = fopen(argv[2], "w");
    tiere_ausgeben(ausgabe, anfang);
    fclose(ausgabe);

    tiere_freigeben(anfang);

    return 0;
}
