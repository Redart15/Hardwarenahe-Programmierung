#include "datum.h"

datum neues_datum(int jahr, int monat, int tag)
{
    datum neues_datum = {.jahr = jahr, .monat = monat, .tag = tag};
    return neues_datum;
}

void datum_ausgeben(datum d, FILE *ausgabe)
{
    fprintf(ausgabe, "%.4d-%.2d-%.2d", d.jahr, d.monat, d.tag);
}

int datum_vergleichen(datum a, datum b)
{
    int result = ((a.jahr - b.jahr)*366) + ((a.monat - b.monat)*31) + (a.tag-b.tag);
    return (result>>(sizeof(int)*8 - 1))|(!!result);
}
