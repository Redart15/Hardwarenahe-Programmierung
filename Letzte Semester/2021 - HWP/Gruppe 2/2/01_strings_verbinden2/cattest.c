/* stringcat.c */
#include <stdio.h>
#include <string.h>

int main(void) {
   char string0[] = " ,olleH";
   char name[20] ={};

   strcat(name, string0);
   printf("%s",name);
   return 0;
}
