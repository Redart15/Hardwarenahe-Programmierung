#include "snake_case.h"

#test leerer_string
    char string[1] = "";
    zu_snake_case(string);
    ck_assert_str_eq(string, "");

#test ente
    char string[5] = "ente";
    zu_snake_case(string);
    ck_assert_str_eq(string, "ente");

#test snakeCase
    char string[11] = "snakeCase";
    zu_snake_case(string);
    ck_assert_str_eq(string, "snake_case");

#test illegales_iglu
    char string[14] = "illicitIgloo";
    zu_snake_case(string);
    ck_assert_str_eq(string, "illicit_igloo");

#test o_o
    char string[6] = "(oO)";
    zu_snake_case(string);
    ck_assert_str_eq(string, "(o_o)");

#test SNAKE
    char string[10] = "sNAKE";
    zu_snake_case(string);
    ck_assert_str_eq(string, "s_n_a_k_e");

#test roll
    char string[49] = "neverGonnaGiveYouUpNeverGonnaLetYouDown";
    zu_snake_case(string);
    ck_assert_str_eq(string, "never_gonna_give_you_up_never_gonna_let_you_down");
