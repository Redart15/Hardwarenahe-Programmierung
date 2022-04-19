#include "camel_case.h"

#test leerer_string
    char string[] = "";
    zu_camel_case(string);
    ck_assert_str_eq(string, "");

#test camel_case
    char string[] = "camel_case";
    zu_camel_case(string);
    ck_assert_str_eq(string, "camelCase");

#test camel___________case
    char string[] = "camel_________case";
    zu_camel_case(string);
    ck_assert_str_eq(string, "camelCase");

#test camel_case_____
    char string[] = "camel_case_____";
    zu_camel_case(string);
    ck_assert_str_eq(string, "camelCase");

#test XMLHttpRequest
    char string[] = "XMLHttpRequest";
    zu_camel_case(string);
    ck_assert_str_eq(string, "XMLHttpRequest");

#test gemischt
    char string[] = "snake_case_camelCase_HTTP_snake_case";
    zu_camel_case(string);
    ck_assert_str_eq(string, "snakeCaseCamelCaseHTTPSnakeCase");

#test zahlen
    char string[] = "zahlen_1234";
    zu_camel_case(string);
    ck_assert_str_eq(string, "zahlen1234");

#test leerzeichen_und_ausrufezeichen
    char string[] = "a_a_a_h! snake_case!";
    zu_camel_case(string);
    ck_assert_str_eq(string, "aAAH! snakeCase!");

#test roll
    char string[] = "never_gonna____give__you_up_never____gonna_let_you____down";
    zu_camel_case(string);
    ck_assert_str_eq(string, "neverGonnaGiveYouUpNeverGonnaLetYouDown");
