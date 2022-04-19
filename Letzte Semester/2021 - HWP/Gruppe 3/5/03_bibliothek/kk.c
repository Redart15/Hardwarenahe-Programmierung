#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
	FILE *ausgabe_faellig = fopen(argv[1], "w");
    printf("schreib was");
    fclose(ausgabe_faellig);
}
