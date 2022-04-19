#include <string.h>
#include "strings_verbinden.h"

#test hello_world_zusammen_laenge
    char string0[] = "Hello";
    char string1[] = ", ";
    char string2[] = "World!";
    char zusammen[14];

    strings_verbinden(zusammen, string0, string1, string2);

    int laenge_zusammen = strlen(zusammen);

    ck_assert_int_eq(13, laenge_zusammen);

#test hello_world_nullterminator
    char string0[] = "Hello";
    char string1[] = ", ";
    char string2[] = "World!";
    char zusammen[14];

    strings_verbinden(zusammen, string0, string1, string2);

    char nullterminator = zusammen[13];

    ck_assert_int_eq('\0', nullterminator);

#test hello_world_zusammen
    char string0[] = "Hello";
    char string1[] = ", ";
    char string2[] = "World!";
    char zusammen[14];

    strings_verbinden(zusammen, string0, string1, string2);

    ck_assert_str_eq(zusammen, "Hello, World!");

#test hello_leer_leer_zusammen
    char string0[] = "Hello";
    char string1[] = "";
    char string2[] = "";
    char zusammen[6];

    strings_verbinden(zusammen, string0, string1, string2);

    ck_assert_str_eq(zusammen, "Hello");

#test leer_world_leer_zusammen
    char string0[] = "";
    char string1[] = "World";
    char string2[] = "";
    char zusammen[6];

    strings_verbinden(zusammen, string0, string1, string2);

    ck_assert_str_eq(zusammen, "World");

#test leer_world_ausrufezeichen_zusammen
    char string0[] = "";
    char string1[] = "World";
    char string2[] = "!";
    char zusammen[7];

    strings_verbinden(zusammen, string0, string1, string2);

    ck_assert_str_eq(zusammen, "World!");

#test leer_leer_leer_zusammen
    char string0[] = "";
    char string1[] = "";
    char string2[] = "";
    char zusammen[1];

    strings_verbinden(zusammen, string0, string1, string2);

    ck_assert_str_eq(zusammen, "");

#test lang_lang_zusammen
    char string0[] = "Dies ist ein laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaanger String";
    char string1[] = " und noch ein etwas kuerzerer String";
    char string2[] = " und wieder ein laaaaaaaaaaaaaaaaaaaaaaaaaanger String.";
    char zusammen[148];

    strings_verbinden(zusammen, string0, string1, string2);

    ck_assert_str_eq(zusammen, "Dies ist ein laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaanger String und noch ein etwas kuerzerer String und wieder ein laaaaaaaaaaaaaaaaaaaaaaaaaanger String.");
