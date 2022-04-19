#include "dungeon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>

/* Viel Erfolg! */
//Danke ^^
void mapcount(FILE *lvl, int xy[3]){
	//Var initilization
	int tempx = 0;
	xy[0] = 0;
	xy[1] = 0;
	char read = ' ';
	
	//Mapcounting
	while(fscanf(lvl, "%c", &read)==1){
		while(read != '\n'){
			tempx++;
			fscanf(lvl, "%c", &read);
		}
		if(tempx>xy[0]){
			xy[0]=tempx+1;
		}
		xy[1]++;
		xy[2] += tempx+1;
		tempx=0;
	}
}

//Speichert map im struct
void mapsave(FILE *lvl, int xy[3],map *karte, player *spieler, hostile **gegner, dexit **ausgang){
	int i =0;
	int xpos = 0;
	int ypos = 0;
	int hoscnt = 0;
	int excnt = 0;
	while(fscanf(lvl, "%c", &karte[i].feld)==1){
		karte[i].posx = xpos;
		karte[i].posy = ypos;
		if(karte[i].feld == 'S'){
			spieler->posx=xpos;
			spieler->posy=ypos;
		}
		if(karte[i].feld == 'A'){
			if(excnt >=1){
				*ausgang = realloc(*ausgang, sizeof(dexit)*(excnt+1));
			}
			(*ausgang)[excnt].posx = xpos;
			(*ausgang)[excnt].posy = ypos;
			excnt++;
		}
		if(karte[i].feld == '^'||karte[i].feld == '>'||karte[i].feld == '<'||karte[i].feld == 'v'){
			if(hoscnt >=1){
				*gegner = realloc(*gegner, sizeof(hostile)*(hoscnt+1));
			}
			(*gegner)[hoscnt].posx = xpos;
			(*gegner)[hoscnt].posy = ypos;
			if(karte[i].feld == '^'){
				(*gegner)[hoscnt].posdir = up;
			}
			if(karte[i].feld == '<'){
				(*gegner)[hoscnt].posdir = left;
			}
			if(karte[i].feld == '>'){
				(*gegner)[hoscnt].posdir = right;
			}
			if(karte[i].feld == 'v'){
				(*gegner)[hoscnt].posdir = down;
			}
			hoscnt++;
		}
		if(karte[i].feld == '\n'){
			xpos = 0;
			ypos++;
		}
		else{
			xpos++;
		}
		i++;
	}	
}

void drawout(int xy[3] , map *karte,FILE *outdat){
	for(int i = 0; i < xy[2]; i++){
		fprintf(outdat, "%c",karte[i].feld);
	}
}
//buffert spielerpos
void movpos(map *karte, int i, int *pposx, int *pposy, int* feldpos){
	*pposx = karte[i].posx;
	*pposy = karte[i].posy;
	*feldpos = i;
}

int playermov(int movcnt, int xy[3], map *karte, player *spieler, FILE* indat, FILE* outdat){
	int excol = 0;
	char ch = ' ';
	fscanf(indat, "%*[\n]");
	fscanf(indat, "%c[^\n]", &ch);
	int pposx = 0;
	int pposy = 0;
	int feldpos = -1;
	//Wählt richtung
	switch(ch){
		case 'w':
		for(int i=0;i < xy[2];i++){
			if(karte[i].posy == spieler->posy -1 && karte[i].posx == spieler->posx){
				movpos(karte, i, &pposx, &pposy, &feldpos);
			}
		}
		break;
		case 'a':
		for(int i=0;i < xy[2];i++){
			if(karte[i].posy == spieler->posy  && karte[i].posx == spieler->posx-1){
				movpos(karte, i, &pposx, &pposy, &feldpos);
			}
		}
		break;
		case 's':
		for(int i=0;i < xy[2];i++){
			if(karte[i].posy == spieler->posy +1 && karte[i].posx == spieler->posx){
				movpos(karte, i, &pposx, &pposy, &feldpos);
			}
		}
		break;
		case 'd':
		for(int i=0;i < xy[2];i++){
			if(karte[i].posy == spieler->posy && karte[i].posx == spieler->posx+1){
				movpos(karte, i, &pposx, &pposy, &feldpos);
			}
		}
		break;
	}
	//aktualisiert chars auf karte
	if(feldpos != -1){
		if(karte[feldpos].feld!= '#'){
			if(karte[feldpos].feld != 'A'){
				karte[feldpos].feld = 'S';
			}
			if(karte[feldpos].feld== 'A'){
				excol++;
			}
			for(int i=0;i < xy[2];i++){
			if(karte[i].posy == spieler->posy && karte[i].posx == spieler->posx && karte[i].feld=='S'){
				karte[i].feld = ' ';
			}
		}
			spieler->posy = pposy;
			spieler->posx = pposx;
		}
		
	}
		fprintf(outdat,"%i %c\n", movcnt, ch);
		return excol;
}
//collision detect für gegner/spieler
int hostilecol(int hoscnt, player* spieler, hostile *gegner){
	for(int i = 0; i < hoscnt; i++){
			if(gegner[i].posx == spieler->posx && gegner[i].posy == spieler->posy){
				return 1;
		}
	}
	return 0;
}
//translate für enum zu char
char enumubersetzer(enum hostiledir posdir){
	switch(posdir){
		case (up):
			return '^';
		break;
		case (down):
			return 'v';
		break;
		case (left):
			return '<';
		break;
		case (right):
			return '>';
		break;
	}
	return ' ';
}
//dreht gegner bei aufprall um
void flip(hostile *gegner, map *karte, int i,int j){
	switch(gegner[j].posdir){
		case (up):
			gegner[j].posdir = (down);
		break;
		case (down):
			gegner[j].posdir = (up);
		break;
		case (left):
			gegner[j].posdir = (right);
		break;
		case (right):
			gegner[j].posdir = (left);
		break;
	}
	int prevhos = 0;
	for(int o = 0; o < j; o++){
		if(gegner[o].posx == gegner[j].posx && gegner[o].posy == gegner[j].posy){
				prevhos = 1;
		}
	}
	if(prevhos == 0){
		karte[i].feld = enumubersetzer(gegner[j].posdir);
	}
}
//tasächliche bewegun von hostilemov
void hosposchange(int xy[3], map *karte,hostile *gegner, int i, int j){
	//Wandcheck mit ausgang
	int prevhos = 0;
	if(karte[i].feld=='#'||karte[i].feld=='A'){
		for(int k=0;k < xy[2];k++){
			if(karte[k].posy == gegner[j].posy && karte[k].posx == gegner[j].posx){
				flip(gegner, karte, k, j);
			}
		}	
	}
	//Bewegung weil keine wand
	else{
		//Ist jemand auf meinem Feld
		for(int o = 0; o < j; o++){
			if(gegner[o].posx == gegner[j].posx && gegner[o].posy == gegner[j].posy){
				prevhos = 1;
			}
		}
		//Löschung vom alten char
		if(prevhos==0){
			for(int k=0;k < xy[2];k++){
				if(karte[k].posy == gegner[j].posy && karte[k].posx == gegner[j].posx){
					if(karte[k].feld=='v'||karte[k].feld=='<'||karte[k].feld=='>'||karte[k].feld=='^'){
						karte[k].feld = ' ';
					}
				}
			}
		}
		else prevhos=0;
		//Bewegung
		gegner[j].posx = karte[i].posx;
		gegner[j].posy = karte[i].posy;
		
		//Platzieren des neuen chars
		for(int o = 0; o < j; o++){
			if(gegner[o].posx == gegner[j].posx && gegner[o].posy == gegner[j].posy){
				prevhos = 1;
			}
		}
		if(prevhos==0){
			for(int k=0;k < xy[2];k++){
				if(karte[k].posy == gegner[j].posy && karte[k].posx == gegner[j].posx){
					karte[k].feld = enumubersetzer(gegner[j].posdir);
				}
			}
		}
	}
}
//wählt richtung für hosposchange und aktiviert col detect
int hostilemov(int hoscnt, int xy[3], map *karte, player *spieler, hostile *gegner,
FILE* indat, FILE* outdat){
	//Hosmov
	for(int j = 0; j < hoscnt; j++){
		switch(gegner[j].posdir){
			case (up):
				for(int i=0;i < xy[2];i++){
					if(karte[i].posy == gegner[j].posy -1 && karte[i].posx == gegner[j].posx){
						hosposchange(xy, karte, gegner, i, j);
						break;
					}
				}
			break;
			case (down):
				for(int i=0;i < xy[2];i++){
					if(karte[i].posy == gegner[j].posy+1 && karte[i].posx == gegner[j].posx){
						hosposchange(xy, karte, gegner, i, j);
						break;
					}
				}
			break;
			case (left):
				for(int i=0;i < xy[2];i++){
					if(karte[i].posy == gegner[j].posy && karte[i].posx == gegner[j].posx -1){
						hosposchange(xy, karte, gegner, i, j);
						break;
					}
				}
			break;
			case (right):
				for(int i=0;i < xy[2];i++){
					if(karte[i].posy == gegner[j].posy && karte[i].posx == gegner[j].posx +1){
						hosposchange(xy, karte, gegner, i, j);
						break;
					}
				}
			break;
		}
	}
	
	//endmov player detection
	if(hostilecol(hoscnt, spieler, gegner)==1) return 1;
	//end
	return 0;
}
//Wo das eigentliche spiel passiert
int gamelogic(int xy[3],map *karte,player *spieler,hostile *gegner,FILE* indat,FILE* outdat){
	int hoscnt = 0;
	int lftnch = 1;
	int movcnt = 1;
	int hoscol = 0;
	int excol = 0;
	//Hostile count
	for(int i = 0; i < xy[2]; i++){
		if(karte[i].feld == '^'||karte[i].feld == '>'||karte[i].feld == '<'||karte[i].feld == 'v'){
			hoscnt++;
		}
	}
	//spielstart
	while(lftnch == 1){
		excol = playermov(movcnt, xy, karte, spieler, indat, outdat);
		movcnt++;
		//Enemy mov
		hoscol = hostilemov(hoscnt, xy,karte,spieler, gegner, indat,outdat);
		//map draw 
		drawout(xy,karte,outdat);
		if(hoscol==1){
			lftnch=0;
			return 1;
		}
		if(excol==1){
			lftnch=0;
			return 0;
		}
	}
	return 0;
}
//ende des spiels
void ergebnisprin(int ergebnis, FILE* outdat){
	if(ergebnis==1){
		fprintf(outdat, "Du wurdest von einem Monster gefressen.\n");
	}
	else{
		fprintf(outdat, "Gewonnen!\n");
	}
}
//Dateifreigebung bei normalen spielende
void freiheit( map *karte, player *spieler, hostile *gegner,dexit *ausgang,char* datin,
char* datout,FILE* lvl,FILE* indat,FILE* outdat)
{
	free(karte);
	free(spieler);
	free(gegner);
	free(ausgang);
	if(strcmp(datin, "")!=0)free(datin);
	if(strcmp(datout, "")!=0)free(datout);
	fclose(lvl);
	if(indat!=stdin) fclose(indat);
	if(outdat!= stdout) fclose(outdat);
	
}
//Dateifreigabe bei unreadable files
void filefreiheit(FILE **lvl,FILE **outdat,FILE **indat,char* datin,char* datout, int arg){
	if(strcmp(datin, "")!=0)free(datin);
	if(strcmp(datout, "")!=0)free(datout);
	fclose(*lvl);
	switch(arg){
		case 2:
		fclose(*indat);
		break;
	}
}
//Dateifreigabe bei nicht vorhandenen files
int filecheck(FILE *check, FILE* indat, FILE* outdat, FILE* lvl,char* datin,char* datout){
	if(check==NULL){
		fprintf(stderr,"DATEI IST FALSCH\n");
		if(strcmp(datin, "")!=0)free(datin);
		if(strcmp(datout, "")!=0)free(datout);
		if(lvl!=NULL) fclose(lvl);
		if(indat!=stdin&&indat!=NULL) fclose(indat);
		if(outdat!= stdout&&outdat!=NULL) fclose(outdat);
		return 1;
	}
	
	return 0;
}
//Check für files
int validfiles(FILE **lvl,FILE **outdat,FILE **indat,char* datin,char* datout,char *argv,int argc){
	char ch =' ';
	if(argc==1){
		fclose(*lvl);
		*lvl = fopen(argv, "r");
		if(filecheck(*lvl, *indat, *outdat, *lvl, datin, datout)==1){
			return 1;
		}
		fscanf(*lvl, "%c", &ch);
		if(ferror(*lvl)){
			filefreiheit(lvl, outdat, indat, datin, datout, 1);
			return 2;
		 }
		rewind(*lvl);
	}
	if(strcmp(datin, "")!=0){
		*indat = fopen(datin, "r");
		if(filecheck(*indat, *indat, *outdat, *lvl, datin, datout)==1){
			return 1;
		}
		fscanf(*indat, "%c", &ch);
		if(ferror(*indat)){
			filefreiheit(lvl, outdat, indat, datin, datout, 2);
			return 2;
		}
		rewind(*indat);
	}
	
	if(strcmp(datout, "")!=0) {
		*outdat = fopen(datout, "w");
		if(filecheck(*outdat, *indat, *outdat, *lvl, datin, datout)==1){
			return 1;
		}
	}
	return 0;
}
//Check für args
int argscatch(int argc, char *argv[]){
	int manyargsi = 0;
	int manyargso = 0;
	
	for(int i = 0; i < argc; i++){
		if(strcmp(argv[i], "-i")==0){
			manyargsi++;
		}
		if(strcmp(argv[i], "-o")==0){
			manyargso++;
		}
	}
	if(manyargsi>1||manyargso>1){
		fprintf(stderr,"Fehler , zu viele Parameter");
		return 3;
	}
	
	return 0;
}
//Main 
int main(int argc, char *argv[]){
	//Setup
	char lvlin[] = "./level/1.txt";
	char *datin  = "";
	char *datout = "";
	char ch;
	
	//toomanyargs catch
	if(argscatch(argc, argv)==3){
		return 3; 
	}
	
	
	//args
	while((ch=getopt(argc, argv, "i:o:"))!= EOF){
		switch(ch){
			case 'i':
			datin = malloc(sizeof(char*)*strlen(optarg));
			strcpy(datin, optarg);
			break;
			
			case 'o':
			datout = malloc(sizeof(char*)*strlen(optarg));
			strcpy(datout, optarg);
			break;
			
			default:
			fprintf(stderr, "Fehler , Falsche Parameter");
			return 3;
		}
	}
	argc-=optind;
	argv+=optind;
	
	if (argc > 1){
		fprintf(stderr,"Fehler , zu viele Parameter");
		return 3;
	 }
	//FILES 
	FILE *lvl = fopen(lvlin, "r");
	FILE *outdat= stdout;
	FILE *indat = stdin;
	int error = validfiles(&lvl, &outdat, &indat, datin, datout, argv[0], argc);
	if(error==1){
		return 1;
	}
	if(error==2){
		fprintf(stderr, "Nicht lesbare Datei");
		return 2;
	}
	//Mapcounter
	int xy[3] = {0,0,0};
	mapcount(lvl,xy);
	//Map initialiser
	map *karte = malloc(sizeof(map)*xy[2]);
	player *spieler = malloc(sizeof(player)); 
	hostile *gegner = malloc(sizeof(hostile));
	dexit *ausgang = malloc(sizeof(dexit));
	rewind(lvl);
	mapsave(lvl, xy, karte, spieler, &gegner, &ausgang);
	drawout(xy,karte,outdat);
	
	//Spiellogik
	ergebnisprin(gamelogic(xy, karte, spieler, gegner, indat, outdat), outdat);
	
	//ending
	freiheit(karte, spieler, gegner, ausgang, datin, datout, lvl, indat, outdat);
	return 0;
}
