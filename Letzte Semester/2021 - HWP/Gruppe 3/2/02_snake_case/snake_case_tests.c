/*
 * DO NOT EDIT THIS FILE. Generated by checkmk.
 * Edit the original source file "snake_case_tests.ts" instead.
 */

#include <check.h>

#line 1 "snake_case_tests.ts"
#include "snake_case.h"

START_TEST(leerer_string)
{
#line 4
    char string[1] = "";
    zu_snake_case(string);
    ck_assert_str_eq(string, "");

}
END_TEST

START_TEST(ente)
{
#line 9
    char string[5] = "ente";
    zu_snake_case(string);
    ck_assert_str_eq(string, "ente");

}
END_TEST

START_TEST(snakeCase)
{
#line 14
    char string[11] = "snakeCase";
    zu_snake_case(string);
    ck_assert_str_eq(string, "snake_case");

}
END_TEST

START_TEST(illegales_iglu)
{
#line 19
    char string[14] = "illicitIgloo";
    zu_snake_case(string);
    ck_assert_str_eq(string, "illicit_igloo");

}
END_TEST

START_TEST(o_o)
{
#line 24
    char string[6] = "(oO)";
    zu_snake_case(string);
    ck_assert_str_eq(string, "(o_o)");

}
END_TEST

START_TEST(SNAKE)
{
#line 29
    char string[10] = "sNAKE";
    zu_snake_case(string);
    ck_assert_str_eq(string, "s_n_a_k_e");

}
END_TEST

START_TEST(roll)
{
#line 34
    char string[49] = "neverGonnaGiveYouUpNeverGonnaLetYouDown";
    zu_snake_case(string);
    ck_assert_str_eq(string, "never_gonna_give_you_up_never_gonna_let_you_down");
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
    tcase_add_test(tc1_1, ente);
    tcase_add_test(tc1_1, snakeCase);
    tcase_add_test(tc1_1, illegales_iglu);
    tcase_add_test(tc1_1, o_o);
    tcase_add_test(tc1_1, SNAKE);
    tcase_add_test(tc1_1, roll);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
