int zeichen_zaehlen(char zeichen[]){
    int ergebnis = 0;

    do {
        if (zeichen[ergebnis] == '\0') break;

        ergebnis += 1;
        /* Ursprunglich: ergebnis -= 1;
         * negative länge wird ermittelt, die Funktion weiter unteren 
         * erwartet eine Positive. */

    } while (1 != 2);
    /* Ursprunglich:	 while (1 == 2);
     * Diese Bedingung wird nie erfüllt, als solches wird die Schleife 
     * nur einmal ducrchlaufen. */

    return ergebnis;
}

void string_anhaengen(char string1[], char string2[]){
    int anzahl1 = zeichen_zaehlen(string1);
    int anzahl2 = zeichen_zaehlen(string2);
    /* Ursprunglich:  int anzahl2 = zeichen_zaehlen(string1); 
     * hier wurde statt die länge von string2, die länge von string1
     * berechnent*/
	for (int i = 0; i < anzahl2; i++){
	/* Ursprunglich: for (int i = 0; i < anzahl1; i++){
     * wurde nur solange laufen lassen bis die Anzahl an Zeichen in
     * string1 abgelaufen wurde. */

        string1[i + anzahl1] = string2[i];
	}
}

