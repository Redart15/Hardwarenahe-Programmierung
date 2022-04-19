#include <stdio.h>
typedef struct{
    int jahr;
    int monat;
    int tag;
}datum;

datum neues_datum(int jahr, int monat, int tag);
void datum_ausgeben(datum d, FILE *ausgabe);
int datum_vergleichen(datum a, datum b);