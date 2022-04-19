/*
 * 1) Studis sollen nach dieser Aufgabe
 *  - Tests von einer ts Dateie in eine c-Datei umwandeln können.
 *    (Sie müssen das '>' noch nicht verstehen.)
 *  - die resultierenden Dateien kompilieren und ausführen können.
 *  - verstehen, was die Ausgaben bedeuten.
 * 2) Beispiele für Fragen an die Studis, um das Verständnis zu prüfen:
 *  - Was bedeutet die Zeile  "0%: Checks: 1, Failures: 1, Errors: 0" ?
 *  - Welche Tests schlagen fehl?
 */

// checkmk simpleString_tests.ts > simpleString_tests.c
// gcc simpleString_korrigiert.c simpleString_tests.c -o tests -Wall -lsubunit -lm -lpthread -lrt -lcheck -std=c99 -g -fprofile-arcs -ftest-coverage

#include <string.h>
#include "simpleString.h"

#test char_is_in_string
    char *haystack = "a";
    char needle = 'a';
    int result = count_in_string(haystack, needle);
    ck_assert_int_eq(1, result);

#test char_is_two_times_in_string
    char *haystack = "aba";
    char needle = 'a';
    int result = count_in_string(haystack, needle);
    ck_assert_int_eq(2, result);

#test not_same_length
    char *string1="abc";
    char *string2="abcd";
    int result = my_strcmp(string1, string2);
    ck_assert_int_eq(0, result);

#test same_length_different_strings
    char *string1="abc";
    char *string2="abd";
    int result = my_strcmp(string1, string2);
    ck_assert_int_eq(0, result);

#test same_strings
    char *string1="abc";
    char *string2="abc";
    int result = my_strcmp(string1, string2);
    ck_assert_int_eq(1, result);
