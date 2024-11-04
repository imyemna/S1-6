#include <stdio.h>

int main () {
    int a;
    float b;
    char c; // Change to single character

    printf("entre un nombre :");
    scanf("%d", &a);
    
    printf("entre un reel :");
    scanf("%f", &b);
    
    printf("entre un caracter :");
    scanf(" %c", &c); // Added space before %c to consume any leftover newline

    printf("\n A est :%d \n B est:%f \n C est:%c", a, b, c); // Changed %s to %c
    return 0;
}