#include <stdio.h>
#include <stdlib.h>

int* zahlen_generieren(int start, int stop){
    int *zahlen;
    int anzahl = stop - start;

    // Speicher allozieren wurde vergessen:

    //zahlen = malloc(anzahl * sizeof(int));

    for (int zahl = start; zahl < stop; zahl++){
        zahlen[zahl - start] = zahl;
    }

    return zahlen;
}

int main(){
    int start, stop, ente;

    printf("Start und Stopzahl eingeben:\n");
    // Es wird nicht überprüft, ob tatsächlich zwei Zahlen gelesen wurden
    scanf("%i %i", &start, &stop);

    int *zahlen = zahlen_generieren(start, stop);

    printf("Die Zahlen von %i bis %i sind:\n", start, stop);

    int anzahl = stop - start;
    for (int i = 0; i < anzahl; i++){
        int zahl = zahlen[i];
        printf("%i\n", zahl);
    }

    // Speicher wird nicht freigegeben:
    //free(zahlen);

    return 0;
}
