#include "bibliothek.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//~ const char *kate[] = {"Fantasy","Krimi","Sachbuch","Sci-Fi"};

int buecher_einlesen(struct buch *buecher, FILE *eingabe){
	int tag;int monat;int jahr;int cnt=0;
	char gate[20];
	for(;(fscanf(eingabe,"%d.%d.%d %s",&tag,&monat,&jahr,gate))==4;cnt++){
		fscanf(eingabe,"%[^\n]",buecher[cnt].titel);
		datum_setzen(&buecher[cnt].verleih, jahr, monat, tag);
		if(strcmp(gate,"Fantasy")==0){
			buecher[cnt].richtung = (FANTASY);
		}
		else if(strcmp(gate,"Krimi")==0){
			buecher[cnt].richtung = (KRIMI);
		}
		else if(strcmp(gate,"Sachbuch")==0){
			buecher[cnt].richtung = (SACHBUCH);
		}
		else if(strcmp(gate,"Sci-Fi")==0){
			buecher[cnt].richtung = (SCI_FI);
		}
	}
	//~ const char *kate[] = {"Fantasy","Krimi","Sachbuch","Sci-Fi"};
	//~ int idx = 0;
	//~ for(;(fscanf(eingabe,"%d.%d.%d %s",&tag,&monat,&jahr,gate))==4;cnt++){
		//~ fscanf(eingabe,"%[^\n]",buecher[cnt].titel);
		//~ datum_setzen(&buecher[cnt].verleih, jahr, monat, tag);
		//~ idx = 0;
		//~ for(;idx<4;idx++){
			//~ if(strcmp(gate,kate[idx])==0){
				//~ buecher[cnt].richtung = idx;
				//~ fprintf(stderr,"%d",idx);
				//~ break;
			//~ }
		//~ }
	//~ }
	return cnt;
}
void buecher_ausgeben(
    FILE *ausgabe_faellig,
    FILE *ausgabe_noch_nicht_faellig,
    struct buch *buecher,
    int anzahl,
    struct datum *testdatum
){
	for(int cnt=0;cnt<anzahl;cnt++){
		int ablauf = datum_vergleichen(&buecher[cnt].verleih,testdatum);
		if(ablauf<0){							// buch ist fällig
			rest(&buecher[cnt],ausgabe_faellig);
		}	
		else{									// buch nicht fällig
			rest(&buecher[cnt],ausgabe_noch_nicht_faellig);
		}
	}
}

void rest(struct buch *buecher, FILE *ausgabe){
	const char *kate[] = {"Fantasy","Krimi","Sachbuch","Sci-Fi"};
	datum_ausgeben(ausgabe,&buecher->verleih);
	fprintf(ausgabe,",%s, %s\n",buecher->titel,kate[buecher->richtung]);
}
int main(int argc, char **argv){
    //~ /* Die main-Funktion darf nicht verändert werden. */
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
