#include <stdio.h>

/*
 * Nimmt Tastatureingabe vom Benutzer entgegen und gibt die eingegebene Zahl zurück.
 */
int warte_auf_eingabe();

/*
 * Ausgabe eines Kaffees.
 */
void print_kaffee();

/*
 * Gibt "anzahl" Tassen Kaffee aus und passt die übergebenen Geld- und Kaffeebestände
 * des Automaten entsprechend an.
 */
void kaffee_ausgeben(int anzahl, double *geldstand, int *tassenstand);

void kassenstand_ausgabe(double geldstand);

int main(int argc, char** argv){
    double geldstand  = 0;
    int tassenstand = 100;

    while(tassenstand > 0){
        int anzahl = warte_auf_eingabe();
        if(anzahl < 0){
            kassenstand_ausgabe(geldstand);
            return 1;
        }
        kaffee_ausgeben(anzahl, &geldstand, &tassenstand);
        printf("Ich habe noch %d Tassen ^-^\n", tassenstand);
    }
    kassenstand_ausgabe(geldstand);
    return 0;
}

void kaffee_ausgeben(int anzahl, double *geldstand, int *tassenstand){
    int auszugebende_tassen = (anzahl > *tassenstand) ? *tassenstand : anzahl;
    for(int i = 0; i < auszugebende_tassen; i++){
        print_kaffee();
        *tassenstand = *tassenstand-1;
        *geldstand = *geldstand+1;
    }
}

void kassenstand_ausgabe(double geldstand){
    if(geldstand >= 50){
        printf("Kasse leeren\n");
    }
}

int warte_auf_eingabe(){
    int eingabe;
    printf("Wie viel Kaffee soll ich dir machen? ^-^\nKaffeeanzahl: ");
    fscanf(stdin, "%d", &eingabe);
    return eingabe;
}

void print_kaffee(){
    printf("  ________\n");
    printf(" |        |_\n");
    printf(" |        |  |\n");
    printf(" | KAFFEE |  |\n");
    printf(" |        |__|\n");
    printf(" |________|\n\n");
}


