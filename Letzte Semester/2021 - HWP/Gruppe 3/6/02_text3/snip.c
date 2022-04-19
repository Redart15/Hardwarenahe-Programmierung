#include <string.h>
#include <stdio.h>

int trennen(char **array,char* text);

int main(){
	char *text = "Unmute++listen:++Ich++habe++lange++in++den++Test++geschaut,++ja++um++15++Uhr++15,++war++inder"
				 "übungsstunde++um++8++da++dies++müsste++lange++genung++sein++hoffe++ich.";
	char array[100][150];
	memset(array,0,15000);
	int anzahl = trennen(array,text);
	for(int cnt = 0;cnt<anzahl;cnt++){
		printf("Array[cnt]: %s\n",array[cnt]);
	}
}

int trennen(char **array,char* text){
	int anzahl = 0;
	char *symbol = "++";
	char *start = text;
	for(;*start!=0;anzahl++){
		char *find = strstr(start,symbol);
		int str_len = find - start;
		strncpy(array[anzahl],start,str_len);
		array[anzahl][str_len+1] = '\0';
		start = find+2;
	}
	return anzahl;
}
