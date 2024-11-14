#include <stdio.h>

int main()
{
    int nb;
    printf("entrer un nombre :");
    scanf("%d",&nb);
    if (nb%2==0)
    {
        goto pair;
    } else {
        goto impair;
    }

pair:
    printf("%d est pair",nb);
    return 0;
impair:
    printf("%d est impair",nb);
    return 0;
}