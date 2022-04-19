#include "text.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reserv(char *name){										// imgrunde "strdup"
	unsigned int laenge = strlen(name) + 1;						// die länge des String wird ermittelt(inc 0-term)
	char *pnt = calloc(1,laenge);								// initialiesierter Platz wird geschaffen
	strncpy(pnt,name,laenge);									// der String wird dahin kopiert
	return pnt;													// Pointer welcher auf diesen String zeigt
																// wird zurück gegeben
}
Text* text_initialisieren(char *string){
	Text *neu = malloc(sizeof(Text));							// fürs Strukt wird Platz geschaffen
	//~ neu->info =malloc(strlen(string)+1);					// relics;
	//~ strncpy(neu->info,string,strlen(string)+1);
	neu->info = reserv(string);									// ein Pointer auf den Text im Speicher
	return neu;													// gibt Pointer des Structs wieder
}
Text** text_trennen(int *anzahl,Text *text,	char *trenner){		
	Text **geteilt = malloc(1*sizeof(Text*));					// Text* ist ein Struct Pointer+
																// Pointer sind 8 bytes lang.
	*anzahl = 0;												// Anzahl wird ini. weil es davor nicht war
	char *start = text->info;									// pnt start auf Anfand vom Text setzen
	char *find;													// find ist der Index, gibt an wo der 
																// erste string gefunden wurde
	while((find=strstr(start,trenner))!=NULL){					// läuft solang bis kein String mehr gefunden wird
		int str_len = find-start;								// ermittelt die länge vie der Differents
		char *pnt = malloc(str_len+1);							// erstellt ein Hilfs pnt im Heap
		strncpy(pnt,start,str_len);								// copiert den Text abschnitt auf den pnt
		pnt[str_len] = 0;										// terminiert den String
		geteilt[(*anzahl)] = text_initialisieren(pnt);			// initialisiert den Text in eine Strukt
		free(pnt);												// befreit den Hildpointer weil wir ihn
																// nicht mehr brauchen
		start = find+strlen(trenner);							// der Text startet jetzt nach den Trenner
		*anzahl = *anzahl + 1;									// Anzahl wird erhöht
		geteilt = realloc(geteilt,((*anzahl)+1)*sizeof(Text*)); // der Platz wird erweitert um ein Pointer
	}
	geteilt[(*anzahl)] = text_initialisieren(start);			// der letze string muss noch kopiert werden
																// dieser ist auch Nullterminiert
	*anzahl = *anzahl + 1;										// die Anzahl wird nochmal angepasst
	return geteilt;												// gibt das "Array wd"				
}
void text_freigeben(Text *text){
	free(text->info);											// befreit zu erst den String pointer
	free(text);													// zuletzt bereit er den Struct pointer
}
char* text_ausgeben(Text *text){
	char *idx = text->info;										// setzt einen Pointer auf den Text selbst
	//~ char *idx = malloc(strlen(text->info)+1);
	//~ strncpy(idx,text->info,strlen(text->info)+1);
	//~ return idx;
	return reserv(idx);											// führt den strdup aus
}
// ^~ Implementieren Sie diese Funktionen. 
//--------------------------------------------------------------------------------------------------
void texte_freigeben(Text **texte, int anzahl){
    /* Diese Funktion ist bereits implementiert, aber darf auch geändert werden, falls nötig. */
    // Über ein Array von Text-Zeigern iterieren und Text-structs einzeln freigeben.
    for (int i = 0; i < anzahl; i++){
        Text *text = texte[i];

        text_freigeben(text);
    }
    // Zum Schluss noch das Array von Zeigern freigeben.
    free(texte);
}
