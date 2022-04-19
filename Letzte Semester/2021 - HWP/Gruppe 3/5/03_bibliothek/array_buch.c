#include "../02_datum/datum.h"
#include <stdio.h>
#include <string.h>

typedef struct{
	short zahl;
}buch;
int eingabe();
void fill_struct(buch *b,int zahl);

int main(int argc,char *argv[]){	
	buch b[100];
	FILE *out = fopen(argv[1],"w");
	fprintf(out,"Die Startzahl lautet:");
	int start = eingabe();
	fprintf(out,"%d\n",start);
	
	
	
	fill_struct(b,start);
	int cnt = 0;
	for(; (b[cnt].zahl != 1)&&(cnt<100); cnt++){
		fprintf(out,"Array Stelle %d: %d\n",cnt,b[cnt].zahl);
		//~ ausgabe(&buecher,start);
	}
	fprintf(out,"Array Stelle %d: %d\n",cnt,b[cnt].zahl);
	fclose(out);
	return 0;
}
int eingabe(){
	int wert;
	fscanf(stdin,"%d",&wert);
	return wert;
}
void fill_struct(buch *b,int zahl){
	for(short idx = 0; idx<100; idx++){
		if(zahl&1)	{
			zahl = zahl*3+1;b[idx].zahl = zahl;
			//~ printf("idx:%d",b[idx].zahl);
			}
		else   		{
			zahl = zahl >> 1;b[idx].zahl = zahl;
			//~ printf("idx:%d",b[idx].zahl);
			}
		//~ for(short idx = 0; idx<100;idx++){
		//~ printf("schleife\n");
	}
}

