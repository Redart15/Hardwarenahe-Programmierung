#include <stdio.h>												
#include <string.h>												
#include <stdlib.h>
#include "jumpandrun.h"

int set_io(FILE **in, FILE **out,int argc, char** argv){
	int f_error = 0;
	if((argc>1) && (strcmp(argv[1],"-") != 0)){
		*in = fopen(argv[1],"r");
	}
	if((argc>2) && (strcmp(argv[2],"-") != 0)){
		*out = fopen(argv[2],"w");
	}
	f_error = error_testing(*in);
	f_error = error_testing(*out);
	if(f_error){
		fehler_melden(f_error);
		fclose(*in);
		fclose(*out);
		return 1;
	}
	return 0;
}
int error_testing(FILE *test){
	if(ferror(test)){
		return 1;
	}
	return 0;
}
void fehler_melden(int flagge){
	const char *fehler[] = {"LEERERSTRING",
							"Die In/Output könnte nicht geöffnet werden",
							"Das Level konnte nicht gelesen werden"};
	printf("------------------------------------------------ \n"
		   "Error Code: %d\n"
		   "Fehler: %s\n"
		   "-------------------------------------------------\n",
		   flagge,fehler[flagge]);
	return;
}
