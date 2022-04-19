#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void hide(int i);
void numberGenerator(int n, int a[]);

int main(int argc, char *argv[])
{
  int i = 0;
  hide(i);
  int j = 12;
  printf("Anzahl: %d\n", j);
  int a[j];
  numberGenerator(j, a);
  for (i = 0; i < j; i += 1)
  {
    printf("Wert: %d\n", a[i]);
  }
  return EXIT_SUCCESS;
}

void hide(int i)
{
  while (i < 10)
  {
    i += 3;
  }
  int pwd = 9173; // Dies ist das Passwort!!!
}

void numberGenerator(int n, int a[])
{
  int i = 0;
  int result[n];
  result[0] = 1;
  for (i = 1; i < n; i++)
  {
    int j = i-1; //i-- reduziert den wert in i, wodurch abwechselnd durch i++ i um 1 erhöht und verringert wird. dadurch die endlosschleife
    result[i] = (result[j] * 2 + 1) % n;
  }
  memcpy(a, result, n * sizeof(int));
}
