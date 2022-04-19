
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <getopt.h>


enum hostiledir{
	up , down , left , right
};

typedef struct map map;

struct map{
	int posx;
	int posy;
	char feld;
};

typedef struct player player;

struct player{
	int posx;
	int posy;
};

typedef struct hostile hostile;

struct hostile{
	int posx;
	int posy;
	enum hostiledir posdir;
	
};

typedef struct dexit dexit;

struct dexit{
	int posx;
	int posy;
};

void mapcount(FILE *lvl, int xy[3]);

void mapsave(FILE *lvl, int xy[3],map *karte, player *spieler, hostile **gegner, dexit **ausgang);

void draw(int xy[3] , map *karte);

void drawout(int xy[3] , map *karte,FILE *outdat);

void whichdraw(int xy[3] , map *karte,FILE *outdat, char datout[]);

void movpos(map *karte, int i, int *pposx, int *pposy, int* feldpos);

int playermov(int movcnt, int xy[3], map *karte, player *spieler, FILE* indat, FILE* outdat);

int hostilecol(int hoscnt, player* spieler, hostile *gegner);

char enumubersetzer(enum hostiledir posdir);

void flip(hostile *gegner, map *karte, int i,int j);

void hosposchange(int xy[3], map *karte,hostile *gegner, int i, int j);

int hostilemov(int hoscnt, int xy[3], map *karte,player *spieler, hostile* gegner, FILE* indat, FILE* outdat);

int gamelogic(int xy[3],map *karte,player *spieler,hostile *gegner,FILE* indat,FILE* outdat);

void ergebnisprin(int ergebnis, FILE* outdat);

void freiheit( map *karte, player *spieler, hostile *gegner,dexit *ausgang,char* datin,char* datout,FILE* lvl,FILE* indat,FILE* outdat);

void filefreiheit(FILE **lvl,FILE **outdat,FILE **indat,char* datin,char* datout, int arg);

int filecheck(FILE *check, FILE* indat, FILE* outdat, FILE* lvl,char* datin,char* datout);

int validfiles(FILE **lvl,FILE **outdat,FILE **indat,char* datin,char* datout,char *argv,int argc);

int argscatch(int argc, char *argv[]);
