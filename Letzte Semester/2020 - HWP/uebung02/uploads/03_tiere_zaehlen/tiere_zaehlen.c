#include "tiere_zaehlen.h"

char default_tiere[5][16] = {"Ente", "Gans", "Maus", "Nasenaffe", "Saigaantilope"};

char* nicht_zeichen_string_erstellen(){
    char* non_zeichen = malloc(sizeof(char) * 255);
    int pos = 0;
    for(int i = 32; i < 255; i++){ //bis ascii character 32 sind es "nicht-symbole", sowas wie nullterminator etc. daher i=32
        if(!((i > 64 && i < 91) || (i > 96 && i < 123))){
            non_zeichen[pos] = i;
            pos++;
        }
    }
    return non_zeichen;
}

int tiere_zaehlen(char tiere[10][16], char *string)
{
    char *string_cpy = malloc(strlen(string)*sizeof(char));
    strcpy(string_cpy, string);
    char *trenner = nicht_zeichen_string_erstellen();
    char *bufffer;
    int anzahl = 0;
    bufffer = strtok(string_cpy, trenner);
    while (bufffer != NULL)
    {
        for(int i = 0; i < 5; i++){
            if(strcmp(default_tiere[i], bufffer) == 0){
                strcpy(tiere[anzahl], bufffer);
                anzahl++;
            }
        }
        bufffer = strtok(NULL, trenner);
    }

    return anzahl;
}
