#include "camel_case.h"
#include <stdio.h>

int main() {
    char string[1000];
    printf("Geben Sie einen String ein:\n");
    if (fgets(string, sizeof(string), stdin)){
        zu_camel_case(string);

        printf("\nZu camelCase konvertiert:\n");

        printf("%s", string);
    }

    return 0;
}
