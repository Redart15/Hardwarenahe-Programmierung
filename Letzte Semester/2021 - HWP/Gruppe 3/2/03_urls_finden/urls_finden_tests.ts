#include "urls_finden.h"

void urls_testen(char richtige_urls[10][150], int richtige_anzahl, char *text){
    char urls[10][150];
    int anzahl = urls_finden(urls, text);

    ck_assert_int_eq(anzahl, richtige_anzahl);

    for (int i = 0; i < anzahl; i++){
        ck_assert_str_eq(urls[i], richtige_urls[i]);
    }
}

#test keine_urls
    char *text = "Hello, World!";
    char urls[10][150];
    urls_testen(urls, 0, text);

#test beispiel
    char *text = "https://www.example.com";
    char urls[10][150] = {"https://www.example.com"};
    urls_testen(urls, 1, text);

#test beispiel_in_text
    char *text = "Die https URL lautet zum Beispiel:https://www.example.com <----";
    char urls[10][150] = {"https://www.example.com"};
    urls_testen(urls, 1, text);

#test alle_drei_formate
    char *text = "https://www.example.com www.example.com http://example.com";
    char urls[10][150] = {"https://www.example.com", "www.example.com", "http://example.com"};
    urls_testen(urls, 3, text);

#test verbotene_sonderzeichen
    char *text = "}www.example.com|www.example.com`www.example.com\\www.example.com{";
    char urls[10][150] = {"www.example.com", "www.example.com", "www.example.com", "www.example.com"};
    urls_testen(urls, 4, text);

#test erlaubte_sonderzeichen
    char *text = "https://example.com:80/@foo/bar.html?q=1;s=2&t=3!#$%~'(a.s-d_f~g),([12+3*4])";
    char urls[10][150] = {
        "https://example.com:80/@foo/bar.html?q=1;s=2&t=3!#$%~'(a.s-d_f~g),([12+3*4])"
    };
    urls_testen(urls, 1, text);

#test www
    char *text = "wwwachnedochnicht";
    char urls[10][150];
    urls_testen(urls, 0, text);

#test nicht_ganz_https
    char *text = "https:/ach kein Bock mehr";
    char urls[10][150];
    urls_testen(urls, 0, text);

#test verschiedene_urls
    char *text =
        "Das beste Video: https://www.youtube.com/watch?v=dQw4w9WgXcQ "
        "Ein Link zum ILIAS: https://ilias.hhu.de/ilias.php?ref_id=1&cmdClass=ilrepositorygui&cmdNode=va&baseClass=ilrepositorygui ,"
        "Wikipedia-Eintrag zur Programmiersprache C https://en.wikipedia.org/wiki/C_(programming_language) "
        "Microsoft https://www.youtube.com/oembed?url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DVhh_GeBPOhs&format=json "
        "Klackernde Tastaturen https://i.imgur.com/pbqiLgY.gif "
        "Schlecht kommentierter Code https://raw.githubusercontent.com/ProjectDock/programming-memes/main/src/MEMES/images/I-am-Harshdeep/meme.png "
        "Schlecht kommentierter Code 2 https://abstrusegoose.com/strips/you_down_wit_OPC-yeah_you_know_me.png "
        "https://i.imgur.com/5DlqfCl.jpg Sonderfaelle "
        "C vs C++ https://devhumor.com/content/uploads/images/December2016/c++-c-class.jpg "
        "Hyperlink https://i.imgur.com/cV9m29E.png "
        "Denkt daran eure Strings zu terminieren und eure Variablen zu initialisieren!";
    char urls[10][150] = {
        "https://www.youtube.com/watch?v=dQw4w9WgXcQ",
        "https://ilias.hhu.de/ilias.php?ref_id=1&cmdClass=ilrepositorygui&cmdNode=va&baseClass=ilrepositorygui",
        "https://en.wikipedia.org/wiki/C_(programming_language)",
        "https://www.youtube.com/oembed?url=https%3A%2F%2Fwww.youtube.com%2Fwatch%3Fv%3DVhh_GeBPOhs&format=json",
        "https://i.imgur.com/pbqiLgY.gif",
        "https://raw.githubusercontent.com/ProjectDock/programming-memes/main/src/MEMES/images/I-am-Harshdeep/meme.png",
        "https://abstrusegoose.com/strips/you_down_wit_OPC-yeah_you_know_me.png",
        "https://i.imgur.com/5DlqfCl.jpg",
        "https://devhumor.com/content/uploads/images/December2016/c++-c-class.jpg",
        "https://i.imgur.com/cV9m29E.png",
    };
    urls_testen(urls, 10, text);
