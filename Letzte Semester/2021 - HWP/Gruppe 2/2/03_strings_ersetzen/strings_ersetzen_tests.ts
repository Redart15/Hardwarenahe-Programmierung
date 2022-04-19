#include "strings_ersetzen.h"

void strings_testen(
    char *text,
    char *richtige_ausgabe,
    char strings[100][100],
    char richtige_strings[100][100],
    int richtige_anzahl_strings
){
    char ausgabe[1000];
    int anzahl_strings = strings_ersetzen(ausgabe, text, strings);

    ck_assert_str_eq(ausgabe, richtige_ausgabe);

    ck_assert_int_eq(anzahl_strings, richtige_anzahl_strings);

    for (int i = 0; i < anzahl_strings; i++){
        ck_assert_str_eq(strings[i], richtige_strings[i]);
    }
}

#test keine_stings
    char strings[100][100];
    char richtige_strings[100][100];
    strings_testen(
        "Hello, World!",
        "Hello, World!",
        strings,
        richtige_strings,
        0);

#test einzelne_sternchen
    char strings[100][100] = {"Hello", "World"};
    char richtige_strings[100][100] = {"*", "*"};
    strings_testen(
        "*, *!",
        "Hello, World!",
        strings,
        richtige_strings,
        2);

#test mehrere_sternchen
    char strings[100][100] = {"Thank"};
    char richtige_strings[100][100] = {"****"};
    strings_testen(
        "**** you!",
        "Thank you!",
        strings,
        richtige_strings,
        1);

#test schinken
    char strings[100][100] = {"Ohrwurm", "belegtes Brot", "Schinken"};
    char richtige_strings[100][100] = {"*", "***", "********"};
    strings_testen(
        "Was hilft gegen einen *? - Ein *** mit ********!",
        "Was hilft gegen einen Ohrwurm? - Ein belegtes Brot mit Schinken!",
        strings,
        richtige_strings,
        3);

#test bestes_video
    char strings[100][100] = {
        "https",
        "www",
        "youtube",
        "com",
        "watch",
        "v",
        "dQw4w9WgXcQ",
    };
    char richtige_strings[100][100] = {
        "***",
        "***",
        "**",
        "*",
        "*",
        "*******",
        "*",
    };
    strings_testen(
        "***://***.**.*/*?*******=*",
        "https://www.youtube.com/watch?v=dQw4w9WgXcQ",
        strings,
        richtige_strings,
        7);

#test code_kommentieren
    char strings[100][100] = {
        "githubusercontent",
        "ProjectDock",
        "memes",
        "png",
    };
    char richtige_strings[100][100] = {
        "*",
        "**",
        "*",
        "***************************",
    };
    strings_testen(
        "https://raw.*.com/**/programming-*/"
        "main/src/MEMES/images/I-am-Harshdeep/meme.***************************",
        "https://raw.githubusercontent.com/ProjectDock/programming-memes/"
        "main/src/MEMES/images/I-am-Harshdeep/meme.png",
        strings,
        richtige_strings,
        4);
