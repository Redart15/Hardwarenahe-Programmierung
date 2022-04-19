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
 * Ausgabe einer Getränkedose als ASCII-Grafik.
 */
void getraenk_ausgeben();
/*
 * Aktualisiert Dosenstand und gibt Getränke aus.
 */
void getraenke_kaufen(int *dosenstand, int anzahl);
/*
 * Ändert die Anzahl der angeforderten Dosen entsprechend der Sonderaktion.
 */
void sonderaktion(int *anzahl);
int eingabe();
/*
 * Warum steht die Funktion hier nochmal? - In C dürfen Funktionen erst
 * verwendet werden, wenn sie vorher deklariert wurden. Siehe dazu auch
 * das Kapitel "Funktionsdeklarationen" aus dem Buch "C von A bis Z":
 * https://openbook.rheinwerk-verlag.de/c_von_a_bis_z/009_c_funktionen_005.htm
 * Später lernen Sie, dass es oft hilfreich ist, wenn man Funktionsdeklaration
 * und Funktionsimplementierung voneinander trennen kann.
 */
int main(){
	int dosenstand = 50;
	/* ini dosenstand auf 50*/
	
	while (dosenstand > 0){
		int anzahl = eingabe();
		getraenke_kaufen(&dosenstand,anzahl);
		}
	/* solang der Dosestand größer null ist wird eine Eingabe gefordert 
	 * und die Funktion getraenke_kaufen aufgerufen */
	 
	printf("Der Automat ist leer.\n");
	return 0;
}
int eingabe(){
	int wert = 0;
	scanf("%i",&wert);
	return wert;
	/* Aufforderung der Eingabe eines Wertes*/
}
void getraenke_kaufen(int *dosenstand, int anzahl){
	sonderaktion(&anzahl);
	/* es wird ermittle wie viele extra Dose Pepsi ausgegeben werden
	 * sollen, hier für wird Anzahl entspächend angeändert*/
	 
	if(anzahl > *dosenstand)
		{anzahl=*dosenstand;}
	/* wird sichergestellt, das Anzahl der Pepsi Dose nicht die Anzahl
	 * verbliebender Dose überschreitet*/
	 
	*dosenstand -= anzahl;
	for(int cnt=1; cnt <= anzahl; cnt++)
		{getraenk_ausgeben();}
	/*  Druckt die ASCII Zeichnung Anzahl mal ab */
	printf("Noch %i Dosen im Automaten.\n",*dosenstand);
} 
void sonderaktion(int *anzahl){
	if(*anzahl > 2){
	int vier_fuer_drei = 0;
	//zwischen Speicher
	
	vier_fuer_drei = *anzahl/3;	
	*anzahl = vier_fuer_drei + *anzahl;	
	/* ermitteln, wie viele extra Dosen einem zustehen.
	 * und addieren dieser zur gekauften Anzahl der Dosen*/
	}
}

void getraenk_ausgeben(){
	/* putzige ASCII Zeichung ^^ */
    printf(" ______ \n");
    printf("/      \\\n");
    printf("|      |\n");
    printf("| Dose |\n");
    printf("|      |\n");
    printf("\\______/\n");
    printf("\n");
}
