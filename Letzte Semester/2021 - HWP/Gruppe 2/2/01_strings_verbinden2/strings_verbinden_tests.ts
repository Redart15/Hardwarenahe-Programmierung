#include <string.h>
#include "strings_verbinden.h"

#test hello_world_zusammen_laenge
    char string0[] = " ,olleH";
    char string1[] = "!dlroW";
    char zusammen[14];

    strings_verbinden(zusammen, string0, string1);

    int laenge_zusammen = strlen(zusammen);

    ck_assert_int_eq(13, laenge_zusammen);

#test hello_world_nullterminator
    char string0[] = " ,olleH";
    char string1[] = "!dlroW";
    char zusammen[14];

    strings_verbinden(zusammen, string0, string1);

    char nullterminator = zusammen[13];

    ck_assert_int_eq('\0', nullterminator);

#test hello_world_zusammen
    char string0[] = " ,olleH";
    char string1[] = "!dlroW";
    char zusammen[14];

    strings_verbinden(zusammen, string0, string1);

    ck_assert_str_eq(zusammen, "Hello, World!");

#test hello_leer_zusammen
    char string0[] = "olleH";
    char string1[] = "";
    char zusammen[6];

    strings_verbinden(zusammen, string0, string1);

    ck_assert_str_eq(zusammen, "Hello");

#test leer_world_zusammen
    char string0[] = "";
    char string1[] = "dlroW";
    char zusammen[6];

    strings_verbinden(zusammen, string0, string1);

    ck_assert_str_eq(zusammen, "World");

#test leer_leer_zusammen
    char string0[] = "";
    char string1[] = "";
    char zusammen[1];

    strings_verbinden(zusammen, string0, string1);

    ck_assert_str_eq(zusammen, "");

#test aaaaaaaa
    char string0[] = "aaaa";
    char string1[] = "aaaa";
    char zusammen[9];

    strings_verbinden(zusammen, string0, string1);

    ck_assert_str_eq(zusammen, "aaaaaaaa");

#test lang_lang_zusammen
    char string0[] = " gnirtS regnaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaL";
    char string1[] = ".gnirtS regnaaaaaaaaaaaaaaaaaaaaaaaaaaaal nie hcon dnu";
    char zusammen[107];

    strings_verbinden(zusammen, string0, string1);

    ck_assert_str_eq(zusammen, "Laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaanger String und noch ein laaaaaaaaaaaaaaaaaaaaaaaaaaaanger String.");
