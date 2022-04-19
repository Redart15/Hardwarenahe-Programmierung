#include "jumpandrun.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void take_action(space **level, spieler *player, FILE *in, FILE *out, int cnt, int *gold_pnt,
                 int *game_state) {
    // zähl,sprung und eingabe Varibalen
    int idx = 0, sprung = 0, jump = 0;
    // Spieler und Feld getrennt, gibt das erste Feld aus und setzt spieler Status
    find_player(cnt, level, player);
    fprintf(out, "%d\n", idx++);
    display(cnt, level, player, out);
    fallen(level, player, gold_pnt, game_state, cnt);
    while (1) {
        // korregiert den Spieler status
        if (level[player->posy + 1]->line[player->posx] == PLATFORM) {
            player->in_luft = AUFBODEN;
        }
        // holt die Eingabe und Werte
        jump = springen(in);
        // beendet das Spiel
        if (jump == -1) {
            *game_state = 2;
            return;
            // springt, da die Eingabe mit Enter bestätigen werden muss kann man die Eingabe
            // für nach vorne gehen ignorieren
        } else if ((jump == 1) && (sprung == 0) && (player->in_luft == AUFBODEN)) {
            sprung = 3;
            player->in_luft = INLUFT;
        }
        // da immmer ein ENTER folgt wird immer versucht zu bewegen
        move(level, player, gold_pnt, game_state);
        // münzen werden gesammt und Spiel status wird ermittelt plus letze Ausgabe
        if (*game_state != 0) {
            fprintf(out, "%d\n", idx++);
            display(cnt, level, player, out);
            return;
        }
        // Spieler bewegt sich nach oben/unten
        if (sprung <= 0) {
            fallen(level, player, gold_pnt, game_state, cnt);
            sprung = 0;
        } else if ((player->in_luft == INLUFT) && (sprung != 0)) {
            steigen(level, player, gold_pnt, game_state, &sprung, 1);
            sprung--;
        }
        // gibt das lvl aus.
        fprintf(out, "%d\n", idx++);
        display(cnt, level, player, out);
        // checkt on sich in der Zwischenzeit was geändert hat
        if (*game_state != 0) {
            return;
        }
    }
}
void next(space **level, spieler *player, int *gold_pnt, int *game_state) {
    // kürzer zu schreiben
    int px = player->posx;
    int py = player->posy;
    char test = level[py]->line[px];
    // prüft was genau passieren soll
    switch (test) {
    // tötet den Spieler, Game_state wird gesetzt auf -1
    case SPIKES:
    case AWAYSPIKE:
    case DOWNSPIKE:
    case UPSPIKE:
        //~ printf("SPIKE");
        *game_state = -1;
        break;
    // sammelt die Münzen, löscht diese aus dem Level und Aktualisiert den Counter
    case GOLD:
        //~ printf("MAX");
        *gold_pnt = *gold_pnt + 1;
        level[py]->line[px] = SPACE;
        break;
    // Glückwunsch Gewonnen, Game_state wird auf 1
    case ZIEL:
        //~ printf("FIN");
        *game_state = 1;
        break;
    // sonst wird nicht gemacht
    default:
        break;
    }
    return;
}
void move(space **level, spieler *player, int *gold_pnt, int *game_state) {
    // die Loop stopt den Spieler vom austretten des Spielfeldes
    if (player->posx < 80) {
        if (level[player->posy]->line[player->posx + 1] != PLATFORM) {
            player->posx++;
            next(level, player, gold_pnt, game_state);
        }
    }
}
void fallen(space **level, spieler *player, int *gold_pnt, int *game_state, int cnt) {
    // Hindert den Spieler das Felde unter zu verlassen
    if (player->posy < (cnt - 1)) {
        if (level[player->posy + 1]->line[player->posx] != PLATFORM) {
            player->posy++;
            next(level, player, gold_pnt, game_state);
            player->in_luft = INLUFT;
            // ändert den Status wenn es eine Boden untem Spieler gibt
        } else {
            player->in_luft = AUFBODEN;
        }
    }
}
void steigen(space **level, spieler *player, int *gold_pnt, int *game_state, int *sprung, int cnt) {
    // Hindert den Spieler das Feld oben zu verlassen
    if (player->posy > (cnt - 1)) {
        if (level[player->posy - 1]->line[player->posx] != PLATFORM) {
            player->posy--;
            next(level, player, gold_pnt, game_state);
            // reseted den Sprungvorgang
        } else {
            *sprung = 0;
        }
    }
}
int springen(FILE *in) {
    // Variablen fürs verarbeiten der Eingabe
    char befehl;
    int jump = 0;
    // Solange ich nicht ausbreche wird hier durch gelaufen
    while (1) {
        // der erste Char wird uas dem Buffer gehollt
        befehl = fgetc(in);
        if (befehl == EOF) {
            jump = -1;
            return jump;
        }
        if (befehl == NEWLINE) {
            jump = 0;
            return jump;
        } else if (befehl == SPACE) {
            jump = 1;
            // jump wird gesetzt um sich zu merken, das ein Leerzeichen eingegeben wurde
            // Buffer wird bereinigt
            while ((befehl = fgetc(in)) != NEWLINE) {}
            return jump;
        }
    }
}
