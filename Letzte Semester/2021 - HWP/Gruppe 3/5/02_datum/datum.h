#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct datum{
	int jahr;
	int monat;
	int tag;
};

void datum_setzen(struct datum *d, int jahr, int monat, int tag);
void datum_ausgeben(FILE *ausgabe, struct datum *d);
int datum_vergleichen(struct datum *a, struct datum *b);
