#include <stdio.h>												
#include <string.h>												
#include <stdlib.h>												
#include "jumpandrun.h"	

int main(int argc, char **argv){
	int gold_pnt = 0, game_state = 0,lvl_len = 0;
	int idx = 3;
	FILE *eingabe = stdin;
	FILE *ausgabe = stdout;
	if(set_io(&eingabe,&ausgabe,argc,argv)){return 1;}
	FILE *level = fopen("./level/2.txt","r");
	
	//~ while( (idx <= argc)&&(game_state != 2)){
	while(game_state != 2){
		if(argc<3){
			freopen("./level/2.txt","r", level);
		}else{
			freopen(argv[idx],"r", level);
		}
		//~ freopen(argv[idx],"r",level);
		if(error_testing(level)){return 2;}
		lvl_len = game_state = gold_pnt = 0;
		space **loaded = load_level(&lvl_len,level);
		spieler *player = malloc(sizeof(spieler));
		take_action(loaded,player,eingabe,ausgabe,lvl_len,&gold_pnt,&game_state);
		unload(lvl_len,loaded,player);
		switch(game_state){
			case   1:
				fprintf(ausgabe,"Gewonnen! Punktzahl: %d\n",gold_pnt);
				if(argc==1){
					fclose(eingabe);
					fclose(ausgabe);
					fclose(level);
					return 0;
				}
				break;
			case  -1:
				fprintf(ausgabe,"Leider verloren. Das Level wird neu gestartet.\n");
				//~ idx--;
				continue;
				break;
			case   2:
				break;
		}
		idx++;
		if(argc <= idx){
			fclose(eingabe);
			fclose(ausgabe);
			fclose(level);
			return 0;
		}
	}
	fclose(level);
	fclose(eingabe);
	fclose(ausgabe); 
	return 0;
}

