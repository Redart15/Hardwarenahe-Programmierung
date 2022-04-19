#include "jumpandrun.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Hier sind Spieler und Struct nicht gekoppelt, was erlaubt einem viele der Feldes unverändert zu
 * lassen, wenn das Struct besser gebaut wäre musste man sich das neu laden aus der Datei sparen*/
void display(int cnt, space **level, spieler *player, FILE *output) {
    // holt sich Spieler Koordinaten
    int px = player->posx;
    int py = player->posy;
    // fängt das Spielfeld auszugeben
    for (int gy = 0; gy < cnt; gy++) {
        for (int gx = 0; gx <= 80; gx++) {
            // Sobald der Spieler gefunden wurde fügt man ihn ein.
            if ((py == gy) && (px == gx)) {
                fprintf(output, "S");
            } else {
                fprintf(output, "%c", level[gy]->line[gx]);
            }
            //~ }
        }
        fprintf(output, "%c", 10);
    }
}
// Findet den Spieler und löscht ihn aus dem Struct, Spiele und Struct sind nicht gekoppelt
void find_player(int cnt, space **level, spieler *player) {
    for (int gy = 0; gy < cnt; gy++) {
        for (int gx = 0; gx < 81; gx++) {
            if (level[gy]->line[gx] == 83) {
                // Findet die Koordinaten des Spielers
                player->posx = gx;
                player->posy = gy;
                // setzt seine Status auf INLUFT standartmäßig
                player->in_luft = INLUFT;
                // ersetzt die Position durch ein Leerzeichen
                level[gy]->line[gx] = SPACE;
            }
        }
    }
}
