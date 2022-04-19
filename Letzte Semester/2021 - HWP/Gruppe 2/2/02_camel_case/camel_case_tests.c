/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "camel_case_tests.ts" instead.
 */

#include <check.h>

#line 1 "camel_case_tests.ts"
#include "camel_case.h"

START_TEST(leerer_string)
{
#line 4
    char string[] = "";
    zu_camel_case(string);
    ck_assert_str_eq(string, "");

}
END_TEST

START_TEST(camel_case)
{
#line 9
    char string[] = "camel_case";
    zu_camel_case(string);
    ck_assert_str_eq(string, "camelCase");

}
END_TEST

START_TEST(camel___________case)
{
#line 14
    char string[] = "camel_________case";
    zu_camel_case(string);
    ck_assert_str_eq(string, "camelCase");

}
END_TEST

START_TEST(camel_case_____)
{
#line 19
    char string[] = "camel_case_____";
    zu_camel_case(string);
    ck_assert_str_eq(string, "camelCase");

}
END_TEST

START_TEST(XMLHttpRequest)
{
#line 24
    char string[] = "XMLHttpRequest";
    zu_camel_case(string);
    ck_assert_str_eq(string, "XMLHttpRequest");

}
END_TEST

START_TEST(gemischt)
{
#line 29
    char string[] = "snake_case_camelCase_HTTP_snake_case";
    zu_camel_case(string);
    ck_assert_str_eq(string, "snakeCaseCamelCaseHTTPSnakeCase");

}
END_TEST

START_TEST(zahlen)
{
#line 34
    char string[] = "zahlen_1234";
    zu_camel_case(string);
    ck_assert_str_eq(string, "zahlen1234");

}
END_TEST

START_TEST(leerzeichen_und_ausrufezeichen)
{
#line 39
    char string[] = "a_a_a_h! snake_case!";
    zu_camel_case(string);
    ck_assert_str_eq(string, "aAAH! snakeCase!");

}
END_TEST

START_TEST(roll)
{
#line 44
    char string[] = "never_gonna____give__you_up_never____gonna_let_you____down";
    zu_camel_case(string);
    ck_assert_str_eq(string, "neverGonnaGiveYouUpNeverGonnaLetYouDown");
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, leerer_string);
    tcase_add_test(tc1_1, camel_case);
    tcase_add_test(tc1_1, camel___________case);
    tcase_add_test(tc1_1, camel_case_____);
    tcase_add_test(tc1_1, XMLHttpRequest);
    tcase_add_test(tc1_1, gemischt);
    tcase_add_test(tc1_1, zahlen);
    tcase_add_test(tc1_1, leerzeichen_und_ausrufezeichen);
    tcase_add_test(tc1_1, roll);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}