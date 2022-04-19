#include <stdio.h>
#include <limits.h>
#include <getopt.h>


int main( int argc, char ** argv ){

    printf("Der Datentyp char benötigt TODO Bytes Speicherplatz.\n", 42);

    char option;
    while((option = getopt(argc, argv, "mM")) !=EOF){
        switch(option){
            case 'm': 
            {
                printf("Die kleinste darstellbare Zahl beträgt dann TODO.\n", 42);
                break;
            }
            case 'M': 
            {
                printf("Die größte darstellbare Zahl beträgt dann TODO.\n", 42);
                break;
            }
        }
    }

    return 0;

}
