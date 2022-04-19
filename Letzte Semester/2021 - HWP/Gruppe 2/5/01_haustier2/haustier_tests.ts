#include <string.h>
#include "haustier.h"

#test bello_name_setzen_ausgeben
    char name[11];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    name_setzen(&tier, "Bello");
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "Bello");

#test leer_name_setzen_ausgeben
    char name[11];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    name_setzen(&tier, "");
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "");

#test bello_name_wiederverwenden
    char name[11];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    name_setzen(&tier, "Bello");
    strcpy(name, "Ente");
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "Bello");

#test bello_name_aendern
    char name[11];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    name_setzen(&tier, "Bello");
    name_setzen(&tier, "Hasso");
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "Hasso");

#test bello_name_umdrehen
    char name[11];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    name_setzen(&tier, "Bello");
    name_umdrehen(&tier);
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "olleB");

#test gerade_anzahl_name_umdrehen
    char name[11];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    name_setzen(&tier, "12345678");
    name_umdrehen(&tier);
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "87654321");

#test ungerade_anzahl_name_umdrehen
    char name[11];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    name_setzen(&tier, "1234567");
    name_umdrehen(&tier);
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "7654321");

#test leer_name_umdrehen
    char name[11];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    name_setzen(&tier, "");
    name_umdrehen(&tier);
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "");

#test hannah_name_umdrehen
    char name[11];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    name_setzen(&tier, "hannah");
    name_umdrehen(&tier);
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "hannah");

#test otto_name_umdrehen
    char name[11];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    name_setzen(&tier, "OTTO");
    name_umdrehen(&tier);
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "OTTO");

#test noel_name_umdrehen
    char name[11];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    name_setzen(&tier, "Noel");
    name_umdrehen(&tier);
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "leoN");

#test regallager_name_umdrehen
    char name[11];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    // Komischer Tiername
    name_setzen(&tier, "Regallager");
    name_umdrehen(&tier);
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "regallageR");
