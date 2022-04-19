#include "jumpandrun.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// "Viel Erfolg!"
// Danke war anstrengend. Bin stolz auf mein Ergebniss!

int main(int argc, char **argv) {
    // öffnet Variablen für Münzen,Game_State,Zeilen Länge,ARGC IDX und FLAGGE;
    int gold_pnt = 0, game_state = 0, lvl_len = 0, idx = 3, flagge = 0;
    // öffnet die ganzen Datenströme und setzt den Srdio und setzt Flaggen gegebenfalls
    FILE *eingabe = stdin;
    FILE *ausgabe = stdout;
    FILE *level = NULL;
    flagge = test_IO(&eingabe, &ausgabe, argc, argv);
    // Prüft diese schließt gegebene falls den Stram und gibt Fehlermelduing aus
    if (flagge) {
        schliessen(level, eingabe, ausgabe, flagge);
        return flagge;
    }
    // Spiel Schleife bricht aus wenn das Spiel beendet wurde
    while (game_state != 2) {
        // setzt die Level, basierend auf den Idx
        flagge = test_LVL(&level, argc, argv, idx);
        if (flagge) {
            schliessen(level, eingabe, ausgabe, flagge);
            return flagge;
        }
        // muss nach jedem neu laden neu Initialisiert werden
        lvl_len = game_state = gold_pnt = 0;
        // erstellt das Spielfeld und den Spieler
        space **loaded = load_level(&lvl_len, level, &flagge);
        spieler *player = malloc(sizeof(spieler));
        if (flagge) {
            schliessen(level, eingabe, ausgabe, flagge);
            return flagge;
        }
        // hier findet das Spiel statt
        take_action(loaded, player, eingabe, ausgabe, lvl_len, &gold_pnt, &game_state);
        // das Spielfeld und der Spieler werden gelöscht und freigegeben, Spielstand wird geprüft
        unload(lvl_len, loaded, player);
        switch (game_state) {
        case 1: // Spieler hat das lvl erfolgreich beendet und ein neues level wird gegenfalls ini.
            fprintf(ausgabe, "Gewonnen! Punktzahl: %d\n", gold_pnt);
            if (argc == 1) {
                schliessen(level, eingabe, ausgabe, flagge);
                return 0;
            }
            break;
        case -1: // Spieler hat das lvl nicht bestanden, das level wirde neu geladen
            fprintf(ausgabe, "Leider verloren. Das Level wird neu gestartet.\n");
            continue;
            break;
        case 2: // Das Spiel wird beendet
            break;
        } // das nächste Lvl soll geladen werden
        idx++;
        // wenn es das letzte Level war wird es beendet
        if (argc <= idx) {
            schliessen(level, eingabe, ausgabe, flagge);
            return 0;
        }
    } // beim ausbrechen der Schleife mussen noch die Streams geschlossen werden
    schliessen(level, eingabe, ausgabe, flagge);
    return 0;
}
