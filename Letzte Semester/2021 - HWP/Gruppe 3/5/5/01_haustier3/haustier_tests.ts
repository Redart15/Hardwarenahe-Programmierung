#include <string.h>
#include "haustier.h"

#test fIdO
    char name[7];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    memset(&tier, 0xff, sizeof(tier));
    name_setzen(&tier, "fIdO");
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "Fido");

#test leerer_string
    char name[7];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    memset(&tier, 0xff, sizeof(tier));
    name_setzen(&tier, "");
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "");

#test Bello
    char name[7];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    memset(&tier, 0xff, sizeof(tier));
    name_setzen(&tier, "Bello");
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "Bello");

#test sNoOP
    char name[7];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    memset(&tier, 0xff, sizeof(tier));
    name_setzen(&tier, "sNoOP");
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "Snoop"); // Dog

#test fido_und_bello
    char name_eingabe[7];
    char name_ausgabe[7];
    memset(name_ausgabe, 0xff, sizeof(name_ausgabe));
    strcpy(name_eingabe, "fiDO");
    struct haustier tier;
    memset(&tier, 0xff, sizeof(tier));
    name_setzen(&tier, name_eingabe);
    // Der folgende Kopiervorgang sollte den Namen des Tiers nicht modifizieren.
    // Wenn das doch passieren sollte, dann ist der Datentyp im struct
    // wahrscheinlich nicht gut gewählt.
    strcpy(name_eingabe, "bELLO");
    name_ausgeben(name_ausgabe, &tier);
    ck_assert_str_eq(name_ausgabe, "Fido");
    name_setzen(&tier, name_eingabe);
    name_ausgeben(name_ausgabe, &tier);
    ck_assert_str_eq(name_ausgabe, "Bello");

#test Donald
    char name[7];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    memset(&tier, 0xff, sizeof(tier));
    name_setzen(&tier, ";~'#|<>0123456789{}[]d-O_n?a!l\"$%&d+-*/()");
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "Donald");

#test XAEA12
    char name[7];
    memset(name, '?', sizeof(name));
    struct haustier tier;
    memset(&tier, 0xff, sizeof(tier));
    name_setzen(&tier, "X AE A-12");
    name_ausgeben(name, &tier);
    ck_assert_str_eq(name, "Xaea");
