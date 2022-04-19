/* Implementieren Sie hier wenn nötig noch weitere Funktionen */
/* Diese Funktion muss implementiert werden. */
//~ #include "lebensmittel.h"
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
int stimmt(char* name, char* filter);
void help();
int abfrage(double deci ,double flt_deci ,int zahl , int flt_zahl ,char* name, char* flt_name,int cnt );


int main(int argc, char* argv[]){
	double preis;double flt_preis = 1000;
	int haltbar;int flt_haltbar = 0;
	char essen[136];char* flt_essen= "";char gori[20];char option;
	
	FILE *datei = stdout;	
	while((option = getopt(argc,argv,"p:d::-::h")) != EOF){
		switch(option){
			case 'p':
				flt_preis	= atof(optarg);
				break;
			case 'd':
				flt_haltbar	= atoi(optarg);
				break;
			case '-':
				flt_essen	= optarg;
				break;
			case 'h': 
				help();
				return 0;
			//~ case '?':
				//~ break;
			default:
				break;
		}
	}
	argc -= optind;
	argv += optind;
	int cnt = 0;
	if(argv[0]){datei = fopen(argv[0],"w");}
	while(fscanf(stdin,"%135s %lf %19s %d",essen,&preis,gori,&haltbar) == 4){
		int test = abfrage(preis,flt_preis, haltbar,flt_haltbar, essen,flt_essen,cnt);
		if(test){cnt++;continue;}
		fprintf(datei,"%s %.2f %s %d\n",essen,preis,gori,haltbar);
		//~ printf("\n");
	}
	fclose(datei);
    return 0;
}


int abfrage(double deci ,double flt_deci ,int zahl , int flt_zahl ,char* name, char* flt_name,int cnt ){
	if(flt_deci < deci){
		//~ printf("%3d deci   flt_deci: %3.2f   deci: %3.2f\n",cnt,flt_deci,deci);
		return 1;
	}
	if(flt_zahl > zahl){
		//~ printf("%3d zahl   flt_zahl: %3d   zahl: %3d\n",cnt,flt_zahl,zahl);
		return 1;
	}
	if(stimmt(name,flt_name)){
		//~ printf("%d stimmt   flt_name: %15s   name: %15s\n",cnt,flt_name,name);
		return 1;
	}
	return 0;
}
int stimmt(char* name, char* filter){
	if(filter[0]==0)	{return 0;}
	//~ if(!filter)			{return 0;}
	int wert = strcmp(name,filter);
	//~ printf("Wert: %2d \t!Wert: %2d \tNot Wert: %2d \tstrcmp: %2d \t!strcmp: %2d\n"
			//~ ,wert,!wert,~wert,strcmp(name,filter),!(strcmp(name,filter)));
	//~ if(!(strcmp(name,filter))){return 0;}
	if(!wert)			{
		//~ printf("wegot here\n");
		return 0;}
						 return 1;

}
//~ int stimmt(char* name,char* fach){
	//~ if(fach[0]==0){return 0;}
	//~ if(!(strcmp(name,fach))){return 0;}
	//~ return 1;
//~ }


void help(){
	printf("\nNutzen des Text studierenden:\n"
				" -p , Betrachtet keine Lebensmittel mit höherem Preis.\n" 
				" -d , Betrachtet keine Lebensmittel mit niedrigerem Haltbarkeitsdatum.\n"
				" -b , Betrachtet keine Lebensmittel mit anderer Bezeichnung.\n"
				" -h , Hilfestellung zur Benutzung des \"studierenden\"\n"
				"Wenn mehrere Optionen gewählt wurden, werden sie nacheinander auf die Daten " 
				"angewähnt\n"
				"z.Bp: \"./lebensmittel.c -p 1.99 -b Eier\"\n"
				"Gibt Eier aus, die 1.99 oder weniger kosten.\n\n");
}
