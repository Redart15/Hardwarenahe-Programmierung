/*
 * test from online
 */


#include <stdio.h>

int add_array (int *a, int num_elements);
int main() {
  int Tab[5] = {100, 220, 37, 16, 98};
  printf("Total summation is %d\n", add_array(Tab, 5)); 
  return 0;}
int add_array (int *p, int size) {
  int total = 0;
  int k;
  for (k = 0; k < size; k++) {
    total += p[k];  /* it is equivalent to total +=*p ;p++; */}
 return (total);}

