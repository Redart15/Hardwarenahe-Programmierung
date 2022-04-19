#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

void opts_behandeln(int *abgelaufen, int **mindesthaltbarkeit, char **bezeichnung, int argc, char **argv);

void lebensmittel_ausgeben(FILE *out, int abgelaufen, int *mindesthaltbarkeit, char *bezeichnung);

int main(int argc, char **argv)
{
  int abgelaufen = 0;
  int *mindesthaltbarkeit = NULL;
  char *bezeichnung = NULL;

  opts_behandeln(&abgelaufen, &mindesthaltbarkeit, &bezeichnung, argc, argv);

  FILE *out = stdout;
  if (optind < argc)
  {
    out = fopen(argv[optind], "w");
  }
  lebensmittel_ausgeben(out, abgelaufen, mindesthaltbarkeit, bezeichnung);
  return 0;
}

void opts_behandeln(int *abgelaufen, int **mindesthaltbarkeit, char **bezeichnung, int argc, char **argv)
{
  int c;
  while ((c = getopt(argc, argv, "am:b:")) != -1)
  {
    switch (c)
    {
    case 'a':
      *abgelaufen = 1;
      break;
    case 'm':
      *mindesthaltbarkeit = malloc(sizeof(int));
      **mindesthaltbarkeit = atoi(optarg);
      break;
    case 'b':
      *bezeichnung = malloc(20 * sizeof(char));
      strcpy(*bezeichnung, optarg);
      break;
    default:
      printf("Unbekannter befehl\n");
    }
  }
}

void lebensmittel_ausgeben(FILE *out, int abgelaufen, int *mindesthaltbarkeit, char *bezeichnung)
{
  int alter;
  int haltbarkeit;
  char produktbezeichnung[20];
  char produktkategorie[20];

  int filter = 1;
  while (scanf("%s %d %s %d", produktbezeichnung, &alter, produktkategorie, &haltbarkeit) == 4)
  {
    filter = 1;
    if (abgelaufen == 1)
      filter = filter & (alter > haltbarkeit);
    if (mindesthaltbarkeit != NULL)
      filter = filter && (haltbarkeit >= *mindesthaltbarkeit);
    if (bezeichnung != NULL)
      filter = filter && (strcmp(bezeichnung, produktbezeichnung) == 0);

    if (filter == 1)
    {
      fprintf(out, "%s %d %s %d\n", produktbezeichnung, alter, produktkategorie, haltbarkeit);
    }
  }
}