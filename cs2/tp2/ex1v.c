#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Entrez la taille du tableau: ");
    scanf("%d", &n);

    float *T = (float *)malloc(n * sizeof(float));
    if (T == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        return 1;
    }

    // 1) Initialisation du tableau par lecture au clavier
    printf("Entrez les éléments du tableau:\n");
    for (float *p = T; p < T + n; p++) {
        scanf("%f", p);
    }

    // 2) Affichage des valeurs du tableau
    printf("Les valeurs du tableau sont:\n");
    for (float *p = T; p < T + n; p++) {
        printf("%.2f ", *p);
    }
    printf("\n");

    // 3) Recherche de l'élément maximal et minimal, puis permutation
    float *max = T, *min = T;
    for (float *p = T; p < T + n; p++) {
        if (*p > *max) max = p;
        if (*p < *min) min = p;
    }
    float temp = *max;
    *max = *min;
    *min = temp;

    // 4) Affichage du nouveau tableau après permutation
    printf("Tableau après permutation du min et max:\n");
    for (float *p = T; p < T + n; p++) {
        printf("%.2f ", *p);
    }
    printf("\n");

    // 5) Calcul de la somme des éléments du tableau
    float somme = 0;
    for (float *p = T; p < T + n; p++) {
        somme += *p;
    }
    printf("La somme des éléments du tableau est: %.2f\n", somme);

    free(T);
    return 0;
}