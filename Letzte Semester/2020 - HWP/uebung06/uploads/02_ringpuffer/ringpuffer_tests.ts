#include "ringpuffer.h"
#include <stdlib.h>

char* make_random_string(int size){
    // Erzeugt einen String mit zufälligen Zeichen von a bis z.
    char *string = malloc(size + 1);
    for (int i = 0; i < size; i++){
        string[i] = "abcdefghijklmnopqrstuvwxyz"[rand() % 26];
    }
    string[size] = '\0';
    return string;
}

#test check_init
    for(int i = 0; i < 100; i++){
        buffer *testbuf = init(i);
        ck_assert_int_eq(testbuf->size, i);
        ck_assert_int_eq(testbuf->pos, 0);
        free_buf(testbuf);
    }

#test single_add
    int size = 10;
    buffer *testbuf = init(size);
    add("Something", testbuf);
    ck_assert_int_eq(testbuf->size, size);
    ck_assert_int_eq(testbuf->pos, 1);
    ck_assert_str_eq(testbuf->strings[0], "Something");
    free_buf(testbuf);

#test strings_should_be_copied
    int size = 3;
    buffer *testbuf = init(size);

    // Strings sollen kopiert werden. Wenn dieser Test fehlschlägt, dann
    // werden die Strings möglicherweise nicht in ein dynamisches Array kopiert,
    // sondern es wird nur der Pointer gespeichert.
    char tmp[100];
    strcpy(tmp, "Something 0");
    add(tmp, testbuf);
    strcpy(tmp, "Something 1");
    add(tmp, testbuf);
    strcpy(tmp, "Something 2");
    add(tmp, testbuf);
    ck_assert_int_eq(testbuf->size, size);
    ck_assert_int_eq(testbuf->pos, 0);
    ck_assert_str_eq(testbuf->strings[0], "Something 0");
    ck_assert_str_eq(testbuf->strings[1], "Something 1");
    ck_assert_str_eq(testbuf->strings[2], "Something 2");

    free_buf(testbuf);

#test more_adds_without_overflow
    int size = 6;
    buffer *testbuf = init(size);
    add("Something 1", testbuf);
    ck_assert_int_eq(testbuf->pos, 1);
    add("Something 2", testbuf);
    ck_assert_int_eq(testbuf->pos, 2);
    add("Something 3", testbuf);
    ck_assert_int_eq(testbuf->pos, 3);
    add("Something 4", testbuf);
    ck_assert_int_eq(testbuf->pos, 4);
    add("Something 5", testbuf);
    ck_assert_int_eq(testbuf->size, size);
    ck_assert_int_eq(testbuf->pos, 5);
    ck_assert_str_eq(testbuf->strings[0], "Something 1");
    ck_assert_str_eq(testbuf->strings[1], "Something 2");
    ck_assert_str_eq(testbuf->strings[2], "Something 3");
    ck_assert_str_eq(testbuf->strings[3], "Something 4");
    ck_assert_str_eq(testbuf->strings[4], "Something 5");

    free_buf(testbuf);

#test more_adds_next_pos_zero
    int size = 3;
    buffer *testbuf = init(size);
    add("Something 1", testbuf);
    ck_assert_int_eq(testbuf->pos, 1);
    add("Something 2", testbuf);
    ck_assert_int_eq(testbuf->pos, 2);
    add("Something 3", testbuf);
    ck_assert_int_eq(testbuf->pos, 0);
    ck_assert_int_eq(testbuf->size, size);
    ck_assert_str_eq(testbuf->strings[0], "Something 1");
    ck_assert_str_eq(testbuf->strings[1], "Something 2");
    ck_assert_str_eq(testbuf->strings[2], "Something 3");

    free_buf(testbuf);

#test more_adds_with_overflow
    int size = 3;
    buffer *testbuf = init(size);
    add("Something 1", testbuf);
    add("Something 2", testbuf);
    add("Something 3", testbuf);
    add("Something 4", testbuf);
    ck_assert_int_eq(testbuf->size, size);
    ck_assert_str_eq(testbuf->strings[0], "Something 4");
    ck_assert_str_eq(testbuf->strings[1], "Something 2");
    ck_assert_str_eq(testbuf->strings[2], "Something 3");

    free_buf(testbuf);

#test remove_only_element
    int size = 5;
    buffer *testbuf = init(size);
    add("Somethin", testbuf);
    remove_last(testbuf);
    ck_assert_int_eq(testbuf->size, size);
    ck_assert_int_eq(testbuf->pos, 0);

    free_buf(testbuf);

#test remove_element_without_overflow
    int size = 5;
    buffer *testbuf = init(size);
    add("Something 1", testbuf);
    add("Something 2", testbuf);
    add("Something 3", testbuf);
    remove_last(testbuf);
    ck_assert_int_eq(testbuf->size, size);
    ck_assert_int_eq(testbuf->pos, 2);
    ck_assert_str_eq(testbuf->strings[0], "Something 1");
    ck_assert_str_eq(testbuf->strings[1], "Something 2");

    free_buf(testbuf);

#test remove_single_element_with_overflow
    int size = 3;
    buffer *testbuf = init(size);
    add("Something 1", testbuf);
    add("Something 2", testbuf);
    add("Something 3", testbuf);
    add("Something 1a", testbuf);
    remove_last(testbuf);
    ck_assert_int_eq(testbuf->size, size);
    ck_assert_int_eq(testbuf->pos, 0);

    ck_assert_str_eq(testbuf->strings[1], "Something 2");
    ck_assert_str_eq(testbuf->strings[2], "Something 3");

    free_buf(testbuf);

#test remove_more_elements_with_overflow
    int size = 3;
    buffer *testbuf = init(size);
    add("Something 1", testbuf);
    add("Something 2", testbuf);
    add("Something 3", testbuf);
    add("Something 1a", testbuf);
    remove_last(testbuf);
    ck_assert_int_eq(testbuf->size, size);
    ck_assert_int_eq(testbuf->pos, 0);
    remove_last(testbuf);
    ck_assert_int_eq(testbuf->size, size);
    ck_assert_int_eq(testbuf->pos, 2);
    ck_assert_str_eq(testbuf->strings[1], "Something 2");

    free_buf(testbuf);

#test test_large_size_and_long_strings
    int size = 100 * 1000;
    buffer *testbuf = init(size);

    // 10 lange strings anfügen.
    for (int i = 0; i < 10; i++){
        int string_length = 123456;

        char *string = make_random_string(string_length);

        add(string, testbuf);

        ck_assert_int_eq(testbuf->pos, i + 1);

        // String kopieren
        char *copy = malloc(string_length + 1);
        strcpy(copy, string);

        // Original löschen
        memset(string, 0, string_length);
        free(string);

        // Mit Kopie vergleichen
        ck_assert_str_eq(testbuf->strings[testbuf->pos - 1], copy);

        free(copy);
    }

    // Rest mit kleinen Strings auffüllen.
    for (int i = 0; i < size - 10; i++){
        add("Something", testbuf);
    }

    ck_assert_int_eq(testbuf->size, size);
    ck_assert_int_eq(testbuf->pos, 0);

    for (int i = 0; i < size; i++){
        remove_last(testbuf);
    }

    ck_assert_int_eq(testbuf->size, size);
    ck_assert_int_eq(testbuf->pos, 0);

    free_buf(testbuf);
