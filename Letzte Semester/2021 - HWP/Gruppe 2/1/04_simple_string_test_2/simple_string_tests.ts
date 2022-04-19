#include "simple_string.h"

#test laenge_leerer_string
    char *string = "";
    int anzahl = zeichen_zaehlen(string);
    ck_assert_int_eq(0, anzahl);

#test laenge_ente
    char *string = "Ente";
    int anzahl = zeichen_zaehlen(string);
    ck_assert_int_eq(4, anzahl);

#test laenge_hallo
    char *string = "Hallo, Welt!";
    int anzahl = zeichen_zaehlen(string);
    ck_assert_int_eq(12, anzahl);


#test laenge_langer_string
    char *string =
        "01234567890123456789012345678901234567890123456789"
        "01234567890123456789012345678901234567890123456789"
        "01234567890123456789012345678901234567890123456789"
        "01234567890123456789012345678901234567890123456789"
        "01234567890123456789012345678901234567890123456789"
        "01234567890123456789012345678901234567890123456789"
        "01234567890123456789012345678901234567890123456789"
        "01234567890123456789012345678901234567890123456789"
        "01234567890123456789012345678901234567890123456789"
        "01234567890123456789012345678901234567890123456789";
    int anzahl = zeichen_zaehlen(string);
    ck_assert_int_eq(500, anzahl);

#test leeren_string_kopieren
    char ziel[25];
    for (int i = 0; i < 25; i++){
        ziel[i] = '?';
    }
    char *quelle = "";

    string_kopieren(ziel, quelle);

    ck_assert_str_eq(ziel, quelle);

#test ente_kopieren
    char ziel[25];
    for (int i = 0; i < 25; i++){
        ziel[i] = '?';
    }
    char *quelle = "Hier kommt die Ente.";

    string_kopieren(ziel, quelle);

    ck_assert_str_eq(ziel, quelle);

#test langen_string_kopieren
    char ziel[101];
    for (int i = 0; i < 101; i++){
        ziel[i] = '?';
    }
    char *quelle =
        "01234567890123456789012345678901234567890123456789"
        "01234567890123456789012345678901234567890123456789";

    string_kopieren(ziel, quelle);

    ck_assert_str_eq(ziel, quelle);
