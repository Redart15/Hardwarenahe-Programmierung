#include <string.h>
#include "strings_verbinden.h"

// Tests bauen und ausführen:
// checkmk strings_verbinden_tests.ts > strings_verbinden_tests.c
// gcc -Wall -std=c99 -g strings_verbinden.c strings_verbinden_tests.c -o tests $(pkg-config --cflags --libs check)
// ./tests

#test hello_world_zusammen_laenge
    char string1[] = "Hello, ";
    char string2[] = "World!";
    char zusammen[14];

    strings_verbinden(zusammen, string1, string2);

    int laenge_zusammen = strlen(zusammen);

    ck_assert_int_eq(13, laenge_zusammen);

#test hello_world_nullterminator
    char string1[] = "Hello, ";
    char string2[] = "World!";
    char zusammen[14];

    strings_verbinden(zusammen, string1, string2);

    char nullterminator = zusammen[13];

    ck_assert_int_eq('\0', nullterminator);

#test hello_world_zusammen
    char string1[] = "Hello, ";
    char string2[] = "World!";
    char zusammen[14];

    strings_verbinden(zusammen, string1, string2);

    ck_assert_str_eq(zusammen, "Hello, World!");

#test hello_leer_zusammen
    char string1[] = "Hello";
    char string2[] = "";
    char zusammen[6];

    strings_verbinden(zusammen, string1, string2);

    ck_assert_str_eq(zusammen, "Hello");

#test leer_world_zusammen
    char string1[] = "";
    char string2[] = "World";
    char zusammen[6];

    strings_verbinden(zusammen, string1, string2);

    ck_assert_str_eq(zusammen, "World");

#test leer_leer_zusammen
    char string1[] = "";
    char string2[] = "";
    char zusammen[1];

    strings_verbinden(zusammen, string1, string2);

    ck_assert_str_eq(zusammen, "");

#test lang_lang_zusammen
    char string1[] = "Laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaanger String ";
    char string2[] = "und noch ein laaaaaaaaaaaaaaaaaaaaaaaaaaaanger String.";
    char zusammen[107];

    strings_verbinden(zusammen, string1, string2);

    ck_assert_str_eq(zusammen, "Laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaanger String und noch ein laaaaaaaaaaaaaaaaaaaaaaaaaaaanger String.");
