int zeichen_zaehlen(char zeichen[]){
    int anzahl;

    for (anzahl = 0; zeichen[anzahl] != '\0'; anzahl++){
	/* 
	 * Ursprungs Code
	 * 		for (anzahl = 1; zeichen[anzahl] == '\0'; anzahl--)
	 * 
	 * Folgende Fehler
	 * 		Array beginnen bei 0 an.
	 * 		Es wird nur so lange gerannt, wie es eine Nullterminator
			gibt, also garnicht.
	 *		Der Counter wurd deklrementiert*/

    }

    return anzahl;
}

void string_kopieren(char ziel[], char quelle[]){
    int anzahl = zeichen_zaehlen(quelle);
    for (int i = 0; i <= anzahl; i++){
	/* 
	 * Ursprungs Code:
	 * 		for (int i = 1; i < anzahl; i++)
	 * 
	 * Folgende Fehler
	 * 		Array fangen bei 0 an
	 * 		Das Array wird mit Nullterminator beendet, dieser wird aber
			nicht gelesen, da er beim kopieren nicht mitkopiert wird.
			Die Loop hält zu früh an, hier kann man auf verschieden 
			Weisen dies Lösen.
			Ich hab mich für das ändern der Laufzeit entschieden.*/
        ziel[i] = quelle[i];
    }
}
