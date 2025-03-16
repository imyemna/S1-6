#include <stdio.h>

int main() {
    int T[] = {1, 0, 3, 0, 5, 6, 0, 8};
    int taille = sizeof(T) / sizeof(T[0]);

    printf("Éléments du tableau:\n");
    for (int *p = T; p < T + taille; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    printf("Indices des éléments nuls:\n");
    for (int *p = T; p < T + taille; p++) {
        if (*p == 0) {
            printf("%ld ", p - T);
        }
    }
    printf("\n");

    return 0;
}