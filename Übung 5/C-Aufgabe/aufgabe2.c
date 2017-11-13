#include <stdio.h>

void swap(int *x, int *y) {
  int tmp;

  if(*x % 2 == 1) *y = *y + 1;

  tmp = *x;
  *x = *y;
  *y = tmp;
}

void swap_wrong(int x, int y) {
  int tmp;

  if(x % 2 == 1) y = y + 1;

  tmp = x;
  x = y;
  y = tmp;
}

int main() {
  int x, y;
   printf("Bitte gib x ein!\n");
   scanf("%i", &x);
   printf("Bitte gib y ein!\n");
   scanf("%i", &y);

   swap(&x, &y);

   printf("x: %i und y: %i", x, y);

   return 0;
}
