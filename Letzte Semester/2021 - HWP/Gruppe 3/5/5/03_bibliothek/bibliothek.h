#include "../02_datum/datum.h"

/* Implementieren Sie hier die vorgegebenen Datentypen. */

enum genre ...

struct buch ...





/*
 * Liest Bücher aus Eingabedatei ein.
 */
int buecher_einlesen(
    struct buch *buecher,
    FILE *eingabe);

/*
 * Teilt Bücher in fällige und noch nicht fällige Bücher auf.
 */
void buecher_ausgeben(
    FILE *ausgabe_faellig,
    FILE *ausgabe_noch_nicht_faellig,
    struct buch *buecher,
    int anzahl,
    struct datum *testdatum);
