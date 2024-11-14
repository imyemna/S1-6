#include <stdio.h>

int main()
{
    int nb;
    printf("entrer un nombre :");
    scanf("%d",&nb);
    if (nb>0)
    {
        goto positif;
    } else {
        goto negatif;
    }

positif:
    printf("%d est positif",nb);
    return 0;
negatif:
    printf("%d est negatif",nb);
    return 0;
}