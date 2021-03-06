/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "strings_verbinden_tests.ts" instead.
 */

#include <check.h>

#line 1 "strings_verbinden_tests.ts"
#include <string.h>
#include "strings_verbinden.h"

START_TEST(hello_world_zusammen_laenge)
{
#line 5
    char string0[] = "Hello";
    char string1[] = ", ";
    char string2[] = "World!";
    char zusammen[14];

    strings_verbinden(zusammen, string0, string1, string2);

    int laenge_zusammen = strlen(zusammen);

    ck_assert_int_eq(13, laenge_zusammen);

}
END_TEST

START_TEST(hello_world_nullterminator)
{
#line 17
    char string0[] = "Hello";
    char string1[] = ", ";
    char string2[] = "World!";
    char zusammen[14];

    strings_verbinden(zusammen, string0, string1, string2);

    char nullterminator = zusammen[13];

    ck_assert_int_eq('\0', nullterminator);

}
END_TEST

START_TEST(hello_world_zusammen)
{
#line 29
    char string0[] = "Hello";
    char string1[] = ", ";
    char string2[] = "World!";
    char zusammen[14];

    strings_verbinden(zusammen, string0, string1, string2);

    ck_assert_str_eq(zusammen, "Hello, World!");

}
END_TEST

START_TEST(hello_leer_leer_zusammen)
{
#line 39
    char string0[] = "Hello";
    char string1[] = "";
    char string2[] = "";
    char zusammen[6];

    strings_verbinden(zusammen, string0, string1, string2);

    ck_assert_str_eq(zusammen, "Hello");

}
END_TEST

START_TEST(leer_world_leer_zusammen)
{
#line 49
    char string0[] = "";
    char string1[] = "World";
    char string2[] = "";
    char zusammen[6];

    strings_verbinden(zusammen, string0, string1, string2);

    ck_assert_str_eq(zusammen, "World");

}
END_TEST

START_TEST(leer_world_ausrufezeichen_zusammen)
{
#line 59
    char string0[] = "";
    char string1[] = "World";
    char string2[] = "!";
    char zusammen[7];

    strings_verbinden(zusammen, string0, string1, string2);

    ck_assert_str_eq(zusammen, "World!");

}
END_TEST

START_TEST(leer_leer_leer_zusammen)
{
#line 69
    char string0[] = "";
    char string1[] = "";
    char string2[] = "";
    char zusammen[1];

    strings_verbinden(zusammen, string0, string1, string2);

    ck_assert_str_eq(zusammen, "");

}
END_TEST

START_TEST(lang_lang_zusammen)
{
#line 79
    char string0[] = "Dies ist ein laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaanger String";
    char string1[] = " und noch ein etwas kuerzerer String";
    char string2[] = " und wieder ein laaaaaaaaaaaaaaaaaaaaaaaaaanger String.";
    char zusammen[148];

    strings_verbinden(zusammen, string0, string1, string2);

    ck_assert_str_eq(zusammen, "Dies ist ein laaaaaaaaaaaaaaaaaaaaaaaaaaaaaaanger String und noch ein etwas kuerzerer String und wieder ein laaaaaaaaaaaaaaaaaaaaaaaaaanger String.");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, hello_world_zusammen_laenge);
    tcase_add_test(tc1_1, hello_world_nullterminator);
    tcase_add_test(tc1_1, hello_world_zusammen);
    tcase_add_test(tc1_1, hello_leer_leer_zusammen);
    tcase_add_test(tc1_1, leer_world_leer_zusammen);
    tcase_add_test(tc1_1, leer_world_ausrufezeichen_zusammen);
    tcase_add_test(tc1_1, leer_leer_leer_zusammen);
    tcase_add_test(tc1_1, lang_lang_zusammen);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
