#include <stdio.h>												
#include <string.h>												
#include <stdlib.h>
/*--------------------------------------------------------------------------------------------------
 * In den Heap laden  -  game_load.c*/   
// Level Struktur  - Zeilen und deren länge                                                               
typedef struct lvl{																					
	char line[81];                                                                                     
} space; 
// Spieler Struktur - x,y Position 
enum air{
	AUFBODEN = 0,
	INLUFT = 1,
};                                                                                         
typedef struct spieler{																				
	int posx;																						
	int posy;
	enum air in_luft;																					
} spieler;
// Häufig Benutze Zeichen, zum Prüfen, kein Besseren nutzen für enums gefunden
typedef enum check{
	NEWLINE  = 10 ,// 10
	SPACE	 = ' ', // 32
	PLATFORM = '#', // 35
	SPIKES	 = '<', // 60 
	AWAYSPIKE= '>', // 62
	GOLD	 = 'G', // 71
	// war mir nicht ganz sicher welches Zeichen der Spike war
	//~ DOWNSPIKE= 'V', // 86
	DOWNSPIKE= 'v', // 86
	ZIEL	 = 'Z', // 90
	UPSPIKE  = '^'	// 94
} check;
// laden des Levels                                                                                        																									
space **load_level(int *lvl_len,FILE *level,int *flaggen);
// laden der Zeile														
space *ini_line(char *read_in, int laenge);	
// löschen des gesammten Levels														
void unload(int cnt,space **level,spieler *player);                                                    
/*--------------------------------------------------------------------------------------------------
 * Game logic - game_logic.c*/
// welches Aktion gewählt werden soll                                                                             
void take_action(space **level,spieler *player,
				 FILE *in,FILE *out,int cnt, int *gold_pnt, int *game_state);
// Errechnent was genau passieren soll anhand der jetzigen Position
void next(space **level,spieler *player,int *gold_pnt, int *game_state);
// hollt die nächste Eingabe
int springen(FILE* in);
// der Speiler bewegt sich nach Vorne
void move(space **level,spieler *player,int *gold_pnt, int *game_state);
// der Spieler fällt nach Unten
void fallen(space **level,spieler *player,int *gold_pnt, int *game_state,int cnt);
// der Spieler steigt nach oben
void steigen(space **level,spieler *player,int *gold_pnt, int *game_state,int *sprung, int cnt);                                              
/*--------------------------------------------------------------------------------------------------
 * Display Funktionen  -  game_display.c*/
// gibt das Spielfeld aus                                                               
void display(int cnt,space **level,spieler *player, FILE *output);
// Spieler und das Feld sind nicht gekoppelt, damit die Wolken erhalten bleiben                                 
void find_player(int cnt,space **level,spieler *player);                                           									
/*--------------------------------------------------------------------------------------------------
 * Ein/Auslese Streams Funktionen - game_io.c*/ 
// testet auf Input/Output auf verschiedene Fehler Quellen                                               						
int test_IO(FILE **in,FILE **out,int cnt, char **array);
// testet das Level auf verschieden Fehler Quellen
int test_LVL(FILE **lvls,int cnt, char** array, int idx);
// Schließt alle Streams und wenn eine Flagge mitgegeben wird, werden hier Fehlernachrichten aus-
// gegeben
void schliessen(FILE *in,FILE *out, FILE *level, int flaggen);
