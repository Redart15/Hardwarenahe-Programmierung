#include <stdio.h>

/*
 * Diese Funktionen müssen von Ihnen implementiert werden.
 * Alle Funktionen müssen zudem sinnvoll verwendet werden.
 * Das bedeutet, dass Sie zum Beispiel nicht die gesamte
 * Funktionalität in der main-Funktion implementieren dürfen,
 * ohne dabei die geforderten Funktionen aufzurufen.
 * Außerdem müssen Pointer verwendet werden. Globale Variablen
 * sind in dieser Veranstaltung nicht erlaubt (siehe Code-Vorgaben
 * im Lernmodul).
 */

/*
 * Ausgabe eines Brotes als ASCII-Grafik.
 */
void brot_ausgeben(int sorte);
int eingabe();
int brotausgabe(int* anzahl_brote, int* zu_kaufen);
/*
 * Aktualisiert Anzahl der Brote und gibt Brote aus.
 */
void brote_kaufen(int *mischbrote, int *vollkornbrote, int anzahl, int sorte);

/*
 * Warum steht die Funktion hier nochmal? - In C dürfen Funktionen erst
 * verwendet werden, wenn sie vorher deklariert wurden. Siehe dazu auch
 * das Kapitel "Funktionsdeklarationen" aus dem Buch "C von A bis Z":
 * https://openbook.rheinwerk-verlag.de/c_von_a_bis_z/009_c_funktionen_005.htm
 * Später lernen Sie, dass es oft hilfreich ist, wenn man Funktionsdeklaration
 * und Funktionsimplementierung voneinander trennen kann.
 */
void brot_ausgeben(int sorte){
    printf(" _____________\n");
    printf("/              \\\n");
    printf("|              |\n");
    if (sorte == 1){
        printf("| Vollkornbrot |\n");
    }else{
        printf("|  Mischbrot   |\n");
    }
    printf("|              |\n");
    printf("\\______________/\n");
    printf("\n");
}
int main(){
	int mischbrote 		= 30;
	int vollkornbrote 	= 10;
	/*
	 *  anzahl an Broten werden hier definiert
	 */
	while((mischbrote!=0)||(vollkornbrote!=0)){
		int anzahl 	= eingabe();
		int sorte 	= eingabe();
		/*
		 *  Anzahl der zukaufenden Brote und die Sorte werden gefordert
		 */
		
		brote_kaufen(&mischbrote,&vollkornbrote,anzahl,sorte);
	}
	/* 
	 * die Funktion wird solange abgelauefn bis beide Bedingungen nicht
	 * mehr gelten
	 */
	printf("Der Automat ist leer.\n");
}
int eingabe(){
	int wert;
	scanf("%i",&wert);
	return wert;
}
void brote_kaufen(int *mischbrote, int *vollkornbrote, int anzahl, int sorte){
	int brot;
	if(sorte == 1){
		brot = brotausgabe(mischbrote,&anzahl);
	}
	else{
		brot = brotausgabe(vollkornbrote,&anzahl);
	}
	/* 
	 * Sorte wird emittelt, Funktion mit Parameter, anzahl der Brotsorte
	 * und Anzahl der zukaufenden Brote wird aufgerufen. Aktualisiert den
	 * Brotstand und gibt ihn als neu Variable wieder.
	 */
	
	for(int cnt=0;cnt!=anzahl;cnt++){
		brot_ausgeben(sorte);
	}
	printf("Noch %i Brote der Sorte %i im Automaten.\n",brot,sorte);
	/* 
	 * gibt die ASCII Zeichung, Anzahl mal aus und gibt den in "brot", 
	 * gespeicherten Brotstand aus.
	 */
}

int brotausgabe(int* anzahl_brote, int* zu_kaufen){
	if(*zu_kaufen>*anzahl_brote){
		*zu_kaufen = *anzahl_brote;
	}
	*anzahl_brote -= *zu_kaufen;
	/*
	 * prüf und korregiert die Anzahl der zukaufenden Brote, 
	 * aktualisiert den Stand und gibt diesen wieder zurück.
	 */
	return *anzahl_brote;
}




