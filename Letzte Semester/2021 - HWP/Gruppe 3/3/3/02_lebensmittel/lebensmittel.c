/* Implementieren Sie hier wenn nötig noch weitere Funktionen */
/* Diese Funktion muss implementiert werden. */
//~ #include "lebensmittel.h"
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
void help();
int abfrage(float deci ,float flt_deci ,int zahl , int flt_zahl ,char* name, char* flt_name);
int stimmt(char* name, char* filter);


int main(int argc, char* argv[]){
	float preis, flt_preis = 1000;								// Varibalen mit flt_ sind options Variablen
	int haltbar, flt_haltbar = 0,test;							// test, Prüfvariable, wird später verwendent um Einträge zu überspringen
	char option,*flt_essen= "",essen[136],gori[20];						// flt_preis gesetzt um später die Bedingung in std Fall zu bestehen.
	FILE *datei = stdout;									// stdout terminal, wenn Argument gegeben in eine Datei
	while((option = getopt(argc,argv,"p:d:b:h")) != EOF){
		switch(option){
			case 'p':
				flt_preis	= atof(optarg);
				break;
			case 'd':
				flt_haltbar	= atoi(optarg);
				break;
			case 'b':
				flt_essen	= optarg;
				break;
			case 'h': 								// nicht vorgegeben aber...
				help();
				return 0;
			default:
				break;
		}
	}
	argc -= optind;
	argv += optind;	
	if(argv[0]){														
		datei = fopen(argv[0],"w");							// Erstellt eine Datei mit Argument namen			
	}
	while(fscanf(stdin,"%135s %f %19s %d",essen,&preis,gori,&haltbar) == 4){		// läuft solange 4 Eingaben geliefert werden
		test = abfrage(preis,flt_preis, haltbar,flt_haltbar, essen,flt_essen);		// Frag ab die Optionsbedingungen und setzt test 0,1
		if(test){									// wenn test gesetzt ist wird die Ausgabe übersprungen	
			continue;									
		}
		fprintf(datei,"%s %.2f %s %d\n",essen,preis,gori,haltbar);			// datei ist der Name der Ausgabe: stdout, sonst argv[0].
	}
	fclose(datei);
    return 0;
}
int abfrage(float deci,float flt_deci,int zahl, int flt_zahl,char *name,char *flt_name){
	if(flt_deci < deci){									// Kein Lebensmittel teurer als Filter
		return 1;									// wenn kein Filter gesetzt ist besteht wird diese Bedinung nie erfüllt.
	}											// da flt_preis = 1000, Lebensmittel mit preis über 1000 werden gefiltert.
												// naive angenohmen das es keine Lebensmittel mit Preis über 1000 gibt.
	if(flt_zahl > zahl){									// Lebensmittel die länger halten als Filter
		return 1;								
	}
	if(stimmt(name,flt_name)){								// Lebensmittel mit dem Filter Namen
		return 1;
	}
	return 0;
}
int stimmt(char* name, char* filter){								
	int wert;										// wenn nicht gegeben ist return 0
	if(filter[0]==0){
		return 0;
	}
	wert = strcmp(name,filter);								// vergleicht die String miteinander return 0 wenn gleich;
	if(!wert){
		return 0;
	}
	return 1;										// Branch is takken
}
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
