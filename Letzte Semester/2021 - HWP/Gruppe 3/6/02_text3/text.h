typedef struct {
    /* Implementieren Sie hier sinnvolle Attribute. */
	char *info;
} Text;
char *reserv(char *name);
/*
 * Erzeugt ein neues Text-struct aus gegebenem String.
 */
Text* text_initialisieren(char *string);

/*
 * Trennt einen Text an einem Separator und gibt die Teile über ein Array von Zeigern auf
 * Text-structs zurück. Außerdem wird die Anzahl über einen Zeiger zurückgegeben.
 */
Text** text_trennen(int *anzahl, Text *text, char *trenner);

/*
 * Gibt ein Array von Texten frei.
 */
void texte_freigeben(Text **texte, int anzahl);

/*
 * Gibt den Speicher eines Text-structs frei.
 */
void text_freigeben(Text *text);

/*
 * Alloziert einen String, schreibt dort den Text rein und gibt den String zurück.
 * Der String muss von der aufrufenden Funktion mit free() freigegeben werden.
 */
char* text_ausgeben(Text *text);

