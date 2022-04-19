#include "caesar_plus2_klein.h"
#include <string.h>
#include <stdlib.h>
/*
 * laut ascii tabelle sind 'a' = 97 und 'z' = 122
 * da kann man in code jetzt einfach 2 dazu addieren.
 * man muss den fall, ueber 122 hinaus zu gehen abfangen.
 * das sollte mit einer modulo rechnung ganz einfach gehen.
 * dabei rechne ich zuerst den bereich 97-122 auf 0-25 um, indem ich den wert-97 rechne.
 * dann kann ich den wert (x+2)%26 rechnen und bekomm am ende eine zahl
 * zwischen 0 und 25 wieder raus. da addiere ich am ende 97 wieder drauf um
 * auf dem bereich 97-122 zurueckzukommen
*/
void caesar(char *klartext){
    for (int i = 0; klartext[i]; i++)
    {
        klartext[i] = ((klartext[i]-97)+2)%26 + 97; //simpel :)
    }
}

int encode_and_compare(char *encoded_string, char *string_to_encode){
    char* string_to_encode_cpy = malloc(strlen(string_to_encode)*sizeof(char));
    strcpy(string_to_encode_cpy, string_to_encode);
    caesar(string_to_encode_cpy);
    return (strcmp(encoded_string, string_to_encode_cpy) == 0) ? 1 : 0; //strcmp returnt 0 wenn beide gleich sind, also hier das ergebnis umdrehen
}
