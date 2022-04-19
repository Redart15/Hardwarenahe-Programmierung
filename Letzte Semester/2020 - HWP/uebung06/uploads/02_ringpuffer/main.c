#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ringpuffer.h"

// In dieser Datei können Sie Ihre Implementierung testen.

int main(int argc, char **argv){
    buffer *buf = init(2);
    printf("*******************************************************\n");
    printf("Puffer der Größe 2 erstellt und einen String eingefügt.\n");
    printf("*******************************************************\n");
    add("Guten Tag", buf);
    print(buf);

    printf("*******************************************************\n");
    printf("Füge >Welt< hinzu.\n");
    printf("*******************************************************\n");
    add("Welt", buf);
    print(buf);

    printf("*******************************************************\n");
    printf("Füge >Hallo< hinzu.\n");
    printf("*******************************************************\n");
    add("Hallo", buf);
    print(buf);

    printf("*******************************************************\n");
    printf("Entferne >Hallo<.\n");
    printf("*******************************************************\n");
    remove_last(buf);
    print(buf);

    printf("*******************************************************\n");
    printf("Gebe Puffer frei.\n");
    printf("*******************************************************\n");
    free_buf(buf);
    buf = NULL;
    print(buf);

    for(int i = 0; i < 100; i++){
        buffer *testbuf = init(i);

        free_buf(testbuf);
    }
    return 0;
}

