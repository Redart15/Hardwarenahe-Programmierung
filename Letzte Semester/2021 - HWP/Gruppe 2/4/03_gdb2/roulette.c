#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t zufallszahl(uint32_t *zufall){
    uint32_t x = *zufall;
    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *zufall = x;
    return x;
}

int roulette_zahl_rollen(uint32_t *zustand){
    /*
     * Anmerkung: Dieser Zufallszahlengenerator generiert nur vorhersagbare
     * und schlecht verteilte Pseudozufallszahlen.
     * Ein richtiges Glücksspiel sollte stattdessen ein Verfahren
     * verwenden, das sich nicht vorhersagen lässt.
     */
    uint32_t zufall = 0;

    for (int i = 0; i < 7; i++){
        zufall ^= zustand[i];
    }

    int ergebnis = 0;

    for (int i = 0; i < 80; i++){
        uint32_t primzahl = 672657529;
        uint32_t x = zufallszahl(&zufall);
        uint32_t y = zufallszahl(&zufall);
        uint32_t z = zufallszahl(&zufall);
        uint32_t w = zustand[y % 7] * primzahl + zustand[z % 7];
        zustand[x % 7] ^= w;
        ergebnis += (w >> zufallszahl(&zufall) % 10) & 1;
    }

    return ergebnis;
}

void ueberpruefen(int zahl){
    if (zahl > 36){
        printf("FEHLER: Roulette-Zahlen dürfen nicht größer als 36 sein.\n");
        printf("Die gerollte Zahl ist aber %i.\n", zahl);
        exit(EXIT_FAILURE);
    }
}

int main(){
    printf("Das Roulette-Spiel beginnt!\n");
    uint32_t roulette_spiel_zustand[7] = {
        0x74984356,
        0x15418613,
        0x54687486,
        0x15313468,
        0x74435138,
        0x46841653,
        0x14586468,
    };
    for (int runde = 1; runde <= 50; runde++){
        int zahl = roulette_zahl_rollen(roulette_spiel_zustand);

        //ueberpruefen(zahl);

        printf("Runde %i: %i\n", runde, zahl);
    }

    return 0;
}
