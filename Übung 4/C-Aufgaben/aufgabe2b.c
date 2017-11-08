#include <stdio.h>

int main() {
    unsigned int n, i, j;

    printf("Bitte gib eine Zahl ein!");
    scanf("%u", &n);

    for (i=1; i <= n; i++) {
      for (j=1; j <=n ; j++) {
        printf("%u\t", i * j);
      }
      printf("\n");
    }
    return 0;
}
