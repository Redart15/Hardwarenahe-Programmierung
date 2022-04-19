#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

int main(int argc, char **argv)
{
  int zahl = 1;
  int opt;

  while ((opt = getopt(argc, argv, "m:d:h")) != -1)
    switch (opt)
    {
    case 'm':
      zahl = zahl * atoi(optarg);
      break;
    case 'd':
      zahl = zahl / atoi(optarg);
      break;
    case 'h':
      printf("Hilfe: ./taschenrechner -m [zahl] -d [zahl] [zahlen...]\n");
      break;
    case '?':
      printf("Command not found, use -h to see commands\n");
      return 1;
    default:
      abort();
    }

  for (int index = optind; index < argc; index++){
    zahl = zahl + atoi(argv[index]);
  }
  printf("%d\n", zahl);
  return 0;
}
