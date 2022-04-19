/* Implementieren Sie hier die geforderte Funktionalität. */
#include <stdio.h>
#include <string.h>
#include <getopt.h>

int fehler(int* flage);
void help();
void run_theparameter(int f_low,int f_betw,char* text,char* symbol);
void lowercase(char* text, int f_low);
void inbetween(char* text,char* symbol, int f_betw);

int main(int argc, char* argv[]){
	int f_low = 0,f_betw = 0,f_err = 0; 								// def,ini flagen, f_low,f_betw funktionsflage, f_err fehlerflagen [0,4]
	char *symbol= 0,option;												// Zwischenspeicher für Eingaben
	char text[10000];
	memset(text,'\0',10000);

	while((option = getopt(argc, argv,"kt:h")) != EOF){					
		switch(option){
		case 't':	symbol = optarg;
					f_betw = 1;											//setzt Flagen
					break;
		case 'k':	f_low = 1;
					break;
		case 'h':	help();												// Hilfsnachricht	
					return 0;
		case '?':	f_err = 1;	
					break;
		case ':':	f_err = 2;	
					break;
		default:	f_err = 3;	
					break;
		}
	}
	argc -= optind;
	argv += optind;
	
	if(argc!=1){f_err = 4;}												// wenn mehr als ein String geben wird, wird flage gesetzt
	if(f_err!=0){return fehler(&f_err);}								// ist flage gesetzt, gibt nachricht aus und Programm beendet
	memmove(text,argv[0],strlen(argv[0]));								// ini text für weitere Verarbeitung
	run_theparameter(f_low,f_betw,text,symbol);
	return 0;
}
int fehler(int* flage){													
	char fehler_flagen[5][50] = 										// array, mit Fehlernachrichten
				{{"If you see this run!"},								
				{"Ungültiger Option"},{"Fehlender Optionsparameter"},
				{"Ungültige Eingabe"},{"Keine/Mehrere Text/e"}};
	fprintf(stderr,
				"-------------------------------------\n"
				"Fehler: %s.\n" 
				"Tippe \"./texteditor -h\" für Hilfe.\n"
				"-------------------------------------\n"
				,fehler_flagen[*flage]);								// anhand der Flage wir die dazugehörige Nachricht ausgegeben
	return 1;															// eine Eins wird wiedergegen
}
void help(){
	printf("Nutzen des Text editors:\n"
				" -k , Konvertiert alle Großbuchstaben zu" 
				"Kleinbuchstaben.\n"
				" -t , Gibt den speziffzierten Text zwischen jedem\n" 
				"      Buchstaben des Eingabetextes aus.\n"
				" -h , Hilfestellung zur Benutzung des Texteditors\n\n"
				"Es wird jeweil nur ein Text angenohmen\n");			// Hilfs Text, ausgabe
}
void run_theparameter(int f_low,int f_betw,char* text,char* symbol){
	if(f_low)	{lowercase(text,f_low);}								// Anhand der gesetzten Flagen werden die Funktionen ausgeführt
	if(f_betw)	{inbetween(text,symbol,f_betw);}
	printf("%s",text);
}
void lowercase(char* text,int f_low){
	int txt_len = strlen(text);
	for(int cnt = 0;txt_len>cnt;cnt++){						
		if((text[cnt]>64)&&(text[cnt]<91)){								// sucht Großbuchstaben 
			text[cnt] += 32;											// ASCII kleinbuchstaben sind +32 der Großbuchstaben
		}
	}
}
void inbetween(char* text,char* symbol,int f_betw){
	int txt_len = strlen(text);
	int str_len = strlen(symbol);
	for(int cnt = 1;txt_len>cnt;cnt++){									// fügt den Parameter string jeweils zwischen jedem Zeichen.			
			char* pos_text = text+cnt;
			memmove(pos_text+str_len,pos_text,txt_len-cnt);
			memmove(pos_text,symbol,str_len);
			cnt += str_len;
			txt_len = strlen(text);
	}
}
