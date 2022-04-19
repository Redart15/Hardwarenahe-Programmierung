#include "jumpandrun.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Hier wird der Speicher verwaltet. Das Level wird als Array von Structs in den Speicher geladen.
 * Anschließen wird der Zeiger übergeben. Hier befindet sich neben her auch die Methoden das Level
 * zu entladen.*/
space **load_level(int *laenge, FILE *level, int *flagge) {
    // Zwischen speicher für die jeweiligen Zeilen
    char word[82];
    int str_len = 0;
    // Zwischenspeicher wird mit lauter Leerzeichen gefüllt
    memset(word, ' ', 81);
    int size = sizeof(space *);
    // ein Zeiger Array wird erstellt
    space **lvl_pnt = malloc(1 * size);
    while (fgets(word, 82, level) != NULL) {
        // soll beim lesen einer Nicht vorhanden Datei hier ausbrechen
        if (ferror(level)) {
            *flagge = 2;
            return lvl_pnt;
        }
        // größe des Array bestimmen, damit er alles kopiert
        str_len = strlen(word);
        // erstellt eine Struct für Zeile und kopiert die Zeile rüber
        space *new = malloc(sizeof(space));
        memset(new->line, 32, 81);
        strncpy(new->line, word, str_len - 1);
        lvl_pnt[*laenge] = new;
        *laenge = *laenge + 1;
        // erweitert das Array um einen Zeiger
        lvl_pnt = realloc(lvl_pnt, ((*laenge) + 1) * size);
    }
    return lvl_pnt;
}
void unload(int cnt, space **level, spieler *player) {
    // läd das zu löschende Level
    for (int idx = 0; idx < cnt; idx++) {
        // löscht alle Zeilen des Levels
        free(level[idx]);
    }
    // löscht das Level selbst
    free(level);
    free(player);
}
