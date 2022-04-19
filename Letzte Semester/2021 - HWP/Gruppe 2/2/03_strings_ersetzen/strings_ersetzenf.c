#include "strings_ersetzen.h"

/* Implementieren Sie hier die geforderte Funktion. 
 * 
 *  "Dies ist ein Text und hier werden die Sternchen durch,"
	"Stings ersetzt, wolmöglich wird das eine interessante Angelegenheit,"
	"da es so aussieht als ob dies nicht die richtige Datei sei um rein"
	"zuschreiben, vlt mach ich einen Fehler und die Datei muss wo anders"
	"geschrieben werden...";
 * 
 * 
 * */
 
int strings_ersetzen(char ausgabe[], char *text, char strings[100][100]);
void remove_stars(char* string);
void einsetzen(char* text,char strings[100][100]);

int main(){
	char strings[100][100]= 
	{"Dies","und","werden","ersetzt","interessante","aussieht",
	 "richtige","Fehler","die","muss","werden"};
	
	
	char *text ="*** ist ein Text * hier *** die Sternchen durch,"
	"Stings ***, wolmöglich wird das eine ***** Angelegenheit,"
	"da es so ** als ob dies nicht die **** Datei sei um rein"
	"zuschreiben, vlt mach ich einen ** und ** Datei *** wo anders"
	"geschrieben ****...";
	
	char ausgabe[1000];
	
	int anzahl = strings_ersetzen(ausgabe,text,strings);
	/* gibt die Anzahl ersetzer Sternchenstrings*/
	printf("%i\n",anzahl);
	printf("%s\n",ausgabe);	   
	return 0;
}
int strings_ersetzen(char ausgabe[], char *text, char strings[100][100]){
	memset(ausgabe,0,1000);
	memmove(ausgabe,text,strlen(text));
	/* ini ausgabe und copiet den string in text*/
	
	remove_stars(ausgabe);
	einsetzen(ausgabe,strings);
	return 0;
}
void remove_stars(char* string){
	for(int cnt=0;strlen(string)>cnt;cnt++){
		if((string[cnt]=='*')&&(string[cnt+1]=='*')){											
			memmove(string+cnt,string+cnt+1,strlen(string)-cnt);
			/* sting+cnt = derzeitige Position in Ausgabe
			 * strlen(string)-cnt ist die verbleibende laenge*/
			cnt--;
		}
	}
	/* entfernt mehrfach aufeinander folgende Sternchen
	 * läuft den Ausgabe test ab, tritt ein Sternchen in der derzeitigen
	 * und kommen Position auf, so wird der Text drauf geschoben.*/
}
void einsetzen(char* text,char strings[100][100]){
	int pos_array=0;
	for(int cnt=0;strlen(text)>cnt;cnt++){
		if(text[cnt]=='*'){	
			int str_laenge=strlen(strings[pos_array]);
			memmove(text+cnt+str_laenge,text+cnt,strlen(text)-cnt);
			cnt--; /* urspruchsposition wiederherstellen*/
			memmove(text+cnt,strings[pos_array],str_laenge);
			/* string vom array kopieren*/
			cnt--;
		}
	}
}






