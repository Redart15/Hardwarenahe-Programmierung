#include <stdio.h> 
#include <string.h> 


void strings_verbinden(char* zusammen,char* str1,char* str2,char* str3);

int main(){
	char zusammen[1000];
	memset(zusammen,1,1000);
	char *str1 = "eins";
	char *str2 = ", zwei";
	char *str3 = ", drei";
	strings_verbinden(zusammen,str1,str2,str3);
	
	for(int cnt = 0;zusammen[cnt]!= '\0';cnt++){
		if(cnt>999){printf("Zusammen ist nicht terminiert\n");return 1;}
	}
	printf("Zusammen ist terminiert\n");
	return 0;
}
