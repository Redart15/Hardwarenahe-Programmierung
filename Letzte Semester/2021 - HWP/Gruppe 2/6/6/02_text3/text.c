#include "text.h"

#include <stdlib.h>
#include <string.h>

Text* text_initialisieren(char *string){
    /* Implementieren Sie diese Funktion. */
}

Text** text_trennen(int *anzahl, Text *text, char *trenner){
    /* Implementieren Sie diese Funktion. */
}

void text_freigeben(Text *text){
    /* Implementieren Sie diese Funktion. */
}

char* text_ausgeben(Text *text){
    /* Implementieren Sie diese Funktion. */
}

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
