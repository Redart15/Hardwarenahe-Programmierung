#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Tier Tier;
char *reserv(char name);
Tier *kneten(char *name);
Tier* tiere_einlesen(FILE *eingabe);
void tiere_ausgeben(FILE *ausgabe, Tier *anfang);
void tiere_freigeben(Tier *anfang);

/* Implementieren Sie hier einen Knoten der verketteten Liste. */
struct Tier {
    char name[15];
    int counter;
	struct Tier *next;
};
Tier *kneten(char *nennen){
	Tier *neu = malloc(sizeof(Tier));		
	strncpy(neu->name,nennen,15);				
	neu->counter = 1;										 	// Zähler, wenn was eingetragen wird ist es eins
	neu->next = NULL;										 	// hier wird die Adresse des nächsten Strukts hinterlegt
	return neu; 												// gibt den Pointer auf dieses Struct wieder
}
Tier* tiere_einlesen(FILE *eingabe){
	Tier *start = NULL;											// Pointer auf den Start der Kette
	Tier *index = NULL;  										// Mit diesem Pointer geht man später die Liste durch
	Tier *tail = NULL;											// Zeiger des letzen Struct der Link-Liste
	char nennung[15];											// Name wird heir gespeichert
	int test = 0;												// wird genutzt zum Vergleichen zweier strings.	
	//~ if(fgets(nennung,15,eingabe)!=NULL){					// mit dieser fgets kriegt ich nur eine Ausgabe
	if((fscanf(eingabe,"%14s",nennung))==1){					// wenn Name nicht Null wird er immer gesetzt
																// wahrscheinlich würde ich schwierigkeiten haben wenn
																// keine Name gegeben wurde
		start = kneten(nennung);								// neues Struct wird erstellt mit next Link NULL
	}	
	//~ while(fgets(nennung,15,eingabe)!=NULL){					// mit dieser fgets kriegt ich nur eine Ausgabe
	while((fscanf(eingabe,"%14s",nennung))==1){		
	//~ while(fscanf(eingabe,"%14s",nennung)){					// so funktionier fscanf nicht
		for(index = start ;										// setzt den Index Pointer auf auf Start pointer
			index != NULL ;										// läuft so lange bis der nächste Pointer NULL ist
			index = index->next){								// diese Stelle bereitet mir vlt am meisten Kopfschmerzen:
				
			/* Beim ersten Durchlauf wird hier nix gemacht interessant wird erst wenn die Liste 
			 * länger ist. Wenn man zwei Tiere hat geht die Funktion durch wenn das Tier nicht da ist
			 * wird der Zeiger Index auf die Adresse des nächsten Struct gesetzt
			 * */
					
			if( index->next == NULL){							// nur wenn am Ende angekommen wird hier der Pointer
				tail = index;									// Tail auf Index gesetzt, Tail ist das letzte Struct 
																// hier wird der Zeiger von Tail wird auf Index, welches
																// das Letzte Element ist. Jetzt wenn Tail Next geändert wird
																// ist das Element gelinkt
			}	
			test = strcmp(nennung,index->name);					// wenn der Name mit der Nennung übereinstimmt 
			if(test == 0){										
				index->counter++;								// wird der Counter erhöht und die for-Schleife
				break;											// wird verlassen.
			}	
		}	
		if(test != 0){											// wenn die for-Schleife vorzeitig nicht beendet wurde
			tail->next = kneten(nennung);						// wir ein neues Tier angehangen. Die Adresse des nächsten Tiers
																// an die Adresse von letzten Tieres gesetzt
		}
	}
	return start;												// gibt den Pointer an welchen diese Liste startet wieder
}
/* ^~ Dies ist kinda a Brainf*ck, not the Esolang, wenn es nach zu viel Kommentaren aussieht liegt es daran
 * Das ist mir am Tag darauf nicht mehr alles Errinnerte und hab beschlossen dies komplett zu kommentieren
 * Wahrscheinlich steht in der Aufgabe 2 und Projekt genau wenn nicht mehr Kommentare drin.*/
void tiere_ausgeben(FILE *ausgabe, Tier *anfang){
    for(;anfang != NULL;anfang = anfang->next){					// Im Vergleich zur beschreiben des Struct
		fprintf(ausgabe,"%d %s\n",anfang->counter,anfang->name);// war das sehr einfach, hier wird einfach jedes Struct	
	}															// der Name und deren Counter ausgegeben
}
void tiere_freigeben(Tier *anfang){

    Tier *schlachten = NULL;
    for(;anfang!=NULL;anfang = schlachten){
		schlachten = anfang->next;
		/* free(anfang->next);
		 * Auch eine Stelle, die ich noch nicht so ganz verstehe, vlt liegt es daran das ich wieder so lang
		 * wach war. Hier wird "schlachten" auf den nächstes Element gesetzt. Einzig hier wenn das richtig
		 * sehe wird der Pointer nie freigegeben, ist aber am Ende weg. Vielleicht könnte dies ein Problem bewirken
		 * Leider weis nicht genau wie ich das Testen soll. Wenn ich aber den Pointer auch frei gebe wird zu viel
		 * freigegeben. Das Einzige was mir einfällt ist dass das Array sammt dem Pointer gelöscht wird,
		 * und daher nicht noch gelöscht werden muss. Letztlich ist der letzte Pointer NULL und muss nicht gelöscht
		 * werden.
		 * 
		 * Kinda regret not writting a bit more comments.
		 * Ich hoffe wer auch immer sioch die Mühe gemacht hat dies zu lesen, noch eine Angenehmen Tag.*/
		free(anfang);
	}
}
/* Diese Funktionen drüber müssen von Ihnen implementiert werden. */
//-------------------------------------------------------------------------------------------------
int main(int argc, char **argv){
    /* Diese Funktion darf nicht verändert werden. */
    if (argc < 3){
        fprintf(stderr, "Zu wenige Parameter übergeben.\n");
        return EXIT_FAILURE;
    }
    // Tiere aus Eingabedatei einlesen.
    FILE *eingabe = fopen(argv[1], "r");
    Tier *anfang = tiere_einlesen(eingabe);
    fclose(eingabe);
    // Tiere in Ausgabedatei ausgeben.
    FILE *ausgabe = fopen(argv[2], "w");
    tiere_ausgeben(ausgabe, anfang);
    fclose(ausgabe);
     // muss nicht eigene Datei lesen oder schreiben.
    tiere_freigeben(anfang);

    return 0;
}
