#include "tiere_zaehlen.h" 			 

#test leerer_text
    char *text = "";
    char tiere[10][16] = {"In", "diesem", "Array", "steht", "nur", "Quatsch"};
    int anzahl_tiere = tiere_zaehlen(tiere, text);
    ck_assert_int_eq(anzahl_tiere, 0);

#test keine_tiere
    char *text = "Bus Auto Bahn Kugelschreiber";
    char tiere[10][16];
    int anzahl_tiere = tiere_zaehlen(tiere, text);
    ck_assert_int_eq(anzahl_tiere, 0);

#test eine_ente
    char *text = "Ente";
    char tiere[10][16];
    int anzahl_tiere = tiere_zaehlen(tiere, text);
    ck_assert_int_eq(anzahl_tiere, 1);
    ck_assert_str_eq(tiere[0], "Ente");

#test zwei_enten
    char *text = "Ente Ente";
    char tiere[10][16];
    int anzahl_tiere = tiere_zaehlen(tiere, text);
    ck_assert_int_eq(anzahl_tiere, 2);
    char *erwartere_tiere[] = {"Ente", "Ente"};
    for (int i = 0; i < 2; i++){
        ck_assert_str_eq(tiere[i], erwartere_tiere[i]);
    }

#test ente_ente_ente_gans
    char *text = "Ente Ente Ente Gans";
    char tiere[10][16];
    int anzahl_tiere = tiere_zaehlen(tiere, text);
    ck_assert_int_eq(anzahl_tiere, 4);
    char *erwartere_tiere[] = {"Ente", "Ente", "Ente", "Gans"};
    for (int i = 0; i < 4; i++){
        ck_assert_str_eq(tiere[i], erwartere_tiere[i]);
    }

#test versteckte_tiere
    char *text = "0123456789Ente_Maus Ente{}[]\r\n\t\"'~#.:,;/*-+Auto<>|Saigaantilope!$&%/()==?Gans462435Nasenaffe62w435235Nasenaffe7263456345";
    char *erwartere_tiere[] = {"Ente", "Maus", "Ente", "Saigaantilope", "Gans", "Nasenaffe", "Nasenaffe"};
    char tiere[10][16];
    int anzahl_tiere = tiere_zaehlen(tiere, text);
    ck_assert_int_eq(anzahl_tiere, 7);
    for (int i = 0; i < 7; i++){
        ck_assert_str_eq(tiere[i], erwartere_tiere[i]);
    }
