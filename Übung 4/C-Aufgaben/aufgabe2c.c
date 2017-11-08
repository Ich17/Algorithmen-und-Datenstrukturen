#include <stdio.h>

#define LEN 1001

int main() {
  unsigned int prim[LEN];
  unsigned int i, j;

  prim[0] = 0, prim[1] = 0;

  for (i = 2; i < LEN; ++i) {
    prim[i] = 1;
  }

  for (i = 2; i < LEN; ++i) {
    if(prim[i] != 0) {
      for (j = 2 * i; j < LEN; j = j + i) {
        prim[j] = 0;
      }
    }
  }

  for (i = 0; i < LEN; ++i) {
    if (prim[i] != 0)
      printf("%u\n", i);
  }

  return 0;
}
