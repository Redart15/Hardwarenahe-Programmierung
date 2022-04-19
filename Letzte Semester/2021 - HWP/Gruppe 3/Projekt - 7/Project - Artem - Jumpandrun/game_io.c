#include "jumpandrun.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test_IO(FILE **in, FILE **out, int cnt, char **array) {
    // wenn eine Eingabe Datei gegeben wurde und diese nicht "-"
    // wird sie gesetzt
    if ((cnt > 1) && (strcmp(array[1], "-") != 0)) {
        *in = fopen(array[1], "r");
        // prüft ob eine Datei/Directory existiert
        if (*in == NULL) {
            return 1;
        }
        // versucht zu lesen, wenn nicht möglich weil es ein Verzeichniss oder
        // eine schreibgeschützte Date ist wird hier ein Fehler aufgeworfen
        fgetc(*in);
        if (ferror(*in)) {
            return 2;
        }
        // da das Level gelesen wurde und der FILE Inhalt verändert wurde
        // wird die Datei Zeiger wieder an den Anfang gestellt
        rewind(*in);
    }
    // wenn eine Ausgabe Datei gegeben wurde und diese nicht "-"
    // wird sie gesetzt
    if ((cnt > 2) && (strcmp(array[2], "-") != 0)) {
        *out = fopen(array[2], "w");
        // prüft ob eine Datei/Directory existiert
        if (*out == NULL) {
            return 1;
        }
        if (ferror(*out)) {
            return 2;
        }
    }
    return 0;
}
int test_LVL(FILE **lvls, int cnt, char **array, int idx) {
    // wenn das Level bereits geöffnet wurde wird es geschlossen
    if (*lvls != NULL) {
        fclose(*lvls);
    }
    // keine extra Level läd das Standard-Level
    if (cnt < 3) {
        *lvls = fopen("./level/1.txt", "r");
        // sonst gibt hollt es sich das nächste Level wenn das Level erfolgreich
        // abgeschlossen wurde sonst läd es das Level neu
    } else {
        *lvls = fopen(array[idx], "r");
    }
    // prüft ob eine Datei/Directory existiert
    if (*lvls == NULL) {
        return 1;
    }
    // versucht zu lesen, wenn nicht möglich weil es ein Verzeichniss oder
    // eine schreibgeschützte Date ist wird hier ein Fehler aufgeworfen
    fgetc(*lvls);
    if (ferror(*lvls)) {
        return 2;
    }
    // da das Level gelesen wurde und der FILE Inhalt verändert wurde
    // wird die Datei Zeiger wieder an den Anfang gestellt
    rewind(*lvls);
    return 0;
}
void schliessen(FILE *in, FILE *out, FILE *level, int flagge) {
    // Ein Array zur Ausgabe verschiedener Fehler Meldungen
    char *error[] = {"ALLES LÄUFT GUT", "Flagge 1: Datei konnte nicht geöffnet werden\n",
                     "Flagge 2: Datei konnte nicht gelesen werden"};
    // wenn Null und stdin wird nicht geschlossen
    if (in != stdin && in != NULL) {
        fclose(in);
    }
    // wenn Null und stdout wird nicht geschlossen
    if (out != stdout && out != NULL) {
        fclose(out);
    }
    // wenn level NULL ist wird nicht geschlossen
    if (level != NULL) {
        fclose(level);
    }
    // Fehler werde nur ausgegeben wenn die Flagge ungleich Null ist
    if (flagge != 0) {
        fprintf(
            stderr,
            "--------------------------------------------------------------------------------\n"
            "%s\n"
            "Prüfen sie bitte die rechte haben die richtige Datei oder eine Datei übergeben\n"
            "--------------------------------------------------------------------------------\n",
            error[flagge]);
    }
}
