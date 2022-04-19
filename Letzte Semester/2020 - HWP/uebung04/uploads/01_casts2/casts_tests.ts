#include "casts.h"

#test drei_durch_twei
    double ergebnis = dividiere(3, 2);

    ck_assert_int_eq(ergebnis * 2, 3);

#test drei_durch_drei
    double ergebnis = dividiere(3, 3);

    ck_assert_int_eq(ergebnis * 3, 3);

#test zwei_durch_vier
    double ergebnis = dividiere(2, 4);

    ck_assert_int_eq(ergebnis * 4, 2);
