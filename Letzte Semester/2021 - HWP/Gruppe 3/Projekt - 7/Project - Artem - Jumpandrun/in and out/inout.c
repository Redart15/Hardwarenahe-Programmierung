#include <stdio.h>												
#include <string.h>												
#include <stdlib.h>
#include "jumpandrun.h"

//~ int set_io(FILE *in, FILE *out,int argc, char** argv);
//~ int leveltest(FILE *lvl);
//~ void fehler_meldung(int flagge);


int set_iot(FILE *in, FILE *out,int argc, char** argv){
	char test;
	int fehler = 0;
	if((argc>1) && (strcmp(argv[1],"-") != 0)){
		freopen(argv[1],"r",in);
	}
	if((argc>2) && (strcmp(argv[1],"-") != 0)){
		freopen(argv[2],"w",out);
	}
	if(in == NULL || out == NULL){fehler = 1;}
	if(in == out){fehler = 1;}
	if((test = fgetc(in)) == EOF){fehler = 1;}
	//~ if((fputs('A',out)) == 0){fehler = 2;}
	if(fehler){
		fclose(in);
		fclose(out);
		return fehler_meldung(fehler);
	}
	return 0;	
}
int leveltest(FILE *lvl){
	int fehler = 0;
	char test;
	if(ferror(lvl)){
		fehler = 2;
	}
	if((test = fgetc(lvl)) == 0){
		fehler = 2;
	}
	if(fehler){
		fclose(lvl);
		return fehler_meldung(fehler);
	}
	return 0;

}



int fehler_meldung(int flagge){
	const char *fehler[] = {"LEERERSTRING",
							"Die Datei konnte nicht geöffent werden",
							"Die Datei konnte nicht gelesen werden"};
	printf("------------------------------------------------ \n"
		   "Error Code: %d\n"
		   "Fehler: %s\n"
		   "-------------------------------------------------\n",
		   flagge,fehler[flagge]);
	return flagge;
}
