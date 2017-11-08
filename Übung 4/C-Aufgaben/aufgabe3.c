#include <stdio.h>

int main() {
  unsigned int n, p;

  scanf("%i", &n);

  p = 1;

  while (n > 1) {
    p = p * n;
    n = n-1;
  }
  printf("%i", p);

  return 0;
}
