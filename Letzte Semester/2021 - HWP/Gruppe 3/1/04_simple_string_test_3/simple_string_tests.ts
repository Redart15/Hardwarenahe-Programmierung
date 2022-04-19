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

#test leeren_string_anhaengen
    char string1[1] = "";
    char *string2 = "";

    string_anhaengen(string1, string2);

    ck_assert_str_eq(string1, "");

#test ente_anhaengen
    char string1[12] = "Enten";
    char *string2 = "hausen";

    string_anhaengen(string1, string2);

    ck_assert_str_eq(string1, "Entenhausen");

#test nichts_anhaengen
    char string1[7] = "nichts";
    char *string2 = "";

    string_anhaengen(string1, string2);

    ck_assert_str_eq(string1, "nichts");

#test etwas_an_nichts_anhaengen
    char string1[7] = "";
    char *string2 = "etwas";

    string_anhaengen(string1, string2);

    ck_assert_str_eq(string1, "etwas");

#test langen_string_anhaengen
    char string1[101] = "01234567890123456789012345678901234567890123456789";
    char *string2 = "01234567890123456789012345678901234567890123456789";

    string_anhaengen(string1, string2);

    char *erwartet =
        "01234567890123456789012345678901234567890123456789"
        "01234567890123456789012345678901234567890123456789";

    ck_assert_str_eq(erwartet, string1);
