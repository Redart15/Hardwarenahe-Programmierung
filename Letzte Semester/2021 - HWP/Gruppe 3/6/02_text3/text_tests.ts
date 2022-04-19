#include "text.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * Verbindet Strings aus einem Array und fügt dazwischen einen trennenden String ein.
 * Zum Beispiel würden die Strings {"a", "b", "c"} mit Trennstring "-" zu "a-b-c".
 * Damit ist "verbinden" praktisch die inverse Operation zum Trennen.
 */
char* verbinden(char **teile, int anzahl, char *trenner){
    // Gesamtlänge aller Teile zusammenzählen
    int gesamtlaenge = 0;
    for (int i = 0; i < anzahl; i++){
        gesamtlaenge += strlen(teile[i]);
        if (i != anzahl - 1){
            gesamtlaenge += strlen(trenner);
        }
    }

    // Alle Teile in String "gesamt" kopieren
    char *gesamt = malloc(gesamtlaenge + 1);
    int position = 0;
    for (int i = 0; i < anzahl; i++){
        strcpy(gesamt + position, teile[i]);
        position += strlen(teile[i]);
        if (i != anzahl - 1){
            strcpy(gesamt + position, trenner);
            position += strlen(trenner);
        }
    }
    return gesamt;
}

void ausgeben(
    char *text_eingabe,
    char *trenner,
    char **erwartete_teile,
    int erwartete_anzahl,
    Text **teile,
    int anzahl
){
    printf("Eingabe: \"%s\"\n", text_eingabe);
    printf("Trenner: \"%s\"\n", trenner);
    printf("\nErwartete Strings:\n");
    for (int i = 0; i < erwartete_anzahl; i++){
        printf("String %i: \"%s\"\n", i, erwartete_teile[i]);
    }
    if (anzahl > 0){
        printf("\nTatsächliche Strings:\n");
        for (int i = 0; i < anzahl; i++){
            char *string = text_ausgeben(teile[i]);
            printf("String %i: \"%s\"\n", i, string);
            free(string);
        }
    }
    printf("\n");
}

/* Testet, ob Texte für eine bestimmte Eingabe korrekt getrennt werden. */
void trennen_testen(
    char *text_eingabe,
    char *trenner,
    char **erwartete_teile,
    int erwartete_anzahl
){
    Text *text = text_initialisieren(text_eingabe);

    int anzahl;
    Text **teile = text_trennen(&anzahl, text, trenner);

    text_freigeben(text);

    if (anzahl != erwartete_anzahl){
        printf("\n");
        printf("FEHLER: Anzahl %d entspricht nicht erwarteter Anzahl %d.\n\n",
            anzahl, erwartete_anzahl);
        ausgeben(text_eingabe, trenner, erwartete_teile, erwartete_anzahl, teile, anzahl);
    }

    ck_assert_int_eq(anzahl, erwartete_anzahl);

    for (int i = 0; i < anzahl; i++){
        char *teil = text_ausgeben(teile[i]);

        if (0 != strcmp(teil, erwartete_teile[i])){
            printf("FEHLER: Falsche Ausgabe bei String %d.\n\n", i);
            ausgeben(text_eingabe, trenner, erwartete_teile, erwartete_anzahl, teile, anzahl);
        }

        ck_assert_str_eq(teil, erwartete_teile[i]);

        free(teil);
    }

    char **ausgaben = malloc(anzahl * sizeof(*ausgaben));

    for (int i = 0; i < anzahl; i++){
        ausgaben[i] = text_ausgeben(teile[i]);
    }

    char *verbunden = verbinden(ausgaben, anzahl, trenner);

    for (int i = 0; i < anzahl; i++){
        free(ausgaben[i]);
    }
    free(ausgaben);

    ck_assert_str_eq(verbunden, text_eingabe);

    free(verbunden);

    texte_freigeben(teile, anzahl);
}

#test initialisieren_freigeben
    Text *text = text_initialisieren("Hello, World!");
    text_freigeben(text);

#test initialisieren_ausgeben_freigeben
    Text *text = text_initialisieren("Hello, World!");
    char *ausgabe = text_ausgeben(text);
    ck_assert_str_eq(ausgabe, "Hello, World!");
    free(ausgabe);
    text_freigeben(text);

#test leerer_string
    Text *text = text_initialisieren("");
    char *ausgabe = text_ausgeben(text);
    text_freigeben(text);
    ck_assert_str_eq(ausgabe, "");
    free(ausgabe);

#test trennen_hallo_welt_komma
    char *text = "Hallo,Welt!";
    char *trenner = ",";
    char *teile[] = {
        "Hallo",
        "Welt!",
    };
    int anzahl = 2;

    trennen_testen(text, trenner, teile, anzahl);

#test trennen_leer
    Text *text = text_initialisieren("");

    char *trenner = ",";

    int anzahl;
    Text **teile = text_trennen(&anzahl, text, trenner);

    text_freigeben(text);

    ck_assert_int_eq(anzahl, 1);

    char *teil_leer = text_ausgeben(teile[0]);

    texte_freigeben(teile, anzahl);

    ck_assert_str_eq(teil_leer, "");

    free(teil_leer);

#test trennen_komma_am_anfang
    char *text = ",Hallo,Welt!";
    char *trenner = ",";
    char *teile[] = {
        "",
        "Hallo",
        "Welt!",
    };
    int anzahl = 3;

    trennen_testen(text, trenner, teile, anzahl);

#test trennen_komma_am_ende
    char *text = "Hallo,Welt!,";
    char *trenner = ",";
    char *teile[] = {
        "Hallo",
        "Welt!",
        "",
    };
    int anzahl = 3;

    trennen_testen(text, trenner, teile, anzahl);

#test trennen_komma_am_anfang_und_am_ende
    char *text = ",Hallo,Welt!,";
    char *trenner = ",";
    char *teile[] = {
        "",
        "Hallo",
        "Welt!",
        "",
    };
    int anzahl = 4;

    trennen_testen(text, trenner, teile, anzahl);

#test trennen_sieben_kommas
    char *text = ",,,,,,,";
    char *trenner = ",";
    char *teile[] = {"", "", "", "", "", "", "", ""};
    int anzahl = 8;

    trennen_testen(text, trenner, teile, anzahl);

#test trennen_wort
    char *text = "Dies ist ein Text.";
    char *trenner = "ist";
    char *teile[] = {"Dies ", " ein Text."};
    int anzahl = 2;

    trennen_testen(text, trenner, teile, anzahl);

#test trennen_wort_am_anfang
    char *text = "Dies ist ein Text.";
    char *trenner = "Dies";
    char *teile[] = {"", " ist ein Text."};
    int anzahl = 2;

    trennen_testen(text, trenner, teile, anzahl);

#test trennen_wort_am_ende
    char *text = "Dies ist ein Text.";
    char *trenner = "Text.";
    char *teile[] = {"Dies ist ein ", ""};
    int anzahl = 2;

    trennen_testen(text, trenner, teile, anzahl);

#test trennen_nerfige_ente
    char *text =
        "<Quack>"
        "Never gonna give you up"
        "<Quack>"
        "Never gonna let you down"
        "<Quack>"
        "Never gonna run around and desert you"
        "<Quack>"
        "Never gonna make you cry"
        "<Quack>"
        "Never gonna say goodbye"
        "<Quack>"
        "Never gonna tell a lie and hurt you"
        "<Quack>";
    char *trenner = "<Quack>";
    char *teile[] = {
        "",
        "Never gonna give you up",
        "Never gonna let you down",
        "Never gonna run around and desert you",
        "Never gonna make you cry",
        "Never gonna say goodbye",
        "Never gonna tell a lie and hurt you",
        "",
    };
    int anzahl = 8;

    trennen_testen(text, trenner, teile, anzahl);

#test trennen_gg
    char *text = "12ggg3gg";
    char *trenner = "gg";
    char *teile[] = {"12", "g3", ""};
    int anzahl = 3;

    trennen_testen(text, trenner, teile, anzahl);

#test trennen_ggg
    char *text = "ggggggggg";
    char *trenner = "ggg";
    char *teile[] = {"", "", "", ""};
    int anzahl = 4;

    trennen_testen(text, trenner, teile, anzahl);

#test trennen_gggg
    char *text = "ggggggggggg";
    char *trenner = "gggg";
    char *teile[] = {"", "", "ggg"};
    int anzahl = 3;

    trennen_testen(text, trenner, teile, anzahl);

#test trennen_123
    char *text = "0123456789Ente0123456789Gans0123456789";
    char *trenner = "0123456789";
    char *teile[] = {"", "Ente", "Gans", ""};
    int anzahl = 4;

    trennen_testen(text, trenner, teile, anzahl);
