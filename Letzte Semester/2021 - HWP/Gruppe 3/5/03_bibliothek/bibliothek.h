#include "../02_datum/datum.h"

/* Implementieren Sie hier die vorgegebenen Datentypen. */

typedef enum{
	FANTASY,KRIMI,SACHBUCH,SCI_FI
} genre;

/* Das Datum ist aus der vorherigen Aufgabe */
struct buch{
	char titel[49];
	struct datum verleih;
	genre richtung;
}; 
/*
 * Liest Bücher aus Eingabedatei ein.
 */
int buecher_einlesen(
    struct buch *buecher,
    FILE *eingabe
);

/*
 * Teilt Bücher in fällige und noch nicht fällige Bücher auf.
 */
void buecher_ausgeben(
    FILE *ausgabe_faellig,
    FILE *ausgabe_noch_nicht_faellig,
    struct buch *buecher,
    int anzahl,
    struct datum *testdatum);
 
void rest(struct buch *buecher, FILE *ausgabe);
