#include "snake_case.h"
#include <stdio.h>

int main() {
    char string[2000] = "DEr StrinG iSt um einigeS AnDer Als erWARteT&";
    zu_snake_case(string);
    
    char* zeiger;
    int cnt;
    for(zeiger = string, cnt = 0;*zeiger != '\0';zeiger++,cnt++){
		if(cnt>1999){printf("Der String wurde nicht terminiert!\n");return 1;}
	}
   printf("Der String wurde terminiert! Der Letzte Char ist: %c\n",string[cnt-1]);

   return 0;
}
