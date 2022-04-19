#include "datum.h"

void datum_setzen(struct datum *d, int jahr, int monat, int tag){
	d->jahr = jahr;												// beschreibt die Werte des struct.
	d->monat = monat;
	d->tag = tag;
}
void datum_ausgeben(FILE *ausgabe, struct datum *d){
	fprintf(ausgabe,"%04i-%02i-%02i",d->jahr,d->monat,d->tag); // gibt das Datum mit führenden Nullen
	// scanf liest mit %i zahlen mit führenden Nulle als eine Oktalzahl ein.
}
int datum_vergleichen(struct datum *a, struct datum *b){
	int	datum_a = a->jahr*360 + a->monat*30 + a->tag;
	int	datum_b = b->jahr*360 + b->monat*30 + b->tag;
	return datum_a-datum_b;										// a>b positiv, a-b negativ, a=b 0
}
