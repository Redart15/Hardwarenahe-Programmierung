#include "strings_verbinden.h"

//hilfsfunktion, damit die schleife nicht 2x geschrieben werden muss. sieht besser aus
void string_verbinden_helper(char zusammen[], char string[], int *zusammen_index)
{
    for (int i = 0; string[i]; i++)
    {
        zusammen[*zusammen_index] = string[i];
        (*zusammen_index)++;
    }
}

// Annahme: strings sind null-terminated (\0 am ende) 
void strings_verbinden(char zusammen[], char string1[], char string2[])
{
    int zusammen_index = 0;
    string_verbinden_helper(zusammen, string1, &zusammen_index);
    string_verbinden_helper(zusammen, string2, &zusammen_index);
    zusammen[zusammen_index] = '\0';
}
