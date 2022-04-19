#include "bruch.h"

#test product_kuerzen
    bruch a = {.zaehler = 10, .nenner = 5};
    bruch b = {.zaehler = 2, .nenner = 3};
    bruch c = product(a, b);
    ck_assert_int_eq(c.zaehler, 4);
    ck_assert_int_eq(c.nenner, 3);

#test product_nicht_kuerzen
    bruch a = {.zaehler = 3, .nenner = 5};
    bruch b = {.zaehler = 7, .nenner = 11};
    bruch c = product(a, b);
    ck_assert_int_eq(c.nenner, a.nenner * b.nenner);
    ck_assert_int_eq(c.zaehler, a.zaehler * b.zaehler);

#test kuerze_einfaches_vielfaches
    bruch a = {.zaehler = 15, .nenner = 5};
    kuerze(&a);
    ck_assert_int_eq(a.nenner, 1);
    ck_assert_int_eq(a.zaehler, 3);

#test kuerze_gemeinsame_primfaktoren
    bruch a = {.zaehler = 6, .nenner = 14};
    kuerze(&a);
    ck_assert_int_eq(a.nenner, 7);
    ck_assert_int_eq(a.zaehler, 3);

#test print_einhalb
    bruch a = {.zaehler = 10, .nenner = 20};
    char ausgabe[100];
    print(a, ausgabe);
    // Nur die ersten 3 Zeichen vergleichen
    ausgabe[3] = '\0';
    ck_assert_str_eq(ausgabe, "0.5");

#test print_minus_drittel
    bruch a = {.zaehler = 3, .nenner = -9};
    char ausgabe[100];
    print(a, ausgabe);
    // Nur die ersten 6 Zeichen vergleichen
    ausgabe[6] = '\0';
    ck_assert_str_eq(ausgabe, "-0.333");
