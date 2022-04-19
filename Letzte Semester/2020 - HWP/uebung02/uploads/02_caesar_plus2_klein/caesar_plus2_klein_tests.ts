#include "caesar_plus2_klein.h"

#test caesar_c_to_e
    char to_test[] = "c";
    caesar(to_test);

    char res[] = "e";
    ck_assert_str_eq(to_test, res);


#test caesar_y_to_a
    char to_test[] = "y";
    caesar(to_test);

    char res[] = "a";
    ck_assert_str_eq(to_test, res);


#test caesar_z_to_b
    char to_test[] = "z";
    caesar(to_test);

    char res[] = "b";
    ck_assert_str_eq(to_test, res);


#test caesar_longer_string
    char to_test[] ="diesisteinlangerstring";
    caesar(to_test);

    char res[] = "fkgukuvgkpncpigtuvtkpi";
    ck_assert_str_eq(to_test, res);


#test caesar_really_long_string
    char to_test[] ="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    caesar(to_test);

    char res[] = "cdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzab";
    ck_assert_str_eq(to_test, res);


#test encode_and_compare_true_short
    char string_to_encode[] = "y";
    char clearstring[] = "a";
    ck_assert_int_eq(encode_and_compare(clearstring, string_to_encode), 1);


#test encode_and_compare_true_long
    char string_to_encode[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
    char clearstring[] = "cdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzab";
    ck_assert_int_eq(encode_and_compare(clearstring, string_to_encode), 1);


#test encode_and_compare_false
    char string_to_encode[] = "a";
    char clearstring[] = "a";
    ck_assert_int_eq(encode_and_compare(clearstring, string_to_encode), 0);
