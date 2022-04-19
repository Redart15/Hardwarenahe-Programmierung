#include "simpleString.h"
#include <string.h>


int my_strcmp(char *string1, char *string2){
    if (strlen(string1) != strlen(string2)){
        return 0;
    }
    int len = 0;
    if (strlen(string1) < strlen(string2)){
        len = strlen(string1);
    } else {
        len = strlen(string2);
    }
    for(int i = 0; i < len; i++){
        if(string1[i] != string2[i]){
            return 0;
        }
    }
    return 1;
}

int count_in_string(char *haystack, char needle){
    int count = 0;
    for(int i=0; i<strlen(haystack);i++){
        if(haystack[i] == needle){
            count++;
        }
    }
    return count;
}
