//~ #include "texteditor.h"
#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
void help();
int Fehler(int flagen);
void run_the_options(int start,int argc,char* symbol,char** argv);

int main (int argc, char** argv){
	int f_err = 0, f_start = 1;					// Flagen für Fehler und Optionen
	char optionen, *tag = "";
	while( (optionen = getopt(argc,argv,"s:t:h")) !=  EOF){
		switch(optionen){
			case 's': 
				f_start = atoi(optarg);			// wenn nicht gesetzt ist es std.mäßig 1
				break;
			case 't': 
				tag = optarg;
				break;
			case 'h': 
				help();					// Hilfetext was zu groß für den switch case
				return 0;
			case '?': 
				f_err = 1;				// Unterschiedliche Flaggen, Unterschiedliche Fehlermeldungen
				break;
			default:
				break;
		}
	}
	argc -= optind;
	argv += optind;						
	if(argc!=1){							// setzt Fehler Flagge wenn mehr als ein Text übergeben wird
		f_err = 2;
	}
	if(f_err){
		return Fehler(f_err);					// gibt einen Fehler Text und beendet das Programm
	}
	run_the_options(f_start,argc,tag,argv);				// arbeitet die Optionen durch
	printf("\n");
	return 0;
}

void run_the_options(int start,int argc,char* symbol,char** argv){
	int cnt=0;							
	printf("%d%s",start,symbol);					// Zeilen Prefix, muss bereits für den erste Text ausgegeben werden
	for(;argv[0][cnt]!=0;cnt++){
		if(argv[0][cnt]==10){					// 10 = NL in ASCII
			start++;
			printf("\n%d%s",start,symbol);			// symbol leer = keine Zusatzausgabe, symbol = Zwischenstringasgabe
		}else{							
			printf("%c",argv[0][cnt]);			// Ansonsten wird ein Char nach dem anderen ausgegeben
		}
	}
}
int Fehler(int flagen){
	char meldung[3][35] =	{{"RUN!"},				// Array mit Fehler Meldungen.
				{"Üngültiger Parameter"},
				{"Text ist unzureichender länge"}};
	printf	("-------------------------------------------\n"
			 "Fehler: %s!\n" 				// ne nach Fehler Flagge werden verschiedene Strings ausgeben
			 "Tippe \"./texteditor -h\" für Hilfe.\n"
		 "-------------------------------------------\n"
		 ,meldung[flagen]);
	return 1;
}
void help(){
	printf("Nutzen des Text editors:\n"				// Hilfe Text, Informiert den Benutzer über Optionen und Programm Limits.
				" -s , Zeilennummer startet bei dieser Zahl, sonst bei 1\n"
				" -t , Gibt den speziffzierten Text zwischen jeder\n" 
				"      Zeilennummer und der entsprechenden Zeile aus\n"
				" -h , Hilfestellung zur Benutzung des Texteditors\n"
				"Es darf nur ein Text eingegebenwerden.\n"
				"Text wird an NL Zeilenweise ausgegebn und durch nummeriert.\n"
				"Wenn ein Text mit ' eigebene wird kann man den Text mit,\n"
				"Leerzeichen und Umbrüche angeben werden. Der Text wird wd\n"
				" ' geschlossen.\n");
}		
