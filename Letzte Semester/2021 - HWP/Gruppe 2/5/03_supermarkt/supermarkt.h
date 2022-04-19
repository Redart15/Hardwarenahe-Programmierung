#include "../02_datum/datum.h"

/* Implementieren Sie hier die vorgegebenen Datentypen. */

enum kategorie ...

struct produkt ...






/*
 * Liest Produkte aus drei Eingabedateien ein.
 */
int produkte_einlesen(
    struct produkt *produkte,
    FILE *eingabe_datum,
    FILE *eingabe_kategorie,
    FILE *eingabe_bezeichnung);

/*
 * Gibt Produkte, die noch nicht abgelaufen sind, in Ausgabedatei aus.
 */
void produkte_ausgeben(
    FILE *ausgabe,
    struct produkt *produkte,
    int anzahl,
    struct datum *verfallsdatum);
