#include <stdio.h>

int main() {
    char name[100];

    printf("Bitte Namen eingeben! ");
    scanf("%99s", name);
    printf("Hallo %s \n", name);

    return 0;
}
