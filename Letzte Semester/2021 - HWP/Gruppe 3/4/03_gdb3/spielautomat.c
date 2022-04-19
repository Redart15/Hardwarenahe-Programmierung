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

void zahlen_wuerfeln(int *zahlen, uint32_t *zustand){
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

    for (int i = 0; i < 3; i++){
        zahlen[i] = 1;
    }

    for (int i = 0; i < 50; i++){
        uint32_t primzahl = 672657529;
        uint32_t x = zufallszahl(&zufall);
        uint32_t y = zufallszahl(&zufall);
        uint32_t z = zufallszahl(&zufall);

        uint32_t w = zustand[y % 7] * primzahl + zustand[z % 7];

        zustand[x % 7] ^= w;
        zahlen[x % 3] += (w >> zufallszahl(&zufall) % 10) & 1;
    }
}

int main(){
    printf("Das Spiel beginnt!\n");
    uint32_t spiel_zustand[7] = {
        0x74984356,
        0x15418613,
        0x54687486,
        0x15313468,
        0x74435138,
        0x46841653,
        0x14586468,
    };
    for (int runde = 1; runde < 25; runde++){
        int zahlen[3];
        zahlen_wuerfeln(zahlen, spiel_zustand);

        printf("Runde %i: ", runde);
        for (int i = 0; i < 3; i++){
            printf("%i ", zahlen[i]);
        }
        printf("\n");

        if (zahlen[0] == zahlen[1] && zahlen[1] == zahlen[2]){
            printf("Gewonnen! Du kriegst 1000€!\n");
        }
    }

    return 0;
}
