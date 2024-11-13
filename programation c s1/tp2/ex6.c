#include <stdio.h>

int main() {
    int choix;
    float temperature, resultat;


    do {
        printf("\nChoisissez l'opération :\n");
        printf("1. Conversion de Celsius en Fahrenheit\n");
        printf("2. Conversion de Fahrenheit en Celsius\n");
        printf("3. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            
            
            case 1:
                printf("Entrez la température en Celsius : ");
                scanf("%f", &temperature);
                resultat = (temperature * 9 / 5) + 32;
                printf("Température en Fahrenheit : %.2f\n", resultat);
                break;

            case 2:
                printf("Entrez la température en Fahrenheit : ");
                scanf("%f", &temperature);
                resultat = (temperature - 32) * 5 / 9;
                printf("Température en Celsius : %.2f\n", resultat);
                break;

            case 3:
                printf("Au revoir !\n");
                break;
                
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    } while (choix != 3);

    return 0;
}
